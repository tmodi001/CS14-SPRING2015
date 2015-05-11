//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Tirth Modi
// SID: 861168370
// Date: 05-11-2015
//  ================== END ASSESSMENT HEADER ===============
#include "lab5.h"

using namespace std;

int main (){
    // BST<int> test1;
    // cout << "Testcase: 1" << endl;
    // test1.insert(7);
    // test1.insert(6);
    // test1.insert(4);
    // test1.insert(3);
    // test1.insert(5);
    // test1.insert(10);
    // test1.insert(8);
    // test1.insert(13);
    // cout << "Part 1" << endl;
    // test1.minCover();
    // test1.displayMinCover();
    // cout << "Part 2" << endl;
    // test1.findSumPath(80);
    // cout << "Part 3" << endl;
    // test1.vertSum();
    // cout << endl;

    BST <int>test2;
    cout << "Testcase: 1" << endl;
    test2.insert(50);
    test2.insert(20);
    test2.insert(10);
    test2.insert(40);
    test2.insert(35);
    test2.insert(45);
    test2.insert(60);
    test2.insert(70);
    cout << "Part 1" << endl;
    test2.minCover();
    test2.displayMinCover();
    cout << "Part 2" << endl;
    test2.findSumPath(80);
    cout << "Part 3" << endl;
    test2.vertSum();
    cout << endl;
    return 0;
}
