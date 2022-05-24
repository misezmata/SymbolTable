#include "ScopeTable.h"
class SymbolTable{
    int tableSize;
    stack<ScopeTable*> tables;
    ScopeTable* currentTable;
    int currentTableScopeSize = 1;
    int globalScopeSize = 1;
public:
    SymbolTable(int size){
        currentTable = new ScopeTable(size);
        tables.push(currentTable);
        tableSize = size;
        currentTable->uniqueId = "1"; 
    }
    void enterScope(){
        ScopeTable* newTable;
        if(currentTable == nullptr){
            newTable = new ScopeTable(tableSize, globalScopeSize++);
            newTable->uniqueId = to_string(globalScopeSize++);
        }
        else{ 
            newTable = new ScopeTable(tableSize, currentTable, currentTableScopeSize);
        }
        tables.push(newTable);
        currentTable = newTable;
        cout<<"Created: "<<currentTable->uniqueId<<endl;
    }
    void exitScope(){
        // tables.pop();
        if(currentTable == nullptr){
            cout<<"no more to pop"<<endl;
            return;
        }
        currentTableScopeSize++;
        cout<<"deleting: "<<currentTable->uniqueId<<endl;
        currentTableScopeSize = currentTable->scopeNo + 1;
        currentTable = currentTable->parent;
    }
    bool insert(string name, string type){
        if(currentTable == nullptr) return false;
        return currentTable->insert(new SymbolInfo(name, type));
    }
    SymbolInfo* lookUp(string name){
        if(currentTable == nullptr) return nullptr;
        ScopeTable* cur = currentTable;
        while(true){
            SymbolInfo* si = cur->lookUpTable(name);
            if(si != nullptr) return si;
            cur = cur->parent;
            if(cur == nullptr) {
                cout<<name<<" is not found!"<<endl;
                return nullptr;
            }
        }
    }
    void printCurrentScope(){
        if(currentTable == nullptr) return;
        currentTable->print();
    }
    void printAllRec(ScopeTable* st){
        if(st == nullptr) return;
        printAllRec(st->parent);
        st->print();
    }
    void printAll(){
        if(currentTable == nullptr) return;
        printAllRec(currentTable);
    }
};