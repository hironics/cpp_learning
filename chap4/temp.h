//#include <algorithm>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

//#include "grade.h"
#include "student_info.h"


using std::cin; using std::setprecision;
using std::cout; using std::sort;
using std::domain_error; using std::streamsize;
using std::endl; using std::string;
using std::max; using std::vector;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while( read(cin, record)){ //note every record will be changed after readin
		maxlen = max(maxlen, record.name.size());
		//prototype  push_back (const value_type& val);
		students.push_back(record); //record is copied into vector
	}

	sort(students.begin(), students.end(), compare);
	/*
	for(vector<Student_info>::iterator i = students.begin();
	         i!= students.end(); i++){
		cout << i->name;
	}
*/
	return 0;
}
