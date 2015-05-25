#include "strfunc.h"

#include <algorithm>

using std::vector;
using std::string;
using std::max;

string::size_type width(const vector<string>& strs)
{
	string::size_type maxlen = 0;
	for(vector<string>::const_iterator i = strs.begin();
		   i != strs.end(); i++){
		maxlen = max(maxlen, i->size());
	}
	return maxlen;
}

vector<string> frame(const vector<string>& s)
{
	vector<string> ret;
	string::size_type maxlen = width(s);
	string border(maxlen+4 , '*');
	
	ret.push_back(border);
	for(vector<string>::const_iterator i = s.begin();
		  i != s.end(); i++) {
		ret.push_back("* " + *i + string(maxlen - i->size(), ' ') + " *");
	}
	ret.push_back(border);
	return ret;
}
