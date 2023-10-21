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

auto compare = [](pair<ll, ll> &a1, pair<ll, ll> &a2) -> bool {
  // less one is top
  return a1.second > a2.second;
};

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  ll n;
  cin >> n;
  vector<pair<ll, ll>> tds(n);
  rep(i, n) {
    ll t, d;
    cin >> t >> d;
    tds[i] = {t, t + d};
  }

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq1;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(compare)> pq2(
      compare);
  for (auto td : tds) pq1.emplace(td);
  ll lastTime = 0;
  ll ans = 0;
  while (!pq1.empty() || !pq2.empty()) {
    while (!pq1.empty() && pq1.top().first <= lastTime + 1) {
      auto td1 = pq1.top();
      pq2.emplace(td1);
      pq1.pop();
    }
    while (!pq2.empty() && pq2.top().second < lastTime + 1) {
      pq2.pop();
    }
    if (pq2.empty()) {
      if (!pq1.empty()) {
        lastTime = pq1.top().first - 1;
        continue;
      } else {
        break;
      }
    }
    ans++;
    // DBG(lastTime);
    // DBG(pq2.top().first);
    // DBG(pq2.top().second);
    // out("");
    pq2.pop();

    lastTime++;
  }
  out(ans);
}
