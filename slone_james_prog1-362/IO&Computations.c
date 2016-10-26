/*Author: James Slone
 * Course: CSC 362
 * Date: 3/16/2016
 * Programming Assignment: #3 IO&Computations.c
 * Instructor: Richard Fox
 * This file has functions that input a txt file, encrypts/decrypts messages, and outputs headers/messages
 */

//include definitions, declarations and prototypes from header file
#include "prog3.h"


/**
 * Reads in an input file char by char into an char array
 * It then adds '\0' at the end of what was read in.
 */
void input(char message[]) {
    //intializes the character that is going to be read out from the input file
    int character;
    
    //sets the count to 0 that will be used to set the chars into the array correctly
    int count = ZERO;
    
    //creates char array for the file location that will be read-only
    char inputfile[]="/Users/slonej3/Desktop/slone_james_prog1-362/slone_james_prog1-362/message1.txt";
    
    //points to fp1
    FILE *fp1;
    //opens the fp1, read-only
    fp1 = fopen(inputfile, "r");
    
    //loops until character in the file hits end of file
    while ((character = getc(fp1)) != EOF) {
        message[count] = character;
        count++;
    }
    //close the file fp1
    fclose(fp1);
    
    //adds '\0' to the end of what was read in
    message[count] = END_STRING;
    
}


/**
 * Encrpyts the message that was read in based on an array of ints that will
 * move the char so many chars forward or backwards and also wrap the chars back to the front or back
 * of the alphabet if the char goes forward or backwards to far.
 * Once the array of ints hits the end the pointer will be resested back to the start of its array
 */
void encryptMessage(char *ptrC,int *ptrI,int encryptionL,int encryptionA[]) {
    //keeps track of how many chars get encrpyted. It will be reseted to 0
    //when it reaches the length of the encryption arry
    int count = ZERO;
    
    //gets the size of the pointer that was passed in
    int sizeOfChar = sizeof(*ptrC);
    
    //loops until the char pointer reaches '\0'
    while(*ptrC != END_STRING) {
        if (!isalpha(*ptrC)) {
            //adds the size of a char to the pointer
            ptrC = ptrC + sizeOfChar;
        }
        //Executes if the count is less than encyrption length and if pointer char and pointer int are added together is still alpha
        else if(count < encryptionL && isalpha(*ptrC + *ptrI)) {
            //adds pointer char and the pointer int together to encrypt the char
            *ptrC = *ptrC + *ptrI;
            //adds the size of a char to the pointer
            ptrC = ptrC + sizeOfChar;
            
            //increments the int pointer and count
            ptrI++;
            count++;
        }
        //Executes if the count is less than encyrption length and if pointer char and pointer int are added together isn't alpha
        else if (count < encryptionL && !isalpha(*ptrC + *ptrI)) {
            //checks if pointer char is lowercase
            if(islower(*ptrC)) {
                //if pointer char minus pointer int is greater than z then it wraps back to the start of the alphabet
                if(*ptrC + *ptrI > 'z') {
                    //adds pointer char and the pointer int together to encrypt the char
                    *ptrC = *ptrC + *ptrI;
                    //the pointer char is subtracted by the length of the alphabet
                    *ptrC = *ptrC - ALPHABET_LENGTH;
                }
                //this will wrap the pointer char to the end of the alphabet
                else {
                    //adds pointer char and the pointer int together to encrypt the char
                    *ptrC = *ptrC + *ptrI;
                    //the pointer char and the length of the alphabet are added together
                    *ptrC = *ptrC + ALPHABET_LENGTH;
                }
            }
            //checks if pointer char is uppercase
            else if(isupper(*ptrC)) {
                //if pointer char minus pointer int is greater than Z then it wraps back to the start of the alphabet
                if(*ptrC + *ptrI > 'Z') {
                    //adds pointer char and the pointer int together to encrypt the char
                    *ptrC = *ptrC + *ptrI;
                    //the pointer char is subtracted by the length of the alphabet
                    *ptrC = *ptrC - ALPHABET_LENGTH;
                }
                //this will wrap the pointer char to the end of the alphabet
                else {
                    //adds pointer char and the pointer int together to encrypt the char
                    *ptrC = *ptrC + *ptrI;
                    //the pointer char and the length of the alphabet are added together
                    *ptrC = *ptrC + ALPHABET_LENGTH;
                }
            }
            //adds the size of a char to the pointer
            ptrC = ptrC + sizeOfChar;
            
            //increments the int pointer and count
            ptrI++;
            count++;
        }
        //executes if count hits the length of the array, resets the count back
        //to 0 and the address of the pointer back to start of the array
        else {
            count = ZERO;
            ptrI = encryptionA;
        }
    }
}


