#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#ifdef __LOCAL
#define DBG(X) cout << #X << " = " << (X) << endl;
#else
#define DBG(X)
#endif
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  vector<mint> dpEQ(n + 1, 0), dpDF(n + 1, 0);
  dpDF[2] = mint(m) * mint(m - 1);
  rep2(i, 2, n) {
    dpDF[i + 1] += dpDF[i] * (m - 2);
    dpDF[i + 1] += dpEQ[i] * (m - 1);
    dpEQ[i + 1] += dpDF[i];
  }
  out(dpDF[n].val());
}
