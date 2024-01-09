#include<bits/stdc++.h>
using namespace std;

struct Person {
  long long id;
  string name, fName, mName;
};

int main() {

  struct Person p[3]; 

  for(int i=0; i<3; i++)
    cin >> p[i].id >> p[i].name >> p[i].fName >> p[i].mName;

  for(int i=0; i<3; i++)
    cout << p[i].id <<" "<< p[i].name << " " << p[i].fName << " " << p[i].mName << endl;



  return 0;
}