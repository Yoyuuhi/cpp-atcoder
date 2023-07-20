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

  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> mem1(n, 0);
  vector<ll> mem2(n, 0);
  ll count = 0;
  ll ans = 0;
  for (ll i = n - 1; i >= 0; i--) {
    if (s[i] == '1') count++;
    if (s[i] == '0') {
      ans += i;
      if (i + 1 < n) mem2[i] += mem1[i + 1] / 2;
      count = 0;
    }
    mem1[i] = count;
    if (i + 1 < n) mem2[i] += mem2[i + 1];
  }

  rep(i, n) {
    char c = s[i];
    if (c == '0') {
      if (i + 1 < n) ans += mem2[i + 1] + mem1[i + 1] / 2 + mem1[i + 1] % 2;
    } else {
      ans += (mem1[i] - 1) / 2 + 1 + mem2[i];
    }
  }
  out(ans);
}
