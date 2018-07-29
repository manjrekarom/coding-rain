#include<iostream>
#define ll long long

using namespace std;

ll powerRecursive(ll a, ll n) {
    if (n == 0) 
        return 1;
    else if (n%2 == 0)
        return powerRecursive(a*a, n/2);
    else return a*powerRecursive(a*a, (n-1)/2);
}

ll powerRecursive(ll a, ll n, ll m) {
    if (n == 0)
        return 1;
    else if (n%2 == 0)
        return powerRecursive((a*a)%m, n/2, m);
    else return (a*powerRecursive((a*a)%m, (n-1)/2, m))%m;
}

int main(int argc, char const *argv[]) {
    /* code */
    ll a, b;

    cout<<"Enter a and b: ";
    cin>>a>>b;
    
    ll m;

    cout<<"Enter m (or 0 to skip modulo): ";
    cin>>m;

    if(!m)
        cout<<"a^b = "<<powerRecursive(a, b)<<endl;
    else cout<<"a^b mod m = "<<powerRecursive(a, b, m)<<endl;

    return 0;
}
