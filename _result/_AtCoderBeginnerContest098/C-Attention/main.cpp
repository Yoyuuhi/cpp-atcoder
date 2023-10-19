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
  string s;
  cin >> s;
  vector<int> mem1(n, 0), mem2(n, 0);
  rep2(i, 1, n) {
    mem1[i] += mem1[i - 1];
    if (s[i - 1] == 'W') mem1[i]++;
  }
  for (int i = n - 2; i >= 0; i--) {
    mem2[i] += mem2[i + 1];
    if (s[i + 1] == 'E') mem2[i]++;
  }

  int ans = INF;
  rep(i, n) ans = min(ans, mem1[i] + mem2[i]);
  out(ans);
}
