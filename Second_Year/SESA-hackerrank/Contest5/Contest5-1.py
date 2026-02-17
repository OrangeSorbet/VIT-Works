# Given the root of a binary tree, return its maximum depth. A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

# Example 1:

# image

# Input: nodes = [3, 9, 20, null, null, 15, 7] Output: 3

# Example 2: Input: nodes = [1, null, 2] Output: 2

# Input Format

# The first line contains an integer N, the number of elements in the level-order array. The second line contains N space-separated values. Each value is either an integer or the string "null" representing a non-existent node.

# Constraints

# Constraints: 0 ≤ number of nodes ≤ 10^4 -100 ≤ Node.val ≤ 100

# Edge-case Rules: If the tree is empty (N = 0 or root is null), the depth is 0. A single root node has a depth of 1.

# Output Format

# A single integer representing the maximum depth of the tree.

# Sample Input 0

# 7
# 3 9 20 null null 15 7
# Sample Output 0

# 3
# Sample Input 1

# 3
# 1 null 2
# Sample Output 1

# 2
# Sample Input 2

# 0
# Sample Output 2

# 0

import sys
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# ================= CODE AREA START =================
def maxDepth(root):
    # Write your code here
    if not root:
        return 0
    left_depth = maxDepth(root.left)
    right_depth = maxDepth(root.right)
    return max(left_depth, right_depth) + 1

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
    if n == 0:
        print(0)
        sys.exit(0)
    nodes = data[1:]
    root = build_tree(nodes)
    print(maxDepth(root))