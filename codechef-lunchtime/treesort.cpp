#include<iostream>
#define Nmax 100005

using namespace std;

pair<long int, long int> vals[Nmax], tree[Nmax];
long int maxLeaf[Nmax], minLeaf[Nmax];
long int n;

long int solve(pair<long int, long int> node, long int idx) {
    if(node.first == -1) {
        vals[idx].first = node.second;
        vals[idx].second = node.second;
        minLeaf[idx] = node.second;
        maxLeaf[idx] = node.second;
        return 0;
    }    
    else {
        long int lft = solve(tree[node.first], node.first);
        long int rgt = solve(tree[node.second], node.second);

        if (lft == -1 || rgt == -1) {
            return -1;
        }
        else if (minLeaf[node.first] >= maxLeaf[node.second]) {
            // Left whole is greater than right whole
            tree[idx].first = node.second;
            tree[idx].second = node.first;
            minLeaf[idx] = minLeaf[node.second];
            maxLeaf[idx] = maxLeaf[node.first];
            return lft + rgt + 1;
        }
        else if (maxLeaf[node.first] <= minLeaf[node.second]) {
            // Right whole is greater than left whole
            minLeaf[idx] = minLeaf[node.first];
            maxLeaf[idx] = maxLeaf[node.second];  
            return lft + rgt;
        }
        else {
            // Cannot be sorted if minimums and maximums overlap
            return -1;
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n;

        long int l, r;
        
        for(long int i=1; i<=n; i++) {
            cin>>l>>r;
            tree[i].first = l;
            tree[i].second = r;
        }

        cout<<solve(tree[1], 1)<<endl;
    }
    return 0;
}
