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

### Testing Checklist

- [x] Basic functionality test
- [x] Edge cases (empty input, single element)
- [x] Large input test
- [x] Invalid input handling
- [x] Performance verification

Happy coding! 🎉
