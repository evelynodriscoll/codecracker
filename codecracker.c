//evelyn o'driscoll
//041014822
//c lab 302 dave houtman
//assignment 2
//july 25, 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "041014822.h"

#define TRUE 1

//forward declarations
int* doFrequencyAnalysis(char*, int*);
int** sortFrequencyAddresses(int*, int**);
int compare(const void*, const void*);
void displayFrequencyAnalysis(int**, int*);
char* swapCipherTextChars(char*);
void swap(char*, char*);


int main(void) {

    char cipherText [strlen(decrypt)];              //create initial arrays
    int charFreq[26] = {0};
    int* alphaSort[26] = {'\0'};

    strcpy(cipherText, decrypt);                    //copy array declared in h file into cipherText
    puts(cipherText);

while(TRUE) {                                       //loop until user decodes message

   memset(charFreq, 0, sizeof(charFreq));           //reset charFreq and alphaSort to 0 so they can display the correct values 
   memset(alphaSort, 0, sizeof(alphaSort));

   doFrequencyAnalysis(cipherText, charFreq);       //count how many times each letter occurs
   sortFrequencyAddresses(charFreq, alphaSort);     //sort alphaSort addresses by frequency of value occurrence descending

   displayFrequencyAnalysis(alphaSort, charFreq);   //output frequency info
   swapCipherTextChars(cipherText);                 //prompt user to swap two characters in the string
   puts(cipherText);                                //output new version of the message
}

exit(EXIT_SUCCESS);
}

int* doFrequencyAnalysis(char cipherText[], int charFreq[]) {

    int size = strlen(cipherText);
    int ascii = 0;
    int a = 65;
    int* currentChar;
    char* p;

    for(p = cipherText; p<(cipherText+size); p++) {
        ascii = (int)*p;
        if(ascii!=32 && ascii!=44) {            //if character not equal space or comma
        currentChar = charFreq + (ascii-a);     //point to beginning address of array + value-65
        *currentChar+=1;                        //increment count for that letter
        }
    }

    return charFreq;

}

int compare(const void* i, const void* j) {       //citation: en.cppreference.com/w/c/algorithm/qsort

    int arg1 = **(const int**)i;
    int arg2 = **(const int**)j;

    return arg1-arg2;                              //compare to see which is higher
}

int** sortFrequencyAddresses(int charFreq[], int* alphaSort[]) {
    
    int* p;
    int** value = alphaSort;

    for(p = charFreq; p<(charFreq+26); p++) {
            *value = p;                            //set value of current element to the memory address of p
            value++;
    }

    qsort(alphaSort, 26, sizeof(int*), compare);    //sort addresses by frequency of occurrence of value, descending
    
}

void displayFrequencyAnalysis(int* alphaSort[], int charFreq[]) {

    int** p;

    for(p = alphaSort; p<(alphaSort+26); p++) {
        int value = **p;
        int letter = (*p-charFreq)+65;
        char c = letter;
            printf("%c: %d %s", c, value, "\t");    //output frequency info to help user break the code!!!

            }
            printf("\n\n");
        }    

char* swapCipherTextChars(char cipherText[]) {
    char oldChar;
    char newChar;

    printf("Enter character you wish to swap out: ");
    scanf(" %c", &oldChar);                              //get user input for characters to swap

    printf("Enter character you wish to replace it with: ");
    scanf(" %c", &newChar);
    printf("\n");
    
    char temp = oldChar;
    char* p; int size = strlen(cipherText);

    for(p = cipherText; p<cipherText+size; p++) {       //cycle through array
        
       if(*p == oldChar) {                              //swap char if it matches input
        *p = newChar;
       }

       else if(*p == newChar) {
        *p = temp;
       }
    }
    
    return cipherText;                                  //return new version of string
  
}








