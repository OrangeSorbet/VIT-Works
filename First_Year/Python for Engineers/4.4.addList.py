print("This program takes two lists from the user and combines them into a third list.")
print("-------------------------------------------------------------")

lst1 = []  # First list
lst2 = []  # Second list

# Input elements for the first list
input1 = int(input("Enter the number of elements in list1: "))
for i in range(input1):
    lst1.append(int(input(f"Enter element {i+1}: ")))

# Input elements for the second list
input2 = int(input("Enter the number of elements in list2: "))
for i in range(input2):
    lst2.append(int(input(f"Enter element {i+1}: ")))

# Display both lists
print(f"List1 is: {lst1}")
print(f"List2 is: {lst2}")

# Combine both lists
lst3 = lst1 + lst2
print(f"Combined list is: {lst3}")
