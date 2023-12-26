/*--------------------  TEST CASES  --------------------*/
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


/* ---------------------------------- MAIN FUNCTION ---------------------------------- */
int main() {
   // Test data for the all functions
   char aStrand[SIZE] = "GGCCGG";

   // Test cases
   char test1[SIZE] = "MADAM";
   char test2[SIZE] = "CATG";
   char test3[SIZE] = "2002";
   char test4[SIZE] = "SAIPPUAKIVIKAUPPIAS";

   // Test cases
   char isStrandDnaPalindrome_test1[SIZE] = "GGATCC";
   char isStrandDnaPalindrome_test2[SIZE] = "GGCCGG";
   char isStrandDnaPalindrome_test3[SIZE] = "AT";
   char isStrandDnaPalindrome_test4[SIZE] = "AG";
   char dnaStrand[SIZE] = "CATG";
   char resultantMrna[SIZE];
   char dnaStrand1[SIZE] = "CGTAGGCAT";
   char dnaStrand2[SIZE] = "CACGC";
   char dnaStrand3[SIZE] = "CAXGC";

   // Calling function #1 - isBasePair
   // Test and print results for each case
   printf("isBasePair('A', 'T'): %d\n", isBasePair('A', 'T')); // should print 1 (true)
   printf("isBasePair('A', 'C'): %d\n", isBasePair('A', 'C')); // should print 0 (false)
   printf("isBasePair('G', 'C'): %d\n", isBasePair('G', 'C')); // should print 1 (true)
   printf("isBasePair('T', 'A'): %d\n", isBasePair('T', 'A')); // should print 1 (true)
   printf("isBasePair('T', 'G'): %d\n", isBasePair('T', 'G')); // should print 0 (false)
   printf("\n");

   // Calling function #2 - isItaDnaSequence
   // Test and print results for each case
   printf("isItaDnaSequence('CT', 'TA'): %d\n", isItaDnaSequence("CT", "TA")); // should print 0 (false)
   printf("isItaDnaSequence('CT', 'GA'): %d\n", isItaDnaSequence("CT", "GA")); // should print 1 (true)
   printf("\n");

   // Calling function #3 - reverse
   // Test and print results for each case
   printf("Testing reverse:\n");
   printf("The original strand: %s\n", aStrand);
   reverse(aStrand);
   printf("The reversed Strand: %s\n", aStrand);
   printf("\n");

   // Calling function #4 - complementIt
   // Test and print results for each case
   printf("Testing complement strand\n");
   printf("A strand: %s\n", aStrand);
   complementIt(aStrand);
   printf("Complement strand: %s\n", aStrand);
   printf("\n");

   // Calling function #5 - isItPalindrome
   // Test and print results for each case
   printf("Testing isItPalindrome:\n");
   printf("Is %s a palindrome? %s\n", test1, isItPalindrome(test1) ? "Yes" : "No");
   printf("Is %s a palindrome? %s\n", test2, isItPalindrome(test2) ? "Yes" : "No");
   printf("Is %s a palindrome? %s\n", test3, isItPalindrome(test3) ? "Yes" : "No");
   printf("Is %s a palindrome? %s\n", test4, isItPalindrome(test4) ? "Yes" : "No");
   printf("\n");

   // Calling function #6 - isStrandDnaPalindrome
   // Test and print results for each case
   printf("Is %s a DNA palindrome? %s\n", isStrandDnaPalindrome_test1, isStrandDnaPalindrome(isStrandDnaPalindrome_test1) ? "Yes" : "No");
   printf("Is %s a DNA palindrome? %s\n", isStrandDnaPalindrome_test2, isStrandDnaPalindrome(isStrandDnaPalindrome_test2) ? "Yes" : "No");
   printf("Is %s a DNA palindrome? %s\n", isStrandDnaPalindrome_test3, isStrandDnaPalindrome(isStrandDnaPalindrome_test3) ? "Yes" : "No");
   printf("Is %s a DNA palindrome? %s\n", isStrandDnaPalindrome_test4, isStrandDnaPalindrome(isStrandDnaPalindrome_test4) ? "Yes" : "No");
   printf("\n");

   // Calling function #7 - howMany
   // Test and print results for each case
   char strand[SIZE] = "GGCCGG";
   char neuclotide = 'G';
   int count = howMany(strand, neuclotide);
   printf("Number of '%c' in strand '%s': %d\n", neuclotide, strand, count);
   printf("\n");

   // Calling function #8 - dnaToMrna
   dnaToMrna(dnaStrand, resultantMrna);
   printf("DNA strand: %s\nmRNA strand: %s\n", dnaStrand, resultantMrna);
   printf("\n");

   // Calling function #9 - translateDnaToMrnaProteins
   printf("Translating DNA to mRNA Proteins:\n");
   translateDnaToMrnaProteins(dnaStrand1);
   printf("\n"); // Separate outputs
   translateDnaToMrnaProteins(dnaStrand2);
   printf("\n");
   translateDnaToMrnaProteins(dnaStrand3);
   printf("\n");


   return 0;
}
/* ---------------------------------- END OF MAIN FUNCTION ---------------------------------- */