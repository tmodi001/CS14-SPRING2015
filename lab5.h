//  =============== BEGIN ASSESSMENT HEADER ================
// Name: Tirth Modi
// SID: 861168370
// Date: 05-11-2015
//  ================== END ASSESSMENT HEADER ===============
#ifndef BST_H
#define BST_H

#include <cassert> 
#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include <string> 
#include <sstream> 
#include <map> 
#include <list>
#include <math.h>
#include <queue>

using namespace std; 

#define nil 0

// #define Value int // restore for testing. 
template < typename Value >
class BST {
    class Node { // binary tree node 
    public:
        Node* left;
        Node* right;
        Value value;
        bool cover;
        Node( const Value v = Value() )
            : left(nil), right(nil), value(v), cover (false) {}
        Value& content() { return value; }
        bool isInternal() { return left != nil && right != nil; } 
        bool isExternal() { return left != nil || right != nil; } 
        bool isLeaf() { return left == nil && right == nil; }
        int height() {
            if (right == nil && left == nil){return 0;}
            if (right == nil){return left->height() + 1;}
            if (left == nil){return right->height() + 1;}
            if (right->height() > left->height()){return  right->height() + 1;}
            if (right->height() < left->height()){return  left->height() + 1;}
            return  right->height() + 1;
        }
        int size() {
            if (right == nil && left == nil){return 1;}
            if (right == nil){return left->size() + 1;}
            if (left == nil){return right->size() + 1;}
            return left->size() + right->size() + 1;
        }
    }; // Node
    // const Node* nil; // later nil will point to a sentinel node.
    Node* root; 
    int count;
    vector<Node*> v;
    private:
        bool search (Value x, Node* y){
            if (y->content() == x){return true;}
            if (y->right == nil && y->left == nil){return false;}
            if (y->content() > x && y->left != nil){return search(x, y->left);}
            if (y->content() < x && y->right != nil){return search(x, y->right);}
            return false;
        }
        
        void preorder(Node* x)const{
            cout << x->content() << endl;
            if (x->left != nil){preorder(x->left);}
            if (x->right != nil){preorder(x->right);}
        }
        
        void postorder(Node* x)const {
            // Traverse and print the tree one Value per line in postorder.
            // FILL IN
            if (x->left != nil){postorder(x->left);}
            if (x->right != nil){postorder(x->right);}
            cout << x->content() << endl;
        }
        
        void inorder(Node* x) const{
            if (x->left != nil){inorder(x->left);}
            cout << x->content() << endl;
            if (x->right != nil){inorder(x->right);}
        }
        
