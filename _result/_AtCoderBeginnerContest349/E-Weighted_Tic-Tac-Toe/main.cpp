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
vector<ll> nis(T n) {
  vector<ll> ret(n);
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

vector<vector<int>> mem(3, vector<int>(3, -1));
vector<vector<ll>> ax;

bool is_three(int i, int j) {
  if (mem[i][0] != -1 && mem[i][0] == mem[i][1] && mem[i][0] == mem[i][2])
    return true;
  if (mem[0][j] != -1 && mem[0][j] == mem[1][j] && mem[0][j] == mem[2][j])
    return true;
  if (i == j && mem[0][0] != -1 && mem[0][0] == mem[1][1] &&
      mem[0][0] == mem[2][2])
    return true;
  if (i == 2 - j && mem[2][0] != -1 && mem[2][0] == mem[1][1] &&
      mem[2][0] == mem[0][2])
    return true;
  return false;
}

bool can_win(int turn) {
  int p = turn % 2;
  bool canWin = false;
  rep(idx, 9) {
    int i = idx / 3, j = idx % 3;
    if (mem[i][j] != -1) continue;
    mem[i][j] = p;
    if (is_three(i, j)) {
      mem[i][j] = -1;
      return true;
    }

    if (turn < 8) {
      canWin = canWin || !can_win(turn + 1);
      mem[i][j] = -1;
    } else {
      vector<ll> sum(2, 0);
      rep(IDX, 9) {
        int ii = IDX / 3, jj = IDX % 3;
        sum[mem[ii][jj]] += ax[ii][jj];
      }
      mem[i][j] = -1;
      return sum[p] > sum[(p + 1) % 2];
    }
  }
  return canWin;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ax.resize(3);
  rep(i, 3) ax[i] = nis(3);
  cout << (can_win(0) ? "Takahashi" : "Aoki") << endl;
}
