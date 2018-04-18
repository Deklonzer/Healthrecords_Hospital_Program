#include "healthrecords.h"

int main()
{
  //defines healthrecords object
  HealthRecords hr;
  //runs processtransactionfile function, which in turn runs all over necessary functions
  hr.processTransactionFile("hw2.txt");

  //end progra,
  return 0;
}
