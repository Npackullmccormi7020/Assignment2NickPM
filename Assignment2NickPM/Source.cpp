#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#define PRE_RELEASE

using namespace std;


struct STUDENT_DATA
{
	string firstName;
	string lastName;
};



int main(void)
{
	string StudentDataPath = "StudentData.txt";

	ifstream StudentDataIn;
	vector<STUDENT_DATA> StudentData;

#ifdef PRE_RELEASE
	cout << "Application is running in PRE_RELEASE Mode:" << endl;
#else
	cout << "Application Running in Standard Mode: " << endl;
#endif

	StudentDataIn.open(StudentDataPath);
	if (StudentDataIn.is_open())
	{
		string line;
		STUDENT_DATA temp;
		while (!StudentDataIn.eof())
		{
			getline(StudentDataIn, line);

			istringstream sline(line);
			string fname;
			getline(sline, fname, ',');
			temp.firstName = fname;
			string lname;
			getline(sline, lname);
			temp.lastName = lname;

			StudentData.push_back(temp);
		}
	}
	else
	{
		cout << "Error Reading File" << endl;
	}
	StudentDataIn.close();

#ifdef PRE_RELEASE
	string StudentEmailPath = "StudentData_Emails.txt";
	ifstream StudentDataEmailIn;

	StudentDataEmailIn.open(StudentEmailPath);
	if (StudentDataEmailIn.is_open())
	{
		cout << "Reading Emails File" << endl;
	}
	else
	{
		cout << "Error Reading File" << endl;
	}
	StudentDataEmailIn.close();
#endif

#ifdef _DEBUG
	cout << endl << "=============================================" << endl;
	for (int i = 0; i < StudentData.size(); i++)
	{
		cout << StudentData[i].firstName << ", " << StudentData[i].lastName << endl;
	}
#endif

	return 1;
}