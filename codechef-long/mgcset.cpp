// C++ program to print distinct subset sums of
// a given array.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Uses Dynamic Programming to find distinct
// subset sums
void calcNoSubseq(int arr[], int n, int m) {
    int sum = 0;
    for (int i=0; i<n; i++)
        sum += arr[i];
 
    // dp[i][j] would be true if arr[0..i-1] has
    // a subset with sum equal to j.
    long long int dp[n+1][sum+1];
    memset(dp, 0, sizeof(dp));
 
    // There is always a subset with 0 sum
    for (int i=0; i<=n; i++)
        dp[i][0]++;
 
    // Fill dp[][] in bottom up manner
    for (int i=1; i<=n; i++)
    {
        dp[i][arr[i-1]]++;
        for (int j=1; j<=sum; j++)
        {
            // Sums that were achievable
            // without current array element
            if (dp[i-1][j]>=1)
            {
                dp[i][j] += dp[i-1][j];
                dp[i][j + arr[i-1]] += dp[i-1][j];
            }
        }
    }
 
    // check out the dp table
    for (int i=0; i<n+1; i++) {
        for (int j=0; j<sum+1; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    long long int count = 0;
    // Print last row elements
    for (int j=m; j<=sum; j+=m) {
        if (dp[n][j]>=1) {
            count += dp[n][j];
        }
    }

    // if total array sum is also m
    if (sum%m == 0) 
        count--;

    cout<<count<<endl;
}


// Driver code
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        
        int arr[n];
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }

        calcNoSubseq(arr, n, m);
    }
    return 0;
}
