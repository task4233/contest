#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<x<<endl;

int m,c;


bool decrypt(int d){
  vector<int> par(10);
  iota(par.begin(), par.end(), 0);

  string cstr = to_string(c);
  int n = cstr.size();
  //debug(cstr);

  // 10!
  do {
    // 10
    for(int i=0;i<n;++i){
      //debug(cstr[i]);
      int id = (int)(cstr[i] - '0');
      //debug(id);
      cstr[i] = (par[id]) + '0';
      // debug(cstr[i]);
    }
    //debug(cstr);
    
    if (cstr==to_string(d)) {
      return true;
    }
    
  } while(next_permutation(par.begin(), par.end()));
  
  return false;
}

signed main() {
  cin>>m>>c;

  // 10
  for(int i=1;i<=9; ++i){
    int d = (1e9+7) * i + m;
    //debug(d);

    if(decrypt(d)){
      cout<<d<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}
