#include <iostream>
#include "string.h"
using namespace std;


 class node{
public:
    string _name;
    node* _father;
    node* _mother;
public:
    node(string name);

    void setFather(string father);

    void setMother(string mother);
    
    node* node::findNode(string name, int gens);

    string relation(string name, int gens,bool male);
    
};

namespace family{

    class Tree{
        node* _root;

    node* findNode(string name);

    void addFather(string name, string father);

    void addMother(string name, string mother);

    string diplay();

    string relation(string name);

    string find(string name);

    void remove(string name);

    };
};