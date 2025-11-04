# Sorting Algorithm Benchmark

A C++ performance benchmarking tool for comparing different sorting algorithms with customizable dataset sizes.

## Overview

This project provides a comprehensive benchmarking suite to measure and compare the performance of various sorting algorithms. It generates random datasets and times how long each algorithm takes to sort the data, helping you understand the practical performance differences between different sorting approaches.

## Features

- **5 Sorting Algorithms Implemented:**
  - Bubble Sort
  - Insertion Sort
  - Selection Sort
  - Quick Sort
  - Merge Sort

- **Customizable Dataset Size:** Choose any number of elements to sort (default: 100,000)
- **Random Number Generation:** Creates truly random datasets for realistic benchmarking
- **High-Precision Timing:** Uses `std::chrono` for millisecond-accurate measurements
- **Automatic Result Logging:** Appends all benchmark results to `benchmark_results.txt` with timestamps
- **Optional Sorted Output:** Save the sorted array to verify correctness
- **User-Friendly Interface:** Interactive command-line menu system

## Project Structure

```
SortingTime/
│
├── sortingBenchmark.cpp      # Main benchmark program (recommended)
├── generate_input.cpp         # Standalone random number generator
├── sortOption.cpp             # Legacy sorting program
├── benchmark_results.txt      # Auto-generated benchmark results log
├── inputSomething.txt         # Sample input data file
└── README.md                  # This file
```

## Installation

### Prerequisites

- C++ compiler with C++11 support (GCC, Clang, MSVC, etc.)
- Windows, Linux, or macOS

### Compilation

**Windows (PowerShell/CMD):**
```powershell
g++ sortingBenchmark.cpp -o sortingBenchmark.exe
```

**Linux/macOS:**
```bash
g++ sortingBenchmark.cpp -o sortingBenchmark
```

## Usage

### Running the Benchmark

**Windows:**
```powershell
.\sortingBenchmark.exe
```

**Linux/macOS:**
```bash
./sortingBenchmark
```

### Interactive Steps

1. **Enter Dataset Size:**
   - Type a number (e.g., `50000`, `1000000`)
   - Or press Enter to use the default (100,000 elements)

2. **Choose Sorting Algorithm:**
   ```
   1. Bubble Sort
   2. Insertion Sort
   3. Selection Sort
   4. Quick Sort
   5. Merge Sort
   ```

3. **View Results:**
   - See real-time execution time in milliseconds
   - Results automatically saved to `benchmark_results.txt`

4. **Optional: Save Sorted Output:**
   - Choose `y` to save the sorted array to a file
   - Choose `n` to skip

### Example Session

```
=====================================
   SORTING ALGORITHM BENCHMARK
=====================================

Enter number of random numbers to generate
(Press Enter for default: 100000): 50000

Generating 50000 random numbers...
Random numbers generated successfully!

=====================================
Choose a sorting algorithm:
=====================================
1. Bubble Sort
2. Insertion Sort
3. Selection Sort
4. Quick Sort
5. Merge Sort

Enter your choice (1-5): 4

Running Quick Sort...

=====================================
BENCHMARK RESULTS
=====================================
Algorithm: Quick Sort
Numbers sorted: 50000
Time taken: 15 ms
=====================================

Results saved to benchmark_results.txt
```

## Algorithm Comparison

### Time Complexity

| Algorithm      | Best Case | Average Case | Worst Case | Space Complexity |
|----------------|-----------|--------------|------------|------------------|
| Bubble Sort    | O(n)      | O(n²)        | O(n²)      | O(1)             |
| Insertion Sort | O(n)      | O(n²)        | O(n²)      | O(1)             |
| Selection Sort | O(n²)     | O(n²)        | O(n²)      | O(1)             |
| Quick Sort     | O(n log n)| O(n log n)   | O(n²)      | O(log n)         |
| Merge Sort     | O(n log n)| O(n log n)   | O(n log n) | O(n)             |

### Performance Recommendations

**For Small Datasets (< 1,000 elements):**
- Insertion Sort often performs well due to low overhead

**For Medium Datasets (1,000 - 100,000 elements):**
- Quick Sort typically fastest in practice
- Merge Sort for consistent performance

**For Large Datasets (> 100,000 elements):**
- Quick Sort (best average case)
- Merge Sort (guaranteed O(n log n))
- **Avoid:** Bubble Sort, Insertion Sort, Selection Sort (too slow)

## Benchmark Results Format

The `benchmark_results.txt` file logs all benchmark runs with the following format:

```
=====================================
Date/Time: Tue Nov 04 15:30:45 2025
Algorithm: Quick Sort
Numbers sorted: 100000
Time taken: 25 ms
=====================================
```

## Additional Tools

### generate_input.cpp

Standalone utility to generate random numbers and save them to a file.

**Compile:**
```powershell
g++ generate_input.cpp -o generate_input.exe
```

**Run:**
```powershell
.\generate_input.exe
```

### sortOption.cpp

Legacy program that reads from `inputSomething2.txt` and performs sorting with separate output files for each algorithm.

## Technical Details

### Random Number Generation
- Uses `std::rand()` with `std::srand(time(nullptr))` for seeding
- Generates integers across the full range of `rand()`

### Timing Mechanism
- Uses `std::chrono::high_resolution_clock` for precise timing
- Measures only the sorting operation (excludes array generation and I/O)

### Memory Management
- Dynamic memory allocation for arrays
- Proper cleanup with `delete[]` to prevent memory leaks

## Contributing

Feel free to contribute by:
- Adding new sorting algorithms (Heap Sort, Shell Sort, etc.)
- Optimizing existing implementations
- Improving the user interface
- Adding statistical analysis features

## Known Limitations

- **Large Datasets:** Bubble Sort, Insertion Sort, and Selection Sort are impractical for datasets > 50,000 elements
- **Stack Overflow:** Quick Sort may cause stack overflow on very large datasets (> 1,000,000) with poor pivot selection
- **Memory:** Large datasets require sufficient RAM (approximately 4 bytes per element)

## Tips for Accurate Benchmarking

1. **Close Other Applications:** Minimize background processes
2. **Run Multiple Tests:** Execute each algorithm several times and average results
3. **Consistent Dataset Size:** Use the same size for fair comparisons
4. **Consider System Variations:** Results vary by CPU, RAM, and system load
5. **Use Larger Datasets:** Small datasets (< 10,000) may not show clear performance differences

## License

This project is open source and available for educational and personal use.

## Author

Created as a performance benchmarking tool for studying and comparing sorting algorithm efficiency.

---

**Happy Benchmarking! 🚀**
