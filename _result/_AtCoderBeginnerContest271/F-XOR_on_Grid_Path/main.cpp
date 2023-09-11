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

int n;
map<ll, ll> calc(int num, vector<vector<ll>> ax, bool rev) {
  map<ll, ll> ans;
  vector<int> route;
  rep(i, n - 1 - num) route.push_back(0);
  rep(i, num) route.push_back(1);
  do {
    int i = 0;
    int j = 0;
    ll num = ax[0][0];
    rep(idx, route.size()) {
      int r = route[idx];
      if (rev && idx == route.size() - 1) continue;
      if (r) {
        i++;
      } else {
        j++;
      }
      num ^= ax[i][j];
    }

    if (ans.find(num) == ans.end()) ans[num] = 0;
    ans[num] += 1;
  } while (next_permutation(all(route)));
  return ans;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  vector<vector<ll>> ax(n, vector<ll>(n));
  rep(i, n) { rep(j, n) cin >> ax[i][j]; }
  vector<vector<ll>> axr(n, vector<ll>(n));
  rep(i, n) {
    rep(j, n) {
      int ii = n - 1 - i;
      int jj = n - 1 - j;
      axr[ii][jj] = ax[i][j];
    }
  }

  ll ans = 0;
  rep(i, n) {
    int j = n - 1 - i;
    map<ll, ll> a1 = calc(i, ax, false);
    map<ll, ll> a2 = calc(j, axr, true);
    for (auto m = a1.begin(); m != a1.end(); m++) {
      ll k1 = m->first;
      ll v1 = m->second;
      ll v2 = a2[k1];
      if (a2.find(k1) == a2.end()) v2 = 0;
      ans += v1 * v2;
    }
  }
  out(ans);
}
