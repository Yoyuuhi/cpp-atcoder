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

  int n;
  cin >> n;
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];

  vector<pair<int, int>> mem(n);
  rep(i, n) {
    mem[i] = {0, n - i};
    rep(j, n) {
      if (ss[i][j] == 'o') mem[i].first++;
    }
  }
  sort(all(mem), greater<pair<int, int>>());
  for (auto m : mem) cout << n - m.second + 1 << " ";
  cout << endl;
}
