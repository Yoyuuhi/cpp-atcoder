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

string s;
ll half(ll k) {
  ll num = s.size();
  while (num * 2 < k) num *= 2;
  return num;
}

char rev(char c) {
  if (c >= 'A' && c <= 'Z') return 'a' + (c - 'A');
  return 'A' + (c - 'a');
}

char calc(ll k) {
  if (k <= s.size()) return s[k - 1];
  return rev(calc(k - half(k)));
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif
  cin >> s;
  ll q;
  cin >> q;
  auto ks = nis(q);
  for (auto k : ks) cout << calc(k) << ' ';
  outl;
}
