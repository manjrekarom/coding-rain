/*
Implement a stack API using only a heap. A stack implements the following methods:

push(item), which adds an element to the stack
pop(), which removes and returns the most recently added element (or throws an error if there is nothing on the stack)
Recall that a heap has the following operations:

push(item), which adds a new key to the heap
pop(), which removes and returns the max value of the heap
*/

#include<iostream>
#include<limits>
#include<cmath>
#include<vector>

using namespace std;

class Heap {
  /* Min heap */ 
  vector< pair<int, int> > vec;

  public:
    bool pushItem( pair< int, int> item);
    pair<int, int> popItem();
    void drawHeap();
    int findHeight();
    int* compare(pair<int, int> a, pair<int, int> b);

  private:
    int smallest(int parent, int left, int right) {
      if (vec[parent].first < vec[left].first) {
        if (vec[parent].first < vec[right].first) 
          return parent;
        else return right;
      }
      else {
        if (vec[left].first < vec[right].first) 
          return left;
        else return right;
      }
    }

    void swap(pair<int, int>& a, pair<int, int>& b) {
      pair<int, int> t;
      t = a;
      a = b;
      b = t;
    }
};

bool Heap::pushItem(pair<int, int> item) {
  if (vec.empty()) {
    vec.push_back(pair<int, int>(numeric_limits<int>::min(), numeric_limits<int>::min()));
    vec.push_back(item);
  }
  else {
    vec.push_back(item);
    int index = vec.size() - 1; 
    /* Percolate up */ 
    for (int i = index; i > 1; i = i/2) {
      if (vec[i].first < vec[i/2].first) {
        swap(vec[i], vec[i/2]);
      }
    }
  }
  return true;
}

pair<int, int> Heap::popItem() {
  pair<int, int> temp(numeric_limits<int>::min(), numeric_limits<int>::min());

  if (vec.size() < 2) {
    cout<<"Can't pop. Not enough elements."<<endl;
    return temp;
  }

  cout<<"Popping ..."<<endl; 
  temp = vec[1];
  
  /* Percolate down */
  vec[1] = vec.back();
  vec.pop_back();
  
  int i = 1;
  while (2*i + 1 < vec.size()) {
    int minIndex = smallest(i, 2*i, 2*i + 1);
    swap(vec[i], vec[minIndex]);
    i = minIndex;
  }

  return temp;
}

int Heap::findHeight() {
  int height = 0;
  
  for (int i = vec.size() - 1; i > 0; i = i/2) {
    height++;
  }

  return height;
}

void Heap::drawHeap() {
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
      cout<<vec[j].first<<", "<<vec[j].second<<"  ";
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
  pair<int, int> input;

  for (int i=1; i<=n; i++) {
    input.first = i;
    cin>>input.second;
    someHeap.pushItem(input);
  }

  cout<<someHeap.findHeight()<<endl;
  someHeap.drawHeap();

  for (int i=n; i>=1; i--) {
    cout<<someHeap.popItem().first<<", ";
  }

	return 0;
}
