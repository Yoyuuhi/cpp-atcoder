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
using Modint = atcoder::modint998244353;
const int INF = numeric_limits<int>::max() / 2;

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  string s;
  cin >> s;

  int x = INF;
  int y = INF;
  rep(i, 8) {
    if (s[i] != 'B') {
      continue;
    }
    if (x == INF) {
      x = i % 2;
      continue;
    }
    y = i % 2;
  }
  if (x == y) {
    out("No");
    return 0;
  }

  x = INF;
  y = INF;
  int z = INF;
  rep(i, 8) {
    if (s[i] == 'K') {
      z = i;
    }
    if (s[i] != 'R') {
      continue;
    }
    if (x == INF) {
      x = i;
      continue;
    }
    y = i;
  }
  if (z < x || z > y) {
    out("No");
    return 0;
  }
  out("Yes")
}
