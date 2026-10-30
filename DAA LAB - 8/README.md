# Question 1: Minimum Coin Change

## Time Complexity

The outer loop runs V times.
The inner loop runs n times for each value of V.
Since the loops are nested:
V × n = nV
Time Complexity = O(nV)

## Space Complexity

The dp array stores values from 0 to V.
Space Complexity = O(V)

# Question 2: Coin Change - Total Number of Ways
## Time Complexity
Outer loop runs n times.
Inner loop runs V times in the worst case.
n × V = nV
Time Complexity = O(nV)

## Space Complexity
dp array size = V+1.
Space Complexity = O(V)

# Question 3: Longest Common Subsequence (LCS)
## Time Complexity
The outer loop runs m times.
The inner loop runs n times.
m × n = mn
Time Complexity = O(mn)

## Space Complexity
The dp array is of size (m+1) × (n+1).
Space Complexity = O(mn)

# Question 4: Longest Increasing Subsequence
## Time Complexity
Outer loop runs n times.
Inner loop runs up to n times.
n × n = n²
Time Complexity = O(n²)

## Space Complexity
dp array size = n.
Space Complexity = O(n)

# Question 5: Maximum Sum Increasing Subsequence
## Time Complexity
Outer loop runs n times.
Inner loop runs up to n times.
n × n = n²
Time Complexity = O(n²)

## Space Complexity
dp array size = n.
Space Complexity = O(n)

# Question 6: Edit Distance with Traceback Information
## Time Complexity
Outer loop runs m times.
Inner loop runs n times.
m × n = mn
Time Complexity = O(mn)

## Space Complexity
The dp array is of size (m+1) × (n+1).
Space Complexity = O(mn)

# Question 7: Rod Cutting with Reconstruction
## Time Complexity
Outer loop runs n times.
Inner loop runs up to n times.
n × n = n²
Time Complexity = O(n²)

## Space Complexity
dp and cut arrays have size n.
Space Complexity = O(n)

# Question 8: Optimal Binary Search Tree (OBST)
## Time Complexity
The length loop runs n times.
The i loop runs up to n times.
The root loop runs up to n times.
n × n × n = n³
Time Complexity = O(n³)

## Space Complexity
The cost and weight tables are of size n × n.
Space Complexity = O(n²)

# Question 9: Collatz Conjecture
## Time Complexity
The program checks every number from a to b.
For each number, the Collatz sequence is generated until it reaches 1.
The number of steps depends on the starting value.
There is no known fixed polynomial time complexity for the Collatz sequence.

## Space Complexity
Only a few variables are used.
Space Complexity = O(1)