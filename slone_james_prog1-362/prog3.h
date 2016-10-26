/*Author: James Slone
 * Course: CSC 362
 * Date: 3/16/2016
 * Programming Assignment: #3 prog3.h
 * Instructor: Richard Fox
 * This header file contains all my library includes, constants, and prototypes
 */
//*****Library include statements*****
//functions for performing input and output.
#include <stdio.h>

//functions for performing string operations
#include <string.h>

//several functions that are useful for testing and mapping characters.
#include <ctype.h>

//*****Constants defined for certain variables*****
//constant for end of string character
#define END_STRING '\0'

//constant for the number 0
#define ZERO 0

//constant for the number 1
#define ONE 1

//constant for the size of the alphabet
#define ALPHABET_LENGTH 26

//constant for the message size length
#define MESSAGE_LENGTH 5000

//*****InputOutput.c function prototypes*****
//inputs a txt file into an array
void input(char []);

//encrypts the message that was read in
void encryptMessage(char *,int *,int,int []);

//decrypts the encrypted message
void decryptMessage(char *,int *,int,int []);

//outputs a header for the encrypted section
void outputEncryptedHeader();


//outputs a header for the decrypted section
void outputDecryptedHeader();

//prints out the message to the console via putchar and pointer
void output(char *);
