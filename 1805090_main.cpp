#include <bits/stdc++.h>
#include "1805090_SymbolTable.h"
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    SymbolTable* st = new SymbolTable(n);
    string s;
    while(cin>>s){
        if(s == "I") {
            string name, type;
            cin>>name>>type;
            cout<<s<<" "<<name<<" "<<type<<endl<<endl;
            st->insert(name, type);
        }else if(s == "L"){
            string name;
            cin>>name;
            cout<<s<<" "<<name<<endl<<endl;
            st->lookUp(name);
        }else if(s == "D"){
            string name;
            cin>>name;
            cout<<s<<" "<<name<<endl<<endl;
            st->remove(name);
        }else if(s == "P"){
            string ac;
            cin>>ac;
            cout<<s<<" "<<ac<<endl<<endl;
            if(ac == "A") st->printAll();
            else st->printCurrentScope();
        }else if(s == "S"){
            cout<<s<<endl<<endl;
            st->enterScope();
        }else if(s == "E") {
            cout<<s<<endl<<endl;
            st->exitScope();
        }else if(s == "Exit"){
            break;
        }
        else {
            cout<<"Couldn't recognize command!"<<endl;
        }
        cout<<endl;
    }

    delete st;
    
}
