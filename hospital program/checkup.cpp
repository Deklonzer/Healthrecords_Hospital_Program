#include "checkup.h"
//default constructor
Checkup::Checkup()
{
  checkupDate = "";
  height = 0; // in feet
  weight = 0; // in pounds
  cholesterol = 0; // total cholesterol
  hdlCholesterol = 0; // HDL cholesterol
  triglycerides = 0; // Triglycerides concentration
  glucose = 0; // glucose level
  bloodPressure = "";
}
//setter
void Checkup::setCheck(string a, double b, double c, int d, int e, int f, int g, string h)
{
  checkupDate = a;
  height = b;
  weight = c;
  cholesterol = d;
  hdlCholesterol = e;
  triglycerides = f;
  glucose = g;
  bloodPressure = h;
}
//getters
double Checkup::getWeight() const
{
  return weight;
}

int Checkup::getChol() const
{
  return cholesterol;
}
int Checkup::getHDL() const
{
  return hdlCholesterol;
}

int Checkup::getTri() const
{
  return triglycerides;
}

int Checkup::getGlu() const
{
  return glucose;
}

string Checkup::getBP() const
{
  return bloodPressure;
}
//turns blood pressure from string to numbers so it can be compared for a printout
bool Checkup::compBP()
{
  int syst = 0;
  int dias = 0;
  int place = 0;
  //Systole
  for(int i = 0; i < 3; i++)
    {
      int part = 0;
      //ignore the slash
      if(!bloodPressure[i]=='/')
        {
          part = bloodPressure[i];
	  //one char at a time typecasted into ascii values, then translated into the respective number
          switch(part)
            {
            case 48:
              part = 0;
              break;
            case 49:
              part = 1;
              break;
            case 50:
              part = 2;
              break;
            case 51:
              part = 3;
              break;
            case 52:
              part = 4;
              break;
            case 53:
              part = 5;
              break;
            case 54:
              part = 6;
              break;
            case 55:
              part = 7;
              break;
            case 56:
              part = 8;
              break;
            case 57:
              part = 9;
              break;
            }
	  //accounts for the place of the number (ones,tens,hundreds)
          switch(place)
            {
            case 1:
              part *= 10;
              break;
            case 2:
              part *= 100;
              break;
	    case 3:
              part *= 1000;
              break;
            }
	  //sums the number and increments place value
          syst += part;
          place++;
        }
    }
  //resets place
  place = 0;
  //Diastole
  //repeats for other part
  for(int i = 0; i < 3; i++)
    {
      int local = 0;
      int place = 0;
      if(!bloodPressure[i]=='/')
        {
          local = bloodPressure[i];
          switch(local)
            {
            case 48:
              local = 0;
              break;
            case 49:
              local = 1;
              break;
            case 50:
              local = 2;
              break;
            case 51:
              local = 3;
	      break;
	    case 52:
	      local = 4;
              break;
            case 53:
              local = 5;
              break;
            case 54:
              local = 6;
              break;
            case 55:
              local = 7;
              break;
            case 56:
              local = 8;
              break;
            case 57:
              local = 9;
              break;
            }
          switch(place)
            {
            case 1:
              local *= 10;
              break;
            case 2:
              local *= 100;
              break;
            case 3:
              local *= 1000;
              break;
            }
          dias += local;
          place++;
        }
    }
  if(syst>120)
    return true;
  if(dias>80)
    return true;
  else
    return false;

}
//more getters
double Checkup::getLDL()
{
  return (double)(cholesterol - hdlCholesterol - triglycerides/5);
}

double Checkup::getCholHDLRatio()
{
  return (double)(cholesterol/hdlCholesterol);
}

double Checkup::getBMI()
{
  return (double)((703*weight)/((height*12)*(height*12)));
}

double Checkup::getHeight()
{
  return height;
}

string Checkup::getCheDate()
{
  return checkupDate.substr(0,3) + checkupDate.substr(6,4);
}
string Checkup::getDate()
{
  return checkupDate;
}
