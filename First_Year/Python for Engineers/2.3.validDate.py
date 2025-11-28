# This program accepts a date in various formats and checks if it's a valid calendar date.
# It supports formats with "/", ".", "-", and written months like "5th July, 2023".
print("This program accepts a date in various formats and checks if the date is valid based on month and leap year rules.")
print("------------------------------------")

# Take the date input from the user
date = input("Enter date: ")

# Check for different date separators and split accordingly
if "/" in date:
    date = date.split("/")  # Split the date using "/" as delimiter
    day = int(date[0])      # First part is day
    month = int(date[1])    # Second part is month
    year = int(date[2])     # Third part is year
    if(month > 12):         # If month > 12, likely American format (MM/DD/YYYY)
        print("Invalid date! Avoid American format!")
        exit()

elif "." in date:
    date = date.split(".")  # Split using "."
    day = int(date[0])
    month = int(date[1])
    year = int(date[2])
    if(month > 12):
        print("Invalid date! Avoid American format!")
        exit()

elif "-" in date:
    date = date.split("-")  # Split using "-"
    day = int(date[0])
    month = int(date[1])
    year = int(date[2])
    if(month > 12):
        print("Invalid date! Avoid American format!")
        exit()

# Handles formats like "5th July 2023" or "5 July, 2023"
elif " " in date:
    # Remove suffixes like "st", "nd", "rd", "th", and comma
    date = date.replace("st", "").replace("nd", "").replace("rd", "").replace("th", "").replace(",", "").split()
    day = int(date[0])       # First part is day
    month_str = date[1].lower()  # Second part is month (e.g., July -> july)
    year = int(date[2])      # Third part is year

    # Dictionary to convert month names to numbers
    months = {
        "jan": 1, "feb": 2, "mar": 3, "apr": 4, "may": 5, "jun": 6,
        "jul": 7, "aug": 8, "sep": 9, "oct": 10, "nov": 11, "dec": 12
    }

    month_str = month_str[:3]  # Take only first 3 characters to standardize
    if month_str not in months:
        print("Invalid month!")  # Check if valid month abbreviation
        exit()
    else:
        month = months[month_str]  # Get corresponding number

# Fallback if no special character found, still handles text formats
else:
    date = date.replace("st", "").replace("nd", "").replace("rd", "").replace("th", "").replace(",", "").split()
    day = int(date[0])
    month_str = date[1].lower()
    year = int(date[2])
    months = {
        "jan": 1, "feb": 2, "mar": 3, "apr": 4, "may": 5, "jun": 6,
        "jul": 7, "aug": 8, "sep": 9, "oct": 10, "nov": 11, "dec": 12
    }
    month_str = month_str[:3]
    if month_str not in months:
        print("Invalid month!")
        exit()
    else:
        month = months[month_str]

# Check if the extracted month is valid and within range
if month in [1,2,3,4,5,6,7,8,9,10,11,12]:
    
    # Special handling for February (leap year logic)
    if month == 2:
        if year % 4 == 0:  # Leap year check
            if day > 29:
                print(f"Invalid date! It's February!")
            elif day == 29:
                print(f"Valid date! {year} is a leap year!")
            else:
                print("Valid date!")
        else:
            if day > 28:
                print("Invalid date! It's February!")
            else:
                print("Valid date!")

    # Months with 31 days
    elif month in [1,3,5,7,8,10,12]:
        if day > 31:
            print("Invalid date!")
        else:
            print("Valid date!")

    # Months with 30 days
    else:
        if day > 30:
            print("Invalid date!")
        else:
            print("Valid date!")
