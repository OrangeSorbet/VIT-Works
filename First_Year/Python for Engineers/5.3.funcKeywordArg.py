print("This program performs arithmetic operations using keyword arguments.")
print("--------------------------------------------------------------------------")

# Define arithmetic operation functions
def add(a, b):
    return a + b

def subtract(a, b):
    return a - b

def multiply(a, b):
    return a * b

def divide(a, b):
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

# Perform operations using keyword arguments
print("Addition of the two numbers is:", add(a=a, b=b))
print("Subtraction of the two numbers is:", subtract(a=a, b=b))
print("Multiplication of the two numbers is:", multiply(a=a, b=b))
print("Division of the two numbers is:", divide(a=a, b=b))
