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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> cs(n);
  rep(i, n) {
    cin >> cs[i];
    cs[i]--;
  }

  vector<vector<char>> mem(m);
  rep(i, n) mem[cs[i]].push_back(s[i]);
  vector<int> is(m, 0);
  rep(i, n) {
    int c = cs[i];
    cout << mem[c][(is[c] - 1 + mem[c].size()) % mem[c].size()];
    is[c]++;
  }
  cout << endl;
}
