#ifndef analysis_H
#define analysis_H

#include <vector>
#include <string>
#include <iostream>

#include "student_info.h"

using std::vector; using std::ostream; using std::string;

double median_analysis(const vector<Student_info>& students);
double average_analysis(const vector<Student_info>& students);
double optimistic_median_analsysi(const vector<Student_info>& students);


void write_analysis(ostream& out, const string& name,
					double analysis(const vector<Student_info>&),
					const vector<Student_info>& did,
					const vector<Student_info>& didnt);
#endif
