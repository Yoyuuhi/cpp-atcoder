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

  int h, w;
  cin >> h >> w;
  vector<string> ss(h);
  rep(i, h) cin >> ss[i];

  dsu d(h * w + 1);
  vector<pair<int, int>> vs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  vector<bool> seen(h * w + 1, false);
  vector<vector<int>> mem(h, vector<int>(w, 0));
  rep(i, h) {
    rep(j, w) {
      if (ss[i][j] == '#') {
        seen[i * w + j] = true;
        for (auto v : vs) {
          int ii = i + v.first, jj = j + v.second;
          if (ii < 0 || ii >= h || jj < 0 || jj >= w || ss[ii][jj] == '#')
            continue;
          mem[ii][jj] = 1;
          seen[ii * w + jj] = true;
        }
      }
    }
  }

  rep(i, h) {
    rep(j, w) {
      if (seen[i * w + j]) continue;
      seen[i * w + j] = true;
      int I = i, J = j;

      queue<pair<int, int>> que;
      que.push({i, j});
      while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();

        int x = now.first, y = now.second;
        for (auto v : vs) {
          int xx = x + v.first, yy = y + v.second;
          if (xx < 0 || xx >= h || yy < 0 || yy >= w || seen[xx * w + yy])
            continue;
          seen[xx * w + yy] = true;
          d.merge(I * w + J, xx * w + yy);
          que.push({xx, yy});
        }
      }
    }
  }

  map<int, int> ansMap;
  rep(i, h * w) { ansMap[d.leader(i)] = d.size(i); }
  rep(i, h) {
    rep(j, w) {
      if (ss[i][j] == '#') continue;
      if (mem[i][j] == 1) {
        map<int, bool> ls;
        for (auto v : vs) {
          int ii = i + v.first, jj = j + v.second;
          if (ii < 0 || ii >= h || jj < 0 || jj >= w || ss[ii][jj] == '#' ||
              mem[ii][jj] == 1)
            continue;
          ls[d.leader(ii * w + jj)] = true;
        }
        for (auto l : ls) {
          ansMap[l.first]++;
        }
      }
    }
  }
  int ans = 1;
  for (auto as : ansMap) ans = max(ans, as.second);
  out(ans);
}
