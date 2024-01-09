#include<bits/stdc++.h>
using namespace std;

struct Person {
  long long id;
  string name, fName, mName;
};

int main() {

  struct Person p; 

  cin >> p.id >> p.name >> p.fName >> p.mName;
  cout << p.id <<" "<< p.name << " " << p.fName << " " << p.mName;



  return 0;
}