import os

root_dir = 'D:\\G-Drive'

for root, dirs, files in os.walk(root_dir):
    i = 1
    for file in files:
        old_path = os.path.join(root, file)
        new_path = os.path.join(root, f"{str(i).zfill(3)}{os.path.splitext(file)[1]}")
        os.rename(old_path, new_path)
        i += 1