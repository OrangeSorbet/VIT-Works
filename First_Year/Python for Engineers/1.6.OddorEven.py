# Prompt the user to input a number
num = int(input("Enter a number to find if odd or even - "))

# Check if the number is even
if num % 2 == 0:
    print(num, "is even")  # If divisible by 2, it's even
else:
    print(num, "is odd")  # Otherwise, it's odd