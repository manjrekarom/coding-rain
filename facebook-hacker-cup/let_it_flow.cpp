#include<iostream>
#include<cstdio>

#define ll long long
#define p 1000000007

using namespace std;

ll powerRecursive(ll a, ll n, ll m) {
    if (n == 0)
        return 1;
    else if (n%2 == 0)
        return powerRecursive((a*a)%m, n/2, m);
    else return (a*powerRecursive((a*a)%m, (n-1)/2, m))%m;
}

int main(int argc, char const *argv[])
{
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
        freopen(argv[2], "w", stdout);
    }

    int t, caseNo = 1;
    cin>>t;
    while (t--) {
        int N;
        cin>>N;
        
        char grid[3][N];

        for (int i=0; i<3; i++) 
            for (int j=0; j<N; j++)
                cin>>grid[i][j];
        
        char src, sink;
        src = grid[0][0], sink = grid[2][N-1];

        cout<<"Case #"<<caseNo++<<": ";
        if (src == '#' || sink == '#') {
            cout<<0<<endl;
        }
        else if (N%2) {
            cout<<0<<endl;
        }
        else {
            int i = 0;
            int count = 0;
            while (i<N) {
                if (i == 0 || i == N-1) {
                    if (grid[1][i] == '#') {
                        cout<<0<<endl;
                        break;
                    }
                    i++;
                }
                else {
                    if (grid[1][i] == '.' && grid[1][i+1] == '.') {
                        if (grid[0][i] == '.' && grid[0][i+1] == '.') {
                            if (grid[2][i] == '.' && grid[2][i+1] == '.') {
                                count++;  
                            }
                        }
                        else if (grid[2][i] == '.' && grid[2][i+1] == '.') {
                            // just relax
                        }
                        else {
                            cout<<0<<endl;
                            break;
                        }
                    }
                    else {
                        cout<<0<<endl;
                        break;   
                    }
                    i += 2;
                }
            }
            if (i >= N) {
                cout<<powerRecursive(2, count, p)<<endl;
            }
        }
    }

    return 0;
}
