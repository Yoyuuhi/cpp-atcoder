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
T pow(T x, int n) {
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

  int n, k;
  cin >> n >> k;
  auto as = nis(k);

  if (k == 1) {
    out(0);
    return 0;
  }
  if (k % 2 == 0) {
    ll ans = 0;
    for (int i = 1; i < k; i += 2) {
      ans += as[i] - as[i - 1];
    }
    out(ans);
    return 0;
  }

  ll sum = 0;
  for (int i = 1; i < k; i += 2) {
    sum += as[i + 1] - as[i];
  }
  ll ans = sum;
  rep2(i, 1, k) {
    if (i % 2 == 1) {
      sum -= as[i + 1] - as[i];
      sum += as[i + 1] - as[i - 1];
    } else {
      sum -= as[i] - as[i - 2];
      sum += as[i - 1] - as[i - 2];
    }
    ans = min(ans, sum);
  }
  out(ans);
}
