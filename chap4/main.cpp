#include <algorithm>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"
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

	while( read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	//sort(students.begin(), students.end(), compare);

	for(vector<Student_info>::iterator i = students.begin();
	         i!= students.end(); i++){
		try {
			double final_grade = grade(*i);
			streamsize prec = cout.precision();
			cout << i->name << string(maxlen + 1 - i->name.size(), ' ')
			 << setprecision(5) << final_grade << endl;
			cout.precision(prec);
	    }
	    catch(...){
			cout << "there is error " << endl;
		}
	}

	return 0;
}
