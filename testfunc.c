#include "mede.h"
#include "testfunc.h"


//STEP3: Functions for training and testing data in each class label
//Author: Minhwa Lee

float testsetosa(int numID, float arr[], char str[][150]){          //Get a probability of the corresponding ID data in the classlabel 'iris-setosa' using a normal probability distribution formula for continous data

    int i, j;
    double add1 = 0, add2 = 0;
    float meansetosa, devsetosa;
    float arrprobsetosa;
    float numsetosa, denosetosa;

    // This ID data will be used as a test set, and the rest of ID data in the same class label wil be used to train the classifier, by using leave-one-out cross validation.

    if (strcmp(str[numID], "Iris-setosa") == 0){
      for (i = 0; i < 50; ++i){
          add1 += arr[i];
      }
      add1 = add1 - arr[numID];
      meansetosa = (float) add1 / 49;

      for (j = 0; j < 50; ++j){
          add2 += ((arr[j] - meansetosa) * (arr[j] - meansetosa));
      }
      add2 = add2 - ((arr[numID] - meansetosa) * (arr[numID] - meansetosa));
      devsetosa = (float) sqrt( (float)add2 / 49);

    }
    else {
        meansetosa = meanfunc(arr, 0, 50);
        devsetosa = stdevfunc(arr, 0, 50);
    }


    numsetosa = (float) exp(-1 * ((arr[numID] - meansetosa)*(arr[numID] - meansetosa)) / (2 * devsetosa * devsetosa));
    denosetosa = (float) sqrt(2 * M_PI) * devsetosa;
    arrprobsetosa = (float) numsetosa / denosetosa;

    return arrprobsetosa;

  }


float testversicolor(int numID, float arr[], char str[][150]){     //Get a probability of the corresponding ID data in the classlabel 'iris-versicolor' using a normal probability distribution formula for continous data
    int i, j;
    float add1= 0, add2 = 0;
    float meanversicolor, devversicolor;
    float arrprobversicolor;
    float numversicolor, denoversicolor;

     // This ID data will be used as a test set, and the rest of ID data in the same class label wil be used to train the classifier, by using leave-one-out cross validation

    if (strcmp(str[numID], "Iris-versicolor") == 0){

      for (i = 50; i < 100; ++i){
          add1 += arr[i];
      }

      add1 = add1 - arr[numID];
      meanversicolor = (float) add1 / 49;

      for (j = 50; j < 100; ++j){
          add2 += ((arr[j] - meanversicolor) * (arr[j] - meanversicolor));
      }
      add2 = add2 - ((arr[numID] - meanversicolor) * (arr[numID] - meanversicolor));
      devversicolor = (float) sqrt((float) add2 / 49);

    }

    else {
        meanversicolor = meanfunc(arr, 50, 100);
        devversicolor = stdevfunc(arr, 50, 100);
    }


    numversicolor = (float) exp(-1 * (float)((arr[numID] - meanversicolor)*(arr[numID] - meanversicolor)) / (2 * devversicolor * devversicolor));
    denoversicolor = (float) sqrt(2 * M_PI) * devversicolor;
    arrprobversicolor = (float)numversicolor / denoversicolor;

    return arrprobversicolor;

  }

float testvirginica(int numID, float arr[], char str[][150]){      //Get a probability of the corresponding ID data in the classlabel 'iris-virginica' using a normal probability distribution formula for continous data

    int i, j;
    float add1= 0, add2 = 0;
    float meanvirginica, devvirginica;
    float arrprobvirginica;
    float numvirginica, denovirginica;

       // This ID data will be used as a test set, and the rest of ID data in the same class label wil be used to train the classifier, by using leave-one-out cross validation

    if (strcmp(str[numID], "Iris-virginica") == 0){

      for (i =  100; i < 150; ++i){
          add1 += arr[i];
      }
      add1 = add1 - arr[numID];
      meanvirginica = (float) add1 / 49;

      for (j = 100; j < 150; ++j){
          add2 += ((arr[j] - meanvirginica) * (arr[j] - meanvirginica));
      }
      add2 = add2 - ((arr[numID] - meanvirginica) * (arr[numID] - meanvirginica));
      devvirginica = (float) sqrt((float) add2/49);

    }

    else {
        meanvirginica = meanfunc(arr, 100, 150);
        devvirginica = stdevfunc(arr, 100, 150);

    }

    numvirginica = (float) exp(-1 * (float)((arr[numID] - meanvirginica) * (arr[numID] - meanvirginica)) / (2 * devvirginica * devvirginica));
    denovirginica = (float) sqrt(2 * M_PI) * devvirginica;
    arrprobvirginica = (float) numvirginica / denovirginica;


    return arrprobvirginica;

  }

  // Minhwa Lee
