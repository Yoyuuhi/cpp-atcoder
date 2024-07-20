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

ll tnum(ll level) {
  if (level == 1) return 10;
  ll ret = ll(9) * tpow(ll(10), (level - 2) / 2);
  if ((level - 2) % 2) ret *= 10;
  return ret;
}

ll tnum1(ll level) {
  if (level == 1) return 10;
  ll ret = ll(10) * tpow(ll(10), (level - 2) / 2);
  if ((level - 2) % 2) ret *= 10;
  return ret;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  string s = "0123456789";
  if (n <= 10) {
    out(s[n - 1]);
    return 0;
  }

  ll level = 1;
  while (n > tnum(level)) {
    n -= tnum(level);
    level++;
  }
  n--;

  ll p = tnum1(level - 2);
  vector<char> ans(level, '-');
  if (level - 2 == 0) {
    ans[0] = s[n + 1];
  } else {
    ans[0] = s[n / p + 1];
  }
  n %= p;

  rep2(i, 1, level / 2 + 1) {
    ll l = level - i * 2;
    if (l <= 2) {
      ans[i] = s[n];
      break;
    } else {
      ll pp = tnum1(l - 2);
      int idx = n / pp;
      ans[i] = s[idx];
      n %= pp;
    }
  }

  rep(i, level / 2) {
    int ii = level - 1 - i;
    ans[ii] = ans[i];
  }
  for (auto a : ans) cout << a;
  outl;
}
