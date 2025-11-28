print("This program takes the size of a tuple and its elements from the user, and then displays the tuple.")
print("-------------------------------------------------------------")

# Loop until the user enters a valid number for the tuple size
while True:
    try:
        size = int(input("Enter size of tuple: "))  # Prompt the user to enter the size of the tuple
        break  # Exit the loop if input is valid
    except ValueError:  # If the user enters an invalid input
        print("Enter a valid number")  # Print an error message and ask for input again

print("Enter numbers in tuple: ")

tpl = ()  # Initialize an empty tuple
for i in range(size):  # Loop through the range of tuple size
    inp = input(f"Enter number {i+1}: ")  # Prompt the user to enter each element
    tpl += (inp,)  # Add each input element as a tuple (not as a list)

print(f"Tuple is: {tpl}")  # Print the final tuple
