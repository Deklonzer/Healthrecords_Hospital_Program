#include "patient.h"
//default constructor
long Patient::nextPatientAccountNum = 5000;
Patient::Patient():patientAccountNum(nextPatientAccountNum)
{
  nextPatientAccountNum += 2;
  firstName = " ";
  lastName = " ";
  SSN = 0;
  gender = ' ';
  birthDate = "";
}
//adds checkup to patient vector
void Patient::addCheck(Checkup a)
{
  patientCheckups.push_back(a);
}
//calculates and returns age very similarly to how we checked blood pressure (which is in checkup.cpp)
int Patient::age()
{
  int place = 0;
  int sum = 0;
  int year = 2018; //this - their DOB year = age
  for(int i = birthDate.length()-1; i > birthDate.length()-5; i--)
    {
      int bit = 0;
      bit = birthDate[i];
      switch(bit)
        {
        case 48:
          bit = 0;
          break;
        case 49:
          bit = 1;
          break;
        case 50:
          bit = 2;
          break;
        case 51:
          bit = 3;
          break;
        case 52:
          bit = 4;
          break;
        case 53:
          bit = 5;
          break;
        case 54:
          bit = 6;
          break;
        case 55:
          bit = 7;
          break;
        case 56:
          bit = 8;
          break;
        case 57:
          bit = 9;
          break;
        }
      switch(place)
        {
        case 1:
          bit *= 10;
          break;
        case 2:
          bit *= 100;
          break;
	case 3:
	  bit *= 1000;
	  break;
        }
      sum += bit;
      place++;
    }
  year -= sum;
  return year;
}

//setter for patient object
void Patient::setAll(string a, string b, long c, char d, string e)
{
  firstName = a;
  lastName = b;
  SSN = c;
  gender = d;
  birthDate = e;
}
//getters
long Patient::getNum()
{
  return patientAccountNum;
}
string Patient::getFName() const
{
  return firstName;
}
string Patient::getLName() const
{
  return lastName;
}
//returns Male or Female based on m/f char
string Patient::getGen() const
{
  if(gender=='M')
    return "Male";
  if(gender=='F')
    return "Female";
  else
    return "Invalid";
}
//getters
string Patient::getDOB() const
{
  return birthDate;
}
//returns entire vector of patients
vector <Checkup> Patient::getChecks() const
{
  return patientCheckups;
}
//returns 1 patient from index specified
Checkup Patient::getCheck(int index)
{
  return patientCheckups[index];
}
//getter
long Patient::getSSN() const
{
  return SSN;
}
