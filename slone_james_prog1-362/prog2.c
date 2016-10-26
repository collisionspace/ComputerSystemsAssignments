/*Author: James Slone
 * Course: CSC 362
 * Date: 2/18/2016
 * Programming Assignment: #2 main.c
 * Instructor: Richard Fox
 * This program takes a input file that will be read line by line with the use of fscanf
 * The fscanf will set the variables with the use of pointers.  getInput and outputHeader funcs will be called
 * The loop will continue to loop until eof is set to -1 inside the getInput func.  On each loop of the while loop
 * several funcs will be called populationDensity, computeRatings, livability, update, getOutput, and getInput
 * in that order.  populationDensity will return a double that is the calculated value of that cities  population density
 * computeRatings will call several other funcs, computePollution,trafficRating,crimePerCapita,and expensePerCaptia
 * Those funcs will return the computations via a return statement back to computeRatings but the variables will then be modified
 * via the use of pointers. The func livability will take those variables that was just set and calculate the cities
 * livability, which will be modified with the use of a pointer. The update func will update statistics of the total of all of 
 * the city livability values, the number of cities, and whether this is the best city found so far. 
 * the func getOutput will output the cities name, population density, and livability score. getInput will be called again since
 * this time its inside the while loop.  This ends the while loop and a footer will print out letting the user know
 * the total amount of cities, the average livability, most liveable city and its livability score.
 */

//include definitions, declarations and prototypes from header file
#include "prog2.h"

int prog2(int argc, const char * argv[]) {
    
    //****intializes the chars****
    
    //cityName is set in the getInput func
    char cityName[40];
    
    //mostLiveableCity is set in the update func
    char mostLiveableCity[40];
    
    //creates char array for the file location that will be read-only
    char inputfile[]="/Users/slonej3/Desktop/slone_james_prog1-362/slone_james_prog1-362/cities2.txt";
    
    //****intializes the ints****
    
    //****getInput func variables*****
    //this set of variables is modified with the use of pointers
    //these variables are from the inputFile txt file
    int population;
    int squareMiles;
    int pollution;
    int crime;
    int expense;
    int numberOfHighways;
    
    //intializes the cityCount to 0
    int cityCount = 0;
    
    //****intializes the doubles****
    
    //value is set when the func populationDensity returns its value
    double populationDen;
    
    //value is set via a pointer when the func livability calculates the score
    double livabilityScore;
    
    //initializes both values to 0.0 both values are modified with pointers through the func update
    double totalLivabilityScore = 0.0;
    double mostLiveableCityScore = 0.0;
    
    //computed values from multiple funcs that are called inside computeRatings, values are modified with the use of pointers.
    //these will be passed into livability to calculate the livabilityScore
    double pollutionAmount;
    double trafficRate;
    double crimeRate;
    double expenseRate;
    
    //points to fp1
    FILE *fp1;
    //opens the fp1, read-only
    fp1 = fopen(inputfile, "r");
    
    //Outputs the top header which is City, Population Density, Livability score
    outputHeader();
    
    //Loops until eof is set to -1
    while(!feof(fp1)) {
        
        //Input a city’s name, population, square mileage, pollution, crime, expense, number of highways.
        //Values are modified with the use of pointers.
        getInput(fp1, cityName, &population, &squareMiles, &pollution, &crime, &expense, &numberOfHighways);
        
        //Compute and return the city’s population density via the return statement
        populationDen = populationDensity(population, squareMiles);
        
        //When this func is called it will call computePollution,trafficRating,crimePerCapita,and expensePerCaptia which will return values back to this
        //func which then will modify the pointer variables pollutionAmount,trafficRate,crimeRate,and expenseRate.
        computeRatings(pollution,crime,expense,numberOfHighways,populationDen,&pollutionAmount,&trafficRate,&crimeRate,&expenseRate);
        
        //When this func is called it will take the computed ratings in and also the livabilityScore which is being based via
        //a pointer.  It will calculate the livability of the city and then modified the livabilityScore pointer
        livability(pollutionAmount,trafficRate,crimeRate,expenseRate,&livabilityScore);
        
        //update statistics of the total of all of the city livability values, the number of cities, and whether this is the best city found so far
        update(&cityCount,&totalLivabilityScore,livabilityScore,cityName,mostLiveableCity,&mostLiveableCityScore);
        
        //outputs the said city, the population density and livability. It's also stylized to look nice and neat when printed out to the console
        getOutput(cityName,populationDen,livabilityScore);
    }
    
    //outputs the footer which tells the user the total cites, average livability, most liveable city name, and its score
    outputUpdateFooter(cityCount,totalLivabilityScore,mostLiveableCity,mostLiveableCityScore);
    
    //close the file fp1
    fclose(fp1);
    return 0;
} 