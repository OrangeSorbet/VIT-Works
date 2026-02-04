# There is a singly-linked list head and we want to delete a node node in it. You are given the node to be deleted node. You will not be given access to the first node of head.

# All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

# Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

# The value of the given node should not exist in the linked list.

# The number of nodes in the linked list should decrease by one.

# The previous node should now point to the node after the deleted node.

# Input Format

# The input is managed by the locked code stub.An integer n, the number of nodes in the linked list.Space-separated integers representing the values of the linked list.An integer node_val, representing the value of the node that must be deleted.

# Constraints

# 2 <= n <= 1000 — The number of nodes in the linked list.

# -1000 <= Node.val <= 1000 — The value of each node in the linked list.

# All node values are unique.

# The node to be deleted is guaranteed to be in the list and is not the tail node.

# Output Format

# The code stub will print the linked list values after the deletion.

# Sample Input 0

# 4
# 4 5 1 9
# 5
# Sample Output 0

# 4 1 9
# Sample Input 1

# 4
# 4 5 1 9
# 1
# Sample Output 1

# 4 5 9
# Sample Input 2

# 3
# 10 20 30
# 20
# Sample Output 2

# 10 30

import math
import os
import random
import re
import sys

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def deleteNode(node):
    """
    :type node: ListNode
    :rtype: void Do not return anything, modify node in-place instead.
    """
    # Write your code here
    node.val = node.next.val
    node.next = node.next.next
    #----
    pass

if __name__ == '__main__':
    # Read all input
    input_data = sys.stdin.read().split()
    
    if not input_data:
        sys.exit()
        
    iterator = iter(input_data)
    
    try:
        # 1. Read n
        n = int(next(iterator))
        
        # 2. Read values
        values = []
        for _ in range(n):
            values.append(int(next(iterator)))
            
        # 3. Read target value to delete
        target_val = int(next(iterator))
        
        if n == 0:
            sys.exit()

        # Build Linked List and Map values to Nodes
        head = ListNode(values[0])
        curr = head
        nodes_map = {values[0]: head}
        
        for i in range(1, n):
            new_node = ListNode(values[i])
            curr.next = new_node
            curr = new_node
            nodes_map[values[i]] = new_node
            
        # Get the actual node object to delete
        target_node = nodes_map[target_val]
        
        # Call Student Function
        deleteNode(target_node)
        
        # Print resulting list
        curr = head
        result = []
        while curr:
            result.append(str(curr.val))
            curr = curr.next
        print(" ".join(result))
        
    except StopIteration:
        pass