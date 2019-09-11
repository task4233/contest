#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

int getNext(int n, int m){
  int tmp = n/m*m;
  return tmp;
}

signed main() {
  int k;cin>>k;
  vector<int> a(k);
  for(int i=k-1;i>=0;--i) cin>>a[i];
  // aは逆に保存している

  int lb=2,ub=2;
  for(int i=0;i<k;++i){
    int tmp = getNext(ub,a[i]);
    if (tmp < lb) {
      cout<<-1<<endl;
      return 0;
    }
    ub = tmp+a[i]-1;

    tmp = getNext(lb,a[i]);
    if(tmp<lb) tmp += a[i];
    lb = tmp;
  }

  cout<<lb<<" "<<ub<<endl;
  
  return 0;
}
