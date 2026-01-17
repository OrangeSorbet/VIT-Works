import os
import subprocess

# Group files by assignment number (e.g., Assignment_1-1.cpp -> Assignment 1)
cpp_files = sorted([f for f in os.listdir('.') if f.endswith('.cpp')])
assignments = {}

for file in cpp_files:
    base = file.split('-')[0]  # e.g., "Assignment_1"
    assignments.setdefault(base, []).append(file)

# Display main menu
print("Select an assignment:\n")
for i, key in enumerate(assignments.keys(), start=1):
    print(f"{i}. {key}")

assign_choice = int(input("\nEnter assignment number: "))

if 1 <= assign_choice <= len(assignments):
    chosen_key = list(assignments.keys())[assign_choice - 1]
    parts = assignments[chosen_key]
    
    # Display parts menu
    print(f"\nSelect part of {chosen_key}:\n")
    for j, part in enumerate(parts, start=1):
        print(f"{j}. {part}")
    
    part_choice = int(input("\nEnter part number: "))
    
    if 1 <= part_choice <= len(parts):
        filename = parts[part_choice - 1]
        output = filename.replace('.cpp', '')
        os.system(f"g++ {filename} -o {output}")
        print(f"\n--- Running {filename} ---\n")
        subprocess.run([f"./{output}"])
    else:
        print("Invalid part number.")
else:
    print("Invalid assignment number.")
