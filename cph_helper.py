#!/usr/bin/env python3
"""
CPH Test Case Helper - Manage and share test cases for Competitive Programming Helper

This script helps you:
1. Import test cases from JSON files to CPH format
2. Export CPH test cases to shareable JSON format  
3. Run automated tests using the test case files
4. Generate test reports

Usage:
    python cph_helper.py --import test_cases/graph/island_perimeter.json
    python cph_helper.py --export .vscode/.cph/
    python cph_helper.py --test "Homework 1/Graph/1.cpp" test_cases/graph/island_perimeter.json
"""

import json
import subprocess
import os
import argparse
import time
from pathlib import Path

class CPHTestHelper:
    def __init__(self):
        self.cph_folder = Path(".vscode/.cph")
        self.test_cases_folder = Path("test_cases")
    
    def load_test_case_file(self, json_file):
        """Load test cases from JSON file"""
        with open(json_file, 'r') as f:
            return json.load(f)
    
    def convert_to_cph_format(self, test_data):
        """Convert JSON test case format to CPH .prob format"""
        cph_data = {
            "name": test_data.get("problem", "Unknown Problem"),
            "group": test_data.get("source", "Local"),
            "url": "",
            "interactive": False,
            "timeLimit": 2000,
            "tests": []
        }
        
        for test_case in test_data.get("test_cases", []):
            cph_test = {
                "input": test_case.get("input", "") + "\n",
                "output": test_case.get("expected_output", "") + "\n"
            }
            cph_data["tests"].append(cph_test)
        
        return cph_data
    
    def import_to_cph(self, json_file):
        """Import test cases from JSON to CPH format"""
        test_data = self.load_test_case_file(json_file)
        cph_data = self.convert_to_cph_format(test_data)
        
        # Create CPH folder if it doesn't exist
        self.cph_folder.mkdir(parents=True, exist_ok=True)
        
        # Generate CPH filename
        problem_name = test_data.get("problem", "unknown").replace(" ", "_").lower()
        cph_file = self.cph_folder / f"{problem_name}.prob"
        
        # Save CPH file
        with open(cph_file, 'w') as f:
            json.dump(cph_data, f, indent=2)
        
        print(f"✅ Imported {len(cph_data['tests'])} test cases to {cph_file}")
        return cph_file
    
    def export_from_cph(self, cph_folder_path=None):
        """Export all CPH test cases to JSON format"""
        if cph_folder_path:
            cph_path = Path(cph_folder_path)
        else:
            cph_path = self.cph_folder
        
        if not cph_path.exists():
            print("❌ CPH folder not found!")
            return
        
        exported_count = 0
        for prob_file in cph_path.glob("*.prob"):
            with open(prob_file, 'r') as f:
                cph_data = json.load(f)
            
            # Convert to shareable format
            shared_data = {
                "problem": cph_data.get("name", "Unknown"),
                "source": cph_data.get("group", ""),
                "description": f"Exported from CPH on {time.strftime('%Y-%m-%d')}",
                "test_cases": []
            }
            
            for i, test in enumerate(cph_data.get("tests", [])):
                shared_data["test_cases"].append({
                    "name": f"Test Case {i+1}",
                    "input": test.get("input", "").rstrip(),
                    "expected_output": test.get("output", "").rstrip(),
                    "explanation": "Exported from CPH"
                })
            
            # Save to test_cases folder
            self.test_cases_folder.mkdir(exist_ok=True)
            output_file = self.test_cases_folder / f"{prob_file.stem}.json"
            
            with open(output_file, 'w') as f:
                json.dump(shared_data, f, indent=2)
            
            print(f"✅ Exported {prob_file.name} to {output_file}")
            exported_count += 1
        
        print(f"📊 Total exported: {exported_count} files")
    
    def test_cpp_with_cases(self, cpp_file, test_case_file):
        """Test a C++ file using test cases from JSON file"""
        print(f"🚀 Testing {cpp_file} with {test_case_file}")
        
        # Load test cases
        test_data = self.load_test_case_file(test_case_file)
        test_cases = test_data.get("test_cases", [])
        
        if not test_cases:
            print("❌ No test cases found!")
            return False
        
        # Compile the C++ file
        executable = "test_program"
        if os.name == 'nt':  # Windows
            executable += ".exe"
        
        compile_result = subprocess.run(
            ["g++", "-std=c++17", "-O2", "-o", executable, cpp_file],
            capture_output=True,
            text=True
        )
        
        if compile_result.returncode != 0:
            print(f"❌ Compilation failed:")
            print(compile_result.stderr)
            return False
        
        print("✅ Compilation successful!")
        
        # Run test cases
        passed = 0
        total = len(test_cases)
        
        for i, test_case in enumerate(test_cases, 1):
            try:
                # Run the program
                run_command = [f"./{executable}"] if os.name != 'nt' else [executable]
                start_time = time.time()
                
                result = subprocess.run(
                    run_command,
                    input=test_case.get("input", ""),
                    capture_output=True,
                    text=True,
                    timeout=5
                )
                
                execution_time = time.time() - start_time
                actual_output = result.stdout.strip()
                expected_output = test_case.get("expected_output", "").strip()
                
                if actual_output == expected_output:
                    print(f"  ✅ Test {i} ({test_case.get('name', f'Case {i}')}): PASSED ({execution_time:.3f}s)")
                    passed += 1
                else:
                    print(f"  ❌ Test {i} ({test_case.get('name', f'Case {i}')}): FAILED")
                    print(f"     Expected: {expected_output}")
                    print(f"     Got:      {actual_output}")
                    if test_case.get("explanation"):
                        print(f"     Note:     {test_case['explanation']}")
                
            except subprocess.TimeoutExpired:
                print(f"  ⏰ Test {i}: TIMEOUT (>5s)")
            except Exception as e:
                print(f"  ❌ Test {i}: ERROR - {e}")
        
        # Cleanup
        if os.path.exists(executable):
            os.remove(executable)
        
        # Summary
        print(f"\n📊 Results: {passed}/{total} tests passed")
        
        if passed == total:
            print("🎉 All tests passed!")
            return True
        else:
            print("😞 Some tests failed!")
            return False
    
    def generate_test_template(self, problem_name, output_file):
        """Generate a template JSON file for new test cases"""
        template = {
            "problem": problem_name,
            "difficulty": "Easy|Medium|Hard",
            "source": "Source (e.g., LeetCode 123, CSES, etc.)",
            "description": "Brief description of the problem",
            "test_cases": [
                {
                    "name": "Example 1",
                    "input": "Input for test case 1",
                    "expected_output": "Expected output for test case 1",
                    "explanation": "Why this output is expected"
                },
                {
                    "name": "Edge case",
                    "input": "Edge case input",
                    "expected_output": "Edge case output",
                    "explanation": "Explanation for edge case"
                }
            ],
            "hints": [
                "Hint 1 for solving the problem",
                "Hint 2 for solving the problem"
            ],
            "time_complexity": "O(?)",
            "space_complexity": "O(?)"
        }
        
        with open(output_file, 'w') as f:
            json.dump(template, f, indent=2)
        
        print(f"✅ Template created at {output_file}")
        print("📝 Edit the file to add your test cases!")

