# You are given two integer arrays. Your task is to find the elements that appear in both arrays. Each element in the result must be unique. To ensure consistency, you must return the result in ascending order. If there are no common elements between the two arrays, print -1.

# Input Format

# The first line contains an integer N, the size of the first array. The second line contains N space-separated integers. The third line contains an integer M, the size of the second array. The fourth line contains M space-separated integers.

# Constraints

# Constraints: 1 ≤ N, M ≤ 10^5 0 ≤ Array elements ≤ 10^9

# Edge Case Behavior: • If no intersection exists, print -1. • Duplicate elements in the input arrays should appear only once in the output.

# Output Format

# Print all unique elements that are present in both arrays. The output elements can be printed in any order.

# Sample Input 0

# 4
# 1 2 2 1
# 2
# 2 2
# Sample Output 0

# 2
# Sample Input 1

# 3
# 4 9 5
# 5
# 9 4 9 8 4
# Sample Output 1

# 4 9

import sys

# ================= CODE AREA START =================
def getIntersection(nums1, nums2):
    # Write your code here
    set1 = set(nums1)
    set2 = set(nums2)
    intersection = set1.intersection(set2)
    if intersection:
        return list(intersection)
    else:
        return []
# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
if __name__ == '__main__':
    data = sys.stdin.read().split()
    if not data: sys.exit(0)
    
    n = int(data[0])
    nums1 = [int(x) for x in data[1:n+1]]
    
    m = int(data[n+1])
    nums2 = [int(x) for x in data[n+2:n+m+2]]
    
    result = getIntersection(nums1, nums2)
    
    if not result:
        print("-1")
    else:
        result.sort()
        print(*(result))