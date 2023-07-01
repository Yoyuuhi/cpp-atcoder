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

bool comp(vector<ll> &a1, vector<ll> &a2) {
  if (a1[1] * (a2[1] + a2[2]) != a2[1] * (a1[1] + a1[2])) {
    return a1[1] * (a2[1] + a2[2]) > a2[1] * (a1[1] + a1[2]);
  } else {
    return a1[0] < a2[0];
  }
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;

  vector<vector<ll>> as(n);
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    as[i] = {i + 1, a, b};
  }
  sort(all(as), comp);
  rep(i, n) { cout << as[i][0] << " "; }
  cout << endl;
}
