#include <iostream>
#include <forward_list>

using namespace std;


bool is_prime (const int& value){
    if (value == 1){
        return false;
    }
    else if (value == 2){
        return true;
    }
    
    for (int i = 2; i < value - 1; i++){
        if ((value % i) == 0){
            return true;
        }
    }
    return false;
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