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

  out(108);
  vector<ll> ps = {4, 9, 5, 7, 11, 13, 17, 19, 23};
  int sum = 0;
  int idx = 0;
  vector<int> as;
  rep(i, 108) {
    if (i + 1 < sum + ps[idx]) {
      as.push_back(i + 2);
      continue;
    }
    as.push_back(i + 2 - ps[idx]);
    sum += ps[idx];
    idx++;
  }
  rep(i, 108) {
    if (i) cout << " ";
    cout << as[i];
  }
  cout << endl;

  vector<int> bs(108);
  rep(i, 108) cin >> bs[i];
  vector<ll> rs;
  sum = 0;
  for (auto p : ps) {
    int target = bs[sum];
    int pos = -1;
    rep(i, 108) {
      if (as[i] == target) {
        pos = i;
        break;
      }
    }
    int res = (pos - sum + 1) % p;
    sum += p;
    rs.push_back(res);
  }
  auto ans = crt(rs, ps);
  out(ans.first);
}
