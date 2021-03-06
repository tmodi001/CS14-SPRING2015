// Name: Tirth Modi
// SID: 861168370
// Date: 04-20-2015

#include "lab2.h"

using namespace std;

bool is_prime (const int& value){
    if (value == 1){
        return false;
    }
    else if (value == 2){
        return false;
    }
    
    for (int i = 2; i < sqrt(value) + 1; i++){
        if ((value % i) == 0){
            return false;
        }
    }

    return true;
}

int primeCount(forward_list<int> list){
    if (list.empty()){return 0;}
    
    if (is_prime(list.front())){
        list.pop_front();
        return 1 + primeCount(list);
    }
    list.pop_front();
    return primeCount(list);
}

template <typename Type>
int List<Type>::size(){
    if (head == 0){return 0;}
    int temp = 0;
    Node<Type>* i = head;
    for (i = head; i != 0; i = i->next){
        temp += 1;
    }
    return temp + 1;  
}

template <typename Type>
List<Type>::List(){
    head = 0;
    tail = 0;
}

template <typename Type>
List<Type>::~List(){
    while (head != 0){pop_front();}
}

template <typename Type>
void List<Type>::pop_front(){
    if (head == 0){return;}
    Node<Type>* temp = head;
    head = head->next;
    delete temp;
    if (head == 0){tail = 0;}
}

template <typename Type>
void List<Type>::elementSwap(int pos){
    if (head == 0)
    {
       cout << "Error: Empty List!\n";
       return;
    }
    if (pos >= size() - 1){
        cout << "Error: Invalid Position!\n";
        return;
    }
    if (pos != 0 && size() >= 4){
        Node<Type> *curr = head->next;
        for (int i = 0; i <= pos; ++i){
            curr = curr->next; // after loop. curr will be desired node
        }
    }
}

template <typename Type>
forward_list <Type> listCopy(forward_list <Type> L, forward_list <Type>& P){
    L.reverse();
    return P.merge(L);
}

template <typename Type>
void printLots(forward_list<Type> L, forward_list<int> P){
    int temp = 0;
    for (auto i = P.begin(); i != P.end(); ++i){
        for (auto j = L.begin(); j != L.end(); ++j){
            if (temp == *i){
                cout << *j << ' ';
                temp = 0;
                break;
            }
            temp += 1;
        }
    }
}

int main ()
{
  forward_list<int> mylist = {7, 80, 7, 15, 85, 52, 6};
  mylist.remove_if (is_prime);      // 80 15 85 52
  cout << "mylist contains:";
  
  
  for (int& x: mylist) cout << ' ' << x;
  cout << endl;

  return 0;
}
