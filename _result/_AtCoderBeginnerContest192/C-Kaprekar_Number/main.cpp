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

ll g1(ll x) {
  vector<ll> nums;
  rep(i, 9) {
    if (!x) break;
    nums.push_back(x % 10);
    x /= 10;
  }
  sort(all(nums), greater<ll>());
  ll ans = 0;
  for (auto num : nums) {
    ans *= 10;
    ans += num;
  }
  return ans;
}

ll g2(ll x) {
  vector<ll> nums;
  rep(i, 9) {
    if (!x) break;
    nums.push_back(x % 10);
    x /= 10;
  }
  sort(all(nums));
  ll ans = 0;
  for (auto num : nums) {
    ans *= 10;
    ans += num;
  }
  return ans;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n, k;
  cin >> n >> k;
  rep(i, k) n = g1(n) - g2(n);
  out(n);
}
