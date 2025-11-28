print("This program allows you to create and view a student dictionary.")
print("-------------------------------------------------------------")

# Initialize the dictionary with predefined keys
students = {
    "name": "",
    "age": 0,
    "courses": list([])
}

# Collecting student details
print("Enter student details: ")
students["name"] = str(input("Enter name: "))
students["age"] = int(input("Enter age: "))
students["courses"] = input("Enter courses (separate by space): ").split()

# Display the student details
print("Student details are: ")
print("Name:", students["name"])
print("Age:", students["age"])
print("Courses:", students["courses"])
