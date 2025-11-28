print("This program calculates the sum of digits of a given number.")
print("-------------------------------------------------------------")

num = int(input("Enter a number to get sum of digits: "))  # Take user input for the number
num = str(num)  # Convert the number to a string so that we can loop through each digit

sum = 0  # Initialize a variable to store the sum of digits

# Loop through each character (digit) in the string representation of the number
for i in num:
    sum += int(i)  # Convert the character back to an integer and add it to the sum

# Print the result, showing the sum of digits
print(f"Sum of digits of {num} is {sum}")
