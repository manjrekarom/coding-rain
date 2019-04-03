/*
Implement a stack API using only a heap. A stack implements the following methods:

push(item), which adds an element to the stack
pop(), which removes and returns the most recently added element (or throws an error if there is nothing on the stack)
Recall that a heap has the following operations:

push(item), which adds a new key to the heap
pop(), which removes and returns the max value of the heap
*/

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void swap(int& a, int& b) {
  int t;
  t = a;
  a = b;
  b = t;
}

class Heap {
  vector<int> vec;

  public:
    bool pushItem(int item);
    int popItem();
    void drawHeap();
    int findHeight();  
};

bool Heap::pushItem(int item) {
  if (vec.empty()) {
    vec.push_back(-1);
    vec.push_back(item);
  }
  else {
    vec.push_back(item);
    int index = vec.size() - 1; 
    for (int i = index; i>1; i = i/2) {
      if (vec[i] < vec[i/2]) {
        swap(vec[i], vec[i/2]);
      }
    }
  }
  return true;
}

int Heap::popItem() {
  cout<<"Popping"<<endl;
  return true;
}

int Heap::findHeight() {
  int height = 0;
  for (int i = vec.size() - 1; i > 0; i = i/2) {
    height++;
  }
  return height;
}

void Heap::drawHeap() {
  // i<vec.size()
  int height = findHeight();
  int spaceInit = pow(2, height - 1) - 1;
  bool breakOut = false;
  cout<<"Heaps don't lie"<<endl;
  for (int i=1; i<=height; i++) {
    for (int j=1; j<=spaceInit; j++) {
      cout<<"  ";
    }
    for (int j=pow(2, i-1); j<=pow(2, i) - 1; j++) {
      if (j > vec.size() - 1) {
        breakOut = true;
        break;
      }
      cout<<vec[j]<<"  ";
    }
    cout<<endl;
    spaceInit--;

    if (breakOut) 
      break;
  }
}

int main() {
  long long int n;
  cin>>n;
  Heap someHeap;
  int input;
  for (int i=0; i<n; i++) {
    cin>>input;
    someHeap.pushItem(input);
  }
  cout<<someHeap.findHeight()<<endl;
  someHeap.drawHeap();
	return 0;
}
