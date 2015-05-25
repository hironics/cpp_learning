#include "student_info.h"
#include "grade.h"
#include <algorithm>

using std::istream;
using std::vector;
using std::list;

bool compare(const Student_info& a, const Student_info& b)
{
	return a.name < b.name;
}

istream& read_hw(istream& is, vector<double> & scores)
{
	if(is){
		scores.clear();

		double x;
		while(is>>x)
			 scores.push_back(x);

		is.clear(); // prepare it for next run
	}
	return is;
}

istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

list<Student_info> extract_fails(list<Student_info>& students)
{
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

	while(iter != students.end()){
		if(fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else
			iter++;
	}
}


bool did_all_hw(const Student_info& s)
{
	return (std::find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end();
}

