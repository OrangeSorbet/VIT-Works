print("This program checks if one of the given lists is empty or not.")
print("-------------------------------------------------------------")

def check():
    choice = int(input())  # User chooses which list to check
    if choice == 1:
        size = len(lst)  # Get size of lst
        if size == 0:
            print(f"Yes! {lst} is empty")  # If size is 0, it's empty
        else:
            print(f"No! {lst} is not empty")  # Otherwise, not empty
    elif choice == 2:
        size = len(lst2)  # Get size of lst2
        if size == 0:
            print(f"Yes! {lst2} is empty")  # If size is 0, it's empty
        else:
            print(f"No! {lst2} is not empty")  # Otherwise, not empty
    else:
        print("Invalid choice! Try again (1/2): ", end="")  # Prompt again if invalid input
        check()  # Recursive call

# Predefined lists (CAN BE MODIFIED)
lst = [0, 2, 3, 4, 5]
lst2 = []

print("I want to see if the size of list is 0 or not")
print(f"The prebuilt lists are: list1 {lst} and list2 {lst2}")
print("Which one is empty? (1/2): ")
check()
