//
//  main.c
//  slone_james_prog1-362
//
//  Created by James Slone on 2/7/16.
//  Copyright © 2016 James Slone. All rights reserved.
//

#include "prog2.h"

int main(int argc, const char * argv[]) {
    //input a city’s name, population, square mileage, pollution, crime, expense, number of highways
    char cityName[20];
    int population;
    int squareMiles;
    int pollution;
    int crime;
    int expense;
    int numberOfHighways;
    int eof = 0;
    
    double populationDen;
    double livabilityScore;
    double totalLivabilityScore = 0.0;
    int cityCount = 0;
    double mostLiveableCityScore = 0.0;
    char mostLiveableCity[20];
    
    
    double pollutionAmount;
    double trafficRate;
    double crimeRate;
    double expenseRate;
    
    FILE *fp1;
    fp1=fopen("/Users/slonej3/Desktop/slone_james_prog1-362/slone_james_prog1-362/cities1.txt", "r");
    
    outputHeader();
    //for (int index = 0; index < 6; index++) {
    while(eof != -1) {
        //Input a city’s name, population, square mileage, pollution, crime, expense, number of highways.
        //Values are modified with the use of pointers.
        getInput(fp1, cityName, &population, &squareMiles, &pollution, &crime, &expense, &numberOfHighways,&eof);
        
        //Compute and return the city’s population density via the return statement
        populationDen = populationDensity(population, squareMiles);
        
        
        //When this func is called it will call computePollution,trafficRating,crimePerCapita,and expensePerCaptia which will return values back to this
        //func which then will modify the pointer variables pollutionAmount,trafficRate,crimeRate,and expenseRate.
        computeRatings(pollution,crime,expense,numberOfHighways,populationDen,&pollutionAmount,&trafficRate,&crimeRate,&expenseRate);
        
        //When this func is called it will take the computed ratings in and also the livabilityScore which is being based via
        //a pointer.  It will calculate the livability of the city and then modified the livabilityScore pointer
        livability(pollutionAmount,trafficRate,crimeRate,expenseRate,&livabilityScore);
        
        
        update(&cityCount,&totalLivabilityScore,livabilityScore,cityName,mostLiveableCity,&mostLiveableCityScore);
        getOutput(cityName,populationDen,livabilityScore);
        
    }
    outputUpdateFooter(cityCount,totalLivabilityScore,mostLiveableCity,mostLiveableCityScore);
    fclose(fp1);
    
    
    return 0;
} 