//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Tirth Modi
// SID: 861168370
// Date: 04-20-2015
//  ================== END ASSESSMENT HEADER ===============
#include<iostream>
#include <stack>
 
using namespace std;

template <typename T>
class TwoStackFixed{
    private:
        T *arr;
        int sz;
        int stack1, stack2;
        int mid;
    public:
        //default constructor
        TwoStackFixed(int size, int maxtop){
           sz = size;
           arr = new T[size];
           stack1 = -1;
           stack2 = size;
           mid = maxtop;
        }
        // pushes into Stack 1
        void pushStack1(T value){
            if (stack1 < mid - 1){
                stack1++;
                arr[stack1] = value;
                return;
            }
            cout << "Stack Overflow\n";
        }
        // pushes into Stack 2
        void pushStack2(T value){
            if (!isFullStack2()){
                stack2--;
                arr[stack2] = value;
                return;
            }
            cout << "Stack Overflow\n";
        }
        // pops from stack 1
        T popStack1(){
           if (stack1 >= 0){
              T x = arr[stack1];
              arr[stack1] = 0;
              stack1--;
              return x;
           }
            cout << "Stack UnderFlow\n";
            exit(1);
        }
        // pops from stack 2
        T popStack2(){
           if (stack2 < sz){
              T x = arr[stack2];
              arr[stack2] = 0;
              stack2++;
              return x;
           }
           cout << "Stack UnderFlow\n";
           exit(1);
        }
        // checks to see if Stack 1 is full
        bool isFullStack1(){
            if (stack1 == mid - 1){return true;}
            return false;
        }
        // checks to see if Stack 2 is full
        bool isFullStack2(){
            if (stack2 == mid){return true;}
            return false;
        }
        // checks to see if Stack 1 is empty
        bool isEmptyStack1(){
            if (stack1 < 0){return true;}
            return false;
        }
        // checks to see if Stack 2 is empty
        bool isEmptyStack2(){
            if (stack2 == sz){return true;}
            return false;
        }
        // displays stack 1
        void displayStack1(){
            if (isEmptyStack1() == true){
                for (int i = 0; i < mid; i++){
                    cout << " _ ";
                }
                return;
            }
            cout << arr[0];
            for (int i = 1; i <= stack1; i++){
                 cout << " " << arr[i];
            }
            
            for (int i = stack1; i < mid - 1; i++){
                cout << " _ ";
            }
        }
        // displays stack 2
        void displayStack2(){
            if (isEmptyStack2() == true){
                for (int i = mid; i < sz; i++){
                    cout << " _ ";
                }
                return;
            }
            for (int i = stack2; i > mid; i--){
                cout << " _ ";
            }
            cout << arr[sz - 1];
            for (int i = sz - 2; i >= stack2; i--){
                 cout << " " << arr[i];
            }
            return;
        }
        // displays thw whole array
        void display() {
            displayStack1();
            displayStack2();
            cout << endl;
        }
};

template <typename T>
class TwoStackOptimal{
    private:
        int *arr;
        int sz;
        int stack1, stack2;
    public:
        // default constructor 
        TwoStackOptimal(int size){
            sz = size;
            arr = new T[size];
            stack1 = -1;
            stack2 = size;
        }
        // pushes into stack 1
        void pushFlexStack1 (T value){
            if (stack1 < stack2 - 1){
                stack1++;
                arr[stack1] = value;
                return;
            }
            cout << "Stack Overflow\n";
            exit(1);
        }
        // pushes into stack 2
        void pushFlexStack2(T value){
            if (stack1 < stack2 - 1){
                stack2--;
                arr[stack2] = value;
                return;
            }
            cout << "Stack Overflow\n";
            exit(1);
        }
        // pops stack 1
        T popFlexStack1(){
            if (stack1 >= 0 ){
                T x = arr[stack1];
                stack1--;
                return x;
            }
            cout << "Stack UnderFlow\n";
            exit(1);
        }
        // pops stack 2
        T popFlexStack2(){
            if (stack2 < sz){
                T x = arr[stack2];
                stack2++;
                return x;
            }
            cout << "Stack UnderFlow\n";
            exit(1);
        }
        // checks to see if Stack 1 is full
        bool isFullStack1(){
            if (stack1 == stack2){return true;}
            return false;
        }
        // checks to see if Stack 2 is full
        bool isFullStack2(){
            if (stack2 == stack1){return true;}
            return false;
        }
        // checks to see if Stack 1 is empty
        bool isEmptyStack1(){
            if (stack1 < 0){return true;}
            return false;
        }
        // checks to see if Stack 2 is empty
        bool isEmptyStack2(){
            if (stack2 == sz){return true;}
            return false;
        }
        // displays the whole array
        void display(){
            // displays stack 1
            for (int i = 0; i <= stack1; i++){
                cout << arr[i];
            }
            // displays the empty slots
            for (int i = stack1; i < stack2 - 1; i++){
                cout << " _ ";
            }
            // checks if Stack 2 is empty
            if (isEmptyStack2()) {
                cout << endl;
                return;
            }
            // displays Stack 2
            cout << arr[sz - 1];
            for (int i = sz - 2; i >= stack2; i--){
                 cout << arr[i];
            }
            // finishes with new line
            cout << endl;
        }
};

// this function adds the string paramater for the names
template <typename T>
void showTowerStates2(int n, stack<T>& A, stack<T>& B, stack<T>& C, string arr[]){
    // setting the names to strings 
    string string0 = arr[0];
    string string1 = arr[1];
    string string2 = arr[2];
    if (n == 0){
        cout << "Moved " << n << " from peg " << arr[0] << " to peg " << arr[2] << endl;
        return;
    }
    arr[1] = string2;
    arr[2] = string1;
    showTowerStates2(n - 1, A, C, B, arr);
    cout << "Moved " << n << " from peg " << arr[0] << " to peg " << arr[1] << endl;
    arr[0] = string1;
    arr[1] = string0;
    arr[2] = string2;
    showTowerStates2(n - 1, C, B, A, arr);
}
// regular call for the function
template <typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C){
    string arr[] = {"A","B","C"};
    // calls the function with array that contains the names
    showTowerStates2(n,A,B,C,arr);
}
