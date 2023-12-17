# Infix to Prefix Converter & Evaluator
## Overview
This project, developed as part of the second Data Structure course at Birzeit University, focuses on converting expressions from infix to prefix notation and evaluating the results. The program reads data from an input.txt file, provides a user menu for operation selection, and saves the answers to an output.txt file.
## Features
- Infix to Prefix Conversion: Converts infix expressions to their equivalent prefix notation.
- Expression Evaluation: Computes the result of the converted prefix expressions.
- File Handling: Reads input expressions from input.txt and saves the computed answers to output.txt.
- User Menu: Offers a user-friendly menu interface to choose between conversion and evaluation.
## Getting Started
### Input Format
  The input.txt file should contain infix expressions, each expression represented in a separate line.
### Usage
1. Compile the code: gcc main.c.
2. Run the executable: ./main
3. Follow the on-screen prompts to select the operation:
 - Choose conversion or evaluation.
 - View the results displayed on the console.
4. Check the output.txt file for the saved answers.

### Project Structure
**main.c:** Contains the main logic for user interaction and file handling.
**input.txt:** Contains infix expressions for conversion or evaluation.
**output.txt:** Displays the results of conversion or evaluation.

## Example

```palintext

Please Choose One Of The Following:
1- Read The Input From The File.
2- Check The Validity Of Equations.
3- Convert Valid Equations From Infix To Prefix And Print The Prefix Expressions.
4- Evaluate The Prefix Expressions And Print The Results Of Each Equation.
5- Print Invalid Equations.
6- Print All Equations To A File (output.txt).
7- Exit.

1
DONE!

Please Choose One Of The Following:
1- Read The Input From The File.
2- Check The Validity Of Equations.
3- Convert Valid Equations From Infix To Prefix And Print The Prefix Expressions.
4- Evaluate The Prefix Expressions And Print The Results Of Each Equation.
5- Print Invalid Equations.
6- Print All Equations To A File (output.txt).
7- Exit.

2
a. Equation No. 4 -> Valid
a. Equation No. 3 -> Invalid: There Is No Operator between 4 And [.
a. Equation No. 2 -> Invalid: ( is not closed.
a. Equation No. 1 -> Valid
Please Choose One Of The Following:
1- Read The Input From The File.
2- Check The Validity Of Equations.
3- Convert Valid Equations From Infix To Prefix And Print The Prefix Expressions.
4- Evaluate The Prefix Expressions And Print The Results Of Each Equation.
5- Print Invalid Equations.
6- Print All Equations To A File (output.txt).
7- Exit.

3
a. + + 2 - 14 9 * 4 - + 6 + 7 5  1
d. + 2 - 3 5

Please Choose One Of The Following:
1- Read The Input From The File.
2- Check The Validity Of Equations.
3- Convert Valid Equations From Infix To Prefix And Print The Prefix Expressions.
4- Evaluate The Prefix Expressions And Print The Results Of Each Equation.
5- Print Invalid Equations.
6- Print All Equations To A File (output.txt).
7- Exit.

4
a. Equation No. 4 -> 75
d. Equation No. 1 -> 0

Please Choose One Of The Following:
1- Read The Input From The File.
2- Check The Validity Of Equations.
3- Convert Valid Equations From Infix To Prefix And Print The Prefix Expressions.
4- Evaluate The Prefix Expressions And Print The Results Of Each Equation.
5- Print Invalid Equations.
6- Print All Equations To A File (output.txt).
7- Exit.

5
b. 2+(14-9)+4[6+(8+5)-1]
c. 2+(14-9)+4*[6+(7+5-1]

Please Choose One Of The Following:
1- Read The Input From The File.
2- Check The Validity Of Equations.
3- Convert Valid Equations From Infix To Prefix And Print The Prefix Expressions.
4- Evaluate The Prefix Expressions And Print The Results Of Each Equation.
5- Print Invalid Equations.
6- Print All Equations To A File (output.txt).
7- Exit.

6
DONE!

Out of Memorey!Please Choose One Of The Following:
1- Read The Input From The File.
2- Check The Validity Of Equations.
3- Convert Valid Equations From Infix To Prefix And Print The Prefix Expressions.
4- Evaluate The Prefix Expressions And Print The Results Of Each Equation.
5- Print Invalid Equations.
6- Print All Equations To A File (output.txt).
7- Exit.

7
DONE!
