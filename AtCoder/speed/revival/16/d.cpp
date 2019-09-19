#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64

// n:10^4
int n;
vector<int> state[10101];
vector<int> in(10101, 0);
vector<int> c;
vector<int> ans;

void dfs(int s){
  vector<bool> visited(n, false);
  stack<int> st;
  st.push(s);
  int i = 0;

  while(!st.empty()){
    int fr=st.top(); st.pop();
    visited[fr] = true;
    ans[fr] = c[i++];
    for(int i=0;i<state[fr].size();++i){
      if (visited[state[fr][i]]) continue;
      st.push(state[fr][i]);
    }
  }
}

signed main() {
  cin>>n;
  for(int i=0;i<n-1;++i){
    int a,b;cin>>a>>b;--a;--b;
    state[a].emplace_back(b);
    state[b].emplace_back(a);
    ++in[a]; ++in[b];
  }

  c.resize(n);
  for(int i=0;i<n;++i) cin>>c[i];
  sort(c.begin(), c.end(), greater<int>());
  
  int root = 0;
  for(int i=0;i<n;++i){
    if(in[root] > in[i]){
      root = i;
    }
  }

  ans.resize(n);
  dfs(root);
  int m = accumulate(c.begin()+1, c.end(), 0);
  cout<<m<<endl;
  for(int i=0;i<n;++i){
    if (i>0) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
