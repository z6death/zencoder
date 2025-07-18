Symbolic Encoder

This program encodes a given input text into a symbolic representation using two layers of encoding and writes the result to an output file. It is designed in C++ and can be executed via a shell script named run.sh.
🔧 Features

    First-layer encoding: Replaces each character (a-z, 0-9, and space) with a symbolic pattern using shapes like ⬤, ▲, ■, and ⎔.

    Second-layer encoding: Transforms those symbols into more visually distinct ASCII representations like [], /_\, |_|_, etc.

    Output is saved to a file named output.txt.

📂 File Structure

.
├── run.sh          # Shell script to compile and run the program
├── main.cpp        # Source code (the C++ program)
├── input.txt       # Input file with the original text
├── convert.txt     # Intermediate encoded file (first layer)
└── output.txt      # Final encoded output (after second layer)

▶️ How to Run

    Make sure run.sh is executable:

chmod +x run.sh

Add your input to input.txt.

Run the script:

    ./run.sh

    Check output.txt for the final result.

🧠 How It Works
main.cpp

    encode(...): Converts characters in input.txt to symbolic representations and stores the result in convert.txt.

    output(...): Converts symbols in convert.txt to more distinct representations and stores the final output in output.txt.

run.sh

Compiles main.cpp and runs the resulting executable.

Example run.sh:

#!/bin/bash
g++ main.cpp -o encoder && ./encoder

📌 Notes

    Only supports lowercase characters; uppercase letters are converted to lowercase.

    Unsupported characters may cause errors or be skipped.

    Intermediate file convert.txt is created automatically; you can inspect it to see the first encoding layer.

📝 Example

input.txt:

hello 123

output.txt (after processing):

[][]|_|_|_|_ |_|_ []/_\[]/_\/_\/_\<>|/\|\/[]|/\|\/|/\|\/

