#include <bits/stdc++.h>
using namespace std;
class SymbolInfo{
public:
    SymbolInfo* next;
    string name, type;
    SymbolInfo(string name, string type){
        this->name = name;
        this->type = type;
        next = nullptr;
    }
    ~SymbolInfo(){
        next = nullptr;
    }
    void print(){
        cout<<"< "<<name<<" : "<<type<<">";
    }
    void print2(){
        cout<<"{"<<endl;
        cout<<"\tthis: "<<this<<endl;
        cout<<"\tname: "<<name<<endl;
        cout<<"\ttype: "<<type<<endl;
        cout<<"\tnext: ";
        if(next == nullptr) cout<<"null"<<endl;
        else cout<<next<<endl;
    }
};