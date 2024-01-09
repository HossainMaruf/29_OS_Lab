#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b) {
  if(a<b) return false;
  else return true;
}

int main() {
  int arr[] = {3, 0, -1, 8, 3, 2};
  // 100 104 108 112

  cout << arr[0] <<  endl;
  cout << &arr[0] <<  endl; // & = Address operator
  cout << arr <<  endl;
  cout << *arr <<  endl;

  sort(arr, arr+6, comp);

  for(int i=0; i<6; i++)
    cout << arr[i] << " ";


  return 0;
}