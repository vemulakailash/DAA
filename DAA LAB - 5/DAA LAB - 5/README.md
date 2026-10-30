## 1. Median Without Sorting

The program finds the median of N numbers without sorting the array. It checks how many elements are smaller than each element and uses this position to determine the median.

Time Complexity: O(n²)
Space Complexity: O(n)

## 2. Kth Smallest Element Without Sorting

The program finds the Kth smallest element without sorting the array. For each element, it counts the number of elements smaller than it. If K-1 elements are smaller, that element is the Kth smallest.

Time Complexity: O(n²)
Space Complexity: O(n)

## 3. Quick Sort

The program sorts N elements using the Quick Sort algorithm. It selects a pivot and divides the array into smaller and larger elements. The same process is repeated recursively.

Best/Average Time Complexity: O(n log n)
Worst Time Complexity: O(n²)
Space Complexity: O(log n) average

## 4. Heap Sort

The program sorts N elements using the Heap Sort algorithm. It first creates a max heap and then repeatedly moves the largest element to the end of the array.

Time Complexity: O(n log n)
Space Complexity: O(1)