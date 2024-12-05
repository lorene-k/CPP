#!/bin/bash

# Check if exactly 2 arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <path/to/original file> <new class name>"
    exit 1
fi

# Assign arguments to variables
original_file="$1"
new_class_name="$2"

# Extract the directory and filename of the original file
file_dir=$(dirname "$original_file")
file_name=$(basename "$original_file")

# Extract the old class name (filename without extension)
old_class_name="${file_name%.*}"

# Extract the file extension
file_extension="${file_name##*.}"

# Set the new filename with the new class name and the old file extension
new_file="$file_dir/$new_class_name.$file_extension"

# Use sed to replace all occurrences of the old class name with the new one
sed "s#$old_class_name#$new_class_name#g" "$original_file" > "$new_file"

# Notify the user
echo "Created copy: $new_file with class name replaced: $old_class_name -> $new_class_name"
