# Print what the code does
print("This program calculates the angles of the hour and minute hands on a clock based on the input time.")
print("It takes input in HH:MM:SS format (24-hour format) and determines the angle of the hour hand, minute hand, and the angle between them.")

# Print the separator line
print("------------------------------------")

# Prompt user for time input
time = input("Enter time in HH:MM:SS format (24-hour format) - ")
time = time.split(":")
hour = int(time[0])
minute = int(time[1])
second = int(time[2]) if len(time) > 2 else 0

# Ensure hour is between 0-23, minute between 0-59, and second between 0-59
if hour < 0 or hour >= 24 or minute < 0 or minute >= 60 or second < 0 or second >= 60:
    print("Invalid time entered")
else:
    # Convert the hour to a 12-hour format for angle calculations
    hour = hour % 12

    # Calculate the angle of the hour hand (relative to the 12 marking)
    hourdeg = (hour * 30) + (minute * 0.5) + (second * (0.5 / 60))
    
    # Output the angle of the hour hand
    print("Angle of hour hand (relative to 12 marking) is", hourdeg, "degrees")

    # Calculate the angle of the minute hand (relative to the 12 marking)
    minute_deg = minute * 6 + second * 0.1  # Minute hand angle

    # Output the angle of the minute hand
    print("Angle of minute hand (relative to 12 marking) is", minute_deg, "degrees")

    # Calculate the angle between the hour and minute hands
    angle_between = abs(hourdeg - minute_deg)
    if angle_between > 180:
        angle_between = 360 - angle_between
    
    print("Angle between hour and minute hand is", angle_between, "degrees")
