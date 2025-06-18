# DSA-1 Lab Topics

![DSA Image](https://media.geeksforgeeks.org/wp-content/uploads/20240213174747/dsa-new.webp) <!-- Replace with an actual image URL -->

Welcome to the DSA-1 Lab! This repository contains various topics and problem sets related to Data Structures and Algorithms. 🚀

## Problem Set

📚You can find a comprehensive list of problems to practice [here](https://cses.fi/problemset/list/).

- [Problem set Leetcode](https://docs.google.com/document/d/1gJ9FZStrHmfAKOSjJLL_Yz-Z4EUr8TjnWf57TKTbO40/edit?tab=t.0)

## Table of Contents

- [Introduction](#introduction)
- [Repository Structure](#repository-structure)
- [Sorting Algorithms](#sorting-algorithms)
- [Search Algorithms](#search-algorithms)
- [Data Structures](#data-structures)
- [How to Use](#how-to-use)
- [Testing with CPH Extension](#testing-with-cph-extension)
- [Using Python to Check Code](#using-python-to-check-code)
- [Sharing Test Cases](#sharing-test-cases)
- [Contributing](#contributing)

## Introduction

This lab is designed to help you understand and implement fundamental data structures and algorithms. 💡

## Repository Structure

```text
DSA-1/
├── Homework 1/          # Assignment problems and solutions
│   ├── Binary Search/   # Binary search implementations
│   ├── Graph/          # Graph algorithm solutions (Island Perimeter, etc.)
│   ├── Linear Search/  # Linear search implementations
│   ├── Linked list/    # Linked list operations
│   ├── Queue/          # Queue implementations
│   ├── Sorting/        # Various sorting algorithms
│   └── stack/          # Stack implementations
├── cses web/           # CSES problem solutions
├── Graph/              # Graph algorithms and implementations
├── linked list/        # Advanced linked list operations
├── Queue/              # Queue data structure implementations
├── sorting/            # Sorting algorithm implementations
└── stack/              # Stack data structure implementations
```

## Sorting Algorithms

- **Bubble Sort** - Simple comparison-based sorting
- **Quick Sort** - Efficient divide-and-conquer sorting
- **Merge Sort** - Stable divide-and-conquer sorting
- **Insertion Sort** - Simple insertion-based sorting
- **Selection Sort** - Simple selection-based sorting

## Search Algorithms

- **Linear Search** - Sequential search through elements
- **Binary Search** - Efficient search in sorted arrays

## Data Structures

- **Arrays** - Basic linear data structure
- **Linked Lists** - Dynamic linear data structure
  - Single Linked List
  - Double Linked List
- **Stacks** - LIFO (Last In, First Out) data structure
- **Queues** - FIFO (First In, First Out) data structure
  - Simple Queue
  - Circular Queue
  - Priority Queue
- **Graphs** - Non-linear data structure for representing relationships
  - Graph traversal (DFS, BFS)
  - Graph problems (Island Perimeter, Connected Components)

## How to Use

### For C++ Files

1. **Clone the repository** 🖥️

   ```bash
   git clone <repository-url>
   cd DSA-1
   ```

2. **Navigate to the desired topic folder** 📂

   ```bash
   cd "Homework 1/Binary Search"
   ```

3. **Compile the C++ code** �️

   ```bash
   g++ -o program_name source_file.cpp
   ```

4. **Run the executable**

   ```bash
   ./program_name        # On Linux/Mac
   program_name.exe      # On Windows
   ```

### For Java Files

1. **Compile Java files**

   ```bash
   javac filename.java
   ```

2. **Run Java programs**

   ```bash
   java filename
   ```

## Testing with CPH Extension

The **Competitive Programming Helper (CPH)** extension for VS Code is an excellent tool for testing your solutions with custom test cases.

### Installing CPH Extension

1. Open VS Code
2. Go to Extensions (Ctrl+Shift+X)
3. Search for "Competitive Programming Helper"
4. Install the extension by DivyanshuAgrawal

### Using CPH for Testing

1. **Open a C++ file** in VS Code
2. **Press Ctrl+Alt+B** to open CPH test case manager
3. **Add test cases** using the "+" button
4. **Run tests** using Ctrl+Alt+R

### Example Test Cases for Graph Problem (Island Perimeter)

For the file `Homework 1/Graph/1.cpp`, here are sample test cases:

**Test Case 1:**

```text
Input:
4 4
0 1 0 0
1 1 1 0
0 1 0 0
1 1 0 0

Expected Output:
16
```

**Test Case 2:**

```text
Input:
1 1
1

Expected Output:
4
```

**Test Case 3:**

```text
Input:
1 2
1 0

Expected Output:
4
```

### CPH Configuration

Create a `.vscode/settings.json` file in your workspace:

```json
{
    "cph.general.defaultLanguage": "cpp",
    "cph.general.timeLimit": 2000,
    "cph.general.memoryLimit": 256,
    "cph.language.cpp.Args": "-std=c++17 -O2",
    "cph.language.cpp.SubmissionCompiler": "g++17"
}
```

## Using Python to Check Code

Python can be used as a powerful tool to verify, test, and analyze the C++ implementations in this repository.

### 1. Basic Testing Script

Create a `test_helper.py` file:

```python
import subprocess
import os

def test_cpp_solution(cpp_file, test_cases):
    """
    Test a C++ solution with multiple test cases
    
    Args:
        cpp_file: Path to the C++ file
        test_cases: List of dictionaries with 'input' and 'expected' keys
    """
    
    # Compile the program
    executable = "test_program"
    if os.name == 'nt':  # Windows
        executable += ".exe"
    
    compile_result = subprocess.run(
        ["g++", "-o", executable, cpp_file],
        capture_output=True, text=True
    )
    
    if compile_result.returncode != 0:
        print(f"❌ Compilation failed: {compile_result.stderr}")
        return False
    
    print(f"✅ Testing {cpp_file}")
    all_passed = True
    
    # Run test cases
    for i, test_case in enumerate(test_cases, 1):
        try:
            run_command = [f"./{executable}"] if os.name != 'nt' else [executable]
            result = subprocess.run(
                run_command,
                input=test_case['input'],
                capture_output=True,
                text=True,
                timeout=5
            )
            
            actual_output = result.stdout.strip()
            expected_output = test_case['expected'].strip()
            
            if actual_output == expected_output:
                print(f"  ✅ Test {i}: PASSED")
            else:
                print(f"  ❌ Test {i}: FAILED")
                print(f"     Expected: {expected_output}")
                print(f"     Got:      {actual_output}")
                all_passed = False
                
        except subprocess.TimeoutExpired:
            print(f"  ❌ Test {i}: TIMEOUT")
            all_passed = False
    
    # Cleanup
    if os.path.exists(executable):
        os.remove(executable)
    
    return all_passed

# Example usage for Island Perimeter problem
if __name__ == "__main__":
    test_cases = [
        {
            'input': '4 4\n0 1 0 0\n1 1 1 0\n0 1 0 0\n1 1 0 0',
            'expected': '16'
        },
        {
            'input': '1 1\n1',
            'expected': '4'
        },
        {
            'input': '1 2\n1 0',
            'expected': '4'
        }
    ]
    
    test_cpp_solution("Homework 1/Graph/1.cpp", test_cases)
```

### 2. Performance Analysis

```python
import time
import matplotlib.pyplot as plt

def measure_performance(cpp_file, input_generator, sizes):
    """
    Measure execution time for different input sizes
    """
    times = []
    
    for size in sizes:
        test_input = input_generator(size)
        
        start_time = time.time()
        # Run the program with generated input
        # ... (compilation and execution code)
        end_time = time.time()
        
        times.append(end_time - start_time)
    
    # Plot results
    plt.figure(figsize=(10, 6))
    plt.plot(sizes, times, marker='o')
    plt.xlabel('Input Size')
    plt.ylabel('Execution Time (seconds)')
    plt.title(f'Performance Analysis: {cpp_file}')
    plt.grid(True)
    plt.show()
    
    return times
```

## Sharing Test Cases

### 1. CPH Test Case Files

CPH stores test cases in `.prob` files. You can share these files with your team:

**Location:** `.vscode/.cph/` folder

**Example `.prob` file structure:**
```json
{
    "name": "Island Perimeter",
    "group": "Graph Problems",
    "url": "https://leetcode.com/problems/island-perimeter/",
    "interactive": false,
    "timeLimit": 2000,
    "tests": [
        {
            "input": "4 4\n0 1 0 0\n1 1 1 0\n0 1 0 0\n1 1 0 0\n",
            "output": "16\n"
        },
        {
            "input": "1 1\n1\n",
            "output": "4\n"
        }
    ]
}
```

### 2. Creating a Test Cases Repository

Create a `test_cases/` folder structure:

```text
test_cases/
├── graph/
│   ├── island_perimeter.json
│   └── connected_components.json
├── sorting/
│   ├── bubble_sort.json
│   └── quick_sort.json
└── search/
    ├── binary_search.json
    └── linear_search.json
```

**Example test case file (`test_cases/graph/island_perimeter.json`):**
```json
{
    "problem": "Island Perimeter",
    "difficulty": "Easy",
    "source": "LeetCode 463",
    "test_cases": [
        {
            "name": "Example 1",
            "input": "4 4\n0 1 0 0\n1 1 1 0\n0 1 0 0\n1 1 0 0",
            "expected_output": "16",
            "explanation": "The perimeter is 16"
        },
        {
            "name": "Single island",
            "input": "1 1\n1",
            "expected_output": "4",
            "explanation": "Single cell has perimeter 4"
        }
    ]
}
```

### 3. Automated Test Case Sharing

Create a script to import/export CPH test cases:

```python
import json
import os
from pathlib import Path

def export_cph_test_cases(cph_folder, output_folder):
    """
    Export CPH test cases to shareable JSON format
    """
    cph_path = Path(cph_folder)
    output_path = Path(output_folder)
    output_path.mkdir(exist_ok=True)
    
    for prob_file in cph_path.glob("*.prob"):
        with open(prob_file, 'r') as f:
            cph_data = json.load(f)
        
        # Convert to shareable format
        shared_format = {
            "problem": cph_data.get("name", "Unknown"),
            "source": cph_data.get("url", ""),
            "test_cases": []
        }
        
        for i, test in enumerate(cph_data.get("tests", [])):
            shared_format["test_cases"].append({
                "name": f"Test {i+1}",
                "input": test.get("input", ""),
                "expected_output": test.get("output", "")
            })
        
        # Save to output folder
        output_file = output_path / f"{prob_file.stem}.json"
        with open(output_file, 'w') as f:
            json.dump(shared_format, f, indent=2)
        
        print(f"Exported: {output_file}")

# Usage
export_cph_test_cases(".vscode/.cph", "shared_test_cases")
```

### 4. Team Collaboration

**For sharing with teammates:**

1. **Git integration:** Add test case files to your repository
2. **CPH sync:** Share the `.vscode/.cph/` folder
3. **Documentation:** Include test case explanations in comments

**Example workflow:**
```bash
# Add test cases to git
git add test_cases/
git add .vscode/.cph/
git commit -m "Add test cases for Island Perimeter problem"
git push

# Teammates can pull and use
git pull
# Test cases are now available in CPH and as JSON files
```

## Contributing

### Code Style Guidelines

- Use meaningful variable names
- Add comments explaining complex logic
- Follow consistent indentation (4 spaces)
- Include time and space complexity analysis

### Adding Test Cases

1. Create test cases in CPH while solving
2. Export test cases to JSON format
3. Add edge cases and corner cases
4. Document expected behavior
5. Share via git repository

### Testing Checklist

- [ ] Basic functionality test
- [ ] Edge cases (empty input, single element)
- [ ] Large input test
- [ ] Invalid input handling
- [ ] Performance verification

Happy coding! 🎉