/**
 * Decrpyts the message that was read in based on an array of ints that will
 * move the char so many chars forward or backwards and also wrap the chars back to the front or back
 * of the alphabet if the char goes forward or backwards to far.
 * Once the array of ints hits the end the pointer will be resested back to the start of its array
 */
void decryptMessage(char *ptrC,int *ptrI,int encryptionL,int encryptionA[]) {
    //keeps track of how many chars get encrpyted. It will be reseted to 0
    //when it reaches the length of the encryption arry
    int count = ZERO;
    
    //gets the size of the pointer that was passed in
    int sizeOfChar = sizeof(*ptrC);
    
    //loops until the char pointer reaches '\0'
    while(*ptrC != END_STRING) {
        //Executes if the current pointer char isn't part of the alphabet
        if (!isalpha(*ptrC)) {
            //adds the size of a char to the pointer
            ptrC = ptrC + sizeOfChar;
        }
        //Executes if the count is less than encyrption length and if pointer char minus pointer int is still alpha
        else if(count < encryptionL && isalpha(*ptrC - *ptrI)) {
            //takes pointer char and subtracts it by the pointer int to get back to the decrypted char
            *ptrC = *ptrC - *ptrI;
            
            //adds the size of a char to the pointer
            ptrC = ptrC + sizeOfChar;
            
            //increments the int pointer and count
            ptrI++;
            count++;
        }
        //Executes if the count is less than encyrption length and if pointer char minus pointer int isn't alpha
        else if (count < encryptionL && !isalpha(*ptrC - *ptrI)) {
            //checks if pointer char is lowercase
            if(islower(*ptrC)) {
                //if pointer char minus pointer int is greater than z then it wraps back to the start of the alphabet
                if(*ptrC - *ptrI > 'z') {
                    //takes pointer char and subtracts it by the pointer int to get back to the decrypted char
                    *ptrC = *ptrC - *ptrI;
                    //the pointer char is subtracted by the length of the alphabet
                    *ptrC = *ptrC - ALPHABET_LENGTH;
                }
                //this will wrap the pointer char to the end of the alphabet
                else {
                    //takes pointer char and subtracts it by the pointer int to get back to the decrypted char
                    *ptrC = *ptrC - *ptrI;
                    //the pointer char and the length of the alphabet are added together
                    *ptrC = *ptrC + ALPHABET_LENGTH;
                }
            }
            //checks if pointer char is uppercase
            else if(isupper(*ptrC)) {
                 //if pointer char minus pointer int is greater than Z then it wraps back to the start of the alphabet
                if(*ptrC - *ptrI > 'Z') {
                    //takes pointer char and subtracts it by the pointer int to get back to the decrypted char
                    *ptrC = *ptrC - *ptrI;
                    //the pointer char is subtracted by the length of the alphabet
                    *ptrC = *ptrC - ALPHABET_LENGTH;
                }
                //this will wrap the pointer char to the end of the alphabet
                else {
                    //takes pointer char and subtracts it by the pointer int to get back to the decrypted char
                    *ptrC = *ptrC - *ptrI;
                    //the pointer char and the length of the alphabet are added together
                    *ptrC = *ptrC + ALPHABET_LENGTH;
                }
            }
            //adds the size of a char to the pointer
            ptrC = ptrC + sizeOfChar;
            
            //increments the int pointer and count
            ptrI++;
            count++;
        }
        //executes if count hits the length of the array, resets the count back
        //to 0 and the address of the pointer back to start of the array
        else {
            count = ZERO;
            ptrI = encryptionA;
        }
    }
    
}

//prints out the header for the encrypted message
void outputEncryptedHeader() {
    printf("Encrypted message:\n");
}

//prints out the header for the decrypted message
void outputDecryptedHeader() {
    printf("\n\nDecrypted message:\n");
}

//The pointer char prints out and gets incremented every loop until end of string ['\0'] is found.
void output(char *ptrC) {
    while (*ptrC != END_STRING) {
        putchar(*ptrC++);
    }
}
