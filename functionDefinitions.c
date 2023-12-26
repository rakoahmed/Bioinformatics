#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 100
#define NUMPROTEINS 64

/* ------ All Function Prototypes ------*/
bool isBasePair (char neu1, char neu2);
bool isItaDnaSequence (char neuSt1 [SIZE], char neuSt2 [SIZE]);
void reverse (char givenStrand [SIZE]);
void complementIt (char aStrand [SIZE]);
bool isItPalindrome (char aStrand [SIZE]);
bool isStrandDnaPalindrome (char aStrand [SIZE]);
int howMany (char [SIZE], char);
void dnaToMrna (char aStrand [SIZE], char mRNA [SIZE]);
void translateDnaToMrnaProteins(char aSeq [SIZE]);
char getCode(char protein[3]);
/* ------------------------------------- */


/*------- FUNCTION #1 -------*/
/* isBasePair will check if the two provided nucleotides (neu1 and neu2) form a valid base pair in DNA.*/ 
// - Adenine (A) pairs with Thymine (T)
// - Guanine (G) pairs with Cytosine (C)
bool isBasePair (char neu1, char neu2) {
   if ((neu1 == 'A' && neu2 == 'T') || (neu1 == 'T' && neu2 == 'A')) {
        return true;
   }
   
   if ((neu1 == 'G' && neu2 == 'C') || (neu1 == 'C' && neu2 == 'G')) {
        return true;
   }
   
   return false;
}

/*------- FUNCTION #2 -------*/
/* isItaDnaSequence will take two strands and check whether they form a valid DNA sequence 
by validating that each pair of nucleotides from 'strand1' and 'strand2' forms a valid base pair.
*/ 
bool isItaDnaSequence(char strand1[SIZE], char strand2[SIZE]) {
   for (int i = 0; strand1[i] != '\0' && strand2[i] != '\0'; i++) {
      if (!isBasePair(strand1[i], strand2[i])) {
         return false; // If any nucleotide pair doesn't form a valid base pair, return false
      }
   }
   return true; // All nucleotide pairs form valid base pairs
}

/*------- FUNCTION #3 -------*/
/* reverse works by iterating from both ends of the string 'aStrand' and swapping the characters 
until it reaches the middle of the string; then, it reverses the string.
*/
void reverse (char aStrand [SIZE]) {
   int length = strlen(aStrand); // Get the length of the strand
   int i, j;
   char temp;

   for (i = 0, j = length - 1; i < j; i++, j--) {
      // Swap characters
      temp = aStrand[i];
      aStrand[i] = aStrand[j];
      aStrand[j] = temp;
   }
}

/*------- FUNCTION #4 -------*/
/*In this function, we loop through each nucleotide 
of the input strand and use a switch statement to replace it with its complement.*/
/*
* Adenine (A) with Thymine (T)
* Thymine (T) with Adenine (A)
* Cytosine (C) with Guanine (G)
* Guanine (G) with Cytosine (C)
*/
void complementIt(char aStrand[SIZE]) {
   for (int i = 0; i < strlen(aStrand); i++) {
      switch (aStrand[i]) {
         case 'A':
            aStrand[i] = 'T';
            break;
         case 'T':
            aStrand[i] = 'A';
            break;
         case 'C':
            aStrand[i] = 'G';
            break;
         case 'G':
            aStrand[i] = 'C';
            break;
         default:
            // Printing an error message:
            printf("Error: Unexpected character '%c' at position %d.\n", aStrand[i], i);

            // Exiting the program:
            // exit(EXIT_FAILURE);
            break;
      }
   }
}

/*------- FUNCTION #5 -------*/
// Checks if the given strand is a palindrome and returns a boolean result.
bool isItPalindrome (char aStrand [SIZE]) {
   int length = strlen(aStrand);
   for (int i = 0; i < length / 2; i++) {
      if (aStrand[i] != aStrand[length - 1 - i]) {
         return false;
      }
   }
   return true;
}

