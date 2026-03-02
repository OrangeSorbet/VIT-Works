# 1. Problem

Design and implement an algorithm to perform **Merge Sort** using the **Divide and Conquer** technique.

**Tasks:**  
i) Recursive divide and merge steps  
ii) Trace recursion tree  
iii) Analyze time and space complexity  

---

# 2. Algorithm (Pseudocode)

## A. Recursive Merge Sort (Divide Step)

**Algorithm `MergeSort(A, left, right)`**

**Input:** Array `A`, starting index `left`, ending index `right`  
**Output:** Sorted array `A`  

```
Step 1: if left < right

Step 2:     mid = (left + right) / 2

Step 3:     MergeSort(A, left, mid)        // Divide left half

Step 4:     MergeSort(A, mid + 1, right)   // Divide right half

Step 5:     Merge(A, left, mid, right)     // Merge sorted halves

Step 6: End
```

---

## B. Merge Procedure (Conquer Step)

**Algorithm `Merge(A, left, mid, right)`**

**Input:** Array `A`, indices `left`, `mid`, `right`  
**Output:** Merged sorted subarray  

```
Step 1: n1 = mid - left + 1
Step 2: n2 = right - mid

Step 3: Create arrays L[0...n1-1] and R[0...n2-1]

Step 4: Copy elements from A into L and R

Step 5: i = 0, j = 0, k = left

Step 6: while i < n1 and j < n2
            if L[i] <= R[j]
                A[k] = L[i]
                i = i + 1
            else
                A[k] = R[j]
                j = j + 1
            k = k + 1

Step 7: Copy remaining elements of L (if any)

Step 8: Copy remaining elements of R (if any)

Step 9: End
```

---

# 3. Recursive Divide and Merge Explanation

### Divide Phase

* The array is recursively divided into two halves.
* Division continues until each subarray contains only one element.
* A single-element array is always sorted.

### Merge Phase

* Two sorted subarrays are merged into one sorted array.
* Merging is done by comparing elements of both subarrays.
* This process continues bottom-up until the entire array is sorted.

---

# 4. Recursion Tree

Example for array of 8 elements:

```
Level 0:                [0,7]
                       /       \
Level 1:          [0,3]         [4,7]
                 /     \       /     \
Level 2:      [0,1]   [2,3]  [4,5]   [6,7]
               / \      / \    / \      / \
Level 3:   [0] [1]  [2] [3] [4] [5]  [6] [7]
```

### Observations:

* Height of recursion tree = `log₂ n`
* Number of levels = `log₂ n`
* At each level, total merging work = `n`

---

# 5. A Priori Analysis

Merge Sort follows the recurrence relation:

```
T(n) = 2T(n/2) + n
```

Where:

* `2T(n/2)` → Two recursive calls
* `n` → Work done during merging

Using Master Theorem:

```
T(n) = O(n log n)
```

### Case Analysis

**Best Case:**  
Array already sorted → Still divides and merges  
Time Complexity = `O(n log n)`  

**Worst Case:**  
Array in reverse order → Same number of divisions and merges  
Time Complexity = `O(n log n)`  

**Average Case:**  
Random order input  
Time Complexity = `O(n log n)`  

Merge Sort performs the same number of operations regardless of input order.

---

# 6. Posterior Analysis

Observed execution behavior:

* Input size `1000` → Small execution time
* Input size `10000` → Time increases proportionally
* Input size `100000` → Time increases steadily

Execution time grows proportional to `n log n`.

Compared to quadratic algorithms like Bubble Sort (`O(n²)`), Merge Sort performs significantly better for large inputs.

---

# 7. Time Complexity

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | `O(n log n)`    |
| Worst Case   | `O(n log n)`    |
| Average Case | `O(n log n)`    |

---

# 8. Space Complexity

Merge Sort requires additional temporary arrays during merging.

* Extra space required = `O(n)`
* Recursion stack space = `O(log n)`

### Total Space Complexity:

```
O(n)
```

---

# Case Comparison Summary

**Best Case:**
Even if array is sorted, it divides completely → `O(n log n)`

**Worst Case:**
Array in reverse order → Same number of operations → `O(n log n)`

**Average Case:**
Random input → `O(n log n)`