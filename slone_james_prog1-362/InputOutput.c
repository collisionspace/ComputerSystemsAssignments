/*Author: James Slone
 * Course: CSC 362
 * Date: 2/18/2016
 * Programming Assignment: #2 InputOutput.c
 * Instructor: Richard Fox
 * This file is just input and outputs funcs. It has a total of 4 funcs which
 * 1 func inputs the file variables with fscanf. The other 3 funcs will
 * output to the console for the user.  It will output a header, lines with
 * cities and their population density/livability score, and a footer.
 */

//include definitions, declarations and prototypes from header file
#include "prog2.h"

//This func recieves certain variables that it then modifies when fscanf is called. It recieves fp1,
//cityName, population, squareMiles, pollution, crime, expense, numberOFHighways
void getInput(FILE *fp1, char *cityName,int *population,int *squareMiles,int *pollution,int *crime,int *expense,int *numberOfHighways) {
    //Input a city’s name, population, square mileage, pollution, crime, expense, number of highways
    fscanf(fp1, "%s %d %d %d %d %d %d", cityName, population, squareMiles, pollution, crime, expense, numberOfHighways);
}

//Outputs a stylized header with printf that says City, Population Density, Livability Score
//The -15s in the printf sets it to left justified 15 chars
void outputHeader() {
    printf("%-15s%s%20s\n","City","Population Density","Livability Score");
}

//Outputs a stylized line with printf that has city name, its population density, and its livability score.
//The -15s in the printf sets it to left justified 15 chars
//Population Density and Livability Scores are rounded to the first 2 decimal places
void getOutput(char *cityName,double popDen,double livability) {
    printf( "%-15s%10.2f%21.2f\n", cityName,popDen,livability);
}

//Outputs a stylized footer with printf that tells the user the total amount of cities, the average livability, the most liveable city and its livability score
//Average Livability and mostLiveableCityScore are both rounded to the first 2 decimal places
void outputUpdateFooter(int cityCount,double totalLivabilityScore,char mostLiveableCity[],double mostLiveableCityScore) {
    printf("Of the %d cities, the average livability score was %3.2f and the most liveable city was %s with a score of %2.2f\n",cityCount,totalLivabilityScore/cityCount,mostLiveableCity,mostLiveableCityScore);
}