//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Tirth Modi
// SID: 861168370
// Date: 05-25-2015
//  ================== END ASSESSMENT HEADER ===============
#ifndef LAB_H
#define LAB_H

#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <ctime>
#include <unordered_set>

using namespace std;

void fill(vector<string> &v, string listFile){
    ifstream file;
    file.open(listFile.c_str());
    if (!file.is_open()){
        cout << "Error: No File\n";
        exit(1);
    }
    while(!file.eof()){
        string temp;
        getline(file, temp);
        v.push_back(temp);
    }
    file.close();
}

int getTreeTime(const vector <string> &v, int n){
    set<string> s;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++){
        s.insert(v.at(i));
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds> (end-start).count();
}

int getHashTime(vector <string> const &v, int n){
    unordered_set<string> h;
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i){
        h.insert(v.at(i));
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds> (end-start).count();
}

void mix(vector <string> &v){
    for (unsigned i = 0; i < v.size(); i++){
        swap(v.at(i), v.at(rand() % 50000));
    }
}

int getTreeAvg(vector <string> &v, int n){
    mix(v);
    int ret = 0;
    for (int i = 0; i < 10; ++i){
        ret += getTreeTime(v, n);
    }
    return ret / 10.0;
}

int getHashAvg(vector <string> &v, int n){
    mix(v);
    int ret = 0;
    for (int i = 0; i < 10; ++i){
        ret += getHashTime(v, n);
    }
    return ret / 10.0;
}
#endif
