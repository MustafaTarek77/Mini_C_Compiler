# Mini C Compiler

This project is a compiler for a language similar to C built using **Flex**, **Bison**, and **GCC** for lexical, syntax, and semantic analysis. A Python GUI built with **Tkinter** is also provided for user-friendly interaction.

---

## Prerequisites

Make sure the following dependencies are installed on your Ubuntu system:

### For Terminal-Based Compilation:
- `flex`
- `bison`
- `gcc`

Install them with:
```bash
sudo apt update
sudo apt install flex bison gcc
````

### For GUI-Based Compilation:

* `python3`
* `tkinter` (Python GUI library)

Install with:

```bash
sudo apt install python3 python3-tk
```

---

##  How to Run the Compiler

### 1️⃣ Run from the Terminal

1. Open a terminal.
2. Navigate to the project directory.
3. Run the build script:

   ```bash
   ./build.sh
   ```
4. This will build and execute the compiler in the terminal.

---

### 2️⃣ Run with the GUI

1. Ensure Python and Tkinter are installed.
2. Open a terminal and run:

   ```bash
   python3 gui.py
   ```
3. The application window will launch.
4. Paste or write your code in the editor and click **Compile**.

---

## Output Directory

After compiling, the following files will be generated in the `output/` folder:

*  `errors.txt` – Compilation errors
*  `warnings.txt` – Warnings
*  `tokens.txt` – List of tokens
*  `symbol_table.txt` – Symbol table entries
*  `quadruples.txt` – Intermediate code (quadruples)

Use these files to review and debug your code.

---

## File Structure

```
project-root/
├── build.sh          # Build and run script
├── gui.py            # Python GUI frontend
├── output/           # Output folder (tokens, errors, etc.)
└── README.md         # This file
```

---
