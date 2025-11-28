# Prompt the user to input a number
num = int(input("Enter a number to find if positive, negative, or zero - "))

# Check if the number is positive
if num > 0:
    print(num, "is positive")  # If greater than 0, the number is positive
# Check if the number is negative
elif num < 0:
    print(num, "is negative")  # If less than 0, the number is negative
# If it's neither positive nor negative, it must be zero
else:
    print(num, "is zero")  # If the number is 0