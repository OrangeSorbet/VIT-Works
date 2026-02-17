# You are given an array of strings words and an integer array weights of length 26. Each integer weights[i] represents the weight of the i-th lowercase English letter (where i = 0 is 'a', i = 1 is 'b', and so on).

# The weight of a word is the sum of the weights of its characters.

# For each word: 1. Calculate its total weight. 2. Take the weight modulo 26. 3. Map the result to a lowercase English letter using reverse alphabetical order: 0 → 'z' 1 → 'y' 2 → 'x' ... 25 → 'a'

# Return the string formed by concatenating these mapped characters for all words in the given order.

# Example: Input: words = ["abcd", "def"], weights = [5, 3, 12, 14, 1, 2, ...]

# "abcd": 5 + 3 + 12 + 14 = 34 34 mod 26 = 8

# Mapping 8 in reverse alphabetical order: 'z' is 0, 'y' is 1, 'x' is 2, ..., 'r' is 8.

# Result: "r..."

# Input Format

# The first line contains an integer N, the number of words. The second line contains N space-separated strings. The third line contains 26 space-separated integers representing the weights for 'a' through 'z'.

# Constraints

# Constraints: 1 ≤ N ≤ 10^4 1 ≤ words[i].length ≤ 20 1 ≤ weights[i] ≤ 100 All characters are lowercase English letters.

# Edge-case Rules: If the total weight is a multiple of 26, the modulo is 0, which maps to 'z'.

# Output Format

# A single string representing the concatenated result.

# Sample Input 0

# 3
# abcd def xyz
# 5 3 12 14 1 2 3 2 10 6 6 9 7 8 7 10 8 9 6 9 9 8 3 7 7 2
# Sample Output 0

# rij
# Sample Input 1

# 3
# a b c
# 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
# Sample Output 1

# yyy
# Sample Input 2

# 3
# jya vvn cas
# 3 8 7 6 10 10 9 5 2 9 3 6 7 2 2 9 8 5 10 9 1 5 6 6 1 8
# Sample Output 2

# mnf

import sys

# ================= CODE AREA START =================
def weightedMapping(words, weights):
    # Write your code here
    result = []
    for word in words:
        total_weight = 0
        for ch in word:
            total_weight += weights[ord(ch) - ord('a')]
        mod_value = total_weight % 26
        mapped_char = chr(ord('z') - mod_value)
        result.append(mapped_char)
    return ''.join(result)

# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
if __name__ == '__main__':
    data = sys.stdin.read().split()
    if not data: sys.exit(0)
    
    n = int(data[0])
    words = data[1:n+1]
    weights = [int(x) for x in data[n+1:]]
    
    print(weightedMapping(words, weights))