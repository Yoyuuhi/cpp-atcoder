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

int h, w, d;
vector<string> ss;
int ans = 0;

void calc(int i, int j) {
  int x1 = i / w, y1 = i % w;
  int x2 = j / w, y2 = j % w;
  if (!(ss[x1][y1] == '.' && ss[x2][y2] == '.')) return;

  vector<vector<bool>> mem(h, vector<bool>(w, false));
  int t = 0;
  rep(ii, h) {
    rep(jj, w) {
      if (ss[ii][jj] != '.') continue;

      if (abs(ii - x1) + abs(jj - y1) <= d && !mem[ii][jj]) {
        mem[ii][jj] = true;
        t++;
      }

      if (abs(ii - x2) + abs(jj - y2) <= d && !mem[ii][jj]) {
        mem[ii][jj] = true;
        t++;
      }
    }
  }

  ans = max(ans, t);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> h >> w >> d;
  rep(i, h) {
    string s;
    cin >> s;
    ss.push_back(s);
  }
  rep(i, h * w) {
    rep(j, h * w) { calc(i, j); }
  }
  out(ans);
}
