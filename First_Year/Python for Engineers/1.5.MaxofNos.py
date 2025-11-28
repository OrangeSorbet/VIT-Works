def two():
    print("Enter two numbers")
    num1 = int(input("Enter first number: "))
    num2 = int(input("Enter second number: "))
    print("--------------------------------------------")

    print("Max number with 'max()' function")
    print(max(num1, num2), "is greater")
    print("--------------------------------------------")

    print("Max number without using 'max()' function")
    if num1 > num2:
        print(num1, "is greater")
    else:
        print(num2, "is greater")

def three():
    print("Enter three numbers")
    num1 = int(input("Enter first number: "))
    num2 = int(input("Enter second number: "))
    num3 = int(input("Enter third number: "))
    print("--------------------------------------------")

    print("Max number with 'max()' function")
    print(max(num1, num2, num3), "is greatest")
    print("--------------------------------------------")

    print("Max number without using 'max()' function")
    if num1 > num2 and num1 > num3:
        print(num1, "is greatest")
    elif num2 > num1 and num2 > num3:
        print(num2, "is greatest")
    else:
        print(num3, "is greatest")

def four():
    print("Enter four numbers")
    num1 = int(input("Enter first number: "))
    num2 = int(input("Enter second number: "))
    num3 = int(input("Enter third number: "))
    num4 = int(input("Enter fourth number: "))
    print("--------------------------------------------")

    print("Max number with 'max()' function")
    print(max(num1, num2, num3, num4), "is greatest")
    print("--------------------------------------------")

    print("Max number without using 'max()' function")
    if num1 > num2 and num1 > num3 and num1 > num4:
        print(num1, "is greatest")
    elif num2 > num1 and num2 > num3 and num2 > num4:
        print(num2, "is greatest")
    elif num3 > num1 and num3 > num2 and num3 > num4:
        print(num3, "is greatest")
    else:
        print(num4, "is greatest")

print("Max of 2, 3, and 4 numbers")
print("1. Max of 2 numbers")
print("2. Max of 3 numbers")
print("3. Max of 4 numbers")
print("4. Exit")
print("Enter your choice:")
choice = int(input())
print("--------------------------------------------------")
if choice == 1:
    two()
elif choice == 2:
    three()
elif choice == 3:
    four()
elif choice == 4:
    print("Exiting...")
else:
    print("Invalid choice. Please enter a valid option.")
print("--------------------------------------------------")