#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

int gcd(int a,int b){return b?gcd(b,a%b):a;}

signed main() {
  int n;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;++i) cin>>a[i];

  stack< tuple<int,int,int> > st;
  // gcd,rest,id
  st.push(make_tuple(0,1,0));

  int ans = 0;
  while(!st.empty()){
    int g,rest,id;
    tie(g,rest,id)=st.top();st.pop();

    if(id==n-1){
      if (rest == 1) ans = max(ans, g);
      else ans = max(ans, gcd(g,a[id]));
      continue;
    }
    
    // take
    int ng = gcd(g, a[id]);
    if (ng==0) ng = a[id];
    if (ng==1) ans = max(ans,1LL);
    st.push(make_tuple(ng,rest,id+1));

    if(rest == 1) {
      // not take
      --rest;
      int tg = g;
      st.push(make_tuple(tg,rest,id+1));
    }
  }
  cout<<ans<<endl;
  
  
  return 0;
}
