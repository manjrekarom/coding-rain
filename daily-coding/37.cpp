#include<iostream>
using namespace std;

void powerset(int *a, int size, int i) {
    // cout<<a[i]<<", ";
    
    // if (i == size-1) {
    //     cout<<" ";
    //     return;
    // }
    powerset(a, size, i+1);

    // cout<<"_, ";
    // if (i == size-1) {
    //     cout<<" ";
    //     return;
    // }
    powerset(a, size, i+1);
}


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    
    powerset(a, n, 0);
    return 0;
}
