#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "student_info.h"

double grade(double, double, double);
double grade(const Student_info &);
double grade(double, double, const std::vector<double>&);


bool fgrade(const Student_info&);
#endif
