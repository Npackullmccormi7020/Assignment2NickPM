#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

//#define PRE_RELEASE

using namespace std;

// Struct containing the data for Student Data
struct STUDENT_DATA
{
	string firstName;
	string lastName;
};


// Main
int main(void)
{
	// Path for StudentData file
	string StudentDataPath = "StudentData.txt";

	// File IO Stream
	ifstream StudentDataIn;

	// Vector to store Student Data Structs
	vector<STUDENT_DATA> StudentData;

	// Statement to tell what mode the program is running in
#ifdef PRE_RELEASE
	cout << "Application is running in PRE_RELEASE Mode:" << endl;
#else
	cout << "Application Running in Standard Mode: " << endl;
#endif

	// Open File IO Stream using StudentData path
	StudentDataIn.open(StudentDataPath);

	// Check if file opened properly
	if (StudentDataIn.is_open())
	{
		// If file opened, create two temp variables used to parse file
		string line;
		STUDENT_DATA temp;

		// Parse the file line by line and save data to temp struct, then push into vector
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
		// If the file failed to open, print message
		cout << "Error Reading File" << endl;
	}
	// Close file IO stream
	StudentDataIn.close();


	// If in pre-release mode, open StudentData_Emails file
#ifdef PRE_RELEASE
	// Set up data for opening studentData_Emails
	string StudentEmailPath = "StudentData_Emails.txt";
	ifstream StudentDataEmailIn;

	// Open StudentData_Emails
	StudentDataEmailIn.open(StudentEmailPath);

	// Check if the file opened properly, print out sucess or failure
	if (StudentDataEmailIn.is_open())
	{
		cout << "Reading Emails File" << endl;
	}
	else
	{
		cout << "Error Reading File" << endl;
	}

	// Close file IO stream
	StudentDataEmailIn.close();
#endif


	// If in debug mode, print out full list of student data
#ifdef _DEBUG
	cout << endl << "=============================================" << endl;
	for (int i = 0; i < StudentData.size(); i++)
	{
		cout << StudentData[i].firstName << ", " << StudentData[i].lastName << endl;
	}
#endif

	// Exit
	return 1;
}