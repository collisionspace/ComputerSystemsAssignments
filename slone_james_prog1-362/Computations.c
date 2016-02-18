//
//  Computations.c
//  slone_james_prog1-362
//
//  Created by James Slone on 2/7/16.
//  Copyright © 2016 James Slone. All rights reserved.
//

#include "prog2.h"

//2nd and 3rd column in the txt file
double populationDensity(int pop, int sqMi) {
    return ((double)pop) / sqMi;
}

double computePollution(int pollution, double populationDensity) {
    return (pollution*populationDensity) / THOUSAND;
}

double trafficRating(int majorHighways,double populationDensity) {
    double numerator = populationDensity * TRAFFIC_RATE_CNST;
    double denominator = numerator/ majorHighways;
    return denominator;
}

double crimePerCapita(int crime, double populationDensity) {
    return (crime * populationDensity)/ CRIME_CNST;
}

double expensePerCapita(int expense, double populationDensity) {
    return (expense * populationDensity)/ EXPENSE_CNST;
}

void computeRatings(int pollution,int crime,int expense,int majorHighways,double populationDensity,double *pollutionAmount,double *trafficRate,double *crimeRate,double *expenseRate) {
    *pollutionAmount = computePollution(pollution,populationDensity);
    *trafficRate = trafficRating(majorHighways,populationDensity);
    *crimeRate = crimePerCapita(crime,populationDensity);
    *expenseRate = expensePerCapita(expense,populationDensity);
}

void livability(double pollutionAmount,double trafficRate,double crimeRate,double expenseRate,double *livabilityScore) {
    *livabilityScore = (pollutionAmount + trafficRate + crimeRate + expenseRate)/ LIVABILITY_CNST;
    *livabilityScore = 100 - *livabilityScore;
}

void update(int *cityCount,double *totalLivableScore,double currentLivabilityScore,char currentCityName[], char mostLivableCity[],double *mostLivableCityScore) {
    *cityCount = *cityCount + 1;
    *totalLivableScore = *totalLivableScore + currentLivabilityScore;
    
    if(currentLivabilityScore > *mostLivableCityScore) {
        *mostLivableCityScore = currentLivabilityScore;
        strcpy(mostLivableCity, currentCityName);
    }
}

