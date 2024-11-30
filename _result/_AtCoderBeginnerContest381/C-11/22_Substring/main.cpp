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

int n;
string s;

int calc(int pos) {
  int l = pos, r = pos;

  while (l - 1 >= 0 && r + 1 < s.size() && s[l - 1] == '1' && s[r + 1] == '2') {
    l--;
    r++;
  }
  return r - l + 1;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif
  cin >> n >> s;
  int ans = 0;
  rep(i, n) {
    if (s[i] == '/') ans = max(ans, calc(i));
  }
  out(ans);
}
