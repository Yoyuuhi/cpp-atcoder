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

map<ll, bool> mem;
vector<string> ss;
ll h, w, k;
ll ans = 0;

ll calc(int i, int j, int k) {
  if (ss[i][j] == '#') return 0;
  if (k == 0) return 1;
  mem[i * w + j] = true;

  vector<vector<int>> vs = {
      {0, 1},
      {0, -1},
      {-1, 0},
      {1, 0},
  };
  ll ta = 0;
  for (auto v : vs) {
    int ii = i + v[0], jj = j + v[1];
    if (ii >= 0 && ii < h && jj >= 0 && jj < w) {
      if (mem.find(ii * w + jj) != mem.end() && mem[ii * w + jj]) continue;

      ta += calc(ii, jj, k - 1);
    }
  }
  mem[i * w + j] = false;
  return ta;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> h >> w >> k;
  rep(i, h) {
    string s;
    cin >> s;
    ss.push_back(s);
  }

  ll ans = 0;
  rep(i, h) {
    rep(j, w) {
      ans += calc(i, j, k);
      // cout << i << ' ' << j << endl;
      // DBG(calc(i, j, k));
    }
  }
  out(ans);
}
