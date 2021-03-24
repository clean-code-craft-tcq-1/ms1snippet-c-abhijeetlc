/*-------------------------Source File ----------------------------------*/
/*Author : Abhijeet C */
#include "sensor-validate.h" /*Header Includes*/

/* Funtion to detect jumps between 2 values*/
/*Arguements : current value, next value , maxdelta */
/*return type : integer*/
int detectjumpsandreact(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

/* Funtion to validate the sensor readings */
/*Arguements : pointer to readings, number of values , maxdelta value */
/*return type : integer*/
int validatereadings(double* values, int numOfValues, double limit) {

  for(int index = 0; index < numOfValues; index++) {
    if(!detectjumpsandreact(values[index], values[index + 1], limit)) {
      return 0;
    }
  }
  return 1;
}
