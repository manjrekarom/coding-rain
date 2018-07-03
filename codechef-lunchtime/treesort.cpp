#include<iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        long int n;
        cin>>n;

        pair<long int, long int> tree[n+1];
        long int l, r;
        
        for(long int i=1; i<=n; i++) {
            cin>>l>>r;
            tree[i].first = l;
            tree[i].second = r;
        }
    }
    return 0;
}
