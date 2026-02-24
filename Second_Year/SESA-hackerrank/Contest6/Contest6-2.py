# Given a string s consisting of words and spaces, return the length of the last word in the string.

# A word is defined as a maximal substring consisting of non-space characters only. The string may contain leading or trailing spaces, and words may be separated by multiple spaces.

# Example 1: Input: s = "Hello World" Output: 5 Explanation: The last word is "World" with length 5.

# Example 2: Input: s = " fly me to the moon " Output: 4 Explanation: The last word is "moon" with length 4.

# Example 3: Input: s = "luffy is still joyboy" Output: 6

# Input Format

# A single line containing the string s.

# Constraints

# s consists of only English letters (uppercase/lowercase) and spaces ' '. There will be at least one word in s.

# Output Format

# A single integer representing the length of the last word.

# Sample Input 0

# Hello World
# Sample Output 0

# 5
# Sample Input 1

#    fly me   to   the moon  
# Sample Output 1

# 4
# Sample Input 2

# luffy is still joyboy
# Sample Output 2

# 6

import sys

# ================= CODE AREA START =================
def lengthOfLastWord(s: str) -> int:
    # Write your code here
    s = s.strip()
    if not s:
        return 0
    words = s.split()
    return len(words[-1])
# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
if __name__ == '__main__':
    # Read entire line including spaces
    line = sys.stdin.read().strip('\r\n')
    if not line:
        sys.exit(0)
    print(lengthOfLastWord(line))