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

ll calc(vector<int> as) {
  ll ans = 0;
  int n = as.size();
  rep(i, n - 1) {
    ll al = as[i];
    ll ar = as[i + 1];
    ll num = ar - al - 1;

    ans += num * (i + 1) * (n - i - 1);
  }
  return ans;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<int> as(n);
  rep(i, n) cin >> as[i];
  map<int, vector<int>> mem;
  rep(i, n) mem[as[i]].push_back(i);
  ll ans = 0;
  for (auto m : mem) {
    ans += calc(m.second);
  }
  out(ans);
}
