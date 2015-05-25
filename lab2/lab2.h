// Name: Tirth Modi
// SID: 861168370
// Date: 04-20-2015

#include <iostream>
#include <cmath>
#include <list>
#include <forward_list>

using namespace std;

template <typename Type>
struct Node{
    Type data;
    Node *next;
    Node(Type data) : data(data), next(0) {}
};

template <typename Type>
class List{
    private:
        Node<Type>* head;
        Node<Type>* tail;
        int size();
    public:
        List();
        ~List();
        void pop_front();
        void elementSwap(int pos);
};

template <typename Type>
forward_list <Type> listCopy(forward_list <Type> L, forward_list <Type>& P);

template <typename Type>
void printLots (forward_list<Type> L, forward_list<int> P);