    public:
        int size() { 
            // size of the overall tree.
            // FILL IN
            return root->size();
        }
        bool empty() { return size() == 0; }
        void print_node( const Node* n ) {
            // Print the node’s value.
            // FILL IN 
             cout << n->content() << endl;
        }
        bool search ( Value x ) { 
            // search for a Value in the BST and return true iff it was found.
            // FILL IN
            return search(x, root);
            //return false;   
        }
        void preorder()const {
            // Traverse and print the tree one Value per line in preorder.
            // FILL IN
            cout << "preorder: \n";
            preorder(root);
        }
        void postorder()const {
            // Traverse and print the tree one Value per line in postorder.
            // FILL IN
            cout << "postorder: \n";
            postorder(root);
        }
        void inorder()const {
            // Traverse and print the tree one Value per line in inorder.
            // FILL IN
            cout << "inorder: \n";
            inorder(root);
        }
        Value& operator[] (int n) {
            // returns reference to the value field of the n-th Node. 
            // FILL IN
            queue<Value> temp;
            operator2 (root, temp);
            for (int i = 0; i < n; i++){
                //cout << temp.front();
                temp.pop();
            }
            Node* temp3 = new Node(temp.front());
            return temp3->value;
        }
        void operator2 (Node* x, queue<Value> &q){
            if (x->left != nil){operator2(x->left, q);}
            q.push(x->value);
            if (x->right != nil){operator2(x->right, q);}
        }
        BST() : root(nil), count(0) {}
        void insert( Value X ) { root = insert( X, root ); } 
        Node* insert( Value X, Node* T ) {
            // The normal binary-tree insertion procedure ... 
            if ( T == nil ) {
                T = new Node( X ); // the only place that T gets updated.
            } else if ( X < T->value ) {
                T->left = insert( X, T->left );
            } else if ( X > T->value ) {
                T->right = insert( X, T->right );
            } else {
                T->value = X;
            }
            
            // later, rebalancing code will be installed here
            return T; 
        }
        void remove( Value X ) { root = remove( X, root ); }
        Node* remove( Value X, Node*& T ) {
        // The normal binary-tree removal procedure ... 
        // Weiss’s code is faster but way more intricate. 
            if( T != nil ) {
                if ( X > T->value ) {
                T->right = remove( X, T->right );
                } else if ( X < T->value ) { 
                    T->left = remove( X, T->left );
                } else {                        // X == T->value
                    if ( T->right != nil ) {
                        Node* x = T->right;
                        while ( x->left != nil ) x = x->left;
                        T->value = x->value; // successor’s value 
                        T->right = remove( T->value, T->right );
                    } else if ( T->left != nil ) {
                        Node* x = T->left;
                        while ( x->right != nil ) x = x->right;
                        T->value = x->value; // predecessor’s value 
                        T->left = remove( T->value, T->left );
                    } else {
                        delete T;
                        T = nil;
                    }
                }
            }
            return T;
        }
        void minCover(){
            minCover(root->left);
            minCover(root->right);
        }
        void minCover(Node *x) {
            if (x == nil) {return;}
            minCover(x->left);
            if (x->size() > 1) {
             v.push_back(x);
             x->cover = true;
            }
            minCover(x->right);
        }
        void displayMinCover() {
            int i;
            for (i = 0; i < v.size(); i++){
                cout << v.at(i)->value << ' ';
            }
            cout << endl << i << endl;
        }
        void printSum(int temp[], int sz){
            for(int i = 1; i <= sz; i++) {
                for (int y = i + 1; y <= sz; y++) {
                    if (temp[y] > temp[i]) {
                        int temp2 = temp[i];
                        temp[i] = temp[y];
                        temp[y] = temp2;
                    }
                }
            }
            for (int x = sz; x > 0; x--){
                cout << temp[x] << ' ';
            }
            cout << endl;
        }
        void findSumPath(Node* n, int sum, int array1[], int x, bool &boolvar){// finds best path
            if (n == nil) {return;}
            array1[++x] = n->value; 
            if (n->isLeaf()){
                int num = 0;
                //int x;
                for (int i = 1; i <= x; i++){
                    num = num + array1[i];
                }
                if (num == sum){ // the path is found
                    boolvar = true; 
                    printSum(array1, x);
                }
            x = 1;
            }
            if (!boolvar){
                findSumPath(n->left, sum, array1, x, boolvar);
                if (!boolvar){findSumPath(n->right, sum, array1, x, boolvar);}
            }
        }
        void findSumPath(int sum){
            if (root == nil){
                cout << '0';
            return;
            }
            if (root->value == sum){
                cout << root->value;
                return;
            }
            int temp = 0;
            int array1[1000];
            bool boolvar = false; 
            findSumPath(root, sum, array1, temp, boolvar);
            if (!boolvar){
                cout << "Not Found!\n";
            }
        }
        void vertSum(Node* node, int i, std::map<int, int>& m){
            m[i] = m[i] + node->value;
            if (node->right != nil){
                i = i + 1;
                vertSum(node->right, i, m);
                i = i - 1;
            }
            if (node->left != nil){
                i = i - 1;
                vertSum(node->left, i, m);
                i = i + 1;
            }
            return;
        }
        void displayVertSum(map<int, int> m){
            map<int,int>::iterator mp = m.begin();
            for (; mp != m.end(); ++mp) {
                cout << m[mp->first] << ' ';
            }
        }
        void vertSum(){
            if (root == nil){
                cout << '0';
                return;
            }
            map<int, int> temp;
            vertSum(root, 0, temp);
            displayVertSum(temp);
        }
};
#endif
