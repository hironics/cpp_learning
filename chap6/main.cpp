#include <vector>
#include <iostream>

#include "student_info.h"
#include "analysis.h"

using std::cout ; using std::cin; using std::endl;

//bool did_all_hw(const Student_info& s);

int main()
{
	vector<Student_info> did, didnt;
	
	Student_info student;
	
	while(read(cin, student)){
		if(did_all_hw(student))
			 did.push_back(student);
		else
			 didnt.push_back(student);
	}
	
	if (did.empty()){
		cout << "Not any students turned in all homeworks" << endl;
	}
	
	write_analysis(cout, "median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	/*
	write_analysis(cout, "median of homework turned in",
				optimistic_median_analsysi, did, didnt);
	*/
	return 0;
}
