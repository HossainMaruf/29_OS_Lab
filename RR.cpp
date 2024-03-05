#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id, at, bt, rt, st = -1, ct, wt, tt;
    bool pushed = false;
};

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
    for(int i=0; i<n; i++) {
        cin >> p[i].id >> p[i].at >> p[i].bt;
        p[i].rt = p[i].bt;
    }
    printProcess(p, n);
    /**
     * Round Robin Implementation
    */
    int minIndex = 0, TQ = 4;
    for(int i=1; i<n; i++) {
        if(p[i].at < p[minIndex].at) minIndex = i;
    }
    vector<struct Process*> ready_queue;
    ready_queue.push_back(&p[minIndex]);
    p[minIndex].pushed = true;

    int t = p[minIndex].at, count = 0;

    while(count != n) {
       struct Process *selected = ready_queue.front(); 
       cout << selected->id << endl;
       ready_queue.erase(ready_queue.begin());
       if(selected->rt < TQ) {
            // when bt is less than tq
            // execute till completion
            if(selected->st == -1) {
                selected->st = t;
            }
            selected->ct = t + selected->rt;
            t = selected->ct;
            count++;
       } else {
            // remaining time is greater than tq
            if(selected->st == -1) {
                selected->st = t;
            }
            selected->ct = t + TQ;
            selected->rt = selected->rt - TQ;
            t = selected->ct;

            // we need to push recently reached process
            for(int i=0; i<n; i++) {
                if((p[i].pushed == false) && (p[i].at <= t)) {
                    ready_queue.push_back(&p[i]);
                    p[i].pushed = true;
                }
            }

            if(selected->rt > 0) {
                // we need to push it back
                ready_queue.push_back(selected);
            } else {
                count++;
            }
       }
    }
    printTable(p, n);
}