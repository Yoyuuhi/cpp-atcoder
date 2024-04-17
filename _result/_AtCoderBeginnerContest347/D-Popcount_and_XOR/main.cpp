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

  ll a, b, C;
  cin >> a >> b >> C;

  ll c = 0;
  vector<int> mem(61, 0);
  rep(i, 61) {
    if (C & (ll(1) << i)) {
      mem[i] = 1;
      c++;
    }
  }

  ll x1 = (a + c - b) / 2;
  ll x2 = c - x1;
  ll k = a - x1;
  if (x2 + k != b || x1 < 0 || x2 < 0 || k < 0 || x1 + x2 + k > 60) {
    out(-1);
    return 0;
  }

  ll A = 0, B = 0;
  rep(i, 61) {
    if (!mem[i]) {
      if (k) {
        A += ll(1) << i;
        B += ll(1) << i;
        k--;
      }
      continue;
    }

    if (x1) {
      A += ll(1) << i;
      x1--;
    } else if (x2) {
      B += ll(1) << i;
      x2--;
    }
  }
  cout << A << " " << B << endl;
}
