#include "SymbolInfo.h"
#include "util.h"
class ScopeTable{
    void printList(SymbolInfo* s){
        SymbolInfo* cur = s;
        while(cur != nullptr){
            cur->print();
            cur = cur->next;
        }
        cout<<endl;
    }
    bool insertTo(int hash, SymbolInfo* s){
        if(hash_table[hash] == nullptr){
            hash_table[hash] = s;
            // cout<<s->name<<" inserted in: "<<uniqueId<<endl;
            cout<<"Inserted in ScopeTable# "<<uniqueId<<" at position "<<hash<<", "<<0<<endl;
            return true;
        }
        int count = 1;
        SymbolInfo* current = hash_table[hash];
        while(true){
            if(current->next == nullptr) break;
            if(current->name == s->name) {
                cout<<"This word already exists"<<uniqueId<<endl;
                return false;
            } 
            current = current->next;
            count++;
        }
        current->next = s;
        cout<<"Inserted in ScopeTable# "<<uniqueId<<" at position "<<hash<<", "<<count<<endl;
        return true;
    }
public:
    ScopeTable *parent;
    SymbolInfo **hash_table;
    string uniqueId;
    int size, scopeNo;
    ScopeTable(int size){
        hash_table = new SymbolInfo*[size];
        parent = nullptr;
        this->size = size;
        scopeNo = 0;
    }
    ScopeTable(int size, int n){
        hash_table = new SymbolInfo*[size];
        parent = nullptr;
        this->size = size;
        uniqueId = to_string(n);
        scopeNo = n;
    }
    ScopeTable(int size, ScopeTable* parent, int n){
        hash_table = new SymbolInfo*[size];
        this->size = size;
        this->parent = parent;
        uniqueId = parent->uniqueId + '.';
        uniqueId += to_string(n);
        scopeNo = n;
    }
    
    int hashFun(string s){
        unsigned long hash_value = hash_sdbm(s);
        hash_value %= size;
        return hash_value;
    }
    bool insert(SymbolInfo *s){
        int hash = hashFun(s->name);
        return insertTo(hash, s);
    }
    void deleteNode(SymbolInfo *s){
        int hash = hashFun(s->name);
        if(hash_table[hash] == s){
            hash_table[hash] = s->next;
            cout<<"Deleted "<<s->name<<" from: "<<uniqueId<<endl;
            return;
        }
        SymbolInfo* p = hash_table[hash];
        SymbolInfo* cur = p->next;
        while(cur != nullptr){
            if(cur == s){
                p->next = cur->next;
                cout<<"Deleted "<<s->name<<" from: "<<uniqueId<<endl;
                delete s;
                return;
            }
            p = cur;
            cur=cur->next;
        }
    }
    SymbolInfo* lookUpTable(string s){
        int hash = hashFun(s);
        SymbolInfo* cur = hash_table[hash];
        int count = 0;
        while(cur != nullptr){
            if(cur->name == s) {
                cout<<"Found in ScopeTable# "<<uniqueId<<" at position "<<hash<<", "<<count<<endl;
                return cur;
            }
            cur = cur->next;
            count++;
        }
        return nullptr;
    }
    
    void print(){
        cout<<"ScopeTable# "<<uniqueId<<endl;
        for(int i=0; i<size; i++){
            cout<<endl<<i<<" --> ";
            printList(hash_table[i]);
        }
    }
};