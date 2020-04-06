#include <iostream>
#include <string>
#include <vector>
#include "string.h"
using namespace std;

string ancestor(int gens,bool male){
    string str="";
    for(int i=1; i<gens-1; i++){
        str="great-"+str;
    }
    if(gens>1)
    str+="grand";
    if(male)
    str+="father";
    else
    {
        str+="mother";
    }
    return str;
}


int main(){
/*
string str="hey";
str+="yall";
printf("%s\n",str.c_str());
*/
int gens=7;
bool male=false;
printf("%s\n",ancestor(gens,male).c_str());
return 0;

}