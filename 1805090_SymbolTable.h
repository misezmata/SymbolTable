#include "1805090_ScopeTable.h"
class SymbolTable{
    int tableSize;
    ScopeTable* currentTable;
public:
    SymbolTable(int size){
        currentTable = new ScopeTable(size, 1);
        tableSize = size;
        currentTable->uniqueId = "1"; 
    }
    ~SymbolTable(){
        ScopeTable* cur = currentTable;
        while(cur != nullptr){
            ScopeTable* parent = cur->parent;
            delete cur;
            cur = parent;
        }
    }
    void enterScope(){
        ScopeTable* newTable;
        if(currentTable == nullptr){
            newTable = new ScopeTable(tableSize, 1);
        }
        else{ 
            newTable = new ScopeTable(tableSize, currentTable);
        }
        currentTable = newTable;
        cout<<"New ScopeTable with id "<<currentTable->uniqueId<<" created"<<endl;
    }
    void exitScope(){
        if(currentTable == nullptr){
            cout<<"Not in a scope"<<endl;
            return;
        }
        cout<<"ScopeTable with id "<<currentTable->uniqueId<<" removed"<<endl;
        ScopeTable* temp = currentTable;
        
        currentTable = currentTable->parent;
        delete temp;
        if(currentTable == nullptr){
            currentTable = new ScopeTable(tableSize, 1);
        }
    }
    bool insert(string name, string type){
        if(currentTable == nullptr) return false;
        SymbolInfo* si = new SymbolInfo(name, type);
        if(currentTable->insert(si)){
            return true;
        }else{
            delete si;
            return false;
        }
    }
    SymbolInfo* lookUp(string name){
        if(currentTable == nullptr) return nullptr;
        ScopeTable* cur = currentTable;
        while(true){
            SymbolInfo* si = cur->lookUpTable(name);
            if(si != nullptr) return si;
            cur = cur->parent;
            if(cur == nullptr) {
                cout<<"Not found"<<endl;
                return nullptr;
            }
        }
    }
    bool remove(string name){
        return currentTable->deleteNode(name);
    }
    void printCurrentScope(){
        if(currentTable == nullptr) return;
        currentTable->print();
    }
    void printAll(){
        ScopeTable* cur = currentTable;
        while(cur != nullptr){
            cur->print();
            cur = cur->parent;
            if(cur != nullptr)cout<<endl;
        }
    }
};
