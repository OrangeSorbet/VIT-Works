print("This program finds the maximum of two numbers entered by the user.")
print("--------------------------------------------------------------------")

# Input two numbers
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))

# Function to find the maximum of two numbers
def max():
    if a > b:
        return a
    else:
        return b

# Display the maximum number
print("Maximum of the two numbers is:", max())
