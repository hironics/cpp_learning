
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

#include "student_info.h"
#include "grade.h"
#include "median.h"

using std::transform; using std::back_inserter;
using std::cin; using std::cout; using std::endl; using std::ostream;
using std::vector;
using std::string;
using std::accumulate;


/*
median calculation
*/
double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(),
			back_inserter(grades), grade_aux);
	return median(grades);
}

/*
average calculation
*/
double average(const vector<double>& v)
{
	double tot = 0.0;
    return accumulate(v.begin(), v.end(), 0.0);
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(),
			back_inserter(grades), average_grade);
	return median(grades);
}



double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(),
				back_inserter(nonzero), 0);
	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analsys(const vector<Student_info>& students);


void write_analysis(ostream& out, const string& name,
					double analysis(const vector<Student_info>&),
					const vector<Student_info>& did,
					const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
}
