#ifndef HEALTHRECORDS
#define HEALTHRECORDS
#ifndef PATIENT
#define PATIENT
#ifndef CHECKUP
#define CHECKUP

#include<sstream>
#include<iostream>
#include<vector>
#include<fstream>
#include<string>


using namespace std;

stringstream ss;
ifstream fin;
ofstream fout;

class Checkup
{
 private:
  string checkupDate;
  double height; // in feet
  double weight; // in pounds
  int cholesterol; // total cholesterol
  int hdlCholesterol; // HDL cholesterol
  int triglycerides; // Triglycerides concentration
  int glucose; // glucose level
  string bloodPressure; // blood pressure
 public:
  Checkup();
};


class Patient
{
 private:
  const long patientAccountNum; // =nextPatientAccountNum
  string firstName;
  string lastName;
  long SSN;
  char gender;
  string birthDate;
  vector <Checkup> patientCheckups;
  static long nextPatientAccountNum; // initialize it to 5000 and increment it by 2
  // as you create a new object
 public:
  Patient();
 };


class HealthRecords
{
 private:
  vector <Patient> patientsRecords;
 public:
  HealthRecords();
};


#endif
#endif
#endif
