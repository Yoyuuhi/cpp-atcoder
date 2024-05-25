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

  int n, t;
  cin >> n >> t;
  auto as = nis(t);

  vector<int> memr(n, 0), memc(n, 0);
  int mem1 = 0, mem2 = 0;
  rep(idx, t) {
    auto a = as[idx];
    int i = (a - 1) / n, j = (a - 1) % n;
    memr[i]++;
    memc[j]++;
    if (i == j) mem1++;
    if (i + j == n - 1) mem2++;
    if (memr[i] == n || memc[j] == n || mem1 == n || mem2 == n) {
      out(idx + 1);
      return 0;
    }
  }
  out(-1);
}
