#include "mede.h"
#include "testfunc.h"


float meanfunc(float arr[], int start, int end){        // compute the mean of data points in each class label

      int i;
      float sum = 0, avg;
      for (i = start; i < end; ++i){
          sum += arr[i];               // Add up all values in the array
      }

      avg = (float) sum / (end - start); // divide the sum by the number of values in the array
      return avg;
}

float stdevfunc(float arr[], int start, int end){      // compute the standard deviation of data points in each class label -> use population standard deviation

      int i;
      float addup = 0, dev;
      float mean = meanfunc(arr, start, end);

      for (i = start; i < end; ++i){
          addup += ((arr[i] - mean) * (arr[i] - mean));
      }

      dev = sqrt((float) addup / (end - start));
      return dev;

}
