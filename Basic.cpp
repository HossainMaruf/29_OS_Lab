#include<bits/stdc++.h>
using namespace std;

struct Person {
  long long id;
  string name, fName, mName;
};

bool comp(struct Person p1, struct Person p2) {
  if(p1.id < p2.id) return false;
  else return true;
}

int main() {

  struct Person p[3]; 

  for(int i=0; i<3; i++)
    cin >> p[i].id >> p[i].name >> p[i].fName >> p[i].mName;

  sort(p, p+3, comp);

  for(int i=0; i<3; i++)
    cout << p[i].id <<" "<< p[i].name << " " << p[i].fName << " " << p[i].mName << endl;



  return 0;
}