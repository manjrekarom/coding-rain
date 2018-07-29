#include<iostream>
#include<cstring>

using namespace std;

char grid[105][105];

void leftShifted (int n, int m) {
    for (int i=0; i<n; i++) {
        int count = 0;
        for (int j=0; j<m; j++) {
            if (grid[i][j] == '1')
                count++;
        }
        for (int j=0; j<m; j++) {
            if (j<count) 
                grid[i][j] = '1';
            else 
                grid[i][j] = '0';
        }
    }
}

void rightShifted (int n, int m) {
    for (int i=0; i<n; i++) {
        int count = 0;
        for (int j=0; j<m; j++) {
            if (grid[i][j] == '1')
                count++;
        }
        for (int j=0; j<m; j++) {
            if (j<m-count) 
                grid[i][j] = '0';
            else 
                grid[i][j] = '1';
        }
    }
}

void upShifted (int n, int m) {
    for (int j=0; j<m; j++) {
        int count = 0;
        for (int i=0; i<n; i++) {
            if (grid[i][j] == '1')
                count++;
        }
        for (int i=0; i<n; i++) {
            if (i<count) 
                grid[i][j] = '1';
            else 
                grid[i][j] = '0';
        }
    }
}

void downShifted (int n, int m) {
    for (int j=0; j<m; j++) {
        int count = 0;
        for (int i=0; i<n; i++) {
            if (grid[i][j] == '1')
                count++;
        }
        for (int i=0; i<n; i++) {
            if (i<n-count) 
                grid[i][j] = '0';
            else 
                grid[i][j] = '1';
        }
    }
}

int main () {
    int t;
    cin>>t;
    while (t--) {
        int n, m;
        cin>>n>>m;

        // char grid[n][m];
        int colCount[m];
        int rowCount[n];

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin>>grid[i][j];
            }
        }

        string s;
        cin>>s;
        
        char changeX = 'X', changeY = 'X';
        int firstX = 0, firstY = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == 'L' || s[i] == 'R')
                changeX = s[i];
            else if (s[i] == 'U' || s[i] == 'D')
                changeY = s[i];

            if (firstX == 0 && firstY == 0) {
                if (s[i] == 'L' || s[i] == 'R')
                    firstX = 1;
                else
                    firstY = 1;
            }
        }

        if (changeX != 'X' && changeY != 'X') {
            if (firstX) {
                if (changeX == 'L')
                    leftShifted(n, m);
                else if (changeX == 'R')
                    rightShifted(n, m);
                if (changeY == 'U')
                    upShifted(n, m); 
                else if (changeY == 'D')
                    downShifted(n, m);
            }
            else if (firstY) {
                if (changeY == 'U')
                    upShifted(n, m); 
                else if (changeY == 'D')
                    downShifted(n, m);
                if (changeX == 'L')
                    leftShifted(n, m);
                else if (changeX == 'R')
                    rightShifted(n, m);
            }
        }
        else if (changeX != 'X') {
            if (changeX == 'L')
                leftShifted(n, m);
            else if (changeX == 'R')
                rightShifted(n, m);
        }
        else if (changeY != 'X') {
            if (changeY == 'U')
                upShifted(n, m); 
            else if (changeY == 'D')
                downShifted(n, m);
        }
            
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout<<grid[i][j];
            }
            cout<<endl;
        }
    }   
    return 0;
}