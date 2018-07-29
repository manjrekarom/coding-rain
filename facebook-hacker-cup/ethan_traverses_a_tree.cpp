#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>

using namespace std;

void preOrder(pair<int, int> *tree, int *sequence, int nodeIdx, int *fillPos) {
    if (nodeIdx == 0) {
        return;
    }

    sequence[(*fillPos)++] = nodeIdx;
    preOrder(tree, sequence, tree[nodeIdx].first, fillPos); 
    preOrder(tree, sequence, tree[nodeIdx].second, fillPos); 
}

void postOrder(pair<int, int> *tree, int *sequence, int nodeIdx, int *fillPos) {
    if (nodeIdx == 0) {
        return;
    }

    postOrder(tree, sequence, tree[nodeIdx].first, fillPos); 
    postOrder(tree, sequence, tree[nodeIdx].second, fillPos);
    sequence[(*fillPos)++] = nodeIdx; 
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr1[], int arr2[], int n)
{
   int i, j;
   bool swapped;
   for (i = 1; i <= n-1; i++)
   {
     swapped = false;
     for (j = 1; j <= n-i; j++)
     {
        if (arr1[j] > arr1[j+1])
        {
           swap(&arr1[j], &arr1[j+1]);
           swap(&arr2[j], &arr2[j+1]);
           swapped = true;
        }
     }
 
     // if no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
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
        int K, N;
        cin>>N>>K;

        pair<int, int> tree[N+1];

        for (int i=1; i<=N; i++) {
            cin>>tree[i].first>>tree[i].second; 
        }

        int labels[N+1];
        memset(labels, -1, (N+1)*sizeof(labels[0]));
    
        int preOrderSequence[N+1];
        int preFillPos = 1;
        preOrder(tree, preOrderSequence, 1, &preFillPos);

        int postOrderSequence[N+1];
        int postFillPos = 1;
        postOrder(tree, postOrderSequence, 1, &postFillPos);

        // for (int i=1; i<=N; i++) {
        //     cout<<preOrderSequence[i]<<" ";
        // }
        // cout<<endl;
        
        // for (int i=1; i<=N; i++) {
        //     cout<<postOrderSequence[i]<<" ";
        // }
        // cout<<endl;

        // qsort one array with respect to another one
        bubbleSort(preOrderSequence, postOrderSequence, N);        

        // for (int i=1; i<=N; i++) {
        //     cout<<preOrderSequence[i]<<" ";
        // }
        // cout<<endl;
        
        // for (int i=1; i<=N; i++) {
        //     cout<<postOrderSequence[i]<<" ";
        // }
        // cout<<endl;

        int label = 1;
        for (int i=1; i<=N; i++) {  
                      
            int first = preOrderSequence[i];
            int second = postOrderSequence[i];


            if (labels[first] == -1 || labels[second] == -1) {
                while (labels[first] == -1 || labels[second] == -1) {
                    labels[first] = label;
                    labels[second] = label;
                    int t = first;
                    first = second;
                    second = postOrderSequence[second];  
                }

                label++;
                if (label > K) {
                    label = 1;
                }
            }
        }

        cout<<"Case #"<<caseNo++<<": ";

        set< int > labelSet;
        for (int i=1; i<=N; i++) {
            labelSet.insert(labels[i]);
        }

        if (labelSet.size() < K) { 
            cout<<"Impossible";
        }
        else {
            for (int i=1; i<=N; i++) {
                cout<<labels[i]<<" ";
            }
        }

        cout<<endl;
    }

    return 0;
}