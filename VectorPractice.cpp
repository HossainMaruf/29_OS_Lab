#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(89);
    vec.push_back(100);
    vec.push_back(1);

    for(auto itr = vec.begin(); itr != vec.end(); itr++) {
        cout << *itr << endl;
    }

    vec.erase(vec.begin());
    vec.erase(vec.begin() + 1);
    vec.erase(vec.begin() + 2);
    vec.erase(vec.begin() + 3);

    cout << endl;

    for(auto itr = vec.begin(); itr != vec.end(); itr++) {
        // cout << vec.erase(itr) << endl;
        vec.erase(itr);
    }

    cout << vec.empty() << endl;



    return 0;
}