//
//  prog2.h
//  slone_james_prog1-362
//
//  Created by James Slone on 2/7/16.
//  Copyright © 2016 James Slone. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#ifndef prog2_h
#define prog2_h

#define HUNDRED 100;
#define THOUSAND 1000;
#define TRUE 1;
#define FALSE 0;

#define TRAFFIC_RATE_CNST 1.7;
#define CRIME_CNST 872.6;
#define EXPENSE_CNST 1217.1;
#define LIVABILITY_CNST 13.81;

//InputOutput.c function prototypes
void getInput(FILE *, char *,int *,int *,int *,int *,int *,int *,int *);
void getOutput(char *,double,double);
void outputHeader();
void outputUpdateFooter(int,double,char [],double);

//Computations.c function prototypes
double populationDensity(int,int);
double computePollution(int,double);
double trafficRating(int,double);
double crimePerCapita(int,double);
double expensePerCapita(int,double);
void computeRatings(int,int,int,int,double,double *,double *,double *,double *);

void livability(double,double,double,double,double *);
void update(int*,double*,double,char [],char [],double *);

#endif /* prog2_h */
