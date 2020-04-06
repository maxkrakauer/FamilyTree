#include <iostream>
#include <string>
#include <vector>
#include "string.h"
using namespace std;

void tokenize(string const &str, const char delim,
			vector<string> &out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

int main()
{
	//string s = "grandmother";
    string s="grand-grand-grand-grandfather";
	const char delim = '-';

	vector<string> out;
	tokenize(s, delim, out);
/*
	for (auto &s: out) {
		std::cout << s << '\n';
	}
*/

int len=out.size();
if(len==1){
    cout<<out[0]<<'\n';
}

else{
    cout<<"size is: "+to_string(len)<<'\n';
    cout<<out[len-1]<<'\n';
}

	return 0;
}