#include <iostream>
#include <string>
#include <vector>
#include "string.h"
using namespace std;

bool _male;
int _gens=0;

void tokenize(string str)
{
    const char delim='-';
    vector<string> out;
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}

    _gens+=out.size();
    
    /*
    if(strcmp("mother",out[out.size()-1]) || 
    strcmp("grandmother",out[out.size()-1]))
    _male=false;
    */
   if(out[out.size()-1].compare("mother")==0 || out[out.size()-1].compare("grandmother")==0){
   _male=false;
   printf("male is false\n");
   }
    else{
        _male=true;
        printf("males is true\n");
    }
    if(out[out.size()-1].compare("grandmother")==0||
    out[out.size()-1].compare("grandfather")==0)
    _gens++;

    printf("gens is: %d\n",_gens);
}

int main()
{
	//string s = "grandmother";
    string s="grand-grandmother";
	
	tokenize(s);

	return 0;
}