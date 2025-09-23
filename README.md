# Sorting Algorithms Implementation

A comprehensive C++ implementation of various sorting algorithms with performance measurement capabilities and configurable strategies.

## Overview

This project provides a collection of sorting algorithms implemented in C++ with a unified interface. Each algorithm is implemented as a class that inherits from a base `Sort` class, allowing for easy comparison and benchmarking. The implementation includes both basic and optimized versions of several algorithms, along with configurable strategies for algorithms like Shell Sort and Quick Sort.

## Features

- **Unified Interface**: All sorting algorithms inherit from a common base class with consistent API
- **Performance Measurement**: Built-in timing functionality to measure sorting performance
- **Strategy Pattern**: Configurable gap strategies for Shell Sort and pivot strategies for Quick Sort
- **Template-based**: Generic implementation supporting any comparable data type
- **Custom Comparators**: Support for custom comparison functions

## Implemented Algorithms

### Basic Sorting Algorithms
- **Selection Sort** - Simple selection sort with O(n²) time complexity
- **Optimized Selection Sort** - Improved version that reduces unnecessary swaps
- **Bubble Sort** - Classic bubble sort implementation
- **Optimized Bubble Sort** - Enhanced version with early termination
- **Insertion Sort** - Efficient for small datasets, stable sorting algorithm

### Advanced Sorting Algorithms
- **Merge Sort** - Divide-and-conquer algorithm with O(n log n) time complexity
- **Quick Sort** - Fast average-case O(n log n) sorting with configurable pivot strategies
- **Shell Sort** - Gap-based insertion sort with configurable gap sequences
- **Heap Sort** - Heap-based sorting algorithm with guaranteed O(n log n) performance
- **Counting Sort** - Linear time sorting for integers within a specific range

### Special Algorithms
- **STL Sort** - Wrapper around the standard library sort function
- **Bogo Sort** - Randomized sorting algorithm (for educational purposes only)

## Strategy Patterns

### Gap Strategies (Shell Sort)
The Shell Sort implementation uses the Strategy pattern to allow different gap sequences:
- **Knuth Gap Strategy** - Uses the sequence (3^k - 1) / 2

### Pivot Strategies (Quick Sort)
Quick Sort supports different pivot selection strategies:
- **Middle Pivot Strategy** - Selects the middle element as pivot

## Usage Example

```cpp
#include "sort.hpp"

int main() {
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    
    // Create a sorting algorithm instance
    auto sorter = make_shared<QuickSort<int>>();
    
    // Sort the data
    sorter->sort(data);
    
    // Display performance information
    cout << *sorter << endl;
    
    return 0;
}
```

## Project Structure

```
src/
├── main.cpp                    # Example usage and testing
├── sort.hpp                    # Main header with all sorting algorithms
├── gap-strategy/
│   ├── gap_strategy.hpp        # Gap strategy interface
│   ├── knuth_gap_strategy.hpp  # Knuth gap sequence implementation
│   └── knuth_gap_strategy.cpp
└── pivot-strategy/
    ├── pivot_strategy.hpp      # Pivot strategy interface
    └── middle_pivot_strategy.hpp # Middle pivot implementation
```

## Building and Running

This is a Visual Studio C++ project. To build and run:

1. Open `sorting-algorithms.sln` in Visual Studio
2. Build the solution (Ctrl+Shift+B)
3. Run the project (F5 or Ctrl+F5)

The main program demonstrates the usage by:
- Creating a vector of 100,000 integers
- Shuffling them randomly
- Sorting using Shell Sort with Knuth gap strategy
- Displaying performance metrics

## Performance Features

Each sorting algorithm automatically measures:
- **Execution Time**: Time taken to sort the array
- **Array Size**: Number of elements sorted
- **Algorithm Name**: Identification of the sorting method used

## Extensibility

The project is designed for easy extension:
- Add new sorting algorithms by inheriting from the `Sort<T>` base class
- Implement new gap strategies for Shell Sort by inheriting from `GapStrategy`
- Create new pivot strategies for Quick Sort by inheriting from `PivotStrategy<T>`

## Educational Value

This implementation serves as an excellent resource for:
- Understanding different sorting algorithm approaches
- Comparing algorithm performance characteristics
- Learning about design patterns (Strategy, Template Method)
- Studying C++ template programming and inheritance

## License

This project is available under the terms specified in the LICENSE file.
