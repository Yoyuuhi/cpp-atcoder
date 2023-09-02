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

  ll n, d, p;
  cin >> n >> d >> p;
  vector<ll> fs(n);
  rep(i, n) cin >> fs[i];
  sort(all(fs), greater<ll>());

  int count = 0;
  ll ans = 0;
  ll sum = 0;
  rep(i, n) {
    sum += fs[i];
    count++;
    if (count == d) {
      count = 0;
      ans += min(sum, p);
      sum = 0;
    }
  }

  ans += min(sum, p);
  out(ans);
}
