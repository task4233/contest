#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;
  vector< int > a(N + 1);
  for (int i = 0; i < N; ++i) {
    cin >> a[i + 1];
  }
  
  int function_sum = 0;
  int min_num;

  for (int l = 1; l <= N; ++l) {
    for (int r = l; r <= N; ++r) {
      min_num = 1e9 + 1;
      for (int min_l = l; min_l <= r; ++min_l) {
	min_num = min(min_num, a[min_l]);
      }
      function_sum += min_num;
    }
  }
  cout << function_sum << endl;
                          
}	
