#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;

  for (int i = S.size() - T.size(); i >= 0; --i) {
    
    bool ok = true;
    for (int j = 0; j < T.size(); ++j) {
      if (S[i + j] == '?' || S[i + j] == T[j]) {
	continue;
      }
      ok &= false;
    }

    if (ok) {
      for (int j = 0; j < T.size(); ++j) {
	S[i + j] = T[j];
      }
      for (int j = 0; j < S.size(); ++j) {
	if (S[j] == '?') {
	  S[j] = 'a';
	}
      }
      
      cout << S << endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE" << endl;
  
  return 0;
}
