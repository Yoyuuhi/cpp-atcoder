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
using mint = atcoder::modint998244353;
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

int h, w;
bool isvalid(int x, int y) { return x >= 0 && x < h && y >= 0 && y < w; }

vector<vector<int>> mem;
vector<vector<int>> vs;
int group;
vector<string> ss;
void bfs(int i, int j) {
  for (auto v : vs) {
    int ii = i + v[0], jj = j + v[1];
    if (!isvalid(ii, jj)) continue;
    char c = ss[ii][jj];
    if (c == '.') continue;
    if (mem[ii][jj] > 0) continue;
    mem[ii][jj] = mem[i][j];
    bfs(ii, jj);
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> h >> w;
  ss.resize(h);
  rep(i, h) cin >> ss[i];
  vs.resize(4);
  vs[0] = {0, 1};
  vs[1] = {0, -1};
  vs[2] = {1, 0};
  vs[3] = {-1, 0};

  group = 0;
  mem.assign(h, vector<int>(w, 0));
  rep(i, h) {
    rep(j, w) {
      char c = ss[i][j];
      if (c == '.') continue;
      if (mem[i][j] > 0) continue;
      mem[i][j] = group + 1;
      group++;
      bfs(i, j);
    }
  }

  mint ans = 0;
  int countR = 0;
  rep(i, h) {
    rep(j, w) {
      char c = ss[i][j];
      if (c != '.') continue;
      countR++;

      set<int> st;
      for (auto v : vs) {
        int ii = i + v[0], jj = j + v[1];
        if (!isvalid(ii, jj)) continue;
        if (mem[ii][jj] == 0) continue;
        st.insert(mem[ii][jj]);
      }
      int n = st.size();
      if (n == 0) {
        ans += group + 1;
      } else {
        ans += group - (n - 1);
      }
    }
  }
  ans /= countR;
  out(ans.val());
}
