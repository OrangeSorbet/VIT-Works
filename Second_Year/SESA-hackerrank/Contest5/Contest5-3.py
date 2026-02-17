# Given the head of a singly linked list, rotate the list to the right by k places. Rotating a list by 1 place means moving the last node of the list to the front.

# Example 1:

# image

# Input: head = [1, 2, 3, 4, 5], k = 2 Output: [4, 5, 1, 2, 3]

# Explanation: Rotate 1: [5, 1, 2, 3, 4] Rotate 2: [4, 5, 1, 2, 3]

# Example 2:

# image

# Input: head = [0, 1, 2], k = 4 Output: [2, 0, 1]

# Explanation: Rotating a list of size 3 by 4 places is equivalent to rotating it by 4 mod 3 = 1 place.

# Input Format

# The first line contains an integer N, the number of nodes in the list. The second line contains N space-separated integers representing the node values. The third line contains an integer k.

# Constraints

# Constraints: 0 ≤ N ≤ 10^5 -10^9 ≤ Node.val ≤ 10^9 0 ≤ k ≤ 10^9

# Edge-case Rules: If N = 0 or N = 1, return the list as is. If k = 0 or k is a multiple of N, the list remains unchanged.

# Output Format

# Print the values of the rotated linked list, separated by spaces. If the list is empty after rotation, print nothing.

# Sample Input 0

# 5
# 1 2 3 4 5
# 2
# Sample Output 0

# 4 5 1 2 3
# Sample Input 1

# 3
# 0 1 2
# 4
# Sample Output 1

# 2 0 1
# Sample Input 2

# 2
# 1 2
# 1
# Sample Output 2

# 2 1

import sys

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# ================= CODE AREA START =================
def rotateRight(head, k):
    # Write your code here
    if not head or not head.next or k == 0:
        return head

    length = 1
    tail = head
    while tail.next:
        tail = tail.next
        length += 1

    tail.next = head

    new_tail = head
    for _ in range(length - k % length - 1):
        new_tail = new_tail.next

    new_head = new_tail.next

    new_tail.next = None
    return new_head

# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
def print_list(head):
    res = []
    curr = head
    while curr:
        res.append(str(curr.val))
        curr = curr.next
    print(" ".join(res))

if __name__ == '__main__':
    data = sys.stdin.read().split()
    if not data: sys.exit(0)
    it = iter(data)
    n = int(next(it))
    if n == 0:
        next(it) # consume k
        sys.exit(0)
    head = ListNode(int(next(it)))
    curr = head
    for _ in range(n - 1):
        curr.next = ListNode(int(next(it)))
        curr = curr.next
    k = int(next(it))
    result = rotateRight(head, k)
    print_list(result)