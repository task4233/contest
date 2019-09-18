#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define debug(x) cerr<<#x<<":"<<x<<endl;

int n, init;
vector<int> state[303];

bool visited[303];
void dfs(const int x){
  stack<int> st;
  st.push(x);
  
  while(!st.empty()) {
    int fr = st.top(); st.pop();
    state[init].emplace_back(fr);
    for(auto&& to: state[fr]){
      if(visited[to]) continue;
      visited[to] = true;
      st.push(to);
    }
  }
}

void check(){
  for(int i=0;i<n;++i){
    // initialize
    fill_n(visited, n, false);
    init = i;
    
    // dfs
    dfs(i);
    dfs(i);
    
    // compress the data
    sort(state[i].begin(), state[i].end());
    state[i].erase(unique(state[i].begin(), state[i].end()), state[i].end());
  }
}

signed main() {
  int m;cin>>n>>m;

  // add direct-path to myself
  for(int i=0;i<n;++i){
    state[i].emplace_back(i);
  }

  // add direct-path
  for(int i=0;i<m;++i){
    int a,b;cin>>a>>b;
    --a; --b;
    state[a].emplace_back(b);
  }

  // dfs from all points
  check();
  check();

  for(int i=0;i<n;++i){
    bool isFirst = true;
    for(int j=0;j<n;++j){
      if(binary_search(state[i].begin(), state[i].end(), j) &&
         binary_search(state[j].begin(), state[j].end(), i)) {
        if (!isFirst) cout<<" ";
        cout<<j+1;
        isFirst = false;
      }
    }
    cout<<endl;
  }
  return 0;
}
