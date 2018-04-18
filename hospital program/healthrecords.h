#include "patient.h"
#ifndef HEALTHRECORDS
#define HEALTHRECORDS
//uses patient, which uses checkup (Inception)
class HealthRecords
{
 private: //uses a vector of patient records
  vector <Patient> patientsRecords;
 public: //the meat and tatoes of this assignment's functions
  //adds a new patient to healthrecords
  void createNewPatient(string fName, string lName, long pSSN, char gender, string birthDate);
  //prints all of them
  void printAllPatients();
  //adds a checkup to a patient
  void addPatientCheckup(long pNum, string cDate, double pHeight, double pWeight, int pCholesterol, int pHDL, int pTriglyceride, int pGlucose, string pBloodPressure);
  //prints 1 checkup for 1 patient
  void printPatientCheckupSummary(long pNum, string sDate);
  //prints all checkups for 1 patient
  void printPatientHistory(long pNum);
  //for reading the file
  void processTransactionFile(string fileName);
};

#endif
