# 1. Problem

Design and implement **Quick Sort** and compare its performance with **Merge Sort**.

**Tasks:**  
i) Use different pivot selection strategies for Quick Sort  
ii) Compare execution time for **sorted**, **reverse-sorted**, and **random** data  

---

# 2. Algorithm (Pseudocode)

## A. Quick Sort

**Algorithm `QuickSort(A, low, high)`**

**Input:** Array `A`, indices `low` and `high`  
**Output:** Sorted array  

```
Step 1: if low < high
            pi = Partition(A, low, high)
            QuickSort(A, low, pi - 1)
            QuickSort(A, pi + 1, high)
Step 2: End
```

**Partition Algorithm (Pivot = Last Element by default)**

```
Step 1: pivot = A[high]
Step 2: i = low - 1

Step 3: for j = low to high - 1
            if A[j] <= pivot
                i = i + 1
                swap A[i] and A[j]

Step 4: swap A[i + 1] and A[high]
Step 5: return i + 1
```

**Pivot Selection Strategies:**

* `First element` → swap A[low] with pivot
* `Middle element` → swap A[(low+high)/2] with pivot
* `Last element` → default, no swap

---

# 3. A Priori Analysis

### Quick Sort

* Average case comparisons ≈ `O(n log n)`
* Worst case comparisons ≈ `O(n^2)` (occurs for already sorted or reverse-sorted arrays with poor pivot choice)
* Space complexity = `O(log n)` (recursion stack)

### Merge Sort

* Comparisons ≈ `O(n log n)` for all cases
* Space complexity = `O(n)` (temporary arrays)
* Performance is stable, independent of initial array order

**Pivot strategy** in Quick Sort affects performance significantly:

* First or last element → poor performance on sorted/reverse data
* Middle element → better balance

---

# 4. Posterior Analysis

Observed execution behavior for arrays of size `n`:

* **Random Data:**

  * Quick Sort and Merge Sort perform similarly
* **Sorted Data:**

  * Quick Sort slower if pivot = first/last element
  * Merge Sort unaffected
* **Reverse-Sorted Data:**

  * Quick Sort slower if pivot = first/last element
  * Merge Sort stable

Execution time comparison grows roughly proportional to `n log n` for Merge Sort and average-case Quick Sort.

---

| Algorithm  | Time Best  | Time Worst | Time Avg   | Space Best | Space Worst | Space Avg |
| ---------- | ---------- | ---------- | ---------- | ---------- | ----------- | --------- |
| Quick Sort | O(n log n) | O(n²)      | O(n log n) | O(log n)   | O(n)        | O(log n)  |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n)       | O(n)        | O(n)      |


| Algorithm  | Reason Best                                                                 | Reason Worst                                                       | Reason Avg                                    | Reason Space Best                                 | Reason Space Worst                                                     | Reason Space Avg                                                        |
| ---------- | --------------------------------------------------------------------------- | ------------------------------------------------------------------ | --------------------------------------------- | ------------------------------------------------- | ---------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| Quick Sort | Pivot splits array evenly → log n recursion levels, n comparisons per level | Pivot splits unevenly → recursion depth n, n comparisons per level | Random pivot gives balanced splits on average | Recursion stack depth ≈ log n for balanced splits | Recursion stack depth ≈ n in worst-case (completely unbalanced splits) | Average recursion depth ≈ log n → extra space proportional to recursion |
| Merge Sort | Always divides array evenly → log n levels, merging n elements each level   | Same as best, divisions and merges always occur                    | Same as best                                  | Extra arrays needed for merging each subarray     | Extra arrays needed at every merge, total ≤ n                          | Extra arrays + recursion stack ≤ n total                                |
