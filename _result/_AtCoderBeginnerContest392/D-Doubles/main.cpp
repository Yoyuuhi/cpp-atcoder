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

  int n;
  cin >> n;
  vector<vector<int>> ax(n);
  rep(i, n) {
    int k;
    cin >> k;
    ax[i] = nis(k);
  }

  double ans = 0;
  rep(i, n) {
    rep2(j, i + 1, n) {
      auto as1 = ax[i], as2 = ax[j];
      map<int, int> mem;
      for (auto a : as1) mem[a]++;

      double ta = 0;
      for (auto a : as2) {
        if (mem.find(a) != mem.end())
          ta += double(mem[a]) / as1.size() / as2.size();
      }
      ans = max(ans, ta);
    }
  }
  cout << fixed << setprecision(16) << ans << endl;
}
