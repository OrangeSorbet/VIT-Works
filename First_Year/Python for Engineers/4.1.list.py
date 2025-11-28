print("This program takes the size of the list and its elements from the user and displays the list.")
print("-------------------------------------------------------------")

# Loop until the user enters a valid number for the list size
while True:
    try:
        size = int(input("Enter size of list: "))  # Prompt the user to enter the size of the list
        break  # Exit the loop if input is valid
    except ValueError:  # If the user enters an invalid input
        print("Enter a valid number")  # Print an error message and ask for input again

print("Enter elements in list: ")

lst = []  # Initialize an empty list
for i in range(size):  # Loop through the range of list size
    inp = input(f"Enter element {i+1}: ")  # Prompt the user to enter each element
    lst.append(inp)  # Append each input element to the list

print(f"List is: {lst}")  # Print the final list
