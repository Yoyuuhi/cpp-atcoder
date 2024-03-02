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

int calc20(int a, int b, int c) {
  int ans = 0;

  int x1 = 10000, x2 = -10000, y1 = 10000, y2 = -10000, z1 = 10000, z2 = -10000;
  rep(i, 8) {
    if (i >= a && i <= a + 7) {
      x1 = min(x1, i);
      x2 = max(x2, i);
    }
  }
  rep(i, 8) {
    if (i >= b && i <= b + 7) {
      y1 = min(y1, i);
      y2 = max(y2, i);
    }
  }
  rep(i, 8) {
    if (i >= c && i <= c + 7) {
      z1 = min(z1, i);
      z2 = max(z2, i);
    }
  }
  ans += max(0, x2 - x1) * max(0, y2 - y1) * max(0, z2 - z1);

  return ans;
}

int calc2(int a2, int b2, int c2, int a3, int b3, int c3) {
  int ans = 0;
  ans += calc20(a2, b2, c2);
  ans += calc20(a3, b3, c3);

  int x1 = 10000, x2 = -10000, y1 = 10000, y2 = -10000, z1 = 10000, z2 = -10000;
  rep2(i, a2, a2 + 8) {
    if (i >= a3 && i <= a3 + 7) {
      x1 = min(x1, i);
      x2 = max(x2, i);
    }
  }
  rep2(i, b2, b2 + 8) {
    if (i >= b3 && i <= b3 + 7) {
      y1 = min(y1, i);
      y2 = max(y2, i);
    }
  }
  rep2(i, c2, c2 + 8) {
    if (i >= c3 && i <= c3 + 7) {
      z1 = min(z1, i);
      z2 = max(z2, i);
    }
  }
  ans += max(0, x2 - x1) * max(0, y2 - y1) * max(0, z2 - z1);

  return ans;
}

int calc3(int a2, int b2, int c2, int a3, int b3, int c3) {
  int x1 = 10000, x2 = -10000, y1 = 10000, y2 = -10000, z1 = 10000, z2 = -10000;
  rep(i, 8) {
    if (i >= a2 && i >= a3 && i <= a2 + 7 && i <= a3 + 7) {
      x1 = min(x1, i);
      x2 = max(x2, i);
    }
  }
  rep(i, 8) {
    if (i >= b2 && i >= b3 && i <= b2 + 7 && i <= b3 + 7) {
      y1 = min(y1, i);
      y2 = max(y2, i);
    }
  }
  rep(i, 8) {
    if (i >= c2 && i >= c3 && i <= c2 + 7 && i <= c3 + 7) {
      z1 = min(z1, i);
      z2 = max(z2, i);
    }
  }

  return max(0, x2 - x1) * max(0, y2 - y1) * max(0, z2 - z1);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int v1, v2, v3;
  cin >> v1 >> v2 >> v3;
  if (v1 + v2 * 2 + v3 * 3 != 1029) {
    out("No");
    return 0;
  }

  rep2(a2, -7, 8) {
    rep2(b2, -7, 8) {
      rep2(c2, -7, 8) {
        rep2(a3, 0, 8) {
          rep2(b3, 0, 8) {
            rep2(c3, 0, 8) {
              int vv1 = 1029;
              int vv2 = calc2(a2, b2, c2, a3, b3, c3);
              int vv3 = calc3(a2, b2, c2, a3, b3, c3);
              vv2 -= 3 * vv3;

              vv1 -= 2 * vv2;
              vv1 -= 3 * vv3;
              if (vv1 == v1 && vv2 == v2 && vv3 == v3) {
                vector<int> ans = {0, 0, 0, a2, b2, c2, a3, b3, c3};
                out("Yes");
                outs(ans);
                outl;
                return 0;
              }
            }
          }
        }
      }
    }
  }

  out("No");
}
