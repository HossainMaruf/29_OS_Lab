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
    int n, sum_wt = 0, idle_sum = 0;
    cin >> n;
    struct Process p[n];
    // Taking input
    for(int i=0; i<n; i++) {
        cin >> p[i].id >> p[i].at >> p[i].bt;
    }
    vector<struct Process*> ready_queue;
    ready_queue.push_back(&p[0]);

    struct Process* selected = ready_queue.front();
    selected->at = 7;

    cout << p[0].at << endl;

    return 0;
}