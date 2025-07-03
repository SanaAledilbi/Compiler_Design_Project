# Compiler Design Project

This project was developed step by step as part of my learning journey in the Compiler Design course (CS224), during my **3rd year, Spring 2025** at Qassim University.  
It simulates the front-end of a basic compiler through multiple phases — from parsing to code generation — each reflecting a new concept learned in class.  
The implementation was done in **C language**, on **Windows 11**, using **Microsoft Visual Studio** as the IDE.

---

## 🧩 Project Overview

The project consists of four main phases:

### 📌 Phase 1 – Postfix Expression to Intermediate Language
- Parses postfix expressions.
- Converts them to a simple Intermediate Language (IL).
- Each file in this phase is standalone and contains its own `main()` function.
- ✅ To run a specific file, comment out other `main()` definitions.

### 📌 Phase 2 – Input Handling
- Adds support for number recognition and whitespace ignoring.
- Also uses independent `main()` files.
- ✅ Follow the same rule as Phase 1: comment out other `main()`s before running.

### 📌 Phase 3 – Core Compiler Logic
- Introduces lexical analysis, parsing, semantic checks, and symbol table handling.
- Includes a centralized `main.c` file to drive the compilation process.
- Generates object code files (`.obj`) and error logs (`.err`, `.exp`).

### 🖼️ Phase 3 Example

Input:
![Input Example](images/phase3_input.png)

Output:
![Output Example](images/phase3_output.png)

### 📌 Phase 4 – Code Generation
- Divided into:
  - **Phase 4a**: Basic code generation output.
  - **Phase 4b**: Improved version with optimizations.
- Both phases include full compiler flow and output files for testing.

### 🖼️ Phase 4b Example

Input:
![Input Example](images/phase4b_input.png)

Output:
![Output Example](images/phase4b_output.png)

---

## 🗂️ Folder Structure

CompilerDesign_Project/
  ├── phase1_postfix_IL/
  ├── phase2_input_handling/
  ├── phase3_compiler_core/
  ├── phase4a_codegen_basic/
  ├── phase4b_codegen_optimized/

---

## ▶️ How to Run

**For Phase 1 and 2:**  
Each file has its own `main()` function. To run a specific one, make sure only that file's `main()` is active, and comment out others.

**For Phase 3 and 4:**  
1. Open the project in Visual Studio.  
2. Make sure `main.c` is set as the entry point.  
3. Build the project and run the output.  
4. Input can be provided via file or manually, depending on the implementation.

- - -

## 🙋‍♀️ About Me

- **Name:** Sana Aledilbi  
- **University:** Qassim University  
- **Major:** Bachelor's in Computer Science
-  **Year:** 3rd Year – Spring 2025
