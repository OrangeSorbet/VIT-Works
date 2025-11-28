print("This program calculates the sum of the digits of a given number using recursion.")
print("------------------------------------------------------------")

# Define a recursive function to calculate the sum of digits
def sum(num):
    if num == 0:
        return 0  # Base case: sum of digits of 0 is 0
    else:
        return num % 10 + sum(num // 10)  # Recursive call to sum the digits

# Get input from the user
num = int(input("Enter a number to find sum of digits - "))

# Display the result
print(f"Sum of digits of {num} is {sum(num)}")
