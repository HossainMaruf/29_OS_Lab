#include <bits/stdc++.h>
using namespace std;
int main() {
    int resource[3] = {10, 5, 7};
    int avail[3] = {10, 5, 7};
    int allocation[5][3] = {{0,1,0}, {2, 0, 0},
                            {3,0,2}, {2, 1, 1},
                            {0, 0, 2}}; 

    int max[5][3] = {{7, 5, 3}, {3, 2, 2},
                            {9, 0, 2}, {2, 2, 2},
                            {4, 3, 3}}; 
    /**
     * Calculation of Need Matrix
     * */                       
    bool served[5] = {false};
    int need[5][3];
    for(int r=0; r<5; r++) {
        for(int c=0; c<3; c++) {
            need[r][c] = max[r][c] - allocation[r][c];
        }
    }
    for(int r=0; r<5; r++) {
        for(int c=0; c<3; c++) {
            cout << need[r][c] << " ";
        }
        cout << endl;
    }
    // Calculation of available resource
    for(int c=0; c<3; c++) {
        for(int r=0; r<5; r++) {
            avail[c] -= allocation[r][c];
        }
    }
    for(int i=0; i<3; i++) {
        cout << avail[i] << " ";
    }
    // MAIN ALGO
    int iteration = 5; 
    while(iteration--) {
    for(int i=0; i<5; i++) {
        if(served[i] == true) continue;
        for(int j=0; j<3; j++) {
            if(avail[j] < need[i][j]) break;
            else {
                if(j == 2) {
                    cout << "P" << i+1 << "\t";
                    served[i] = true;
                }
                for(int k=0; k<3; k++) {
                    avail[k] += allocation[i][k];
                }

            }
        }
    }
    }
    return 0;
}