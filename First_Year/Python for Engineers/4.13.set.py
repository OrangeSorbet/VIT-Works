print("This program takes the size of a set and its elements from the user, and then displays the set.")
print("-------------------------------------------------------------")

size = int(input("Enter size of set: "))  # Get the size of the set from the user
print("Enter elements in set: ")

lst = set()  # Initialize an empty set

# Collect elements from user input and add to the set
for i in range(size):
    inp = input(f"Enter element {i+1}: ")
    lst.add(inp)

print(f"Set is: {lst}")  # Display the set
