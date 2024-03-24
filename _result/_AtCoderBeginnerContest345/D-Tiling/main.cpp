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

int n, h, w;
vector<vector<int>> vab;

vector<int> findXY(vector<vector<bool>> mem) {
  int x = -1, y = -1;
  rep(i, h) {
    rep(j, w) {
      if (mem[i][j]) {
        x = i;
        y = j;
        return {x, y};
      }
    }
  }
  return {x, y};
}

void delMem(int x, int y, int a, int b, vector<vector<bool>> &mem) {
  rep2(i, x, x + a) rep2(j, y, y + b) mem[i][j] = true;
}

bool writeMem(int x, int y, int a, int b, vector<vector<bool>> &mem) {
  rep2(i, x, x + a) {
    rep2(j, y, y + b) {
      if (i >= h || j >= w || !mem[i][j]) return false;
    }
  }

  rep2(i, x, x + a) rep2(j, y, y + b) mem[i][j] = false;
  return true;
}

bool judge(vector<vector<bool>> mem, vector<int> vs, int idx) {
  auto xy = findXY(mem);
  int x = xy[0], y = xy[1];
  if (x == -1) return true;

  if (idx >= n) return false;
  int a = vab[vs[idx]][0], b = vab[vs[idx]][1];

  if (writeMem(x, y, a, b, mem)) {
    if (judge(mem, vs, idx + 1)) return true;
    delMem(x, y, a, b, mem);
  }
  if (writeMem(x, y, b, a, mem)) {
    if (judge(mem, vs, idx + 1)) return true;
    delMem(x, y, b, a, mem);
  }

  return false;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif
  cin >> n >> h >> w;

  vab.resize(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    vab[i] = {a, b};
  }

  vector<int> vs(n, 0);
  rep2(i, 1, n) vs[i] = vs[i - 1] + 1;
  do {
    vector<vector<bool>> mem(h, vector<bool>(w, true));
    if (judge(mem, vs, 0)) {
      out("Yes");
      return 0;
    }
  } while (next_permutation(all(vs)));
  out("No");
}
