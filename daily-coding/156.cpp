/*
Given a positive integer n, find the smallest number of squared integers which sum to n.

For example, given n = 13, return 2 since 13 = 32 + 22 = 9 + 4.

Given n = 27, return 3 since 27 = 32 + 32 + 32 = 9 + 9 + 9.
*/

#include<iostream>
#include<cmath>
using namespace std;

bool isPerfectSquare(int val) {
  long long int valSqrRoot = sqrt(val);
  if (valSqrRoot * valSqrRoot == val) 
    return true; 
  return false;
}

long long int minSquareSum(long long int val) {
  if (isPerfectSquare(val))
    return 1;
  long long int bestResult = val;
  for(long long int i = val-1; i >= val/2; i--) {
    if (isPerfectSquare(i)) {
      long long int result = 1 + minSquareSum(val - i);
      if (bestResult > 1 + minSquareSum(val - i))
        bestResult = result;
    }
  }
  return bestResult;
}

int main() {
  long long int n;
  cin>>n;
  cout<<minSquareSum(n);
	return 0;
}