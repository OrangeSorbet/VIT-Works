# You are given an integer array nums, where nums[i] represents the points scored in the i-th game.

# There are exactly two players. Initially, the first player is active and the second player is inactive.

# For each game i (starting from index 0), the following rules apply sequentially: 1. If nums[i] is odd, the active and inactive players swap roles. 2. If it is every 6th game (i.e., indices 5, 11, 17, ...), the active and inactive players swap roles again.

# The player who is active after the above rules plays the i-th game and gains nums[i] points.

# Return an integer representing the score difference, defined as: (first player's total score − second player's total score).

# Example 1: Input: nums = [1, 2, 3] Output: 0

# Game 0: 1 is odd → Swap. Player 2 becomes active. Player 2 gains 1.

# Game 1: 2 is even → No swap. Player 2 remains active. Player 2 gains 2.

# Game 2: 3 is odd → Swap. Player 1 becomes active. Player 1 gains 3.

# Final scores: Player 1 = 3 Player 2 = 3

# Difference = 3 − 3 = 0

# Input Format

# The first line contains an integer, the number of games. The second line contains space-separated integers representing the points for each game.

# Constraints

# Note: Use 64-bit integers (long long in C++, long in Java/Python) for the scores.

# Output Format

# A single integer representing (Total Score P1 - Total Score P2).

import sys

# ================= CODE AREA START =================
def getScoreDifference(nums):
    # Write your code here
    player1_score = 0
    player2_score = 0
    active_player = 1

    for i in range(len(nums)):
        if nums[i] % 2 == 1:
            active_player = 3 - active_player

        if i % 6 == 5:
            active_player = 3 - active_player

        if active_player == 1:
            player1_score += nums[i]
        else:
            player2_score += nums[i]

    return player1_score - player2_score
# ================= CODE AREA END =================

# DO NOT MODIFY THE CODE BELOW
if __name__ == '__main__':
    data = sys.stdin.read().split()
    if not data: sys.exit(0)
    n = int(data[0])
    nums = [int(x) for x in data[1:]]
    print(getScoreDifference(nums))