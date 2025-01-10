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

  int k;
  string s, t;
  cin >> k >> s >> t;

  int l = 0, r = 0;
  while (l < min(s.size(), t.size()) && s[l] == t[l]) l++;
  while (r < min(s.size(), t.size()) &&
         s[s.size() - r - 1] == t[t.size() - r - 1])
    r++;
  if (abs(int(s.size() - t.size())) == 1 && l + r >= min(s.size(), t.size())) {
    out("Yes");
    return 0;
  }
  if (s.size() == t.size() && l + r >= s.size() - 1) {
    out("Yes");
    return 0;
  }

  out("No");
}
