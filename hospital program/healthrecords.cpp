#include "healthrecords.h"
//creates new patient in healthrecords
void HealthRecords::createNewPatient(string fName, string lName, long pSSN, char gender, string birthDate)
{
  bool invalid = false;
  for(int i = 0; i < patientsRecords.size(); i++)
    {//checks that ssn is not copy
      if(pSSN==patientsRecords[i].getSSN())
	invalid = true;
    }//errors if it is
  if(invalid)
    cout << "Information was duplicate, new patient not created." << endl;
  else
    {//creates object, sets values, and pushes it into health records
      Patient a;
      a.setAll(fName,lName,pSSN,gender,birthDate);
      patientsRecords.push_back(a);
      cout << "Patient successfully added." << endl;
    }
}

void HealthRecords::printAllPatients()
{//if empty will not print any
  if(patientsRecords.size()==0)
    cout << "There are no records of any patients." << endl << endl;
  else
    {
      cout << "----------------------------------------------------------------" << endl;
      cout << "Account No.     First Name     Last Name     Gender        DOB  " << endl;
      for(int i = 0; i < patientsRecords.size(); i++)
        { //otherwise prints all patients
          cout << "----------------------------------------------------------------" << endl;
          cout << patientsRecords[i].getNum() << setw(22) << patientsRecords[i].getFName() << setw(14) << patientsRecords[i].getLName() << setw(10) << patientsRecords[i].getGen() << setw(14) << patientsRecords[i].getDOB() << endl;
          cout << "----------------------------------------------------------------" << endl;
        }
    }
}
//adds checkup
void HealthRecords::addPatientCheckup(long pNum, string cDate, double pHeight, double pWeight, int pCholesterol, int pHDL, int pTriglyceride, int pGlucose, string pBloodPressure)
{
  
  bool valid = false;
  int index = 0;
  if(pNum<5000)//acct numbers start at 5000 so any less must be invalid
    cout << "Account number invalid, checkup not added to database." << endl;
  
  for(int i = 0; i < patientsRecords.size(); i++)
    {//makes sure acct num is in system
      if(patientsRecords[i].getNum()==pNum)
	{
	  index = i;
          valid = true;
	}
      
    }
  if(valid)
    {//creates object, sets values, and pushes checkup into patient records
      Checkup a;
      a.setCheck(cDate,pHeight,pWeight,pCholesterol,pHDL,pTriglyceride,pGlucose,pBloodPressure);
      patientsRecords[index].addCheck(a);
      cout << "Checkup successfully added to database." << endl;
    }
  else
    cout << "Account number invalid, checkup not added to database." << endl;
}

