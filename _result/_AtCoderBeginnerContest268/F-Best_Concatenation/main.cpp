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

bool comp(pair<ll, ll> &a1, pair<ll, ll> &a2) {
  return a1.second * a2.first < a1.first * a2.second;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];

  vector<pair<ll, ll>> mem;
  ll ans = 0;
  for (auto s : ss) {
    int count = 0;
    int sum = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      auto c = s[i];
      if (c - '0' < 10) {
        sum += c - '0';
      } else {
        ans += sum;
        count++;
      }
    }
    mem.push_back({count, sum});
  }

  sort(all(mem), comp);
  ll sum = 0;
  for (int i = mem.size() - 1; i >= 0; i--) {
    ll count = mem[i].first;
    ll num = mem[i].second;
    ans += count * sum;
    sum += num;
  }
  out(ans);
}
