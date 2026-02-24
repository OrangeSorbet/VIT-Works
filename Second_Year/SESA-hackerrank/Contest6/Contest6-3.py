# You are given the root of a Binary Search Tree (BST) and an integer k. Your task is to return the k-th smallest value (1-indexed) among all the node values in the tree.

# Recall that in a BST, for every node: • All values in the left subtree are smaller than the node's value. • All values in the right subtree are larger than the node's value.

# Example 1:

# image

# Input: nodes = [3, 1, 4, null, 2], k = 1 Output: 1

# Example 2:

# image

# Input: nodes = [5, 3, 6, 2, 4, null, null, 1], k = 3 Output: 3

# Input Format

# The first line contains an integer the number of elements in the level-order representation of the tree. The second line contains space-separated values (integers or the string "null"). The third line contains an integer k.

# Constraints

# A single integer representing the smallest value.

# Edge-case rules (Minimum value in BST). (Maximum value in BST). Skewed trees (linked-list-like structures).

# Output Format

# The input is guaranteed to be a valid Binary Search Tree.

# Sample Input 0

# 5
# 3 1 4 null 2
# 1
# Sample Output 0

# 1
# Sample Input 1

# 8
# 5 3 6 2 4 null null 1
# 3
# Sample Output 1

# 3
# Sample Input 2

# 1
# 1
# 1
# Sample Output 2

# 1

import sys
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# ================= CODE AREA START =================
def kthSmallest(root, k):
    # Write your code here
    stack = []
    current = root
    count = 0
    while stack or current:
        while current:
            stack.append(current)
            current = current.left
        current = stack.pop()
        count += 1
        if count == k:
            return current.val
        current = current.right
    return -1
# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
def build_tree(nodes):
    if not nodes or nodes[0] == "null": return None
    root = TreeNode(int(nodes[0]))
    queue = deque([root])
    i = 1
    while queue and i < len(nodes):
        node = queue.popleft()
        if i < len(nodes) and nodes[i] != "null":
            node.left = TreeNode(int(nodes[i]))
            queue.append(node.left)
        i += 1
        if i < len(nodes) and nodes[i] != "null":
            node.right = TreeNode(int(nodes[i]))
            queue.append(node.right)
        i += 1
    return root

if __name__ == '__main__':
    data = sys.stdin.read().split()
    if not data: sys.exit(0)
    n = int(data[0])
    nodes_arr = data[1:n+1]
    k_val = int(data[n+1])
    root_node = build_tree(nodes_arr)
    print(kthSmallest(root_node, k_val))