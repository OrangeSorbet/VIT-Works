print("This program greets the user with a personalized message.")
print("------------------------------------------------------------")

# Define a function to greet the user
def greet_user(name):
    print(f"Good morning {name}! We hope you have a great day ahead!")  # Personalized greeting

# Get input from the user (no validation)
name = input("Enter your name/username - ").title() # Title case for better formatting

# Call the function to greet the user
greet_user(name)
