#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, at, bt;
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
  
    return 0;
}