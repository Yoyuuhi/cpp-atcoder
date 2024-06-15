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

  int n, m;
  cin >> n >> m;
  vector<int> ss(n);
  rep(i, n) {
    string s;
    cin >> s;

    int val = 0;
    rep(ii, m) {
      if (s[ii] == 'o') val += (1 << ii);
    }
    ss[i] = val;
  }

  rep2(I, 1, n + 1) {
    vector<int> vs(n, 0);
    rep2(idx, n - I, n) vs[idx] = 1;
    do {
      int val = 0;
      rep(idx, n) {
        if (vs[idx] == 1) val = (val | ss[idx]);
        if (val == (1 << m) - 1) {
          out(I);
          return 0;
        }
      }
    } while (next_permutation(all(vs)));
  }
}
