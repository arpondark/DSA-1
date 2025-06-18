# CPH Test Helper PowerShell Script
# Enhanced testing and management for CPH test cases

param(
    [Parameter(Position=0)]
    [ValidateSet("test", "import", "export", "list", "template", "help")]
    [string]$Command = "help",
    
    [Parameter(Position=1)]
    [string]$File1,
    
    [Parameter(Position=2)]
    [string]$File2
)

function Show-Header {
    Write-Host ""
    Write-Host "==========================================" -ForegroundColor Cyan
    Write-Host "   CPH Test Case Helper - PowerShell" -ForegroundColor Cyan  
    Write-Host "==========================================" -ForegroundColor Cyan
    Write-Host ""
}

function Show-Help {
    Show-Header
    Write-Host "Available Commands:" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "  test <cpp_file> <test_file>     " -ForegroundColor Green -NoNewline
    Write-Host "- Test C++ file with JSON test cases"
    Write-Host "  import <json_file>              " -ForegroundColor Green -NoNewline  
    Write-Host "- Import JSON test cases to CPH"
    Write-Host "  export [cph_folder]             " -ForegroundColor Green -NoNewline
    Write-Host "- Export CPH test cases to JSON"
    Write-Host "  list                            " -ForegroundColor Green -NoNewline
    Write-Host "- List available test case files"
    Write-Host "  template <name> <output>        " -ForegroundColor Green -NoNewline
    Write-Host "- Create test case template"
    Write-Host ""
    Write-Host "Examples:" -ForegroundColor Yellow
    Write-Host "  .\test_helper.ps1 test 'Homework 1\Graph\1.cpp' 'test_cases\graph\island_perimeter.json'" -ForegroundColor Gray
    Write-Host "  .\test_helper.ps1 import 'test_cases\sorting\bubble_sort.json'" -ForegroundColor Gray
    Write-Host "  .\test_helper.ps1 list" -ForegroundColor Gray
    Write-Host ""
    Write-Host "Quick Test (Island Perimeter):" -ForegroundColor Yellow
    Write-Host "  .\test_helper.ps1 test 'Homework 1\Graph\1.cpp' 'test_cases\graph\island_perimeter.json'" -ForegroundColor Magenta
}

function Test-Prerequisites {
    # Check if Python is available
    try {
        $pythonVersion = python --version 2>&1
        Write-Host "✅ Python found: $pythonVersion" -ForegroundColor Green
    }
    catch {
        Write-Host "❌ Python not found! Please install Python 3.x" -ForegroundColor Red
        return $false
    }
    
    # Check if g++ is available
    try {
        $gccVersion = g++ --version 2>&1 | Select-Object -First 1
        Write-Host "✅ g++ compiler found: $gccVersion" -ForegroundColor Green
    }
    catch {
        Write-Host "❌ g++ compiler not found! Please install g++ or MinGW" -ForegroundColor Red
        return $false
    }
    
    # Check if cph_helper.py exists
    if (Test-Path "cph_helper.py") {
        Write-Host "✅ CPH helper script found" -ForegroundColor Green
    }
    else {
        Write-Host "❌ cph_helper.py not found in current directory!" -ForegroundColor Red
        return $false
    }
    
    return $true
}

function Invoke-PythonHelper {
    param([string[]]$Arguments)
    
    try {
        $result = python cph_helper.py @Arguments
        return $result
    }
    catch {
        Write-Host "❌ Error running Python helper: $_" -ForegroundColor Red
        return $false
    }
}

function Test-CppFile {
    param([string]$CppFile, [string]$TestFile)
    
    if (-not (Test-Path $CppFile)) {
        Write-Host "❌ C++ file not found: $CppFile" -ForegroundColor Red
        return
    }
    
    if (-not (Test-Path $TestFile)) {
        Write-Host "❌ Test case file not found: $TestFile" -ForegroundColor Red
        return
    }
    
    Write-Host "🚀 Testing $CppFile with $TestFile..." -ForegroundColor Blue
    Write-Host ""
    
    Invoke-PythonHelper @("--test", $CppFile, $TestFile)
}

function Import-TestCases {
    param([string]$JsonFile)
    
    if (-not (Test-Path $JsonFile)) {
        Write-Host "❌ JSON file not found: $JsonFile" -ForegroundColor Red
        return
    }
    
    Write-Host "📥 Importing test cases from $JsonFile..." -ForegroundColor Blue
    Invoke-PythonHelper @("--import", $JsonFile)
}

function Export-TestCases {
    param([string]$CphFolder = ".vscode\.cph")
    
    Write-Host "📤 Exporting test cases from $CphFolder..." -ForegroundColor Blue
    Invoke-PythonHelper @("--export", $CphFolder)
}

function Show-TestCases {
    Write-Host "📋 Available test case files:" -ForegroundColor Blue
    Invoke-PythonHelper @("--list")
}

function New-Template {
    param([string]$ProblemName, [string]$OutputFile)
    
    Write-Host "📝 Creating template for '$ProblemName'..." -ForegroundColor Blue
    Invoke-PythonHelper @("--template", $ProblemName, $OutputFile)
}

# Main script logic
Show-Header

if (-not (Test-Prerequisites)) {
    Write-Host ""
    Write-Host "Please fix the issues above and try again." -ForegroundColor Red
    exit 1
}

Write-Host ""

switch ($Command) {
    "test" {
        if (-not $File1 -or -not $File2) {
            Write-Host "❌ Please specify both C++ file and test case file" -ForegroundColor Red
            Write-Host "Usage: .\test_helper.ps1 test <cpp_file> <test_file>" -ForegroundColor Yellow
        }
        else {
            Test-CppFile -CppFile $File1 -TestFile $File2
        }
    }
    
    "import" {
        if (-not $File1) {
            Write-Host "❌ Please specify JSON test case file to import" -ForegroundColor Red
            Write-Host "Usage: .\test_helper.ps1 import <json_file>" -ForegroundColor Yellow
        }
        else {
            Import-TestCases -JsonFile $File1
        }
    }
    
    "export" {
        if ($File1) {
            Export-TestCases -CphFolder $File1
        }
        else {
            Export-TestCases
        }
    }
    
    "list" {
        Show-TestCases
    }
    
    "template" {
        if (-not $File1 -or -not $File2) {
            Write-Host "❌ Please specify problem name and output file" -ForegroundColor Red
            Write-Host "Usage: .\test_helper.ps1 template <problem_name> <output_file>" -ForegroundColor Yellow
        }
        else {
            New-Template -ProblemName $File1 -OutputFile $File2
        }
    }
    
    default {
        Show-Help
    }
}

Write-Host ""
