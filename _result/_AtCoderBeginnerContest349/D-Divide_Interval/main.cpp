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

vector<vector<ll>> ans;

void calc(ll l, ll r) {
  ll bit = 1;
  ll LL = -1, RR = -1;
  rep(i, 64) {
    ll left = l / bit * bit;
    if (l % bit) left += bit;
    if (left + bit <= r) {
      LL = left;
      RR = left + bit;
    } else {
      break;
    }
    bit <<= 1;
  }

  ans.push_back({LL, RR});
  if (LL > l) calc(l, LL);
  if (RR < r) calc(RR, r);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll l, r;
  cin >> l >> r;
  calc(l, r);
  sort(all(ans));

  out(ans.size());
  for (auto a : ans) {
    cout << a[0] << ' ' << a[1] << endl;
  }
}