void HealthRecords::printPatientCheckupSummary(long pNum, string sDate)
{//prints a checkup from a patient
  bool heart = false;
  bool exists = false;
  bool extra = false;
  int patient = -1;
  int checkup = -1;
  
  for(int i = 0; i < patientsRecords.size(); i++)
    {//makes sure acct num and date of checkup are valid
      if(pNum==patientsRecords[i].getNum())
        for(int j = 0; j < patientsRecords[i].getChecks().size(); j++)
          if(sDate==patientsRecords[i].getCheck(j).getDate())
            {
              exists = true;
              patient = i;
              checkup = j;
            }
    }
  
  if(exists==true)
    {//prints all the valid attributes
      cout << patientsRecords[patient].getFName() << "  " << patientsRecords[patient].getLName() << endl;
      cout << "Born on " << patientsRecords[patient].getDOB() << ", " <<  patientsRecords[patient].getGen() << endl;
      cout << patientsRecords[patient].age() << " years old, " << patientsRecords[patient].getCheck(checkup).getHeight() << " feet, ";
      cout << fixed << setprecision(0) << patientsRecords[patient].getCheck(checkup).getWeight() << " pounds" << endl << endl << endl;
      cout << "\t\t\t\t" << sDate << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << "Total Cholesterol" << setw(22) << patientsRecords[patient].getCheck(checkup).getChol() << endl;
      cout << "(Reference Range: 125-199mg/dL)" << endl << endl;
      cout << "HDL Cholesterol" << setw(24) << patientsRecords[patient].getCheck(checkup).getHDL() << endl;
      cout << "(Reference Range: > or = 40 mg/dL)" << endl << endl;
      cout << "Triglycerides" << setw(26) << patientsRecords[patient].getCheck(checkup).getTri() << endl;
      cout << "(Reference Range: < 150 mg/dL)" << endl << endl;
      cout << "LDL Cholesterol" << setw(24) << patientsRecords[patient].getCheck(checkup).getLDL() << endl;
      cout << "(Reference Range: < 130 mg/dL)" << endl << endl;
      cout << "Cholesterol/HDL Ratio" << setw(18) << patientsRecords[patient].getCheck(checkup).getCholHDLRatio() << endl;
      cout << "(Reference Range: < or = 5.0)" << endl << endl;
      cout << "Glucose" << setw(32) << patientsRecords[patient].getCheck(checkup).getGlu() << endl;
      cout << "(Reference Range: 65-99 mg/dL)" << endl << endl;
      cout << "Blood Pressure" << setw(25) << patientsRecords[patient].getCheck(checkup).getBP() << endl;
      cout << "(Reference Range: < 120/80 mmHg)" << endl << endl;
      cout << fixed << setprecision(2) << "Body Mass Index" << setw(24) << patientsRecords[patient].getCheck(checkup).getBMI() << endl;
      cout << "(Reference Range: 18.5-24.9)" << endl << endl;
      cout << "--------------------------------------------------------------------" << endl;
      //checks for values outside of normal ranges, and prints notes to correlate
      if(patientsRecords[patient].getCheck(checkup).getChol()>199||patientsRecords[patient].getCheck(checkup).getChol()<125)
	{
          cout << "Notes to patient: " << "-   Total Cholesterol levels outside of normal ranges.";
          extra = true;
	  heart = true;
        }
      if(patientsRecords[patient].getCheck(checkup).getHDL()<40)
        {
          cout << endl << "Notes to patient: " << "-   HDL Cholesterol level outside of normal ranges.";
          extra = true;
          heart = true;
	}
      if(patientsRecords[patient].getCheck(checkup).getTri()>=150)
      {
	cout << endl << "Notes to patient: " << "-   Triglyceride levels outside of normal ranges.";
	extra = true;
	heart = true;
      }
      if(patientsRecords[patient].getCheck(checkup).getLDL()>=130)
	{
	  cout << endl << "Notes to patient: " << "-   LDL Cholesterol levels outside of normal ranges.";
	  extra = true;
	  heart = true;
	}
      
      if(patientsRecords[patient].getCheck(checkup).getCholHDLRatio()>5.0)
	{
	  cout << endl << "Notes to patient: " << "-   Total/HDL Cholesterol Ratio outside of normal ranges.";
	  extra = true;
	  heart = true;
	}
      
      if(patientsRecords[patient].getCheck(checkup).getGlu()<65||patientsRecords[patient].getCheck(checkup).getGlu()>99)
	{
	  cout << endl << "Notes to patient: " << "-   Glucose levels outside of normal ranges.";
	  extra = true;
	  heart = true;
	}
      if(heart)
	cout <<  endl << "Notes to patient: " << "-   One or more of these correspond to a higher risk of heart disease." << endl;
      if(patientsRecords[patient].getCheck(checkup).compBP())
	{	
	  cout << "Notes to patient: " << "-   Has hypertension (high blood pressure)" << endl; 
	  extra = true;
	}
      if(patientsRecords[patient].getCheck(checkup).getBMI()>=25)
	{
	  cout << "Notes to patient: " << "-   Is Overweight with increased risk for health conditions such as heart disease, stroke." << endl;
	  extra = true;
	}
      if(patientsRecords[patient].getCheck(checkup).getBMI()<=18.5)
	{
	  cout << "Notes to patient: " << "-   Is Underweight with increased risk of electrolyte imbalances and osteoporosis." << endl;
	  extra = true;
	}
      if(!extra)
	cout << "You appear to be in perfect health, nothing more to report." << endl;
      cout << "--------------------------------------------------------------------" << endl;
      
    }
  
  else
    cout << "There is no record of this checkup." << endl;
}

