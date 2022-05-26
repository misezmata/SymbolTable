#include <bits/stdc++.h>
#include "SymbolTable.h"
// #include "ScopeTable.h"
using namespace std;

// unsigned long hash_sdbm(string s){
//     unsigned long hash = 0;
//     int l = s.length();
//     for(int i=0; i<l; i++){
//         int c = s[i];
//         hash = c + (hash << 6) + (hash << 16) - hash;
//     }
//     return hash;
// }

// unsigned long hash_sdbm2(const char* s){
//     unsigned  long hash = 0;
//     int c;
//     while(c = *s++){
//         hash = c + (hash << 6) + (hash << 16) - hash;
//     }
//     return hash;
// }


// int main(){
//     ScopeTable* parent = new ScopeTable(7);
//     parent->uniqueId = "1.2";
//     ScopeTable* child = new ScopeTable(7, parent, 10);
//     cout<<(child->uniqueId)<<endl;
//     child->insert(new SymbolInfo("a", "function"));
//     child->insert(new SymbolInfo("h", "function"));
//     child->insert(new SymbolInfo("o", "function"));
//     child->insert(new SymbolInfo("b", "function"));
//     child->print();
//     SymbolInfo* si = child->lookUpTable("b");
//     child->deleteNode(si);
//     child->print();
// }
int main(){
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
        }
        else {
            cout<<"Couldn't recognize command!"<<endl;
        }
        cout<<endl;
    }
    
}