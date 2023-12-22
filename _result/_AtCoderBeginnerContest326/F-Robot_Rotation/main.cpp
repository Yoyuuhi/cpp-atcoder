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

int calcV(vector<int> as, int bit, int offset, int length) {
  int ret = 0;
  rep(i, length) {
    if (bit & (1 << i)) {
      ret += as[i + offset];
    } else {
      ret -= as[i + offset];
    }
  }
  return ret;
}

vector<vector<pair<int, int>>> calc(vector<int> as) {
  int n = as.size();
  vector<pair<int, int>> m1, m2;

  int l = n / 2, r = n - l;
  rep(i, 1 << l) {
    int v = calcV(as, i, 0, l);
    m1.push_back({v, i});
  }
  rep(i, 1 << r) {
    int v = calcV(as, i, l, r);
    m2.push_back({v, i});
  }
  return {m1, m2};
}

string getBitStr(int bit, int length) {
  string ret = "";
  rep(i, length) ret += (bit & (1 << i) ? '1' : '0');
  return ret;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, x, y;
  cin >> n >> x >> y;
  vector<int> xs, ys;
  rep(i, n) {
    int a;
    cin >> a;
    if (i % 2 == 1) {
      xs.push_back(a);
    } else {
      ys.push_back(a);
    }
  }

  auto cx = calc(xs), cy = calc(ys);
  auto xm1 = cx[0], xm2 = cx[1];
  sort(all(xm1));
  sort(all(xm2));
  vector<int> x12 = {INF, INF};
  for (auto x1 : xm1) {
    int x2v = x - x1.first;
    int x2i = lower_bound(all(xm2), pair<int, int>{x2v, 0}) - xm2.begin();
    if (x2i < xm2.size() && x2v == xm2[x2i].first) {
      x12 = {x1.second, xm2[x2i].second};
    }
  }
  auto ym1 = cy[0], ym2 = cy[1];
  sort(all(ym1));
  sort(all(ym2));
  vector<int> y12 = {INF, INF};
  for (auto y1 : ym1) {
    int y2v = y - y1.first;
    int y2i = lower_bound(all(ym2), pair<int, int>{y2v, 0}) - ym2.begin();
    if (y2i < ym2.size() && y2v == ym2[y2i].first) {
      y12 = {y1.second, ym2[y2i].second};
    }
  }
  if (x12[0] == INF || y12[0] == INF) {
    out("No");
    return 0;
  }

  string sx = getBitStr(x12[0], xs.size() / 2) +
              getBitStr(x12[1], xs.size() - xs.size() / 2);
  string sy = getBitStr(y12[0], ys.size() / 2) +
              getBitStr(y12[1], ys.size() - ys.size() / 2);
  string ans = "";
  rep(i, n) {
    // y
    if (i % 2 == 0) {
      int iy = i / 2, pix = iy - 1;
      char cy = sy[iy], cx;
      if (pix == -1) {
        cx = '1';
      } else {
        cx = sx[pix];
      }
      ans += (cx == cy ? 'L' : 'R');
    }
    // x
    if (i % 2 == 1) {
      int ix = i / 2, piy = ix;
      char cx = sx[ix], cy = sy[piy];
      ans += (cx == cy ? 'R' : 'L');
    }
  }
  out("Yes");
  out(ans);
}
