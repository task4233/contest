#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int h,w,a,b;cin>>h>>w>>a>>b;

  vector<string> ans(h,string(w,'0'));

  for(int hi=0;hi<b;++hi){
    for(int wi=0;wi<a;++wi){
      ans[hi][wi] = '1';
    }
  }

  for(int hi=b;hi<h;++hi){
    for(int wi=a;wi<w;++wi){
      ans[hi][wi] = '1';
    }
  }

  for(int hi=0;hi<h;++hi){
    cout<<ans[hi]<<endl;
  }
  
  return 0;
}
