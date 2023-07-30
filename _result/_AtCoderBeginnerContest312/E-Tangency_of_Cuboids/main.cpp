#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
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

vector<vector<vector<int>>> mem;
vector<vector<int>> vs = {{1, 0, 0},  {-1, 0, 0}, {0, 1, 0},
                          {0, -1, 0}, {0, 0, 1},  {0, 0, -1}};
vector<set<int>> sts;

bool valid(int x) { return x >= 0 && x < 101; }
void solve(int x, int y, int z) {
  if (mem[x][y][z] == -1) return;
  for (auto v : vs) {
    int xx = x + v[0];
    int yy = y + v[1];
    int zz = z + v[2];
    if (!valid(xx)) continue;
    if (!valid(yy)) continue;
    if (!valid(zz)) continue;
    if (mem[xx][yy][zz] == -1 || mem[xx][yy][zz] == mem[x][y][z]) continue;
    sts[mem[x][y][z]].insert(mem[xx][yy][zz]);
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  mem.assign(101, vector<vector<int>>(101, vector<int>(101, -1)));
  rep(i, n) {
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    rep2(x, x1, x2) {
      rep2(y, y1, y2) {
        rep2(z, z1, z2) { mem[x][y][z] = i; }
      }
    }
  }

  sts.resize(n);
  rep(x, 101) {
    rep(y, 101) {
      rep(z, 101) { solve(x, y, z); }
    }
  }
  for (auto st : sts) out(st.size());
}