def main():
    parser = argparse.ArgumentParser(description="CPH Test Case Helper")
    parser.add_argument("--import", dest="import_file", help="Import JSON test cases to CPH")
    parser.add_argument("--export", dest="export_folder", help="Export CPH test cases to JSON")
    parser.add_argument("--test", nargs=2, metavar=("CPP_FILE", "TEST_FILE"), 
                       help="Test C++ file with JSON test cases")
    parser.add_argument("--template", nargs=2, metavar=("PROBLEM_NAME", "OUTPUT_FILE"),
                       help="Generate test case template")
    parser.add_argument("--list", action="store_true", help="List available test case files")
    
    args = parser.parse_args()
    helper = CPHTestHelper()
    
    if args.import_file:
        helper.import_to_cph(args.import_file)
    
    elif args.export_folder:
        helper.export_from_cph(args.export_folder)
    
    elif args.test:
        cpp_file, test_file = args.test
        helper.test_cpp_with_cases(cpp_file, test_file)
    
    elif args.template:
        problem_name, output_file = args.template
        helper.generate_test_template(problem_name, output_file)
    
    elif args.list:
        print("📋 Available test case files:")
        if helper.test_cases_folder.exists():
            for json_file in helper.test_cases_folder.rglob("*.json"):
                rel_path = json_file.relative_to(helper.test_cases_folder)
                print(f"  📄 {rel_path}")
        else:
            print("  No test case files found. Create some using --template!")
    
    else:
        print("🐍 CPH Test Case Helper")
        print("\nUsage examples:")
        print("  python cph_helper.py --import test_cases/graph/island_perimeter.json")
        print("  python cph_helper.py --test \"Homework 1/Graph/1.cpp\" test_cases/graph/island_perimeter.json")
        print("  python cph_helper.py --export .vscode/.cph/")
        print("  python cph_helper.py --template \"New Problem\" test_cases/new_problem.json")
        print("  python cph_helper.py --list")
        print("\n💡 This tool helps you manage and share CPH test cases easily!")

if __name__ == "__main__":
    main()
