# Print what the code does
print("This program finds the largest of three input numbers.")

# Print the separator line
print("------------------------------------")

# Prompt user to input three numbers
a = int(input("Enter first number: "))
b = int(input("Enter second number: "))
c = int(input("Enter third number: "))

# Check which number is the largest and print the result
if a > b and a > c:
    print("Max is", a)
elif b > a and b > c:    
    print("Max is", b)
else:
    print("Max is", c)
