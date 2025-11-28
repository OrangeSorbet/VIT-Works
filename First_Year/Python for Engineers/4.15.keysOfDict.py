print("This program creates a dictionary to store student details and displays its keys.")
print("-------------------------------------------------------------")

# Initialize the dictionary with keys for student details
students = {
    "name": "",         # To store the student's name
    "age": 0,           # To store the student's age
    "courses": list([]) # To store a list of enrolled courses
}

# Get input from the user and update dictionary values
print("Enter student details: ")
students["name"] = str(input("Enter name: "))                      # Input for name
students["age"] = int(input("Enter age: "))                        # Input for age
students["courses"] = input("Enter courses (separated by spaces): ").split()            # Input courses, split into list

# Display the full dictionary
print("Student details are: ")
print("Name:", students["name"])
print("Age:", students["age"])
print("Courses:", students["courses"])

# Display the keys of the dictionary
print("Keys of dictionary are:", students.keys())
