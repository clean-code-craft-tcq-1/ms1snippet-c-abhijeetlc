#include "sensor-validate.h"

int _give_me_a_good_name(double value, double nextValue, double maxDelta) {
  if(nextValue - value > maxDelta) {
    return 0;
  }
  return 1;
}

int validateSOCreadings(double* values, int numOfValues) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!_give_me_a_good_name(values[i], values[i + 1], 0.05)) {
      return 0;
    }
  }
  return 1;
}

int validateCurrentreadings(double* values, int numOfValues) {
  int lastButOneIndex = numOfValues - 1;
  for(int i = 0; i < lastButOneIndex; i++) {
    if(!_give_me_a_good_name(values[i], values[i + 1], 0.1)) {
      return 0;
    }
  }
  return 1;
}

int validatereadings(double* values, int numOfValues, double limit) {

  for(int index = 0; index < numOfValues; index++) {
    if(!_give_me_a_good_name(values[index], values[index + 1], limit)) {
      return 0;
    }
  }
  return 1;
}
