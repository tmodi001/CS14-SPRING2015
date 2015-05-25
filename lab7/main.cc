//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Tirth Modi
// SID: 861168370
// Date: 05-25-2015
//  ================== END ASSESSMENT HEADER ===============
#include "lab7.h"

using namespace std;

int main(){
    ofstream fout("data.txt");
    vector <string> v;
    fill(v, "words.txt");
    for(unsigned int i = 5000; i <= v.size(); i+=5000){
        int t = getTreeAvg(v, i);
        int h = getHashAvg(v, i);
        fout << i << ' ' << t << ' ' << h << ' ' 
        << t/static_cast<double>(i) << ' ' << h/static_cast<double>(i) << endl;
    }
}
