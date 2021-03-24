#include "sensor-validate.h"

int detectjumpsandreact(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}


int validatereadings(double* values, int numOfValues, double limit) {

  for(int index = 0; index < numOfValues; index++) {
    if(!detectjumpsandreact(values[index], values[index + 1], limit)) {
      return 0;
    }
  }
  return 1;
}
