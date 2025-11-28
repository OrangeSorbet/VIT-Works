print("This program takes a series of numbers, calculates the frequency of each number, and identifies the most frequent number(s).")
print("------------------------------------------------------------")

numbers = []  # List to store the numbers entered by the user

# Loop to take multiple numbers as input
while True:
    num = int(input("Enter numbers (0 to stop): "))  # Take input from the user
    if num == 0:  # Exit the loop if the user enters 0
        break
    numbers.append(num)  # Add the number to the list

numbers.sort()  # Sort the numbers in ascending order
print("List is:", numbers)

# Create an empty dictionary to store the frequency of each number
freq_dict = {}

# Count the frequency of each number in the list
for i in numbers:
    freq_dict[i] = freq_dict.get(i, 0) + 1  # Use get() to return 0 if key doesn't exist and then increment

# Find the maximum frequency value
max_freq = max(freq_dict.values())

# Find all numbers with the highest frequency
most_frequent_numbers = [key for key, value in freq_dict.items() if value == max_freq]

# Print the results
print(f"Highest frequency number(s): {most_frequent_numbers} with {max_freq} occurrences")
