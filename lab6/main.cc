//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Tirth Modi
// SID: 861168370
// Date: 05-18-2015
//  ================== END ASSESSMENT HEADER ===============
#include "selectionsort.h"

using namespace std;

int main (){
    //Testing with single elements
    vector<int> myvector = {2,4,5,1,8,9};
    
    //Testing with pairs
    vector<pair<int,int>> myvector1;
    pair<int,int> pair1 (3, 6);
    myvector1.push_back(pair1);
    pair<int,int> pair2 (3, 1);
    myvector1.push_back(pair2);
    pair<int,int> pair3 (5, 1);
    myvector1.push_back(pair3);
    pair<int,int> pair4 (1, 1);
    myvector1.push_back(pair4);
    
    //calling the sort function
    selectionsort(myvector);
    selectionsort(myvector1);
    return 0;
}
