# Print what the code does
print("This program checks if a given year (in a sentence or format with BC/AD) is a leap year or not.")

# Print the separator line
print("------------------------------------")

# Take input from the user (can be in sentence, BC/AD, etc.)
yr = input("Enter year in BC or AD or sentence!: ")

# Extract only digits from the input and convert to integer
yr = int("".join([char for char in yr if char.isdigit()]))

# Check if it's a leap year
if yr % 4 == 0:
    print(f"{yr} is a leap year!")
else:
    print(f"{yr} is not a leap year!")
