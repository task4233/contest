#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int h,w,a,b;cin>>h>>w>>a>>b;

  vector<string> s(h,string(w,'1'));

  for(int hi=0;hi<h;++hi){
    for(int wi=0;wi<w;++wi){
      if(wi<a && hi<b) {
        s[hi][wi] = '0';
      }
      if(wi>=a && hi>=b){
        s[hi][wi] = '0';
      }
    }
  }

  for(int hi=0;hi<h;++hi)
    cout<<s[hi]<<endl;

  return 0;
}
