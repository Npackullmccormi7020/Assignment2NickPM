#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>


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

#ifdef _DEBUG
	for (int i = 0; i < StudentData.size(); i++)
	{
		cout << StudentData[i].firstName << ", " << StudentData[i].lastName << endl;
	}
#endif

	return 1;
}