#include <iostream>
#include "string.h"
#include "FamilyTree.hpp"
#include <string>
#include <vector>
using namespace std;
using namespace std;
using namespace family;

bool _male;
int _gens=0;


    void node::setFather(string father){
        if(_father==NULL){
            _father=new node(father);
        }
        _father->_name=father;
    }

    void node::setMother(string mother){
        if(_mother==NULL){
            _mother=new node(mother);
        }
        _mother->_name=mother;
    }

    
    node* node::findNode(string name,int gens){
        if(gens==0)
        return;
        else gens--;
        if(strcmp(name.c_str(),_name.c_str())==0){
            return this;
        }
        else{
            if(_father!=NULL){
             node* person=_father->findNode(name,gens);
             if(person!=NULL)
             return person;
            }
            if(_mother!=NULL)
            return _mother->findNode(name,gens);
        }
        return NULL;
    }

    

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


node* Tree::findNode(string name){
        if(strcmp(name.c_str(),_root->_name.c_str())==0){
            return NULL;
        }
        return _root;
    }

void Tree::addFather(string name, string father){
    findNode(name)->setFather(father);
}

void Tree::addMother(string name, string mother){
    findNode(name)->setMother(mother);
}

string Tree::find(string name){
    tokenize(name);
    int gens=_gens;
    node* node =_root->findNode(name,gens);
    if(node==NULL)
    node=_root->findNode(name,gens);
    if(node!=NULL){
        return node->_name;
    }
    //return what();

}


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


string Tree::relation(string name){
   
    if(_root!=NULL && _root->_father!=NULL){
    string pat=_root->_father->relation(name,1,true);
    if(!pat.empty)
    return pat;
    }

    if(_root && NULL && _root->_mother!=NULL){
    string mot=_root->_mother->relation(name,1,false);
    if(!mot.empty)
    return mot;
    }

    return NULL;
}

string node::relation(string name, int gens,bool male){
    if(strcmp(name.c_str(),_name.c_str())==0){
        return ancestor(gens,male);
    }

    else{
    gens++;
    if(_father!=NULL){
    string pat=_father->relation(name,gens,true);
    if(!pat.empty)
    return pat;
    }
    
    if(_mother!=NULL){
    string mot=_mother->relation(name,gens,false);
    if(!mot.empty)
    return mot;
    }
    }

    return NULL; 
}





