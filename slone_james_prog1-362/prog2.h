/*Author: James Slone
 * Course: CSC 362
 * Date: 2/18/2016
 * Programming Assignment: #2 prog2.h
 * Instructor: Richard Fox
 * This header file contains all my library includes, constants, and prototypes
 */
//*****Library include statements*****
//functions for performing input and output.
#include <stdio.h>

//functions for performing string operations
#include <string.h>

//*****Constants defined for certain variables*****
//constant for traffic rate
#define TRAFFIC_RATE_CNST 1.7;

//constant for crime rate
#define CRIME_CNST 872.6;

//constant for expense rate
#define EXPENSE_CNST 1217.1;

//constant for livability score
#define LIVABILITY_CNST 13.81;

//constant for the number 1
#define ONE 1

//constant for the number 100
#define HUNDRED 100

//constant for the number 1000
#define THOUSAND 1000

//*****InputOutput.c function prototypes*****
//input from one line in the txt file with the help of fscanf
void getInput(FILE *, char *,int *,int *,int *,int *,int *,int *);

//output to the console city name, population density, and livability score
void getOutput(char *,double,double);

//outputs the top header for the console - City Population Density Livability Score
void outputHeader();

//outputs the update footer to the console.
//e.x. - Of the 10 cities, the average livability score was 51.40 and the most liveable city was Las_Vegas with a score of 84.91
void outputUpdateFooter(int,double,char [],double);

//*****Computations.c function prototypes*****
//computes and returns the population density for the current city
double populationDensity(int,int);

//computes and returns the pollution for the current city
double computePollution(int,double);

//computes and returns the traffic rating for the current city
double trafficRating(int,double);

//computes and returns the crime per capita for the current city
double crimePerCapita(int,double);

//computes and returns the expense per capita for the current city
double expensePerCapita(int,double);

//takes the last 4 funcs and runs them and the variables that are returned are then modified with pointers
void computeRatings(int,int,int,int,double,double *,double *,double *,double *);

//computes the livability of the current city
void livability(double,double,double,double,double *);

//computes city count, average livability score, most livable city, and its score
void update(int*,double*,double,char [],char [],double *);

