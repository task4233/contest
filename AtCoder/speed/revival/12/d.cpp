#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

signed main() {
  int a,b;cin>>a>>b;

  vector<string> ans(100, string(100,'-'));
  char mn='.',mx='#';
  if (a>b) {
    swap(mn,mx);
    swap(a,b);
    // a<bを保証
  }

  bool close=false, done=false;
  for(int hi=0;hi<100;++hi){
    for(int wi=0;wi<100;++wi){
      if (done) {
        ans[hi][wi] = mx;
      }
      if (ans[hi][wi] != '-') continue;
      
      if (wi==0 && a<50 && abs(a-b)>1) close=true;
      if (wi%2==0) {
        ans[hi][wi] = mx;
        --b;
      }else{
        ans[hi][wi] = mn;
        --a;
        if (a<0) {
          ans[hi+1][wi] = mn;
        }
        else if (close) {
          ans[hi+1][wi] = mx;
          --b;
          if (wi+1<100) {
            ans[hi][wi+1] = mx;
            --b;
          }
        }
      }
    }
    if (close){
      for(int wi=0;wi<100;++wi){
        if (ans[hi][wi]!='-') ans[hi][wi] = mn;
      }
      ++hi;
      for(int wi=0;wi<100;++wi){
        if (ans[hi][wi]!='-') ans[hi][wi] = mn;
      }
      close = false;
      done = true;
    }
  }
  cout<<100<<" "<<100<<endl;
  for(int hi=0;hi<100;++hi){
    for(int wi=0;wi<100;++wi){
      cout<<ans[hi][wi];
    }
    cout<<endl;
  }
  cout<<endl;
  return 0;
}
