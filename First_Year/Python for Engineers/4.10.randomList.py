print("This program generates a list of random numbers between 1 and 20, based on the user's input for the list size.")
print("-------------------------------------------------------------")

import random  # Import random module to generate random numbers

size = int(input("Enter size of list: "))  # Prompt user for the size of the list
print("Now, we will generate a list of random numbers from 1 to 20.")

lst = []  # Initialize an empty list

# Loop to generate random numbers and add them to the list
for i in range(size):
    lst.append(random.randint(1, 20))  # Generate a random number between 1 and 20 and add to the list

# Output the randomly generated list
print(f"Random list so produced is: {lst}")