void HealthRecords::printPatientHistory(long pNum)
{//prints all checkups
  bool pat = false;
  int patient;
  for(int i = 0; i < patientsRecords.size(); i++)
    {
      if(pNum==patientsRecords[i].getNum())
        {
          pat = true;
          patient = i;
        }
    }
  //very similar to above functino, except prints every single checkup and relevant information
  if(pat)
    {
      cout << patientsRecords[patient].getFName() << "  " << patientsRecords[patient].getLName() << endl;
      cout << "Born on " << patientsRecords[patient].getDOB() << ", " <<  patientsRecords[patient].getGen() << endl << endl;
      cout << "\t\t\t\t";
      for(int i = 0; i < patientsRecords[patient].getChecks().size(); i++)
        cout << fixed << setprecision(0) << patientsRecords[patient].getCheck(i).getCheDate() << "     ";
      cout << endl;
      cout << "--------------------------------------------------------------------" << endl;
      cout << "Total Cholesterol" << setw(22);
      for(int i = 0; i < patientsRecords[patient].getChecks().size(); i++)
        cout << patientsRecords[patient].getCheck(i).getChol() << "         ";
      cout << endl;
      cout << "(Reference Range: 125-199mg/dL)" << endl << endl;
      cout << "HDL Cholesterol" << setw(24);
      for(int i = 0; i < patientsRecords[patient].getChecks().size(); i++)
        cout << patientsRecords[patient].getCheck(i).getHDL() << "         ";
      cout << endl;
      cout << "(Reference Range: > or = 40 mg/dL)" << endl << endl;
      cout << "Triglycerides" << setw(26);
      for(int i = 0; i < patientsRecords[patient].getChecks().size(); i++)
        cout << patientsRecords[patient].getCheck(i).getTri() << "         ";
      cout << endl;
      cout << "(Reference Range: < 150 mg/dL)" << endl << endl;
      cout << "LDL Cholesterol" << setw(24);
      for(int i = 0; i < patientsRecords[patient].getChecks().size(); i++)
        cout << patientsRecords[patient].getCheck(i).getLDL() << "         ";
      cout << endl;
      cout << "(Reference Range: < 130 mg/dL)" << endl << endl;
      cout << "Cholesterol/HDL Ratio" << setw(18);
      for(int i = 0; i < patientsRecords[patient].getChecks().size(); i++)
        cout << patientsRecords[patient].getCheck(i).getCholHDLRatio() << "         ";
      cout << endl;
      cout << "(Reference Range: < or = 5.0)" << endl << endl;
      cout << "Glucose" << setw(32);
      for(int i = 0; i < patientsRecords[patient].getChecks().size(); i++)
        cout << patientsRecords[patient].getCheck(i).getGlu() << "         ";
      cout << endl;
      cout << "(Reference Range: 65-99 mg/dL)" << endl << endl;
      cout << "Blood Pressure" << setw(25);
      for(int i = 0; i < patientsRecords[patient].getChecks().size(); i++)
        cout << patientsRecords[patient].getCheck(i).getBP() << "         ";
      cout << endl;
      cout << "(Reference Range: < 120/80 mmHg)" << endl << endl;
      cout << "Body Mass Index" << setw(24);
      for(int i = 0; i < patientsRecords[patient].getChecks().size(); i++)
        cout << fixed << setprecision(2) << patientsRecords[patient].getCheck(i).getBMI() << "         ";
      cout << endl;
      cout << "(Reference Range: 18.5-24.9)" << endl << endl;
      cout << "--------------------------------------------------------------------" << endl;
      
    }
  else
    cout << "Patient not found, no records to output." << endl;
  
}

void HealthRecords::processTransactionFile(string fileName)
{//defines many temporary variables for reading in from file
  ifstream fin;
  long pNum;
  string cDate;
  double pHeight;
  double pWeight;
  int pCholesterol;
  int pHDL;
  int pTriglyceride;
  int pGlucose;
  string pBloodPressure;

  string fName;
  string lName;
  long pSSN;
  char gender;
  string birthDate;

  string cmd;
  //file name
  fin.open(fileName.c_str());
  if (fin) //makes sure fin worked
    {
      while (fin>>cmd)
	//runs HealthRecord member functions based on command that is read in
        {
	  if (cmd == "CreateNewPatient")
            {
              fin >> fName >> lName;
              fin >> pSSN;
              fin >> gender;
              fin >> birthDate;
              createNewPatient(fName, lName, pSSN, gender, birthDate);
            }
          else if (cmd == "PrintAllPatients")
            {
              printAllPatients();
            }
          else if (cmd == "AddPatientCheckup")
            {
              fin >> pNum;
              fin >> cDate;
              fin >> pHeight >> pWeight;
              fin >> pCholesterol >> pHDL >> pTriglyceride >> pGlucose;
              fin >> pBloodPressure;
              addPatientCheckup(pNum, cDate, pHeight, pWeight, pCholesterol, pHDL, pTriglyceride, pGlucose, pBloodPressure);
            }
          else if (cmd == "PrintPatientHistory")
            {
              fin >> pNum;
	      printPatientHistory(pNum);
            }
          else if (cmd == "PrintPatientCheckupSummary")
            {
              fin >> pNum;
              fin >> cDate;
              printPatientCheckupSummary(pNum, cDate);
            }
	  
        }
    }
  //if no appropriate file is found, prints error
  else
    cout << "Could not find file." << endl;
  fin.close();
  //closes ifstream
}
