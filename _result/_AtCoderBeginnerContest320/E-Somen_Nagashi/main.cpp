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

  int n, m;
  cin >> n >> m;

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq1;
  vector<ll> mem(n, 0);
  vector<bool> exist(n, true);
  rep(i, n) { pq.push(i); }

  rep(i, m) {
    ll t, w, s;
    cin >> t >> w >> s;
    if (!pq1.empty()) {
      auto p1 = pq1.top();
      while (!pq1.empty() && p1.first <= t) {
        pq1.pop();
        if (!exist[p1.second]) {
          pq.push(p1.second);
          exist[p1.second] = true;
        }
        if (!pq1.empty()) {
          p1 = pq1.top();
        }
      }
    }
    if (pq.empty()) continue;
    auto p = pq.top();
    pq.pop();
    exist[p] = false;
    pq1.push({t + s, p});
    mem[p] += w;
  }
  for (auto m : mem) out(m);
}
