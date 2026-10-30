# 1D Array Operations

## Time and Space Complexity

1. Maximum Element
   Time Complexity: O(n)
   Space Complexity: O(1)

2. First and Second Largest Elements
   Time Complexity: O(n)
   Space Complexity: O(1)

3. Mean
   Time Complexity: O(n)
   Space Complexity: O(1)

4. Median
   Time Complexity: O(n log n)
   Space Complexity: O(n)

5. Standard Deviation
   Time Complexity: O(n)
   Space Complexity: O(1)

6. Mode
   Time Complexity: O(n²)
   Space Complexity: O(1)

7. Removing Duplicates
   Time Complexity: O(n²)
   Space Complexity: O(n)

8. Reversing the Array
   Time Complexity: O(n)
   Space Complexity: O(n)

9. Partitioning Using Pivot
   Time Complexity: O(n)
   Space Complexity: O(n)

# Procedure

1. Check the number of loops in the program.
2. One loop running n times gives O(n).
3. Two nested loops give O(n²).
4. Sorting gives O(n log n) when an efficient sorting algorithm is used.
5. Fixed variables use O(1) space.
6. An extra array of size n uses O(n) space.

# 2D Square Matrix Operations

## Time and Space Complexity

1. Matrix Addition
   Time Complexity: O(n²)
   Space Complexity: O(n²)

2. Matrix Multiplication
   Time Complexity: O(n³)
   Space Complexity: O(n²)

3. Checking Zero Matrix
   Time Complexity: O(n²)
   Space Complexity: O(1)

4. Checking Symmetric Matrix
   Time Complexity: O(n²)
   Space Complexity: O(1)

5. Finding Determinant
   Time Complexity: O(n³)
   Space Complexity: O(n²)

6. Transposing Matrix In Place
   Time Complexity: O(n²)
   Space Complexity: O(1)

7. Finding Eigenvalue and Eigenvector
   Time Complexity: O(n³)
   Space Complexity: O(n)

# Procedure

1. Check the loops used in each operation.
2. Two nested loops running n times give O(n²).
3. Three nested loops running n times give O(n³).
4. A fixed number of variables uses O(1) space.
5. An additional matrix of size n × n uses O(n²) space.
6. An additional array of size n uses O(n) space.

# 4. Sorting via Reversal Procedure

## Time and Cost Complexity

The permutation is sorted using only the reverse operation.

Number of Reversals: O(n)

The cost of reversing elements from index i to j is:

Cost = |j-i|+1

The algorithm uses divide and conquer.

Cost of partitioning one level: O(n log n)

Number of recursive levels: O(log n)

Therefore, the total reversal cost is:

O(n log²n)

## Running Time

Running Time: O(n log²n)

## Space Complexity

Recursion Space: O(log n)

# Procedure

1. Divide the permutation into two groups using the middle value.
2. Use reversals to move smaller elements to the left and larger elements to the right.
3. Recursively repeat the process for both groups.
4. Continue until each group contains only one element.
5. The permutation becomes sorted in increasing order.

# Correctness

At every step, elements smaller than or equal to the middle value are moved to the left and larger elements are moved to the right.

The same process is recursively applied to both parts.

Therefore, after all recursive calls, all elements are arranged in increasing order.

Hence, the algorithm correctly sorts the permutation.

