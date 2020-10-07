#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "mede.h"
#include "testfunc.h"

int main(){

  //Step1: Read a file (Author: Minhwa Lee)
  FILE  *infile; // Opening a file "Iris.data.txt" from the directory file.
  infile = fopen ("iris.data.txt", "r"); // open the file "iris.data.txt" in read mode.

  if (infile == NULL)
    printf ("*** The file could not be opened.\n"); // Not saved in the same directory file
  else
    printf ("The file is successfully opened.\n"); // Saved in the same directory -> Desktop

  int i=0;
  float x1[150];
  float x2[150];
  float x3[150];
  float x4[150];
  char com1[150], com2[150], com3[150], com4[150];
  char classlabel[150][150];

  while (feof(infile) == 0){ // read data points from the file and save those into each array.

        fscanf(infile, "%f", &x1[i]);
        fscanf(infile, "%c", &com1[i]);
        fscanf(infile, "%f", &x2[i]);
        fscanf(infile, "%c", &com2[i]);
        fscanf(infile, "%f", &x3[i]);
        fscanf(infile, "%c", &com3[i]);
        fscanf(infile, "%f", &x4[i]);
        fscanf(infile, "%c", &com4[i]);
        fscanf(infile, "%s", classlabel[i]);
        ++i;
    }

  fclose(infile);


  for (int j = 0; j < sizeof(x1)/sizeof(float); ++j)
      printf("%.1f %.1f %.1f %.1f %s\n", x1[j], x2[j], x3[j], x4[j], classlabel[j]); // Showing data points in each column of the file in the terminal


  //Author: Sejeong Lee

  int position; //declare a variable holding ID number
  float psetosa, pversicolor, pvirginica; // declare a variable holding P(C_classlabel)
  int numbercorrectclasslabel = 0; // declare a variable holding the number of correctly predcited class labels
  float classaccuracy;
  char predictedclasslabel[150][150]; // declare a multidimensional array holding character strings of predcited class label
  float probsetosa, probvirginica, probversicolor; // declare a varible holding P(X|C)

  printf("----------------Analysis-----------------\n");

  for (position = 0; position < 150; ++position){ // looping to obtain the predicted result from all 150 data points


    if (strcmp(classlabel[position], "Iris-setosa") == 0){ //P(C_iris-setosa);
      psetosa = (float) 49/149;
      pversicolor = (float) 50/149;
      pvirginica = (float) 50/149;
    }

    else if (strcmp(classlabel[position], "Iris-versicolor") == 0){ //P(C_iris-versicolor)
      psetosa = (float) 50/149;
      pversicolor = (float) 49/149;
      pvirginica = (float) 50/149;

    }
    else if(strcmp(classlabel[position], "Iris-virginica")== 0){ //P(C_iris-virginica)

      psetosa = (float) 50/149;
      pversicolor = (float) 50/149;
      pvirginica = (float) 49/149;

    }

    //STEP4 and 5: Obtain P(X|Ci)

    // Obtain the values of each P(C_iris-setosa|X=position) = P(X1|C_iris-setosa) * P(X2|C_iris-setosa) * P(X3|C_iris-setosa) * P(x4|C_iris-setosa)* P(C_iris-setosa)
    probsetosa = testsetosa(position, x1, classlabel) * testsetosa(position, x2, classlabel) * testsetosa(position, x3, classlabel) * testsetosa(position, x4, classlabel) * psetosa;
    // P(C_iris-versicolor|X=position) = P(X1|C_iris-versicolo) * P(X2|C_iris-versicolor) * P(X3|C_iris-Versicolor) * P(x4|C_iris-versicolor)* P(C_iris-versicolor)
    probversicolor = testversicolor(position, x1, classlabel) * testversicolor(position, x2, classlabel) * testversicolor(position, x3, classlabel) * testversicolor(position, x4, classlabel) * pversicolor;
    //P(C_iris-virginica|X=position) = P(X1|C_iris-virginica) * P(X2|C_iris-virginica) * P(X3|C_iris-virginica) * P(x4|C_iris-virginica)* P(C_iris-virginica)
    probvirginica = testvirginica(position, x1, classlabel) * testvirginica(position, x2, classlabel) * testvirginica(position, x3, classlabel) * testvirginica(position, x4, classlabel) * pvirginica;


    printf("ID = %i\n", position+1); //Show each number of ID (position)
    printf("Actual class: %s.\n", classlabel[position]); // Show actual class of each ID number (position)


    //STEP 6: Determine the class label and obtain the classification accuracy

    if (probsetosa > probversicolor && probsetosa > probvirginica){ // Compare three values of probability and determine the class label
        printf("Predicted class: Iris-setosa.\n");
        strcpy(predictedclasslabel[position], "Iris-setosa");
    }
    else if (probversicolor > probsetosa && probversicolor > probvirginica){
        printf("Predicted class: Iris-versicolor.\n");
        strcpy(predictedclasslabel[position], "Iris-versicolor");
    }
    else if (probvirginica > probsetosa && probvirginica > probversicolor){
        printf("Predicted class: Iris-virginica.\n");
        strcpy(predictedclasslabel[position], "Iris-virginica");
    }

    printf("-----------------------------------------\n");


    if (strcmp(classlabel[position], predictedclasslabel[position]) == 0) // Add up all numbers of correctly predicted class label
        numbercorrectclasslabel += 1;

    }


  classaccuracy = (float) numbercorrectclasslabel * 100 / 150; // Classification accuracy

  printf("Classification Accuracy = %f %%\n", classaccuracy);

  return 0; // Sejeong Lee
}
