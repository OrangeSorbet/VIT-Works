print("This program reverses a sequence of numbers entered by the user.")
print("------------------------------------------------------------")

# Define a recursive function to reverse the sequence
def rev():
    num = int(input())  # Prompt the user to enter a number
    if num != 00:  # Check if the number is not '00' (to end the sequence)
        rev()  # Recursive call to continue the sequence
        print(num)  # Print the number after the recursive calls

# Inform the user on how to enter numbers and end the sequence
print("Enter a number and press enter each time. Enter '00' to end the sequence.")
rev()  # Start the recursive sequence
print("End of sequence")  # End message after the sequence is finished
