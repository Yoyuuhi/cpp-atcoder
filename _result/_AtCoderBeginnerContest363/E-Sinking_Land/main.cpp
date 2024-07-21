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

using P = vector<int>;

int h, w, y;
bool validIJ(int i, int j) { return i >= 0 && i < h && j >= 0 && j < w; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> h >> w >> y;
  vector<vector<int>> ax(h, vector<int>(w));
  rep(i, h) {
    ax[i] = nis(w);
    // outs(ax[i]);
  }

  vector<vector<int>> vs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  priority_queue<P, vector<P>, greater<P>> pq;
  rep(j, w) {
    pq.push({ax[0][j], 0, j});
    pq.push({ax[h - 1][j], h - 1, j});
  }
  rep2(i, 1, h - 1) {
    pq.push({ax[i][0], i, 0});
    pq.push({ax[i][w - 1], i, w - 1});
  }

  ll ans = h * w;
  rep2(year, 1, y + 1) {
    P p = pq.top();
    while (!pq.empty() && p[0] <= year) {
      pq.pop();
      if (ax[p[1]][p[2]] == 0) {
        p = pq.top();
        continue;
      }
      ax[p[1]][p[2]] = 0;

      ans--;
      for (auto v : vs) {
        int ii = p[1] + v[0];
        int jj = p[2] + v[1];

        if (!validIJ(ii, jj) || ax[ii][jj] == 0) continue;
        pq.push({ax[ii][jj], ii, jj});
      }
      p = pq.top();
    }
    out(ans);
  }
}
