# 1. Problem

Design and implement an algorithm to perform **Binary Search** on a sorted array.

**Tasks:**  
i) Recursive and iterative implementations  
ii) Count number of comparisons  
iii) Compare best, worst, and average cases  

---

# 2. Algorithm (Pseudocode)

## A. Iterative Binary Search

**Algorithm `BinarySearchIterative(A, n, target)`**  

**Input:** Sorted array `A` of size `n`, element `target`  
**Output:** Index of target or `-1` if not found  

```
Step 1: left = 0
Step 2: right = n - 1

Step 3: while left <= right
            mid = left + (right - left) / 2

            if A[mid] == target
                return mid

            if A[mid] < target
                left = mid + 1
            else
                right = mid - 1

Step 4: return -1
Step 5: End
```

---

## B. Recursive Binary Search

**Algorithm `BinarySearchRecursive(A, left, right, target)`**  

**Input:** Sorted array `A`, indices `left`, `right`, element `target`  
**Output:** Index of target or `-1` if not found  

```
Step 1: if left > right
            return -1

Step 2: mid = left + (right - left) / 2

Step 3: if A[mid] == target
            return mid

Step 4: if A[mid] < target
            return BinarySearchRecursive(A, mid + 1, right, target)
        else
            return BinarySearchRecursive(A, left, mid - 1, target)

Step 5: End
```

---

# 3. A Priori Analysis

Binary Search divides the search space into half at every step.

For each iteration/recursive call:

* One comparison for `A[mid] == target`
* One comparison for `A[mid] < target`

Maximum comparisons per level = `2`

Number of levels = `log₂ n`

* Worst case comparisons ≈ `2 log₂ n`
* Best case comparisons = `1`
* Average case ≈ `log₂ n`

Number of operations increases logarithmically with `n`.

---

# 4. Posterior Analysis

Observed execution behavior:

* Input size `1000` → Execution time very small
* Input size `10000` → Slight increase in execution time
* Input size `100000` → Execution time increases slowly

Comparison count grows approximately proportional to `log₂ n`.

Execution time increases very slowly compared to linear algorithms.

---

# 5. Time Complexity

## Iterative Binary Search

* Best Case: `O(1)`
* Worst Case: `O(log n)`
* Average Case: `O(log n)`

## Recursive Binary Search

* Best Case: `O(1)`
* Worst Case: `O(log n)`
* Average Case: `O(log n)`

---

# 6. Space Complexity

## Iterative Version

Uses only `left`, `right`, and `mid` variables.
Space Complexity = `O(1)`

## Recursive Version

Uses recursion stack.
Maximum recursion depth = `log n`

Space Complexity = `O(log n)`

---

# Case Comparison Summary

**Best Case:**
Target found at first middle position → `1` comparison → `O(1)`

**Worst Case:**
Target not found or found at deepest level → `log n` divisions → `O(log n)`

**Average Case:**
Target found at intermediate level → `O(log n)`

---