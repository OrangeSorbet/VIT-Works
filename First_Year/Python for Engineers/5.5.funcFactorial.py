print("This program calculates the factorial of a given number using recursion.")
print("-------------------------------------------------------------")

# Define a recursive function to calculate the factorial
def fact(n):
    if n == 0:
        return 1  # Base case: factorial of 0 is 1
    else:
        return n * fact(n-1)  # Recursive call to calculate factorial

# Get input from the user
num = int(input("Enter a number to find factorial - "))

# Display the result
print(f"Factorial of {num} is {fact(num)}")
