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

  int h, w, k;
  cin >> h >> w >> k;
  vector<string> ss(h);
  rep(i, h) cin >> ss[i];

  int ans = INF;

  vector<vector<int>> memr(h, vector<int>(w, w));
  rep(i, h) {
    for (int j = w - 1; j >= 0; j--) {
      if (j < w - 1) memr[i][j] = min(memr[i][j], memr[i][j + 1]);
      if (ss[i][j] == 'x') memr[i][j] = j;
    }
  }
  rep(i, h) {
    vector<int> mem(w + 1, 0);
    int l = -1;
    rep(j, w) {
      if (j > 0) mem[j] += mem[j - 1];
      if (ss[i][j] == 'x') {
        l = j;
        continue;
      }

      if (ss[i][j] == 'o') {
        mem[j]++;
        mem[min(j + k, memr[i][j])]--;
      }
      if (j - l >= k) ans = min(ans, k - mem[j]);
    }
  }

  vector<vector<int>> memd(h, vector<int>(w, h));
  rep(j, w) {
    for (int i = h - 1; i >= 0; i--) {
      if (i < h - 1) memd[i][j] = min(memd[i + 1][j], memd[i][j]);
      if (ss[i][j] == 'x') memd[i][j] = i;
    }
  }
  rep(j, w) {
    vector<int> mem(h + 1, 0);
    int t = -1;
    rep(i, h) {
      if (i > 0) mem[i] += mem[i - 1];
      if (ss[i][j] == 'x') {
        t = i;
        continue;
      }

      if (ss[i][j] == 'o') {
        mem[i]++;
        mem[min(i + k, memd[i][j])]--;
      }
      if (i - t >= k) ans = min(ans, k - mem[i]);
    }
  }
  if (ans == INF) {
    out(-1);
  } else {
    out(ans);
  }
}
