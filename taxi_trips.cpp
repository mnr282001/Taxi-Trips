#include <stdexcept>
#include <string>
using std::string;
#include "taxi_trips.h"




bool is_payment_valid(string type, string valid_types[], unsigned int size) {
  // TODO(student): implement
  unsigned int counterT = 0;
  unsigned int iHolder;
  if (size==0) {
	  throw std::invalid_argument("Size is 0");
  }
  for (int i = 0; i < 4; i++) {
	  if(type == valid_types[i]) {
		  counterT++;
		  iHolder = i;
	  }	
  }
  if ((counterT > 0)&&(size > iHolder)) {
	  return true;
  } else {
	  return false;
  }
}

double max(double values[], unsigned int size) {
  // TODO(student): implement
  if(size == 0) {
	  throw std::invalid_argument("Size of 0");
  }
  if(size == 1) {
	  return values[0];
  }
  double maxHolder = values[0];
  for (unsigned int i = 0; i < size; i++) {
	  if (values[i] >= maxHolder) {
		  maxHolder = values[i];
	  }
  }
	  
  return maxHolder;
}

double min(double values[], unsigned int size) {
  // TODO(student): implement
  if(size == 0) {
	  throw std::invalid_argument("Size of 0");
  }
  if(size == 1) {
	  return values[0];
  }
  double minHolder = values[0];
  for (unsigned int i = 0; i < size; i++) {
	  if (minHolder >= values[i]) {
		  minHolder = values[i];
	  }
  }
	  
  return minHolder;
}

double average(double values[], unsigned int size) {
  // TODO(student): implement
  if(size == 0) {
	  throw std::invalid_argument("Size of 0");
  }
  if(size==1) {
	  return values[0];
  }
  double average = 0;
  for (unsigned int i = 0; i < size; i++) {
	  average = average + values[i];
  }
  average = average/size;
  return average;
}

double mode(double values[], unsigned int size) {
  // TODO(student): implement
  if(size == 0) {
	  throw std::invalid_argument("Size of 0");
  }
  if(size==1) {
	  return values[0];
  }
  double testArray[MAX_TRIPS];
  double x_i;
  double x_p;
  double counter_x;
  for (unsigned int i = 0; i < size; ++i) {
	  counter_x = 0;
	  x_i = values[i];
	  for (unsigned int p = 0; p < size; ++p) {
		  x_p = values[p];
		  if (x_i == x_p) {
			  ++counter_x;
		  }
	  }
	  testArray[i] = counter_x;
  }
  if (max(testArray,size) == 0) {
	  return testArray[0];
  }
  double maxHolder = testArray[0];
  double modeOutput = values[0];
  for(unsigned int i = 0; i < size; ++i) {
	  if(testArray[i] > maxHolder) {
		  maxHolder = testArray[i];
		  modeOutput = values[i];
	  }
  }
  return modeOutput;
	  
}

unsigned int length_longest_seq_zeros(double values[], unsigned int size) {
  // TODO(student): implement
  if(size == 0) {
	  throw std::invalid_argument("Size of 0");
  }
  unsigned int count;
  unsigned int p;
  double testArrays[MAX_TRIPS];
   
  for (unsigned int i = 0; i < size; ++i) {
	  count = 0;
	  p = i;
	  while(values[p] == 0 && p < size) {
		  ++count;
		  ++p;
	  }
	  testArrays[i]=count;
	  while(p>i+1) {
		  testArrays[i+1] = 0;
		  ++i;
	  }
  }
  
  return max(testArrays,size);
}
