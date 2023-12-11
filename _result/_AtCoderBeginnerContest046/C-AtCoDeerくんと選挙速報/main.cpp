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

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  ll t = 1, a = 1;
  rep(i, n) {
    ll T, A;
    cin >> T >> A;
    ll tt = t / T + (t % T ? 1 : 0);
    ll ta = a / A + (a % A ? 1 : 0);

    ll t1 = T * tt, a1 = A * tt;
    ll t2 = T * ta, a2 = A * ta;
    if (t1 > t2) {
      swap(t1, t2);
      swap(a1, a2);
    }
    if (t1 >= t && a1 >= a) {
      t = t1;
      a = a1;
    } else {
      t = t2;
      a = a2;
    }
  }
  out(t + a);
}
