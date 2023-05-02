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

ll n, a, b, c2;
vector<ll> ps;

vector<ll> get_primes(ll N) {
  vector<ll> primes;
  vector<bool> prime(N + 1, true);
  if (n >= 0) prime[0] = false;
  if (n >= 1) prime[1] = false;
  for (ll i = 2; i <= N; i++) {
    if (!prime[i]) continue;
    for (ll j = i * i; j <= N; j += i) {
      prime[j] = false;
    }
    primes.push_back(i);
  }
  return primes;
}

int bs(int ok, int ng, bool f(int)) {
  if (!f(ok)) return -1;
  if (f(ng)) return ng;
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (f(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

bool f(int idx) {
  ll c = ps[idx];
  return c * c <= c2;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  ps = get_primes(1000000);
  int ans = 0;

  rep(i, ps.size()) {
    a = ps[i];
    if (a * a * a * a * a > n) {
      break;
    }
    rep2(j, i + 1, ps.size()) {
      b = ps[j];
      c2 = n / (a * a * b);
      int ic = bs(j + 1, ps.size() - 1, f);
      if (ic == -1) {
        break;
      }
      ans += ic - j;
    }
  }
  out(ans);
}
