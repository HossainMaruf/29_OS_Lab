#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, at, bt, st, ct;
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
    cout << "ID\tAT\tBT\tST\tCT" << endl;
    for(int i=0; i<n; i++) {
        cout << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].ct << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
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
   }

   // Printing the table
   printTable(p, n);
  
    return 0;
}