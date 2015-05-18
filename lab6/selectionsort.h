//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Tirth Modi
// SID: 861168370
// Date: 05-18-2015
//  ================== END ASSESSMENT HEADER ===============
#ifndef S_H
#define S_H

#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <map>

using namespace std;

//overloaded display function for pairs
template<typename B, typename D>
void display(pair<B,D> l){
    cout << " " << "(" << l.first << "," << l.second << ")";
}

//overloaded display function for non-pairs
template<typename C>
void display(C l){
    cout << " " << l;
}

//sort function
template<typename L>
void selectionsort(L &l){
    int moves = 0;
    
    //prints the elements before sorting
    cout << "pre: ";
    for (auto i = l.begin(); i != l.end(); i++){
        display(*i);
    }
    cout << endl;
    
    //sorts the elements
    for (auto i = l.begin(); i != l.end(); i++){
        auto small = i;
        auto j = i;
        for (j = i; j != l.end(); j++){
            if (*i > *j){
                small = j;
            }
        }
        if (small != i){
            swap (*i,*small);
            moves = moves + 3;
        }
    }
    
    //prints the elements after sorting
    cout << "post:";
    for (auto i = l.begin(); i != l.end(); i++){
        display(*i);
    }
    cout << "\n0 copies and " << moves << " moves\n";
}

#endif
