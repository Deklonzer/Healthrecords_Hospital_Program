#include "checkup.h"
#ifndef PATIENT
#define PATIENT
//define Patient, which uses 
class Patient
{
 private: // attributes
  const  long patientAccountNum; // =nextPatientAccountNum
  string firstName;
  string lastName;
  long SSN;
  char gender;
  string birthDate;
  vector <Checkup> patientCheckups; //creates vector of Checkups
  static long nextPatientAccountNum; // initialize it to 5000 and increment it by 2
  // as you create a new object
 public:
  Patient();
  int age();//age getter
  void addCheck(Checkup a); //for adding checkup object to array
  void setAll(string a, string b, long c, char d, string e); //for setting attributes to a patient
  //getters
  long getNum();
  string getFName() const;
  string getLName() const;
  string getGen() const;
  string getDOB() const;
  //return vector of checkups
  vector <Checkup> getChecks() const;
  //return only 1
  Checkup getCheck(int index);
  long getSSN() const;
};


#endif
