#include<ostream>
#include "node.hpp"
#include "string.h"
using namespace std;

int main(){
    node* yossi=new node("yossi");
    yossi->setFather("dan");
    printf("%s\n",yossi->_father->_name.c_str());
    return 0;
}