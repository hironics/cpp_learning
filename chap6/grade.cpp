#include <stdexcept>
#include <vector>
#include "grade.h"
#include "student_info.h"
#include "median.h"

using std::domain_error;
using std::vector;

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const std::vector<double>& scores)
{
	if(scores.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(scores));
}

bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}


double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm, s.final, 0) ;
	}
}
