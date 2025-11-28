print("This program finds the largest number in a list using max() and also from a sorted list.")
print("-------------------------------------------------------------")

size = int(input("Enter size of list: "))  # Ask user for list size
print("Enter numbers in list: ")
lst = []

for i in range(size):
    lst.append(int(input(f"Enter number {i+1}: ")))  # Take list elements as input

print(f"List is: {lst}")
print(f"Largest number in list (by max) is: {max(lst)}")  # Using max() to get largest

lst.sort(reverse=True)  # Sort list in descending order
print(f"Largest number in descending sorted {lst} is: {lst[0]}")  # First element is largest
