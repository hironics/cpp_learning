#include <string>
#include <cctype>
#include <vector>

#include "strfunc.h"

using std::string;
using std::vector;


vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;
	while(i != s.size()){
		//remove leading space
		while(i != s.size() && isspace(s[i])){
			i++;
		}
		//loop to next space
		string_size j = i;
		while(j != s.size() && !isspace(s[j])){
			j++;
		}
		if(i != j){
			ret.push_back(s.substr(i, j-i));
			i = j;
		}
	}
	return ret;
}

#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::getline;

int main() {
	string s;
	// read and split each line of input
	while (getline(cin, s)) {
		vector<string> v = frame(split(s));
		// write each word in v
		for (vector<string>::size_type i = 0; i != v.size(); ++i)
			cout << v[i] << endl;
	}
	return 0;
}
