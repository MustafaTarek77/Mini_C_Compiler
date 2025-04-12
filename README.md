# Mini C Compiler Parser

This project is a **mini C-like compiler frontend** that uses **Flex** and **Bison** to parse a subset of the C language, including variable declarations, expressions, control flow statements (`if`, `while`, `switch`, etc.), function definitions, and more.

---

## 🛠️ Requirements

Make sure the following tools are installed on your system:

- `flex` (Fast lexical analyzer generator)
- `bison` (Parser generator)
- `gcc` (GNU Compiler Collection)

Install them (if needed) on Ubuntu-based systems using:

```bash
sudo apt update
sudo apt install flex bison gcc
```

---

## 🚀 How to Compile and Run

Follow these steps to build and run the parser:

1. **Generate the lexer file using Flex:**

   ```bash
   flex Lexer.l
   ```

2. **Generate the parser files using Bison:**

   ```bash
   bison -d Parser.y
   ```

3. **Compile the generated C files using GCC:**

   ```bash
   gcc Parser.tab.c lex.yy.c -o mini-c-compiler -lfl
   ```

4. **Run the compiler with an input file:**

   ```bash
   ./mini-c-compiler < input.txt
   ```

---