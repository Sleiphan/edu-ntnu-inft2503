# Check if the correct number of arguments are provided
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 EXERCISE_NUM"
  exit 1
fi

# Assign the argument to EXERCISE_NUM and check if it's a number
EXERCISE_NUM="$1"

if ! [[ "$EXERCISE_NUM" =~ ^[0-9]+$ ]]; then
  echo "Error: EXERCISE_NUM must be a number."
  exit 1
fi

# Check if the directory exists
EXERCISE_DIR="Exercise_$EXERCISE_NUM"
if [ ! -d "$EXERCISE_DIR" ]; then
  echo "Error: Directory $EXERCISE_DIR does not exist."
  exit 1
fi

# Define variables
SOURCE_DIR="."
DEST_TARBALL="oving$EXERCISE_NUM.tar.gz"
INTERNAL_DIR="edu-ntnu-inft2503"

# Create a temporary directory
TEMP_DIR=$(mktemp -d)
mkdir "$TEMP_DIR/$INTERNAL_DIR"

# Copy specific files into the temporary directory
cp "$SOURCE_DIR/README.md" "$TEMP_DIR/$INTERNAL_DIR/"
cp "$SOURCE_DIR/CMakeLists.txt" "$TEMP_DIR/$INTERNAL_DIR/"
cp "$SOURCE_DIR/.gitignore" "$TEMP_DIR/$INTERNAL_DIR/"
cp "$SOURCE_DIR/.devcontainer" "$TEMP_DIR/$INTERNAL_DIR/" -r
cp "$SOURCE_DIR/.vscode" "$TEMP_DIR/$INTERNAL_DIR/" -r
cp "$SOURCE_DIR/$EXERCISE_DIR" "$TEMP_DIR/$INTERNAL_DIR/" -r

# Process the copied CMakeLists.txt
CMAKE_FILE="$TEMP_DIR/$INTERNAL_DIR/CMakeLists.txt"
if [ -f "$CMAKE_FILE" ]; then
  # Remove lines starting with add_subdirectory(Exercise_
  awk '!/^add_subdirectory\(Exercise_/' "$CMAKE_FILE" > "$CMAKE_FILE.tmp"
  # Append the new line
  echo "add_subdirectory($EXERCISE_DIR)" >> "$CMAKE_FILE.tmp"
  # Replace the original file with the modified one
  mv "$CMAKE_FILE.tmp" "$CMAKE_FILE"
else
  echo "Error: Copied CMakeLists.txt does not exist."
  exit 1
fi

# Create the tarball with files in the desired internal directory
tar -czf "$DEST_TARBALL" -C "$TEMP_DIR" "$INTERNAL_DIR"

# Clean up the temporary directory
rm -rf "$TEMP_DIR"