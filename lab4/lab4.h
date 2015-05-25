//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Tirth Modi
// SID: 861168370
// Date: 05-04-2015
//  ================== END ASSESSMENT HEADER ===============
#ifndef LAB4_H
#define LAB4_H

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//priorityqueue class
template <typename Entry>
class priorityqueue{
    public:
        vector <Entry> entries;
        Entry& front() {return entries.back();}
        void pop() {entries.pop_back();}
        bool empty(){ return entries.empty();}
        void push (Entry e){
            entries.push_back(e);
            for (int i = entries.size() - 1; i != 0; --i){
                int sum1 = entries [i].first + entries [i].second;
                int sum2 = entries [i-1].first + entries [i-1].second;
                if(sum2 > sum1){swap (entries[i], entries[i-1]);}
                swap (entries[i], entries[i-1]);
            }
        }
};

//helper recursive function for pre-order
void printpreorder(int m, int n, int max){
    int temp1 = (2 * m) - n;
    int temp2 = (2 * m) + n;
    int temp3 = m + (2 * n);
    
    if (m + n < max){
        //prints the pair
        cout << m << ' ' << n << endl;
        //makes the recursive call
        printpreorder(temp1, m, max);
        printpreorder(temp2, m, max);
        printpreorder(temp3, n, max);
    }
}

// pre-order function call
void printpreorder(int k){
    cout << "pre-order" << endl;
    // calls the helper function
    printpreorder(2, 1, k);
    printpreorder(3, 1, k);
}

//helper recursive function for post-order
void printpostorder(int m, int n, int max){
    int temp1 = (2 * m) - n;
    int temp2 = (2 * m) + n;
    int temp3 = m + (2 * n);
    
    if (m + n < max){
        printpostorder(temp1, m, max);
        printpostorder(temp2, m, max);
        printpostorder(temp3, n, max);
        cout << m << ' ' << n << endl;
    }
}

// post-order function call
void printpostorder(int k){
    cout << "post-order" << endl;
    // calls the helper function
    printpostorder(2, 1, k);
    printpostorder(3, 1, k);
}

//Global queue
priorityqueue<pair<int, int> > sorted;

//helper recursive function for sorted
void sort(int m, int n, int max){
    int temp1 = (2 * m) - n;
    int temp2 = (2 * m) + n;
    int temp3 = m + (2 * n);
    
    pair<int, int> p;
    if (m + n < max){
        //pushes the pair into the queue
        p.first = m;
        p.second = n;
        sorted.push(p);
        // makes the recursive calls
        sort(temp1, m, max);
        sort(temp2, m, max);
        sort(temp3, n, max);
    }
}

void printsorted(int k){
    cout << "sorted" << endl;
    sort(2, 1, k);
    sort(3, 1, k);
    
    //sorts the lists according to the first value
    for (unsigned int i = 0; i < sorted.entries.size(); i++){
        int sum1 = sorted.entries [i].first + sorted.entries [i].second;
        int sum2 = sorted.entries [i+1].first + sorted.entries [i+1].second;
        if (sum1 == sum2) {
            if (sorted.entries [i].first < sorted.entries [i+1].first){
                swap (sorted.entries[i], sorted.entries[i+1]);
                i = 0;
            }
        }
    }
    
    //prints out the queue and frees the memory
    while (!sorted.empty()){
         cout << sorted.front().first << ' ' << sorted.front().second << endl;
         sorted.pop();
    }
}
#endif
