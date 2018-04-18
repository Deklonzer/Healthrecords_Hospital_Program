#ifndef CHECKUP
#define CHECKUP
//include all the things we need
#include<sstream>
#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<string>


using namespace std;

//define Checkup class
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
  Checkup(); //constructor
  void setCheck(string a, double b, double c, int d, int e, int f, int g, string h); //setting values for the an object
  //the getters
  int getChol() const;
  int getHDL() const;
  int getTri() const;
  int getGlu() const;
  string getBP() const;
  bool compBP();
  double getLDL();
  double getCholHDLRatio();
  double getBMI();
  double getWeight() const;
  double getHeight();
  string getCheDate();  
  string getDate();
};

#endif
