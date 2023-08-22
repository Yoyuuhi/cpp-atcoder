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
  vector<int> mem1(n, 0);
  vector<vector<int>> mem2(n);
  rep(i, n) {
    int f, s;
    cin >> f >> s;
    f--;
    mem1[f] = max(mem1[f], s);
    mem2[f].push_back(s);
  }

  sort(all(mem1), greater<int>());
  int ans = mem1[0] + mem1[1];
  rep(i, n) {
    if (mem2[i].size() < 2) continue;
    sort(all(mem2[i]), greater<int>());
    ans = max(ans, mem2[i][0] + mem2[i][1] / 2);
  }
  out(ans);
}
