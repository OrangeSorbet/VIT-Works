print("This program calculates the number of seconds between two timestamps in HH:MM:SS format.")
print("-----------------------------------------------------------------------------------------")

# Function to get and validate a timestamp
def get_valid_timestamp(prompt):
    while True:
        time = input(prompt).split(":")
        if len(time) != 3:
            print("Invalid timestamp, use 24 hour format")
            continue

        if not (time[0].isdigit() and time[1].isdigit() and time[2].isdigit()):
            print("Invalid timestamp, use 24 hour format")
            continue

        h, m, s = int(time[0]), int(time[1]), int(time[2])

        if h < 0 or h >= 24 or m < 0 or m >= 60 or s < 0 or s >= 60:
            print("Invalid timestamp, use 24 hour format")
        else:
            return h, m, s

# Get valid timestamps from the user
h1, m1, s1 = get_valid_timestamp("Enter timestamp 1 (HH:MM:SS): ")
h2, m2, s2 = get_valid_timestamp("Enter timestamp 2 (HH:MM:SS): ")

# Convert both timestamps to total seconds
t1_seconds = h1 * 3600 + m1 * 60 + s1
t2_seconds = h2 * 3600 + m2 * 60 + s2

# Calculate the difference
seconds_between = abs(t2_seconds - t1_seconds)

# Output result
print(f"Seconds between timestamps: {seconds_between} seconds")
print("-----------------------------------------------------------------------------------------")
