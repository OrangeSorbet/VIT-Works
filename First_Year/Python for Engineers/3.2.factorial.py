# This program calculates the factorial of a number entered by the user.
print("This program calculates the factorial of a number you enter.")
print("-------------------------------------------------------------")

a = int(input("Enter a number to get factorial: "))
fact = 1  # Initialize factorial result as 1

# Loop from 1 to the entered number (inclusive)
for i in range(1, a + 1):
    fact *= i  # Multiply fact by the current number

# Display the final factorial result
print(f"Factorial of {a} is {fact}")
