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
    SymbolTable* st = new SymbolTable(7);
    st->insert("a", "a");
    st->enterScope();
    st->insert("h", "h");
    st->enterScope();
    st->printAll();
    st->lookUp("o");
    st->lookUp("a");
    st->exitScope();
    st->enterScope();
    st->insert("foo", "FUNCTION");
    st->exitScope();
    st->enterScope();
    st->insert("i", "VAR");
    st->printAll();
    st->lookUp("foo");
    st->lookUp("j");
    st->exitScope();
    st->exitScope();
    st->enterScope();
    st->insert("5", "NUMBER");
    st->printAll();
}