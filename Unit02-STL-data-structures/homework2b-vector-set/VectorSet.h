#pragma once
#include <algorithm>
#include <vector>
 
using namespace std;

template<class T>
class VectorSet {
private: 
    vector<T> temp;
public:
    bool contains(T item) const {
        for(unsigned int i = 0; i < temp.size(); i++) {
            if(temp[i] == item) {
                return true;
            }
        }
        return false;
    }

    bool insert(T item) {
        for(unsigned int i = 0; i < temp.size(); i++) {
            if(temp[i] == item) {
                return false;
            }
        }
        
        temp.push_back(item);
        if(temp.back() == item) {
            return true;
        }
        else {
            return false;
        }
            
    }

    bool remove(T item) {
       for(unsigned int i = 0; i < temp.size(); i++) {
            if(temp[i] == item) {
                temp.erase(temp.begin() + i);
                return true;
            }
        }
        return false;
    }

    int size() const {
        return temp.size();
    }

    bool empty() const {
        if(temp.empty()) {
            return true;
        }
        else {
            return false;
        }
    }

    void clear() {
        temp.clear();
    }
};
