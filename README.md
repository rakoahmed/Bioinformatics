# Bioinformatics
Tools for DNA sequence analysis in C, featuring base pair validation, sequence manipulation, and protein translation functions.

# DNA Sequence Analysis in C

This repository contains a C program for analyzing and manipulating DNA sequences. The program includes various functionalities such as checking base pairs, determining if a sequence is a valid DNA sequence, reversing sequences, finding complements, checking for palindromes, counting occurrences of specific characters, and translating DNA to mRNA.

## Features

- **Base Pair Checking**: Determines if two nucleotides form a valid base pair.
- **DNA Sequence Validation**: Checks if a given string represents a valid DNA sequence.
- **Sequence Reversal**: Reverses a given DNA sequence.
- **Finding Complements**: Generates the complement of a DNA sequence.
- **Palindrome Checking**: Determines if a DNA sequence is a palindrome.
- **Character Counting**: Counts occurrences of a specific character in a DNA sequence.
- **DNA to mRNA Translation**: Converts a DNA sequence to its corresponding mRNA sequence.
- **Protein Translation**: Translates DNA sequences into mRNA proteins.

## Files

- `main(testCases).c`: Contains the `main` function with test cases for the various functionalities.
- `functionDefinitions.c`: Includes the definitions of all the functions used in the program.

## Usage

To use the program:

1. Clone the repository to your local machine.
2. Compile the C files using a C compiler like GCC.
3. Run the resulting executable to see the test cases in action.

```sh
gcc -o dna_analysis main(testCases).c functionDefinitions.c
./dna_analysis
