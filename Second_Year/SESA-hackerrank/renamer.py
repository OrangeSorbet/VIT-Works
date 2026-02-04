import os

BASE_DIR = r"C:\Users\ashvi\Documents\VS_Codes\VITWork\Second_Year\SESA-hackerrank"

for contest in os.listdir(BASE_DIR):
    contest_path = os.path.join(BASE_DIR, contest)

    # Skip files like renamer.py
    if not os.path.isdir(contest_path):
        continue

    for filename in os.listdir(contest_path):
        if not filename.endswith(".py"):
            continue

        # Skip already-renamed files
        if filename.startswith(f"{contest}-"):
            continue

        old_path = os.path.join(contest_path, filename)
        new_filename = f"{contest}-{filename}"
        new_path = os.path.join(contest_path, new_filename)

        os.rename(old_path, new_path)
        print(f"Renamed: {contest}/{filename} -> {new_filename}")