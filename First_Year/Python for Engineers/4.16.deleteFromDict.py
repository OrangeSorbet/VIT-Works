print("This program allows you to create a dictionary of student details and modify it by inserting or deleting key-value pairs.")
print("--------------------------------------------------------------------------------------------------------------")

# Initialize the student dictionary
students = {
    "name": "",      # Student's name
    "age": 0,        # Student's age
    "courses": []    # List of courses the student is enrolled in
}

# Collect student details
print("Enter student details: ")
students["name"] = input("Enter name: ")  # Input name
students["age"] = int(input("Enter age: "))  # Input age
students["courses"] = input("Enter courses (comma-separated): ").split(",")  # Input and split courses into a list

# Display the entered details
print("\nStudent details are: ")
print("Name:", students["name"])
print("Age:", students["age"])
print("Courses:", students["courses"])

# Allow user to modify the dictionary
while True:
    # Ask if user wants to insert or delete a key-value pair
    choice = input("\nDo you want to insert or delete any key-value pair in the dictionary? (yes/no): ").strip().lower()
    
    if choice == "no":
        print("Okay bye!")
        break

    elif choice == "yes":
        while True:
            # Ask user to choose between insertion or deletion
            deci = input("Do you want to insert or delete? (insert/delete): ").strip().lower()

            if deci == "insert":
                key = input("Enter key: ").strip()
                value = input("Enter value (for list, separate items with commas): ").strip()

                # Convert to list if value has commas, or to int if numeric
                if "," in value:
                    value = value.split(",")
                elif value.isdigit():
                    value = int(value)

                students[key] = value  # Insert key-value into dictionary
                print("\nUpdated dictionary:", students)
                break

            elif deci == "delete":
                key = input("Enter key to delete: ").strip()
                if key in students:
                    del students[key]  # Delete the key if it exists
                    print("\nUpdated dictionary:", students)
                else:
                    print("Key not found!")  # Key doesn't exist
                break

            else:
                print("Invalid choice! Please enter 'insert' or 'delete'.")  # Invalid insert/delete option

    else:
        print("Invalid input! Please enter 'yes' or 'no'.")  # Invalid yes/no option
