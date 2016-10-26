/*Author: James Slone
 * Course: CSC 362
 * Date: 3/16/2016
 * Programming Assignment: #3 main.c
 * Instructor: Richard Fox
 * This program will read in an message from a txt file and then the encrpyt/decrypt functions are called
 * which will perform pointer arthmetic on two arrays, the message array and the array that has the encryption 
 * distances.  Both functions will loop through the array encrypting/decrypting the message and incrementing the
 * pointers. When the char is less than a or z it will then wrap it back to the otherside of the alphabet so
 * y + 2 would wrap it back to a.  After that is done then the output function will be called which the pointer char 
 * prints out and gets incremented every loop until end of string ['\0'] is found.
 */

//include definitions, declarations and prototypes from header file
#include "prog3.h"

int prog3(int argc, const char * argv[]) {
    //initializes the size of the array to 5000
    char messageArray[MESSAGE_LENGTH];
    
    //sets the array with ints that will be used to encrypt and decrypt the messages
    int encryptionArray[] = {5, 2, -1, 2, -3, 2, -4, -2, 6, 4};
    
    //gets the size of the encryption array
    int encryptionLength = sizeof(encryptionArray)/sizeof(encryptionArray[ZERO]);
    
    //sets pointers to the encryption and message array, these will be used to loop through the arrays
    int *ptrInt = encryptionArray;
    char *ptrChar = messageArray;
    
    //reads the input file in which will be the message
    input(messageArray);
    
    
    //encrypts the message a certain distance
    encryptMessage(ptrChar,ptrInt,encryptionLength,encryptionArray);
    
    //outputs a header
    outputEncryptedHeader();
    //prints out the message to the console via putchar and pointer
    output(ptrChar);
    
    
    //decrypts the message that was encrypted
    decryptMessage(ptrChar,ptrInt,encryptionLength,encryptionArray);
    
    //outputs a header
    outputDecryptedHeader();
    //prints out the message to the console via putchar and pointer
    output(ptrChar);
    
    return 0;
}
