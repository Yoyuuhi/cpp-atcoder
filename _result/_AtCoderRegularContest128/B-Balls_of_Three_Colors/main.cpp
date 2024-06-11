#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS)                      \
  for (auto X : XS) cout << X << " "; \
  cout << endl;
#define outl cout << endl;
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
using mint = atcoder::modint1000000007;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
T tpow(T x, int n) {
  T ret = 1;
  while (n > 0) {
    if (n & 1) ret *= x;
    x *= x;
    n >>= 1;
  }
  return ret;
}

int calc(int r, int g, int b) {
  if ((b - g) % 3 > 0) return INF;
  return b;
}

void solve() {
  vector<int> mem(3);
  rep(i, 3) cin >> mem[i];
  sort(all(mem));
  auto ans = INF;

  ans = min(ans, calc(mem[0], mem[1], mem[2]));
  ans = min(ans, calc(mem[1], mem[0], mem[2]));
  ans = min(ans, calc(mem[2], mem[0], mem[1]));
  if (ans == INF) {
    out(-1);
  } else {
    out(ans);
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int t;
  cin >> t;
  rep(i, t) solve();
}
