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

  ll n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int c1 = 0, c2 = 0;
  for (auto c : s) {
    if (c == '(')
      c1++;
    else
      c2++;
  }

  ll cnt = 0, balance = 0, ans = 0;
  rep(i, 2 * n) {
    char c = s[i];
    if (c == '(') {
      balance++;
    } else {
      balance--;
    }

    if (balance < 0) {
      cnt++;
      balance++;
    }
  }

  ans += b * abs(c1 - c2) / 2;
  if (c1 < c2) cnt -= abs(c1 - c2);
  ans += (cnt / 2 + cnt % 2) * min(a, 2 * b);
  out(ans);
}
