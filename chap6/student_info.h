#ifndef GUARD_Student_info
#define GUARD_Student_info


#include <iostream>
#include <ios>
#include <string>

#include <vector>
#include <list>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};
bool did_all_hw(const Student_info& s);
bool compare(const Student_info& a, const Student_info& b);
std::istream& read_hw(std::istream& is, std::vector<double>& scores);
std::istream& read(std::istream& is, Student_info& s);
#endif
