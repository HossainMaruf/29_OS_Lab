#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(89);
    vec.push_back(100);
    vec.push_back(1);

    cout << vec[0] << endl; // 10
    cout << vec[1] << endl; // 89
    cout << vec[3] << endl; // 1

    cout <<"Size: " <<  vec.size() << endl;
    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << endl;
    }
    cout << *(&vec[0]) << endl;
    // cout << &vec[1] << endl;
    cout << *vec.begin() << endl;
    cout << endl;

    // cout << *(&vec[vec.size() -1]) << endl;
    // cout << *vec.end() << endl;
    cout << &vec[0] + 1 << endl;
    cout << &vec[1] << endl;

    cout << &vec[vec.size()] - &vec[0]<< endl;
    // cout << vec.end() - vec.begin() << endl;



    return 0;
}