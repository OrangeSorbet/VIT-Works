# Prompting the user to enter two numbers
print("Enter two numbers to find the maximum")
print("---------------------------------------------")
# Taking input for the first number
num1 = int(input("Enter first number: "))
# Taking input for the second number
num2 = int(input("Enter second number: "))

# Finding the maximum using the 'max()' function
print("--------------------------------------------")
print("Max number with 'max()' function")
# The max function returns the largest of the two numbers
print(max(num1, num2), "is greater")

# Finding the maximum without using the 'max()' function
print("--------------------------------------------")
print("Max number without using 'max()' function")
# If condition to compare the numbers
if num1 > num2:
    print(num1, "is greater")  # If num1 is greater than num2, print num1
else:
    print(num2, "is greater")  # Otherwise, print num2
