#include <bits/stdc++.h>
using namespace std;

int main(){
    random_device seed_gen;
    mt19937_64 rnd(seed_gen());

    uniform_int_distribution<int> dist_N(1, 300), dist_A(1, 300);
    int N = 300;
    int M = 300;
    vector<int> A(N);
    vector<int> B(M);
    for(int i=0; i<N; i++) {
      A[i] = dist_A(rnd);
      B[i] = dist_A(rnd);
      while (A[i] == B[i]) B[i] = dist_A(rnd);
    }

    cout << N << " " << M << endl;
    for(int i=0; i<N; i++) cout << A[i] << " " << B[i] << " \n";
    return 0;
}
