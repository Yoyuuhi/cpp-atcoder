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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  int ans = 0;
  rep(i, n) {
    auto c = s[i];
    if (c == 'A' && i + 2 < n) {
      if (s[i + 1] == 'B' && s[i + 2] == 'C') ans++;
    }
  }

  rep(i, q) {
    int x;
    char c;
    cin >> x >> c;
    x--;

    auto c0 = s[x];
    if (c0 == 'A') {
      if (x + 2 < n && s[x + 1] == 'B' && s[x + 2] == 'C') ans--;
    }
    if (c0 == 'B') {
      if (x - 1 >= 0 && s[x - 1] == 'A' && x + 1 < n && s[x + 1] == 'C') ans--;
    }
    if (c0 == 'C') {
      if (x - 2 >= 0 && s[x - 2] == 'A' && x - 1 < n && s[x - 1] == 'B') ans--;
    }

    if (c == 'A') {
      if (x + 2 < n && s[x + 1] == 'B' && s[x + 2] == 'C') ans++;
    }
    if (c == 'B') {
      if (x - 1 >= 0 && s[x - 1] == 'A' && x + 1 < n && s[x + 1] == 'C') ans++;
    }
    if (c == 'C') {
      if (x - 2 >= 0 && s[x - 2] == 'A' && x - 1 < n && s[x - 1] == 'B') ans++;
    }

    s[x] = c;

    out(ans);
  }
}
