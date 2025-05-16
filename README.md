# C-Minus+ Compiler

## Description

This is a compiler for C-Minus+, a simplified subset of C with additional features. 
The compiler takes C-Minus+ source code as input and generates MIPS assembly code as output.

It includes:

- Lexical analysis (using Flex)
- Syntax analysis (using Bison/YACC)
- Abstract Syntax Tree (AST) generation
- Symbol table management
- Type checking
- MIPS assembly code generation

The compiler supports language features such as:

- Integer and void data types
- Global and local variables
- Arrays
- Function definitions and calls
- Control structures (if-else, while)
- Input/output operations (read, write)
- Arithmetic and logical expressions

## Dependencies

- **Flex** (Fast Lexical Analyzer Generator) - for lexical analysis
- **Bison** (GNU Parser Generator) - for syntax analysis
- **GCC** (GNU Compiler Collection) - for compiling C code
- **Java Runtime Environment** - for running the MIPS simulator (Mars4_5.jar)

## Installation

To install the required dependencies on a Debian/Ubuntu system:

```bash
sudo apt-get update
sudo apt-get install flex bison gcc openjdk-11-jre
```

## Usage

### Compiling the Compiler

To build the compiler:

```bash
make
```

### Running the Compiler

To compile a C-Minus+ program:

```bash
./lab9 -o outputname < input_file.c
```

Where:

-   `outputname` is the desired name for the output file (without the `.asm` extension).
-   `input_file.c` is the C-Minus+ source code to compile.

The compiler will generate `outputname.asm`, which contains MIPS assembly code.

### Command-line Options

-   `-o outputname`: Specify the output filename (required)
-   `-d`: Enable debug mode (optional)

### Running the Generated Assembly

To run the generated MIPS assembly code:

```bash
java -jar Mars4_5.jar outputname.asm
```

### Examples

Compile a test program:

```bash
./lab9 -o test < examples/test.c
```

Compile with debug information:

```bash
./lab9 -o test -d < examples/test.c
```

## Project Structure

-   `lab9.l`: Lexical analyzer specification (Flex)
-   `lab9.y`: Parser specification (Bison/YACC)
-   `ast.c/h`: Abstract Syntax Tree implementation
-   `symtable.c/h`: Symbol table management
-   `emit.c/h`: MIPS code generation
-   `examples/`: Sample C-Minus+ programs
-   `Mars4_5.jar`: MIPS assembly simulator
