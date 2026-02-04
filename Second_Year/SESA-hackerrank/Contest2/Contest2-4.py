# Given the head of a singly linked list, determine if the linked list contains a cycle. A cycle exists if you can reach a node again by continuously following the next pointers. Internally, a pos variable is used to indicate the index of the node that the tail connects to, but it is not passed to your function.

# You need to implement a function that returns true if there is a cycle, otherwise false.

# Complete the function hasCycle that takes the head of a singly linked list as input and returns a boolean indicating whether the linked list contains a cycle.

# Input Format

# The function receives a single parameter:

# head: a pointer/reference to the head node of a singly linked list.

# Note: The linked list is created and passed by the system. You do not need to read input.

# Constraints

# The number of nodes in the linked list is in the range [0, 10^4].

# -10^5 <= Node.val <= 10^5

# pos is -1 or a valid index in the linked list (used internally for testing cycles).

# Output Format

# Return true if the linked list contains a cycle, else return false.

# Sample Input 0

# 4
# 3 2 0 -4
# 1
# Sample Output 0

# true
# Sample Input 1

# 2
# 1 2
# 0
# Sample Output 1

# true
# Sample Input 2

# 1
# 1
# -1
# Sample Output 2

# false

import math
import os
import random
import re
import sys

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def hasCycle(head):
    # Write your code here
    slow=head
    fast=head
    while fast and fast.next:
        slow=slow.next
        fast=fast.next.next
        if slow==fast:
            return True
    return False
    # Return true if there is a cycle, false otherwise
    pass

if __name__ == '__main__':
    # Read all input from stdin
    input_data = sys.stdin.read().split()
    
    if not input_data:
        print("false")
        sys.exit()
    
    iterator = iter(input_data)
    
    try:
        # 1. Read number of nodes
        n = int(next(iterator))
        
        if n == 0:
            print("false")
            sys.exit()

        # 2. Read node values
        values = []
        for _ in range(n):
            values.append(int(next(iterator)))
        
        # 3. Read pos
        pos = int(next(iterator))
        
    except StopIteration:
        pass

    # Build the Linked List
    head = ListNode(values[0])
    nodes = [head]
    current = head
    
    for i in range(1, n):
        new_node = ListNode(values[i])
        current.next = new_node
        current = new_node
        nodes.append(new_node)
        
    # Create the Cycle if pos is valid
    if pos != -1 and pos < len(nodes):
        current.next = nodes[pos]

    # Call Student Function
    result = hasCycle(head)

    # Print Result
    if result:
        print("true")
    else:
        print("false")