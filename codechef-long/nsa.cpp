#include<iostream>
#include<cstring>
#include<cstdlib>
#define SIGMA 26

using namespace std;

int main () {
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        
        long int N = s.length();

        for (long int i=0; i<N; i++) {
            s[i] -= 'a';
        }
        
        long int B[N][SIGMA] = {{0}};
        long int F[N][SIGMA] = {{0}};
        long int Y0 = 0;

        // DP table
        for (long int i=1; i<N; i++) {
            for (int c=0; c<SIGMA; c++) {
                B[i][c] = B[i-1][c] + (s[i-1]<c);
                F[N-i-1][c] = F[N-i][c] + (s[N-i]>c);
            }
            // calculation of initial Y0
            Y0 += F[N-i-1][s[N-i-1]];
        }

        long int optimal = Y0;
        // Calculating optimal cost
        for (long int i=0; i<N; i++) {
            for (int c=0; c<SIGMA; c++) {
                long int cost = abs(s[i] - c) + Y0 - (B[i][s[i]] + F[i][s[i]]) + (B[i][c] + F[i][c]);
                if (cost < optimal) 
                    optimal = cost;
            }
        }

        cout<<optimal<<endl;
    }
    return 0;
}