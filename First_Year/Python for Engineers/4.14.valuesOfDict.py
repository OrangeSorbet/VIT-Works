print("This program allows you to store student details in a dictionary and view them as needed.")
print("-------------------------------------------------------------")

# Initialize the dictionary with default values
students = {
    "name": "",       # Stores the student's name
    "age": 0,         # Stores the student's age
    "courses": []     # Stores a list of courses the student is enrolled in
}

# Get student details from user input
print("Enter student details: ")
students["name"] = input("Enter name: ")  # Input for name
students["age"] = int(input("Enter age: "))  # Input for age (converted to integer)
students["courses"] = input("Enter courses (separate with spaces): ").split()  # Split input into a list of courses

# Start a loop to allow viewing specific details
while True:
    print("Which detail do you want to view? (name/age/course/exit): ")  # Prompt user for detail to view
    choice = input().lower()  # Convert choice to lowercase for consistency

    # Show corresponding detail based on user input
    if choice == "name":
        print("Name:", students["name"])
    elif choice == "age":
        print("Age:", students["age"])
    elif choice == "course":
        print("Courses:", ", ".join(students["courses"]))  # Join list items with commas for display
    elif choice == "exit":
        print("Exiting...")  # Exit the loop and program
        break
    else:
        print("Invalid choice. Please choose again.")  # Handle invalid input
        continue

    # Ask user if they want to continue viewing more details
    more = input("Do you want to view more details? (yes/no): ").lower()
    if more != "yes":
        print("Exiting...")  # Exit the loop if user doesn't want to continue
        break
