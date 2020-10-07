#ifndef TESTFUNC_H
#define TESTFUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


float testsetosa(int numID, float arr[], char str[][150]);
//Get a probability of the corresponding ID data in the classlabel 'iris-setosa' using a normal probability distribution formula for continous data

float testversicolor(int numID, float arr[], char str[][150]);
//Get a probability of the corresponding ID data in the classlabel 'iris-versicolor' using a normal probability distribution formula for continous data

float testvirginica(int numID, float arr[], char str[][150]);
//Get a probability of the corresponding ID data in the classlabel 'iris-virginica' using a normal probability distribution formula for continous data


#endif
