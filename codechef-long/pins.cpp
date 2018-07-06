#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        long int n;
        cin>>n;
        long int numPower = ceil((float)n/2);
        long int denPower = n;
        cout<<1<<" "<<1;
        for(long int i=0; i<denPower - numPower; i++)
            cout<<0;
        cout<<endl;
    }
    return 0;
}