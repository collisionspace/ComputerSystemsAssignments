/*Author: James Slone
 * Course: CSC 362
 * Date: 1/14/2016
 * Programming Assignment: #1 main.c
 * Instructor: Richard Fox
 * This program takes a input file that will be read in char by car in a loop.
 * It will alternate between uppercase and lowercase chars
 * Start of a sentence will always be uppercase and if a char in the middle of
 * a sentence is uppercase then it will be made a lowercase.
 * Each output char will be written to a output txt file. The user will see
 * in the console the input/output file names, number of
 * input/output chars and the percent of reduction in output.
 */

//defines three variable types, several macros, and various
//functions for performing input and output.
#include <stdio.h>

//declares several functions that are useful for testing and mapping characters.
#include <ctype.h>
#define HUNDRED 100             //int 100
#define TRUE 1                  //boolean using int 1
#define FALSE 0                 //boolean using int 0
#define PERIOD 46               //ascii value of a period
#define PUNCTUATION_START 32    //start of punctuation ascii value
#define PUNCTUATION_END 45      //end of punctuation ascii value
#define NEWLINE '\n'            //checks for newline

int prog1(int argc, const char * argv[]) {
    
    //intializes the character that is going to be read out from the input file
    int character;
    FILE *inputFile, *outputFile; //points to the inputFile and points to the outputFile
    
    //creates char array for the file location that will be read-only
    char name[]="/Users/slonej3/Desktop/slone_james_prog1-362/slone_james_prog1-362/input3.txt";
    //creates char array for the file location that will be write-only
    char outputFileName[] = "/Users/slonej3/Desktop/slone_james_prog1-362/slone_james_prog1-362/output3.txt";
    
    inputFile = fopen(name, "r");            //opens the inputFile, read-only
    outputFile = fopen(outputFileName, "w"); //opens the outPutFile, write-only
    
    //boolean that is true(1 is returned) if the next char should be a lowercase
    //and false(0 is returned) if the next char should capitialized.
    int nextShouldBeLower = FALSE;
    
    //boolean that is true(1 is returned) if the period was found
    //and false(0 is returned) if the period has not been found.
    int foundThePeriod = FALSE;
    
    //intializes the input character count at 1 since I'm going to
    //ignore the EOF that is at the end of the file.
    int inputCharacterCount = 1;
    
    
    
    //intializes the output character count at 1 since I'm going to
    //ignore the EOF that is at the end of the file.
    int outputCharacterCount = 1;
    
    //intializes the percentReduction variable
    double percentReduction;
    
    if (inputFile) {    //executes if the input file isn't null
        
        //gets next char from input file, store in character, until we reach EOF
        while ((character = getc(inputFile)) != EOF) {
            
            //isalpha - returns non-zero value if c is an alphabet,
            //else it returns 0. Also checking to see if foundThePeriod
            //is false. If both is true then the nested ifs are checked.
            if(isalpha(character) && foundThePeriod != TRUE) {
                
                //if inputCharacterCount is at 1, next char should not be lower,
                //and the char is uppercase then execute the inside lines.
                if(inputCharacterCount == 1 && nextShouldBeLower != TRUE && isupper(character)) {
                    
                    //writes the current char to the open output file
                    fputc(character, outputFile);
                    
                    //adds a 1 to the current output char count
                    outputCharacterCount++;
                    
                    //sets nextShouldBeLower to true, so it can check for a lowercase char the next iteration
                    nextShouldBeLower = TRUE;
                }
                //if inputCharacterCount does not equal 1, next char should not
                //be lower, and the char is uppercase then execute the inside lines.
                else if(inputCharacterCount != 1 && nextShouldBeLower != TRUE && isupper(character)) {
                    
                    //current char is set to lowercase and is wrote to the open outputfile
                    fputc(tolower(character), outputFile);
                    
                    //adds a 1 to the current output char count
                    outputCharacterCount++;
                    
                    //sets nextShouldBeLower to true, so it can check for a
                    //lowercase char the next iteration
                    nextShouldBeLower = TRUE;
                }
                
                //if next char should be lower and is a lowercase char then execute the inside lines
                else if(nextShouldBeLower == TRUE && islower(character)) {
                    
                    //writes the current char to the open output file
                    fputc(character, outputFile);
                    
                    //adds a 1 to the current output char count
                    outputCharacterCount++;
                    
                    
                    
                    //sets nextShouldBeLower to false, so it can check for
                    //a uppercase char the next iteration
                    nextShouldBeLower = FALSE;
                }
            }
            //this statements inside here check for for punctuations and newlines
            else {
                
                //if the char is a period then execute the inside lines
                if(character == PERIOD) {
                    
                    //writes the current char to the open output file
                    fputc(character, outputFile);
                    
                    //adds a 1 to the output char count
                    outputCharacterCount++;
                    
                    //sets foundThePeriod boolean to 1 for true
                    foundThePeriod = TRUE;
                }
                //looks between the ascii values of 32 and 45 to see if the char is equal that or if the char is a new line
                else if((character >= PUNCTUATION_START && character <= PUNCTUATION_END) || character == NEWLINE) {
                    
                    //writes the current char to the open output file
                    fputc(character, outputFile);
                    
                    //adds a 1 to the current output char count
                    outputCharacterCount++;
                }
                //if the period has been found and the char is a
                //uppercase char then execute the inside lines
                else if(foundThePeriod == TRUE && isupper(character)) {
                    
                    //writes the current char to the open output file
                    fputc(character, outputFile);
                    
                    //adds a 1 to the current output char count
                    outputCharacterCount++;
                    
                    //sets foundThePeriod boolean to 0 for false
                    foundThePeriod = FALSE;
                    
                    //sets nextShouldBeLower to true, so it can check for
                    //a lowercase char the next iteration
                    nextShouldBeLower = TRUE;
                }
            }
            inputCharacterCount++;  //adds a 1 to the input char count
        }
        //when done, close both files
        fclose(inputFile);
        fclose(outputFile);
        
        
        
        
        //calculating the percent reduction of the chars from input file
        //to the outputfile. Output & Input are both casted
        //as a double when divided and then multiplied by 100
        percentReduction = ((double)outputCharacterCount/(double)inputCharacterCount) * HUNDRED;
        
        //print to console the input file name
        printf("Input file: %s\n", name);
        
        //print to console the output file name
        printf("Output file: %s\n", outputFileName);
        
        //print to console the input char count
        printf("Number of input characters: %d\n",inputCharacterCount);
        
        //print to console the output char count
        printf("Number of output characters: %d\n",outputCharacterCount);
        
        //print to console the percent of char that was reduced in
        //the output file to the first two digits of the double.
        printf("Percent reduction in output: %.2f%%\n", percentReduction);
    }
    
    return 0;
}