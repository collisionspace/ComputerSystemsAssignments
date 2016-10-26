/*Author: James Slone
 * Course: CSC 362
 * Date: 4/6/2016
 * Programming Assignment: #4 prog4.c
 * Instructor: Richard Fox
 * This program will calculate the closeness of a number that the user inputs in to being a perfect number. 
 * Formula: | (sum of factors – number) | / number. 
 * For instance, 12 has factors 1, 2, 3, 4, 6 which sum up to 16 so that 12 has a closeness of |(16–12)|/12 = 33% of a perfect number.
 * The program loops through the first half of numbers (12/2 = 6) of the user inputted number and each loop if its divisible by the number it will be added
 * to a sum count. It will then calculate closeness with the formula above and output some data to the user.
 */
#include <stdio.h>

int prog4(int argc, const char * argv[]) {
    
    // variable declarations in C
    // input the value to be tested in C
    int input, count, sum, dif, divide;
    
    //printing to the console asking the user to input a number
    printf("Please enter a number that you would like to see the closeness of to being a perfect number, program will quit when your input is less than 2\n");
    
    //obtain the input from the user
    scanf("%d", &input);
    
    //loop while input is greater than 1
    while (input > 1) {
        
        count = 1; //reset count to 1 since I can't divide by 0
        sum = 0;   //reset sum to 0
        dif = 2;   //reset dif to 2
        
           __asm {
                top:     mov eax, input     //loads input into eax
                         mov edx, 0         //loads 0 into edx for use of remainder
                         div dif            //eax = input / dif
                         mov divide, eax    //divide = input / dif
                         mov ebx, divide    //loads divide into the ebx register
                         cmp count, ebx     // compares ebx and count -> count == ebx
                         jg absolute        //if count > divide then jump to xout -> count
                         mov eax, input     //loads input into eax
                         mov edx, 0         //sets edx to 0 for use of remainder
                         div count          //eax = input / count
                         cmp edx, 0         //compares remainder to 0 -> input % count == 0
                         jne bottom         //if not equal to 0 then jumps to bottom
                         mov eax, sum    //loads sum into eax
                         add eax, count  //eax = sum + count
                         mov sum, eax    //saves result into sum  sum = eax
               
             bottom:     add count, 1   //count++
                         jmp top        //jumps back to top of loop
               
           absolute:     mov eax, sum    //loads sum into eax
                         sub eax, input  //eax = sum - input
                         mov dif, eax    //saves result into dif  dif = eax
                         cmp dif, 0      //dif == 0
                         jl  negative    //if its less than 0 then jump to negative
                         mov eax, 100   //loads 100 into eax
                         mov edx, 0     //loads 0 into edx for use of remainder
                         mul dif        //eax = 100 * dif
                         mov edx, 0     //loads 0 into edx for use of remainder
                         div input      //eax = eax/input
                         mov dif, eax   //saves result into dif  dif = eax
                         jmp xout       //jumps to xout
           
           negative:     mov eax, -1    //multiplies the difference by -1 to make it positive
                         mov edx, 0     //loads 0 into edx for use of remainder
                         mul dif        //eax = sum * dif
                         mov dif, eax   //saves result into dif  dif = eax
                         mov eax, 100   //loads 100 into the eax
                         mov edx, 0     //loads 0 into edx for use of remainder
                         mul dif        //eax = 100 * dif
                         mov dif, eax   //saves result into dif dif = eax
                         mov edx, 0     //loads 0 into edx for use of remainder
                         div input      //divide eax and input  eax = eax/input
                         mov dif, eax   //saves result into dif  dif = eax
               
               xout:     nop
           }
        // output statements in C for the input number, sum of factors, and percentage
        printf("input = %d\tsum of factors = %d\tpercentage = %d%%\n", input, sum, dif);
        //ask user for next input 4, 32, 50, 51, 64, 81, 500, 8128, 90000
        printf("Please enter a number that you would like to see the closeness of to being a perfect number, program will quit when your input is less than 2\n");
        //get next input
        scanf("%d", &input);
    }
    return 0;
}
