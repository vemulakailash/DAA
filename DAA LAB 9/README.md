# Time and Space Complexity 

## 1. Fractional Knapsack with Deterioration Rate

**Time Complexity:** O(n²)

Process: Finding the best item takes O(n). Repeating for n items gives n × O(n) = O(n²).

**Space Complexity:** O(n)

Process: Storing n items requires O(n) space.

## 2. Huffman Coding

**Time Complexity:** O(n²)

Process: Finding the two minimum-frequency nodes takes O(n) per merge. For n merges, the complexity is n × O(n) = O(n²). Sorting the canonical codebook also takes O(n²).

**Space Complexity:** O(n²)

Process: The tree arrays and fixed-size code buffers require O(n²) space.

## 3. Minimum Initial Fuel

**Time Complexity:** O(n²)

Process: Each refuelling step scans n stations. For at most n steps, the complexity is n × O(n) = O(n²).

**Space Complexity:** O(n)

Process: Storing station distances, fuel amounts and visited flags requires O(n) space.

## 4. Minimum Cost to Connect Sticks

**Time Complexity:** O(n³)

Process: Bubble sort takes O(n²) per iteration. Repeating for n iterations gives n × O(n²) = O(n³).

**Space Complexity:** O(n)

Process: The stick lengths are stored in an array of size n.

## 5. Candy Distribution Problem

**Time Complexity:** O(n)

Process: The left-to-right pass takes O(n), the right-to-left pass takes O(n), and calculating the total takes O(n). Overall complexity is O(n).

**Space Complexity:** O(n)

Process: Two arrays store the ratings and candy counts.

## 6. Reorganise String with K-Distance Apart

**Time Complexity:** O(n)

Process: Each of the n positions scans 256 possible characters. Therefore, O(256n) = O(n), since the character set is fixed.

**Space Complexity:** O(n)

Process: The output string requires O(n) space, while the frequency and waiting arrays have fixed size.

## 7. Minimise Deviation in Array

**Time Complexity:** O(n log M)

Process: Finding the minimum and maximum takes O(n) per iteration. The maximum is halved at most O(log M) times. Therefore, the total complexity is O(n log M).

**Space Complexity:** O(n)

Process: The array stores n elements.

Here, M is the maximum value after doubling the odd elements.

## 8. Minimum Number of Meeting Rooms

**Time Complexity:** O(n²)

Process: Bubble sorting the start and end arrays takes O(n²). The two-pointer traversal takes O(n). Overall complexity is O(n²).

**Space Complexity:** O(n)

Process: Two arrays store the start and end times of n meetings.

## 9. Hu-Tucker Greedy Simulation

**Time Complexity:** O(n³)

Process: There are O(n²) intervals, and each interval checks up to n possible splits. Therefore, O(n² × n) = O(n³).

**Space Complexity:** O(n²)

Process: The cost, sum and split tables require O(n²) space.

Note: This complexity applies to the interval dynamic programming implementation.

## 10. Greedy Superstring Conjecture

**Time Complexity:** O(n³M²)

Process: Each iteration checks O(n²) pairs. Each overlap calculation takes O(M²), and there are at most n iterations. Therefore, the total complexity is O(n × n² × M²) = O(n³M²).

**Space Complexity:** O(nM)

Process: Storing n strings of maximum length M requires O(nM) space.

Here, n is the number of strings and M is the maximum string length.