print("This program removes duplicates from a list and shows which duplicates were removed along with their indices.")
print("-------------------------------------------------------------")

size = int(input("Enter size of list: "))  # Prompt the user to enter the size of the list
print("Enter numbers in list: ")

lst = []  # Initialize an empty list
for i in range(size):
    lst.append(int(input(f"Enter number {i+1}: ")))  # Append each input number to the list

print(f"List is: {lst}")  # Display the original list
print("Now, we remove duplicates from the list.")

seen = []  # List to keep track of unique numbers
dupes = []  # List to keep track of duplicates

# Loop to find duplicates
for i in lst:
    if i not in seen:
        seen.append(i)  # If number is not already in seen, add it
    else:
        dupes.append(i)  # If number is a duplicate, add it to dupes list

# Print the duplicates and their indices
for i in range(len(dupes)):
    print(f"Duplicate {i+1}: {dupes[i]} at index {lst.index(dupes[i])}")

print(f"List after removing duplicates is: {seen}")  # Display the list with duplicates removed
