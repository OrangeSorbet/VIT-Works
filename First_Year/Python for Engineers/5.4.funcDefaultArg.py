print("This program performs arithmetic operations using default arguments.")
print("-------------------------------------------------------------------------")

# Define arithmetic operation functions with default values
def add(a=0, b=0):
    return a + b

def subtract(a=0, b=0):
    return a - b

def multiply(a=0, b=0):
    return a * b

def divide(a=1, b=1):  # Avoid zero division with default
    return a / b

# Get user input with validation
while True:
    a_input = input("Enter first number: ")
    b_input = input("Enter second number: ")

    # Validate that both inputs are numbers
    if a_input.isdigit() and b_input.isdigit():
        a = int(a_input)
        b = int(b_input)
        break
    else:
        print("Invalid input! Please enter valid numbers.")

# Perform operations by overriding default arguments
print("Addition of the two numbers is:", add(a, b))
print("Subtraction of the two numbers is:", subtract(a, b))
print("Multiplication of the two numbers is:", multiply(a, b))
print("Division of the two numbers is:", divide(a, b))
