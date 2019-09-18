#include <bits/stdc++.h>
using namespace std;

bool state[303][303];

int n;
void wf(){
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      for(int k=0;k<n;++k){
        if(state[i][j] && state[j][k]) state[i][k] = true;
      }
    }
  }
}

int main() {
  int m;cin>>n>>m;

  for(int i=0;i<n;++i){
    state[i][i] = true;
  }
  
  for(int i=0;i<m;++i){
    int a,b;cin>>a>>b;
    --a; --b;
    state[a][b] = true;
  }

  wf();
  wf();

  for(int i=0;i<n;++i){
    bool isFirst = true;
    for(int j=0;j<n;++j){
      if (state[i][j] && state[j][i]){
        if (!isFirst) cout << " ";
        cout << (j+1);
        isFirst = false;
      }
    }
    cout<<endl;
  }
  
  return 0;
}
