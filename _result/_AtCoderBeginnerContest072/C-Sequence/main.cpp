#include <bits/stdc++.h>

#include <atcoder/all>
#define out(X) cout << (X) << endl;
#define outs(XS)                      \
  for (auto X : XS) cout << X << " "; \
  cout << endl;
#define outl cout << endl;
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
using mint = atcoder::modint1000000007;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n) {
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}

ll n;
vector<ll> as;
ll calc() {
  ll sum = as[0];
  ll ans = 0;
  rep2(i, 1, n) {
    if (sum > 0) {
      if (sum + as[i] < 0) {
        sum += as[i];
      } else {
        ans += sum + as[i] + 1;
        sum = -1;
      }
    } else {
      if (sum + as[i] > 0) {
        sum += as[i];
      } else {
        ans += 1 - (sum + as[i]);
        sum = 1;
      }
    }
  }
  return ans;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  as = nis(n);

  ll ans = INFLL;
  ll a0 = as[0];
  if (a0 > 0) {
    as[0] = a0;
    ans = min(ans, calc());
  } else {
    as[0] = 1;
    ans = min(ans, calc() + 1 - a0);
  }
  if (a0 < 0) {
    as[0] = a0;
    ans = min(ans, calc());
  } else {
    as[0] = -1;
    ans = min(ans, calc() + a0 + 1);
  }
  out(ans);
}
