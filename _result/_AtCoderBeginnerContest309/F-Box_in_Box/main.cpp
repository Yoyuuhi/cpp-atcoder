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
const ll INF = numeric_limits<ll>::max() / 2;

ll op(ll a, ll b) { return min(a, b); }
ll e() { return INF; }

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<vector<ll>> hwds(n, vector<ll>(3));
  set<ll> stws;
  rep(i, n) {
    vector<ll> hwd(3);
    rep(j, 3) cin >> hwd[j];
    sort(all(hwd));
    hwds[i] = hwd;
    stws.insert(hwd[1]);
  }
  sort(all(hwds));

  vector<ll> mem(stws.size(), INF);
  vector<ll> ws;
  for (auto w : stws) ws.push_back(w);
  segtree<ll, op, e> st(mem);
  queue<vector<ll>> que;
  rep(i, n) {
    ll h = hwds[i][0];
    ll w = hwds[i][1];
    ll d = hwds[i][2];
    if (i && h > hwds[i - 1][0]) {
      while (!que.empty()) {
        vector<ll> hwd = que.front();
        que.pop();
        int idx = lower_bound(all(ws), hwd[1]) - ws.begin();
        st.set(idx, min(st.get(idx), hwd[2]));
      }
    }
    int idx = lower_bound(all(ws), w) - ws.begin();
    if (st.prod(0, idx) < d) {
      out("Yes");
      return 0;
    }
    que.push({h, w, d});
  }
  out("No");
}
