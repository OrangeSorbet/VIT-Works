print("This program allows you to create a list, and either get the index of a value or the value at a specific index.")
print("-------------------------------------------------------------")

size = int(input("Enter size of list: "))  # Get the size of the list from the user
print("Enter numbers in list: ")

lst = []
for i in range(size):  # Input elements one by one
    inp = input(f"Enter number {i+1}: ")
    lst.append(inp)  # Add each element to the list

print(f"List is: {lst}")  # Display the full list

# Ask user what operation they want to perform: get index of value or get value at index
while True:
    choice = input("Do you want to get index(i) or value(v) of list? (i/v): ")
    if choice == 'i' or choice == 'v':
        break  # Exit loop if valid choice is entered
    else:
        print("Enter a valid choice (i/v): ")

# If user chose to get index of a value
if choice == 'i':
    while True:
        val = input("Enter value to get index: ")  # Ask for the value
        if val in lst:
            print(f"Index of {val} is: {lst.index(val)}")  # Display index if found
            break  # Exit loop if value is found
        else:
            print(f"{val} not found in list")  # Message if value is not in the list

# If user chose to get value at an index
elif choice == 'v':
    while True:
        idx_input = input("Enter index to get value: ")  # Ask for index
        if idx_input.isdigit():  # Check if input is a number
            idx = int(idx_input)
            if 0 <= idx < len(lst):
                print(f"Value at index {idx} is: {lst[idx]}")  # Display value if index is valid
                break # Exit loop if index is valid
            else:
                print(f"Invalid index (0-{size-1})")  # Message for out-of-range index
        else:
            print("Please enter a valid number")  # Message for non-numeric input
