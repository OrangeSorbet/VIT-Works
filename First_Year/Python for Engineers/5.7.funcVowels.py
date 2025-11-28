print("This program counts the number of vowels in a given string.")
print("-----------------------------------------------------------")

# Define a function to count vowels in a string
def count_vowels(stri):
    vowels = 'aeiou'  # Define the set of vowels
    stri = stri.lower()  # Convert the string to lowercase for uniform comparison
    count = 0  # Initialize the count of vowels

    # Loop through each character in the string
    for i in stri:
        # Check if the character is a vowel
        for j in vowels:
            if i == j:
                count += 1  # Increment count if a vowel is found

    return count  # Return the total count of vowels

# Get input from the user
stri = input("Enter a string to count vowels - ")

# Display the result
print(f"Number of vowels in '{stri}' is {count_vowels(stri)}")
