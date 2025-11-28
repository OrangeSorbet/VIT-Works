import string

# This program manages student records for Vishwakarma Institute of Technology, Pune.
# It allows adding, viewing, deleting, and modifying student records.
# define the Student class to represent a student

print("To keep record of students’ data, manipulate files to store, update, and delete students’ information")
class Student:
    def __init__(self, name, student_class, division, roll_no, prn_no):
        self.name = name
        self.student_class = student_class
        self.division = division
        self.roll_no = roll_no
        self.prn_no = prn_no

    def __str__(self):
        return f"Name - {self.name} | Stream - {self.student_class} | Division - {self.division} | Roll Number - {self.roll_no} | PRN Number - {self.prn_no}"

# Function to add a student to the file
def add_student(filename, student):
    with open(filename, 'a') as file:
        file.write(str(student) + '\n\n')

# Function to view all students in the file
def view_students(filename):
    with open(filename, 'r') as file:
        students = file.readlines()
        if not students:
            print("\nNo student records found.\n")
            return
        
        # Print the header
        student_count = 1
        for student_data in students:
            # Ignore empty lines
            if student_data.strip() == '':
                continue
            
            # Split the student data into individual fields
            student_lines = student_data.strip().split(" | ")
            if len(student_lines) != 5:
                print(f"Incomplete data: {student_data}")
                continue

            try:
                name = student_lines[0].split(" - ")[1]
                student_class = student_lines[1].split(" - ")[1]
                division = student_lines[2].split(" - ")[1]
                roll_no = student_lines[3].split(" - ")[1]
                prn_no = student_lines[4].split(" - ")[1]
                
                print(f"\n{'-'*32}")
                print(f"Student {student_count}")
                print(f"{'-'*32}")
                print(f"Name - {name}")
                print(f"Stream - {student_class}")
                print(f"Division - {division}")
                print(f"Roll Number - {roll_no}")
                print(f"PRN Number - {prn_no}")
                print(f"{'-'*32}\n")
                student_count += 1
            except IndexError:
                print(f"Error parsing student data: {student_data}")
                continue

# Function to delete a student from the file
def delete_student(filename, prn_no):
    students_deleted = False
    with open(filename, 'r') as file:
        students = file.readlines()
    
    with open(filename, 'w') as file:
        for student_data in students:
            if prn_no in student_data:
                students_deleted = True
                continue  # Skip the student with the matching PRN number
            file.write(student_data)
    
    # Check if any student was deleted
    if students_deleted:
        print(f"\nStudent with PRN {prn_no} has been deleted.\n")
    else:
        print(f"\nNo student found with PRN {prn_no}.\n")

# Function to modify a student's details
def modify_student(filename, prn_no):
    students_modified = False
    with open(filename, 'r') as file:
        students = file.readlines()
    
    # Check if the file is empty
    with open(filename, 'w') as file:
        for student_data in students:
            if prn_no in student_data:
                students_modified = True
                print(f"\nModifying student with PRN {prn_no}")
                
                # Ask for new details
                name = input("Enter new name (first last) - ").strip()
                name = format_name(name)  # Apply name formatting
                student_class = input("Enter new stream (or press Enter to keep current): ") or student_data.split(" | ")[1].split(" - ")[1]
                division = input("Enter new division (or press Enter to keep current): ") or student_data.split(" | ")[2].split(" - ")[1]
                roll_no = input("Enter new roll number (or press Enter to keep current): ") or student_data.split(" | ")[3].split(" - ")[1]
                
                # Validate new PRN number
                new_prn_no = input("Enter new PRN number: ")
                while not new_prn_no.isdigit() or len(new_prn_no) != 8:
                    print("Invalid PRN number. Please enter a valid number with exactly 8 digits.")
                    new_prn_no = input("Enter new PRN number: ")

                # Update student details
                updated_student = Student(name, student_class, division, roll_no, new_prn_no)
                file.write(str(updated_student) + '\n\n')
            else:
                file.write(student_data)
    
    # Check if any student was modified
    if students_modified:
        print(f"\nStudent with PRN {prn_no} has been modified.\n")
    else:
        print(f"\nNo student found with PRN {prn_no}.\n")

def format_name(name):
    # Capitalize first letter of each word
    return ' '.join([word.capitalize() for word in name.split()])

def main():
    filename = '6.1.students.txt'
    sclass = ['CS', 'AIDS', 'CSAI', 'CSAIML', 'CSSE', 'CSIOT', 'CSDS', 'EnTC', 'IT', 'Instru', 'Mech', 'Chem', 'Civil']
    
    while True:
        print("\n----------------------------------------")
        print("Vishwakarma Student Records 2025")
        print("----------------------------------------")
        print("1. Add Students")
        print("2. Delete Students")
        print("3. Modify Students")
        print("4. View Students")
        print("5. Exit")
        print("----------------------------------------")
        choice = input("Choose your option: ")
        
        if choice == '1':
            name = input("Enter name (first last) - ").strip()
            name = format_name(name)  # Apply name formatting
            student_class = input("Enter class (CS, AIDS, CSAI, CSAIML, CSSE, CSIOT, CSDS, EnTC, IT, Instru, Mech, Chem, Civil): ")
            
            while student_class not in sclass:
                print("Invalid class. Please try again.")
                student_class = input("Enter class (CS, AIDS, CSAI, CSAIML, CSSE, CSIOT, CSDS, EnTC, IT, Instru, Mech, Chem, Civil): ")
                
            division = input("Enter division (A-C): ")
            division = division.upper()
            
            roll_no = input("Enter roll number: ")
            while not roll_no.isdigit():
                print("Invalid roll number. Please enter a valid number.")
                roll_no = input("Enter roll number: ")

            prn_no = input("Enter PRN number: ")
            while not prn_no.isdigit() or len(prn_no) != 8:
                print("Invalid PRN number. Please enter a valid number with exactly 8 digits.")
                prn_no = input("Enter PRN number: ")
            
            student = Student(name, student_class, division, roll_no, prn_no)
            add_student(filename, student)
        
        elif choice == '2':
            prn_no = input("Enter the PRN number of the student to delete: ")
            delete_student(filename, prn_no)
        
        elif choice == '3':
            prn_no = input("Enter the PRN number of the student to modify: ")
            modify_student(filename, prn_no)
        
        elif choice == '4':
            view_students(filename)
        
        elif choice == '5':
            print("\nExiting... Goodbye!\n")
            break
        
        else:
            print("\nInvalid choice. Please try again.")

if __name__ == "__main__":
    main()
