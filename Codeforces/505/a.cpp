#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  scanf("%d", &N);
  char *ch;
  ch = (char *)malloc(sizeof(char) * N);

  map< char, int > mp;
  for (int i = 0; i < N; ++i) {
    scanf("%c", &ch[i]);
    mp[ch[i]]++;
  }

  bool ok = false;
  for (auto&& mi : mp) {
    if (mi.second >= 2) {
      ok = true;
      break;
    }
  }

  cout << "No";
  
  return 0;
}
