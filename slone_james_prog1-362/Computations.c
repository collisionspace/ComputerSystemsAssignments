/*Author: James Slone
 * Course: CSC 362
 * Date: 2/18/2016
 * Programming Assignment: #2 Computations.c
 * Instructor: Richard Fox
 * This file is just funcs that compute certain variables. 6 funcs calculate variables needed to show the user, which are
 * populationDensity, computePollution, trafficRating, crimePerCaptia, expensePerCaptia, and livability.
 * The func computeRatings calls computePollution, trafficRating, crimePerCaptia, and expensePerCaptia
 * The func update updates variables for the city county, average livability, and most livable city and its score
 */

//include definitions, declarations and prototypes from header file
#include "prog2.h"

//This func divides population (which is casted to a double)
//and square miles and it will return the population density for the said city
double populationDensity(int pop, int sqMi) {
    return ((double)pop) / sqMi;
}

//This func computes the pollutiuon for the said city. It receives pollution and population density as parameters.
//It takes pollution and multiplies it by the population density and then divides it by a thousand
//This func will return the pollution to the computeRatings func
double computePollution(int pollution, double populationDensity) {
    return (pollution*populationDensity) / THOUSAND;
}

//This func computes the traffic rating for the said city. It receives major highways and population density as parameters.
//The numerator multiples population density and the traffic rate constant (1.7) together and then the denominator
//divides the numerator by major highways.  The denominator is then returned to the computeRatings func
double trafficRating(int majorHighways,double populationDensity) {
    double numerator = populationDensity * TRAFFIC_RATE_CNST;
    double denominator = numerator/ majorHighways;
    return denominator;
}

//This func computes the crime per captia for the said city. It receives crime and population density as parameters.
//crime and population density are multiplied together and then its divided by the crime constant (872.6)
//This is will be returned to the computeRatings func
double crimePerCapita(int crime, double populationDensity) {
    return (crime * populationDensity)/ CRIME_CNST;
}

//This func computes the expense per captia for the said city.  It receives expense and population density as parameters.
//expense and population density is multiplied together and then its divided by the expense constant (1217.1)
//This will be returned to the computeRatings func
double expensePerCapita(int expense, double populationDensity) {
    return (expense * populationDensity)/ EXPENSE_CNST;
}

//This func calls 4 other funcs to compute ratings for the said city. It recieves pollution, crime, expense, majorHighways, populationDensity,
//pollutionAmount, trafficRate, crimeRate, expenseRate as parameters (The last 4 parameters are pointers).
void computeRatings(int pollution,int crime,int expense,int majorHighways,double populationDensity,double *pollutionAmount,double *trafficRate,double *crimeRate,double *expenseRate) {
    //The pollution amount is calculated by the computePollution func and the variable that is returned then gets modified because of the pointer
    *pollutionAmount = computePollution(pollution,populationDensity);
    
    //The traffic rate is calculated by the trafficRating func and the variable that is returned then gets modified because of the pointer
    *trafficRate = trafficRating(majorHighways,populationDensity);
    
    //The crime amount is calculated by the crimePerCapita func and the variable that is returned then gets modified because of the pointer
    *crimeRate = crimePerCapita(crime,populationDensity);
    
    //The expense rate is calculated by the expensePerCapita func and the variable that is returned then gets modified because of the pointer
    *expenseRate = expensePerCapita(expense,populationDensity);
}

//This func computes the livability of the said city.  It recieves pollution, traffice rate, crime rate, expense rate, and livability score as parameters.
//Livability is the only pointer the func recieves.
void livability(double pollutionAmount,double trafficRate,double crimeRate,double expenseRate,double *livabilityScore) {
    //livability score is first calculated by adding pollution, traffic rating, crime rate, and expense rate together
    //and then dividing by the livability constant (13.81)
    *livabilityScore = (pollutionAmount + trafficRate + crimeRate + expenseRate)/ LIVABILITY_CNST;
    
    //100 is subtracted off the livability score.
    *livabilityScore = HUNDRED - *livabilityScore;
}

//This func updates city count, total livable score, most liveable city and most livable city score. It recieves city count, total livable score, current
//livable score, current city name, most livable city, most livable city socre.
void update(int *cityCount,double *totalLivableScore,double currentLivabilityScore,char currentCityName[], char mostLivableCity[],double *mostLivableCityScore) {
    //Adds one to the current city count
    *cityCount = *cityCount + ONE;
    
    //Sets totalLivableScore equal to the current totalLivableScore plus currentLivabilityScore
    *totalLivableScore = *totalLivableScore + currentLivabilityScore;
    
    //The statement inside will be ran if the currentLivabilityScore is greater than the mostLivableCityScore
    if(currentLivabilityScore > *mostLivableCityScore) {
        
        //sets the mostLivableCityScore to the currentLivabilityScore
        *mostLivableCityScore = currentLivabilityScore;
        
        //Copies the currentCityName into mostLivableCity
        strcpy(mostLivableCity, currentCityName);
    }
}

