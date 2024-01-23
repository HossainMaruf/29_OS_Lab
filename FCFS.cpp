#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, at, bt, st, ct, wt, tt;
};
bool comp(struct Process p1, struct Process p2) {
    if(p1.at < p2.at) return true;
    else return false;
}
void printProcess(struct Process p[], int n) {
  for(int i=0; i<n; i++) {
        cout << p[i].id << " " << p[i].at << " " << p[i].bt << endl;
    }
}
void printTable(struct Process p[], int n) {
    cout << "ID\tAT\tBT\tST\tCT\tWT\tTT" << endl;
    for(int i=0; i<n; i++) {
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].ct << "\t" << p[i].wt << "\t" << p[i].tt << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n, sum_wt = 0;
    cin >> n;
    struct Process p[n];
    // Taking input
    for(int i=0; i<n; i++) {
        cin >> p[i].id >> p[i].at >> p[i].bt;
    }
    // Printing the output
    printProcess(p, n);

    // Sorting according to AT
    sort(p, p+n, comp);

    cout << endl;

    // Printing the output
    printProcess(p, n);

    /**
     * Calculating GANTT chart
    */
   for(int i=0; i<n; i++) {
        if(i == 0) {
            p[i].st = p[i].at;
            p[i].ct = p[i].bt;
        } else {
            p[i].st = p[i-1].ct;
            p[i].ct = p[i].st + p[i].bt;
        }
        p[i].wt = p[i].st - p[i].at;
        p[i].tt = p[i].wt + p[i].bt;
        sum_wt += p[i].wt;
   }

   // Printing the table
   printTable(p, n);

   cout << endl;
   cout << "AWT = " << (float)sum_wt / n << endl; 
  
    return 0;
}