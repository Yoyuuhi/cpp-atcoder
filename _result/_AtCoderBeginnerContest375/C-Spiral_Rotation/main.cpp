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

int n;
vector<string> sa;
vector<string> ans;

void calc(int t, int x, int y) {
  int xx = x, yy = y;
  if (t == 0) return;
  if (t >= 2) {
    t -= 2;
    xx = n + 1 - xx;
    yy = n + 1 - yy;
  }
  if (t == 1) {
    auto txx = yy, tyy = n + 1 - xx;
    xx = txx;
    yy = tyy;
  }
  ans[xx - 1][yy - 1] = sa[x - 1][y - 1];
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  rep(i, n) {
    string str;
    cin >> str;
    sa.push_back(str);
  }

  ans = sa;
  rep2(i, 1, n / 2 + 1) {
    int t = i % 4;
    rep2(y, i, n + 1 - i + 1) {
      int x = i;
      calc(t, x, y);
    }
    rep2(y, i, n + 1 - i + 1) {
      int x = n + 1 - i;
      calc(t, x, y);
    }
    rep2(x, i, n + 1 - i + 1) {
      int y = i;
      calc(t, x, y);
    }
    rep2(x, i, n + 1 - i + 1) {
      int y = n + 1 - i;
      calc(t, x, y);
    }
  }
  for (auto a : ans) out(a);
}
