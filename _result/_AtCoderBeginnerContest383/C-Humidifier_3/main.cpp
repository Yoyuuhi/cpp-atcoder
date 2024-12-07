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

  int h, w, d;
  cin >> h >> w >> d;
  vector<string> ss;

  rep(i, h) {
    string s;
    cin >> s;
    ss.push_back(s);
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
  vector<vector<int>> mem(h, vector<int>(w, -1));
  int ans = 0;
  rep(i, h) {
    rep(j, w) {
      if (ss[i][j] == 'H') {
        pq.emplace(d, i * w + j);
        mem[i][j] = d;
        ans++;
      }
    }
  }

  vector<vector<int>> vs = {
      {-1, 0},
      {1, 0},
      {0, -1},
      {0, 1},
  };

  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int dd = p.first, i = p.second / w, j = p.second % w;
    for (auto v : vs) {
      int ii = i + v[0], jj = j + v[1];
      if (!(ii >= 0 && ii < h && jj >= 0 && jj < w)) continue;
      if (ss[ii][jj] == '.' && mem[ii][jj] < dd - 1) {
        mem[ii][jj] = dd - 1;
        ans++;

        if (dd - 1 > 0) pq.emplace(dd - 1, ii * w + jj);
      }
    }
  }
  out(ans);
}
