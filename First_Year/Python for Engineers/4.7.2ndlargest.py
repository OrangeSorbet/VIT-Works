print("This program finds the second largest number in a list after sorting it in descending order.")
print("-------------------------------------------------------------")

size = int(input("Enter size of list: "))  # Get the size of the list from user
print("Enter numbers in list: ")
lst = []

for i in range(size):
    lst.append(int(input(f"Enter number {i+1}: ")))  # Append input numbers to the list

print(f"List is: {lst}")

lst.sort(reverse=True)  # Sort the list in descending order
print(f"Second largest number in descending sorted {lst} is: {lst[1]}")  # Display second largest number
print(f"Second largest number using max function: {max([x for x in lst if x != max(lst)])}")  # Display second largest number