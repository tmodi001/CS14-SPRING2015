//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Tirth Modi
// SID: 861168370
// Date: 04-20-2015
//  ================== END ASSESSMENT HEADER ===============
#include "lab3.h"

using namespace std;

int main()
{
    // // Checks the Fixed stack 
    // TwoStackFixed<int> ts(5,2);
    // ts.display();
    // ts.pushStack1(1);
    // ts.display();
    // ts.pushStack2(1);
    // ts.display();
    // ts.pushStack2(5);
    // ts.display();
    // cout << "Popped element from Stack1 is " << ts.popStack1() << endl;
    // cout << "Popped element from Stack2 is " << ts.popStack2() << endl;
    // ts.display();
    
    // // Checks the Optimal stack
    // TwoStackOptimal<int> ts(5);
    // ts.display();
    // ts.pushFlexStack1(1);
    // ts.display();
    // ts.pushFlexStack2(1);
    // ts.display();
    // ts.pushFlexStack2(5);
    // ts.pushFlexStack2(5);
    // ts.display();
    // ts.display();
    // cout << "Popped element from Stack1 is " << ts.popFlexStack1() << endl;
    // cout << "Popped element from Stack2 is " << ts.popFlexStack2() << endl;
    // ts.display();
    
    // // checks the puzzle
    stack <int> one;
    stack <int> two;
    stack <int> three;
    showTowerStates(5, one, two, three);
    return 0;
}
