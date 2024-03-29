#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS) \
  for (auto X : XS) cout << X << " ";
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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int w, b;
  cin >> w >> b;
  string s = "wbwbwwbwbwbw";
  int nw = 0, nb = 0;
  for (auto c : s) {
    if (c == 'w') nw++;
    if (c == 'b') nb++;
  }

  s += s;
  rep(i, s.size()) {
    int cw = 0, cb = 0;
    rep2(j, i, s.size()) {
      char c = s[j];
      if (c == 'w') cw++;
      if (c == 'b') cb++;

      if (cw == w && cb == b || (w - cw) % nw == 0 && (b - cb) % nb == 0 &&
                                    (w - cw) / nw == (b - cb) / nb) {
        out("Yes");
        return 0;
      }
    }
  }
  out("No");
}
