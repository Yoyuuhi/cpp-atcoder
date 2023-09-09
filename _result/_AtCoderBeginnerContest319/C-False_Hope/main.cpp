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

int c;
vector<int> cx;
bool poss(int bit, ll passed) {
  int i = bit / 3;
  int j = bit % 3;

  ll bit1, bit2;
  bit1 = i * 3 + (j + 1) % 3;
  bit2 = i * 3 + (j + 2) % 3;
  if (cx[bit1] == cx[bit2] && cx[bit1] && (passed & (1 << bit1)) &&
      (passed & (1 << bit2)))
    return false;
  bit1 = (i + 1) % 3 * 3 + j;
  bit2 = (i + 2) % 3 * 3 + j;
  if (cx[bit1] == cx[bit2] && cx[bit1] && (passed & (1 << bit1)) &&
      (passed & (1 << bit2)))
    return false;
  bit1 = (i + 1) % 3 * 3 + (j + 1) % 3;
  bit2 = (i + 2) % 3 * 3 + (j + 2) % 3;
  if (i == j && cx[bit1] == cx[bit2] && cx[bit1] && (passed & (1 << bit1)) &&
      (passed & (1 << bit2)))
    return false;
  bit1 = (i + 1) % 3 * 3 + (j - 1 + 3) % 3;
  bit2 = (i + 2) % 3 * 3 + (j - 2 + 3) % 3;
  if (i + j == 2 && cx[bit1] == cx[bit2] && cx[bit1] &&
      (passed & (1 << bit1)) && (passed & (1 << bit2)))
    return false;

  return true;
}
void dfs(ll passed) {
  if (passed == (1 << 9) - 1) {
    c++;
    return;
  }
  rep(i, 9) {
    if (passed & (1 << i)) continue;
    if (!poss(i, passed)) continue;

    dfs(passed | (1 << i));
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cx.resize(9);
  rep(i, 9) cin >> cx[i];

  int total = 1;
  rep2(i, 1, 10) total *= i;
  dfs(0);
  cout << fixed << setprecision(10) << double(c) / double(total) << endl;
}
