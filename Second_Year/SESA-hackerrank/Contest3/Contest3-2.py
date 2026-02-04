# You are given the head of a singly linked list. Your task is to sort the list in ascending order and return the new head. Example Visualization:

# image

# Note: The image above shows the transformation of an unsorted list into a sorted one. The algorithm should run in O(n log n) time complexity and use constant or logarithmic space.

# Input Format

# The first line contains an integer N, the number of elements in the linked list. The second line contains N space-separated integers representing the node values of the linked list.

# Constraints

# 0 ≤ N ≤ 5 × 10^4 -10^5 ≤ Node.val ≤ 10^5

# Edge Case Behavior If N = 0 (empty list), print nothing (or handle gracefully). If N = 1, print the single element. The output must be printed by the locked main() function, not your function.

# Output Format

# Print the values of the sorted linked list, separated by spaces.

# Sample Input 0

# 4
# 4 2 1 3
# Sample Output 0

# 1 2 3 4
# Sample Input 1

# 5
# -1 5 3 4 0
# Sample Output 1

# -1 0 3 4 5

import sys

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

#
# Complete the 'sortList' function below.
#
# The function is expected to return a ListNode.
# The function accepts ListNode head as parameter.
#

# ================= CODE AREA START =================
def sortList(head):
    # Write your code here
    if not head or not head.next:
        return head

    def split(head):
        slow = head
        fast = head
        prev = None
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        if prev:
            prev.next = None
        return head, slow

    def merge(l1, l2):
        dummy = ListNode(0)
        tail = dummy
        while l1 and l2:
            if l1.val < l2.val:
                tail.next = l1
                l1 = l1.next
            else:
                tail.next = l2
                l2 = l2.next
            tail = tail.next
        tail.next = l1 if l1 else l2
        return dummy.next

    left, right = split(head)
    left_sorted = sortList(left)
    right_sorted = sortList(right)
    return merge(left_sorted, right_sorted)
# ================= CODE AREA END =================



# DO NOT MODIFY THE CODE BELOW
def print_list(node):
    parts = []
    while node:
        parts.append(str(node.val))
        node = node.next
    print(" ".join(parts))

if __name__ == '__main__':
    input_data = sys.stdin.read().split()
    if not input_data:
        sys.exit(0)
    
    iterator = iter(input_data)
    try:
        n = int(next(iterator))
        if n == 0:
            sys.exit(0)
            
        head = ListNode(int(next(iterator)))
        current = head
        
        for _ in range(n - 1):
            val = int(next(iterator))
            current.next = ListNode(val)
            current = current.next
            
        result = sortList(head)
        print_list(result)
        
    except StopIteration:
        pass