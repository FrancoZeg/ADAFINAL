#include <iostream>
#include <vector>
using namespace std;

vector<int> merge (vector<int> &L, vector<int> &R) {
  vector<int> c;
  int i = 0, j = 0;
  
  while(i < L.size() && j < R.size()){
    if (L[i] <= R[j]){
      c.push_back(L[i++]);
    } else {
      c.push_back(R[j++]);
    }
  }
  
  while (i < L.size()) c.push_back(L[i++]);
  while (j < R.size()) c.push_back(R[j++]);
  
  return c;
  
}

vector<int> mergeAll (vector<vector<int>> &arr, int left, int right){
  if (left == right) return arr[left];
  int mid = left + (right - left)/2;
  vector<int> L = mergeAll(arr, left, mid);
  vector<int> R = mergeAll(arr, mid + 1, right);
  
  return merge(L, R);
}

int main(){
  
  vector<vector<int>> vectors = {
    {1, 5, 9},
    {2, 6, 8},
    {3, 7, 10},
    {4, 11, 12}
  };
  
  cout << "Vectores originales:" << endl;
  for (const auto &vec : vectors) {
    for (int x : vec) cout << x << " ";
    cout << endl;
  }

  vector<int> result = mergeAll (vectors, 0, vectors.size() - 1);
  
  cout << "Vector combinado ordenado:" << endl;
  for (int x : result) cout << x << " ";
  cout << endl;

  return 0;
}
