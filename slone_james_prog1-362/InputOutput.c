//
//  InputOutput.c
//  slone_james_prog1-362
//
//  Created by James Slone on 2/7/16.
//  Copyright © 2016 James Slone. All rights reserved.
//

#include "prog2.h"

//input a city’s name, population, square mileage, pollution, crime, expense, number of highways
void getInput(FILE *fp1, char *cityName,int *population,int *squareMiles,int *pollution,int *crime,int *expense,int *numberOfHighways, int *eof) {
    if(fscanf(fp1, "%s %d %d %d %d %d %d", cityName, population, squareMiles, pollution, crime, expense, numberOfHighways) == EOF) {
        *eof = EOF;
    }
}

void getOutput(char *cityName,double popDen,double livability) {
    printf( "%-15s%10.2f%21.2f\n", cityName,popDen,livability);
}

void outputHeader() {
    printf("%-15s%s%20s\n","City","Population Density","Livability Score");
}

void outputUpdateFooter(int cityCount,double totalLivabilityScore,char mostLiveableCity[],double mostLiveableCityScore) {
    printf("Of the %d cities, the average livability score was %3.2f and the most liveable city was %s with a score of %2.2f\n",cityCount,totalLivabilityScore/cityCount,mostLiveableCity,mostLiveableCityScore);
}