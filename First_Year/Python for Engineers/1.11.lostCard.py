# Print what the code does
print("This program finds the missing card from a set of cards numbered 1 to N.")
print("It takes as input the total number of cards (N) and the numbers of the remaining cards.")
print("The program will then output the number of the missing card.")

# Print the separator line
print("------------------------------------")

# Importing random module for card simulation
import random

# Taking input for the number of cards
size = int(input("Enter number of cards: "))
cards = []

# Populating the full set of cards with numbers from 1 to N
for i in range(size):
    cards.append(i + 1)

print(cards)  # Display the full list of cards
print("WOOSH, CARD LOST!")

# Initialize an empty list for remaining cards
cardsr = []

# Asking the user to input the remaining cards
print("Enter remaining cards:")

while True:
    try:
        # Ask for a card number
        card = int(input(f"Enter card number (1 to {size}) - "))
        
        # Check if card number is within the valid range
        if card < 1 or card > size:
            print(f"Card number should be between 1 and {size}")
            continue
        
        # Ensure card number isn't entered multiple times
        if card in cardsr:
            print("Card already entered")
            continue
        
        # Append the entered card to the remaining cards list
        cardsr.append(card)
        
        # Stop when the remaining cards list has size-1 cards
        if len(cardsr) == size - 1:
            break
    
    except ValueError:
        # This will run in case of any invalid input (non-integer value)
        for i in range(size - 1):
            cardsr.append(int(input(f"Enter card number (1 to {size}) - ")))

# Sort the remaining cards in ascending order
cardsr.sort()
print("Remaining cards - ", cardsr)

# Find and print the missing card
for card in cards:
    if card not in cardsr:
        print("Missing card is", card)
