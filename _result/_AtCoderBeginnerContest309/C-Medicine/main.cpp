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

bool comp(pair<int, int> &a1, pair<int, int> &a2) {
  return a1.first < a2.first;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> abs(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    abs[i] = {a, b};
  }
  sort(all(abs), comp);

  ll sum = 0;
  rep(i, n) sum += abs[i].second;
  if (sum <= k) {
    out(1);
    return 0;
  }

  for (auto ab : abs) {
    if (sum - ab.second <= k) {
      out(ab.first + 1);
      return 0;
    }
    sum -= ab.second;
  }
}
