# Given the head of a singly linked list, return true if it is a palindrome or false otherwise. A linked list is a palindrome if the sequence of values read from front to back is the same as the sequence read from back to back. Example Visualization:

# image

# Input Format

# The first line contains an integer N, the number of nodes in the list. The second line contains N space-separated integers representing the node values.

# Constraints

# Constraints: 1 ≤ N ≤ 10^5 0 ≤ Node.val ≤ 9

# Edge Case Behavior: • A single node (N = 1) is always a palindrome.

# Follow-up: Try to solve the problem in O(N) time and O(1) extra space.

# Output Format

# Print true if the list is a palindrome, otherwise print false. (Lowercase)

# Sample Input 0

# 4
# 1 2 2 1
# Sample Output 0

# true
# Sample Input 1

# 2
# 1 2
# Sample Output 1

# false

import sys

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# ================= CODE AREA START =================
def isPalindrome(head: ListNode) -> bool:
    # Write your code here
    if not head or not head.next:
        return True

    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    prev = None
    curr = slow
    while curr:
        next_temp = curr.next
        curr.next = prev
        prev = curr
        curr = next_temp

    first_half = head
    second_half = prev
    while second_half:
        if first_half.val != second_half.val:
            return False
        first_half = first_half.next
        second_half = second_half.next
    return True
# ================= CODE AREA END =================




if __name__ == '__main__':
    data = sys.stdin.read().split()
    if not data: sys.exit(0)
    n = int(data[0])
    if n == 0: sys.exit(0)
    vals = data[1:]
    head = ListNode(int(vals[0]))
    curr = head
    for i in range(1, n):
        curr.next = ListNode(int(vals[i]))
        curr = curr.next
    print("true" if isPalindrome(head) else "false")