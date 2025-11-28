print("Keeping record of patients’ medical data, manipulate files to store, update, and delete such information")
print("------------------------------------------------------------------------------------------")

# Class to store patient information
class Patient:
    def __init__(self, name, age, gender, weight, height, room_number):
        self.name = name
        self.age = age
        self.gender = gender
        self.weight = weight
        self.height = height
        self.room_number = room_number

    # String format for saving patient info to a file
    def __str__(self):
        return f"Name - {self.name} | Age - {self.age} | Gender - {self.gender} | Weight - {self.weight} | Height - {self.height} | Room Number - {self.room_number}"

# Add patient data to file
def add_patient(filename, patient):
    with open(filename, 'a') as file:
        file.write(str(patient) + '\n\n')

# Display all patient records
def view_patients(filename):
    with open(filename, 'r') as file:
        patients = file.readlines()
        if not patients:
            print("\nNo patient records found.\n")
            return

        patient_count = 1
        for patient_data in patients:
            if not patient_data.strip():
                continue

            patient_lines = patient_data.strip().split(" | ")
            if len(patient_lines) < 6:
                print(f"Incomplete data: {patient_data.strip()}")
                continue

            name = patient_lines[0].split(" - ")[1]
            age = patient_lines[1].split(" - ")[1]
            gender = patient_lines[2].split(" - ")[1]
            weight = patient_lines[3].split(" - ")[1]
            height = patient_lines[4].split(" - ")[1]
            room_number = patient_lines[5].split(" - ")[1]

            patient = Patient(name, age, gender, weight, height, room_number)

            print(f"\n{'-'*32}")
            print(f"Patient {patient_count}")
            print(f"{'-'*32}")
            print(f"Name - {patient.name}")
            print(f"Age - {patient.age}")
            print(f"Gender - {patient.gender}")
            print(f"Weight(kg) - {patient.weight}")
            print(f"Height(cm) - {patient.height}")
            print(f"Room Number - {patient.room_number}")
            print(f"{'-'*32}\n")
            patient_count += 1

# Delete patient record by name
def delete_patient(filename, name):
    patients_deleted = False
    with open(filename, 'r') as file:
        patients = file.readlines()

    with open(filename, 'w') as file:
        for patient_data in patients:
            if name.lower() in patient_data.lower():
                patients_deleted = True
                continue
            file.write(patient_data)

    if patients_deleted:
        print(f"\nPatient with name {name} has been deleted.\n")
    else:
        print(f"\nNo patient found with name {name}.\n")

# Modify patient record by name
def modify_patient(filename, name):
    patients_modified = False
    with open(filename, 'r') as file:
        patients = file.readlines()

    with open(filename, 'w') as file:
        for patient_data in patients:
            if name.lower() in patient_data.lower():
                patients_modified = True
                print(f"\nModifying patient with name {name}")

                new_name = input("Enter new name (first last) - ").strip()
                while not new_name.replace(" ", "").isalpha():
                    print("Invalid name. Name should only contain alphabetic characters.")
                    new_name = input("Enter new name (first last) - ").strip()
                new_name = format_name(new_name)

                new_age = input("Enter new age (or press Enter to keep current): ") or patient_data.split(" | ")[1].split(" - ")[1]
                while not new_age.isdigit():
                    print("Invalid age. Please enter a valid number.")
                    new_age = input("Enter new age: ")

                new_gender = input("Enter new gender (Male/Female or press Enter to keep current): ").strip().capitalize() or patient_data.split(" | ")[2].split(" - ")[1]
                while new_gender not in ["Male", "Female"]:
                    print("Invalid gender. Please enter 'Male' or 'Female'.")
                    new_gender = input("Enter new gender (Male/Female): ").strip().capitalize()

                new_weight = input("Enter new weight (or press Enter to keep current): ") or patient_data.split(" | ")[3].split(" - ")[1]
                while not new_weight.isdigit():
                    print("Invalid weight. Please enter a valid number.")
                    new_weight = input("Enter new weight (in kg): ")

                new_height = input("Enter new height (or press Enter to keep current): ") or patient_data.split(" | ")[4].split(" - ")[1]
                while not new_height.isdigit():
                    print("Invalid height. Please enter a valid number.")
                    new_height = input("Enter new height (in cm): ")

                new_room_number = input("Enter new room number (or press Enter to keep current): ") or patient_data.split(" | ")[5].split(" - ")[1]
                while not new_room_number.isdigit() or not (101 <= int(new_room_number) <= 505):
                    print("Invalid room number. Please enter a valid room number between 101 and 505.")
                    new_room_number = input("Enter new room number: ")

                updated_patient = Patient(new_name, new_age, new_gender, new_weight, new_height, new_room_number)
                file.write(str(updated_patient) + '\n\n')
            else:
                file.write(patient_data)

    if patients_modified:
        print(f"\nPatient with name {name} has been modified.\n")
    else:
        print(f"\nNo patient found with name {name}.\n")

# Format name to capitalize first letters
def format_name(name):
    return ' '.join([word.capitalize() for word in name.split()])

# Main program loop
def main():
    filename = '6.8.zpatients.txt'

    while True:
        print("\n----------------------------------------")
        print("Vishwakarma Medical Records 2025")
        print("----------------------------------------")
        print("1. Add Patient")
        print("2. Delete Patient")
        print("3. Modify Patient")
        print("4. View Patients")
        print("5. Exit")
        print("----------------------------------------")

        choice = input("Choose your option: ")

        if choice == '1':
            name = input("Enter name (first last) - ").strip()
            while not name.replace(" ", "").isalpha():
                print("Invalid name. Name should only contain alphabetic characters.")
                name = input("Enter name (first last) - ").strip()
            name = format_name(name)

            age = input("Enter age: ")
            while not age.isdigit():
                print("Invalid age. Please enter a valid number.")
                age = input("Enter age: ")

            gender = input("Enter gender (Male/Female): ").strip().capitalize()
            while gender not in ["Male", "Female"]:
                print("Invalid gender. Please enter 'Male' or 'Female'.")
                gender = input("Enter gender (Male/Female): ").strip().capitalize()

            weight = input("Enter weight (in kg): ")
            while not weight.isdigit():
                print("Invalid weight. Please enter a valid number.")
                weight = input("Enter weight (in kg): ")

            height = input("Enter height (in cm): ")
            while not height.isdigit():
                print("Invalid height. Please enter a valid number.")
                height = input("Enter height (in cm): ")

            room_number = input("Enter room number (101-505): ")
            while not room_number.isdigit() or not (101 <= int(room_number) <= 505):
                print("Invalid room number. Please enter a valid room number between 101 and 505.")
                room_number = input("Enter room number: ")

            patient = Patient(name, age, gender, weight, height, room_number)
            add_patient(filename, patient)

        elif choice == '2':
            name = input("Enter the name of the patient to delete: ")
            delete_patient(filename, name)

        elif choice == '3':
            name = input("Enter the name of the patient to modify: ")
            modify_patient(filename, name)

        elif choice == '4':
            view_patients(filename)

        elif choice == '5':
            print("\nExiting... Goodbye!\n")
            break

        else:
            print("\nInvalid choice. Please try again.")

# Start the program
if __name__ == "__main__":
    main()
