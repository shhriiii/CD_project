
THIS COMMAND and CODE WILL WORK IN MACBOOK ONLY NOT FOR WINDOW 

NAME - Shriyansh pandey
ROLL NO - 23115091
SUBJECT- Compiler design

# 🛠️ Compiler Design Project

This is a mini compiler project built for educational purposes. It takes a simple arithmetic expression, performs lexical and syntax analysis, generates intermediate code, and finally simulates assembly code generation. This version is tailored for macOS users.

## 📁 Project Structure

 ├── driver.cpp # Main file to drive compilation ├── scanner.cpp # Lexical analyzer ├── logiccheck.cpp # Syntax and semantic validation ├── treegen.cpp # Parse tree generation ├── midgen.cpp # Intermediate code generator ├── finalgen.cpp # Final assembly code generator ├── simple.asm # Output file (simulated assembly) ├── Makefile # Optional: add for easy compilation


---

## ✅ Features

- ✅ Lexical Analysis
- ✅ Parse Tree Generation
- ✅ Semantic Checks
- ✅ Intermediate Code Generation (Three-Address Code)
- ✅ Final Assembly Simulation (x86-style)

---

## 🚀 Getting Started (macOS)

## 🛠️ Prerequisites

Make sure you have the following installed:

- **Xcode Command Line Tools**
- **Homebrew GCC**

Install them with:

```bash
xcode-select --install
brew install gcc

cd ~/Desktop/CD_Project
g++ driver.cpp scanner.cpp logiccheck.cpp treegen.cpp midgen.cpp finalgen.cpp -o compiler
./compiler

🧩 Run NASM and Generate Executable
bash
Copy
Edit
nasm -f macho32 simple.asm -o simple.o
ld -arch i386 -o simple_exec simple.o -macos_version_min 10.7 -lSystem -e _start
objdump -d simple_exec
Enter the arithmetic expression:
((3 + 4) * (1 + 2)) + ((5 - 2) * (10 + 11))

simple.asm

🧠 How It Works
Lexical Analysis (scanner.cpp)
Breaks the input into tokens.

Logic Checking (logiccheck.cpp)
Verifies expression syntax and validity.

Tree Generation (treegen.cpp)
Builds a parse tree.

Intermediate Code (midgen.cpp)
Converts expression into three-address code.

Final Assembly (finalgen.cpp)
Translates to simulated assembly code


🛠️ Customization
To change the core equation logic, edit:

midgen.cpp → for intermediate code logic.

finalgen.cpp → to adjust simulated assembly instructions.

logiccheck.cpp → to update allowed grammar rules.
