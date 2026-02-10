# You are given the head of a singly linked list. Your task is to determine if the linked list has a cycle in it. A cycle exists if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that the tail's next pointer is connected to (0-indexed). If pos is -1, then there is no cycle in the linked list. If a cycle exists, return the node where the cycle begins. If there is no cycle, return null. Important: Your code will be tested by a hidden main() function. The main() function will build the list, create the cycle based on pos, call your function, and then print the index of the node you returned. If you return null, it will print -1.

# Example Visualization:

# Example 01:image

# Input: head = [3,2,0,-4], pos = 1 Output: tail connects to node index 1 Explanation: There is a cycle in the linked list, where tail connects to the second node.

# Example 02:image

# Input: head = [1,2], pos = 0 Output: tail connects to node index 0 Explanation: There is a cycle in the linked list, where tail connects to the first node.

# Example 03:image

# Input: head = [1], pos = -1 Output: no cycle Explanation: There is no cycle in the linked list.

# Input Format

# The first line contains an integer N, the number of nodes in the list. The second line contains N space-separated integers representing the node values. The third line contains an integer pos, representing the index (0-indexed) that the tail points back to. If pos is -1, there is no cycle.

# Constraints

# Constraints: 0 ≤ N ≤ 10^5 -10^9 ≤ Node.val ≤ 10^9 -1 ≤ pos < N

# Do not modify the linked list.

# Expected Time Complexity: O(N)

# Expected Space Complexity: O(1)
# (Try to solve it without using extra memory such as HashSets.)

# Edge-case Rules: • If the list is empty (N = 0), output -1. • If pos = -1, output -1. • If pos = 0, the cycle starts at the head of the linked list.

# Output Format

# A single integer representing the 0-indexed position of the node where the cycle begins. Print -1 if no cycle exists.

# Sample Input 0

# 4
# 3 2 0 -4
# 1
# Sample Output 0

# 1
# Sample Input 1

# 2
# 1 2
# 0
# Sample Output 1

# 0
# Sample Input 2

# 1
# 1
# -1
# Sample Output 2

# -1
# Sample Input 3

# 7
# 30 89 71 36 -53 -85 64
# 5
# Sample Output 3

# 5
# Sample Input 4

# 6
# 66 -47 -39 -9 -43 5
# 4
# Sample Output 4

# 4
# Sample Input 5

# 7
# -21 -65 10 -88 61 0 97
# 0
# Sample Output 5

# 0
# Sample Input 6

# 9
# -62 4 89 54 -37 95 43 -92 41
# -1
# Sample Output 6

# -1
# Sample Input 7

# 4
# -60 -68 -9 -69
# 1
# Sample Output 7

# 1
# Sample Input 8

# 10
# -82 -67 -91 10 -57 -11 -42 5 -15 -26
# 9
# Sample Output 8

# 9
# Sample Input 9

# 9
# 37 -26 2 21 -45 -7 -16 57 -32
# 3
# Sample Output 9

# 3

import sys

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

#
# Complete the 'detectCycle' function below.
#
# The function is expected to return a ListNode.
# The function accepts ListNode head as parameter.
#

# ================= CODE AREA START =================
def detectCycle(head):
    # Write your code here
    if head is None:
        return None
    slow = head
    fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            break
    else:
        return None
    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next
    return slow

# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
if __name__ == '__main__':
    input_data = sys.stdin.read().split()
    if not input_data:
        sys.exit(0)
    
    it = iter(input_data)
    try:
        n = int(next(it))
        if n == 0:
            next(it) # skip pos
            print("-1")
            sys.exit(0)
            
        nodes = []
        val = int(next(it))
        head = ListNode(val)
        nodes.append(head)
        curr = head
        
        for _ in range(n - 1):
            val = int(next(it))
            curr.next = ListNode(val)
            curr = curr.next
            nodes.append(curr)
            
        pos = int(next(it))
        if pos != -1 and pos < len(nodes):
            curr.next = nodes[pos]
            
        result_node = detectCycle(head)
        
        if result_node is None:
            print("-1")
        else:
            found_index = -1
            for i in range(len(nodes)):
                if nodes[i] is result_node:
                    found_index = i
                    break
            print(found_index)
            
    except StopIteration:
        pass