print("This program checks whether the number you enter is prime or not.")
print("-------------------------------------------------------------")

num = int(input("Enter a number to check prime: "))  # Take number input from user

if num > 1:  # A prime number is greater than 1
    for i in range(2, num):  # Check for divisibility from 2 to num-1
        if num % i == 0:  # If the number is divisible by any number other than 1 and itself
            print(f"{num} is not prime")  # It is not prime
            break  # Exit the loop as we have found a factor
    else:
        print(f"{num} is prime")  # If the loop completes without finding a factor, the number is prime
else:
    print(f"{num} is not prime")  # Numbers less than or equal to 1 are not prime
