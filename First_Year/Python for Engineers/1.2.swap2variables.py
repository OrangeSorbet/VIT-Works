# Function to swap two values
def swap(a, b):
    # Swap the values of a and b
    a, b = b, a
    # Return the swapped values
    return a, b

# Get user input for the two numbers
print("Enter two numbers to swap")
print("------------------")
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))

# Call the swap function and unpack the returned values
a, b = swap(a, b)

# Display the swapped values
print("------------------")
print("After swapping - ")
print("First number is", a)
print("Second number is", b)
print("------------------")