/*------- FUNCTION #6 -------*/
// - Checks if the given DNA strand forms a dna_palindrome.
// - param aStrand: The DNA strand to be checked.
bool isStrandDnaPalindrome(char aStrand[SIZE]) {
   char complementedStrand[SIZE];
   strcpy(complementedStrand, aStrand); // Copying the original strand to the complemented strand

   complementIt(complementedStrand); // Getting the complemented version

   int length = strlen(aStrand);
   for (int i = 0; i < length; i++) {
      if (aStrand[i] != complementedStrand[length - 1 - i]) {
         return false;
      }
   }
   return true;
}

/*------- FUNCTION #7 -------*/
// Counts and returns the total occurrences of a specific nucleotide in a DNA strand.
int howMany(char aStrand[SIZE], char neu) {
   int count = 0;
   for (int i = 0; i < strlen(aStrand); i++) {
      if (aStrand[i] == neu) {
         count++;
      }
   }
   return count;
}

/*------- FUNCTION #8 -------*/
// Converts a given DNA strand into its corresponding mRNA strand.
void dnaToMrna(char aSeq[SIZE], char mRNA[SIZE]) {
   int length = strlen(aSeq);
   for (int i = 0; i < length; i++) {
      switch (aSeq[i]) {
         case 'A':
            mRNA[i] = 'U';
            break;
         case 'T':
            mRNA[i] = 'A';
            break;
         case 'C':
            mRNA[i] = 'G';
            break;
         case 'G':
            mRNA[i] = 'C';
            break;
         default:
            printf("Error: Unexpected character '%c' at position %d.\n", aSeq[i], i);
            break;
      }
   }
   mRNA[length] = '\0';  // Ensure the mRNA string is null-terminated
}


// /*------- FUNCTION #9 -------*/
/*
Converts a given DNA strand into its corresponding mRNA strand and prints
the list of amino acids that the mRNA translates to using the getCode function.
*/
void translateDnaToMrnaProteins(char aSeq[SIZE]) {
   char mRNA[SIZE];
   dnaToMrna(aSeq, mRNA);  

   printf("DNA: %s\n", aSeq);
   printf("mRNA: %s, which translates to:\n", mRNA);

   for (int i = 0; i < strlen(mRNA) - 2; i += 3) { // Iterate in triplets
      char protein[4];  // To store the 3-letter nucleotide plus a null terminator
      strncpy(protein, &mRNA[i], 3);
      protein[3] = '\0';  // Null-terminate the string
      char code = getCode(protein);  // Get the single-letter code

      printf("%s : %c\n", protein, code);
      if (code == 'Z') {
         printf("The input sequence has an incorrect base.\n");
         break;  // If an incorrect base is found, we break out of the loop
      }
   }

}

// /*------- FUNCTION #getCode() -------*/
char getCode (char protein [3]) {
   // array allProteins has a list of all 3-triplet amino acids required for this assignment
   char allProteins [NUMPROTEINS][SIZE] = {"GCA", "GCC", "GCG", "GCU", "AGA", "AGG", "CGA", "CGC","CGG","CGU","GAC", "GAU","AAC","AAU","UGC","UGU","GAA","GAG","CAA","CAG", "GGA", "GGC","GGG","GGU","CAC", "CAU","AUA","AUC","AUU", "UUA", "UUG","CUA","CUC", "CUG", "CUU", "AAA", "AAG","AUG", "UUC","UUU", "CCA", "CCC", "CCG", "CCU", "AGC","AGU","UCA","UCC","UCG", "UCU","ACA","ACC","ACG", "ACU", "UGG","UAC","UAU", "GUA","GUC","GUG", "GUU"};
   // array allCodes stores the single-letter code of each triplet given in the above array
   char allCodes [NUMPROTEINS] = {'A','A','A','A','R','R','R','R','R','R','D','D','N','N','C','C','E','E','Q','Q', 'G','G','G','G','H','H','I','I','I', 'L','L','L','L','L','L','K','K','M','F','F','P','P','P','P','S','S','S','S','S','S','T','T','T','T', 'W','Y','Y','V','V','V','V'};
   for (int i = 0; i < NUMPROTEINS; i++) {
      if  (strncmp (protein, allProteins[i], 3) == 0){
         return allCodes [i];
      }
   }
   
   return 'Z';   // to indicate an incorrect code - code that doesn't exist in array allCodes
}




