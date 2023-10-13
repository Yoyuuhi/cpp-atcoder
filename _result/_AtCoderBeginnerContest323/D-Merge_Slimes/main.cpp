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

ll calcRest(ll num) {
  ll ans = 0;
  while (num) {
    ans += (num % 2);
    num /= 2;
  }
  return ans;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;

  map<ll, ll> mem;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  vector<pair<ll, ll>> scs(n);
  map<ll, bool> memed;
  ll ms = 0;
  rep(i, n) {
    ll s, c;
    cin >> s >> c;
    scs[i] = {s, c};
    pq.push(s);
    mem[s] = c;
    memed[s] = true;
    ms = max(ms, s);
  }

  ll ans = 0;
  while (!pq.empty()) {
    ll s = pq.top();
    pq.pop();

    ll num = mem[s];

    if (s >= ms) {
      ans += calcRest(num);
      continue;
    }
    ans += num % 2;
    mem[s * 2] += num / 2;
    if ((num / 2) && !memed[s * 2]) {
      pq.push(s * 2);
      memed[s * 2] = true;
    };
  }
  out(ans);
}
