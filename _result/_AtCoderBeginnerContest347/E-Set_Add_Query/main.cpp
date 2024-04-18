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

  ll n, q;
  cin >> n >> q;
  auto xs = nis(q);

  vector<ll> mem(200001, -1);
  vector<ll> sum(q + 1, 0);
  ll s = 0;

  vector<ll> ans(n, 0);
  rep(i, q) {
    ll x = xs[i];
    sum[i + 1] += sum[i];
    if (mem[x] == -1) {
      s++;
      mem[x] = i;
    } else {
      s--;
      ans[x - 1] += sum[i] - sum[mem[x]];
      mem[x] = -1;
    }
    sum[i + 1] += s;
  }

  rep(x, 200001) {
    if (mem[x] == -1) continue;
    ans[x - 1] += sum[q] - sum[mem[x]];
  }
  outs(ans);
}
