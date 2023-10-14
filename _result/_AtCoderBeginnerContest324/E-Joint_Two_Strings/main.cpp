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

int n;
string t;
vector<vector<int>> mem(26);
vector<int> is;
vector<int> ris;

void calcIs(string s) {
  int it = 0;
  rep(is, s.size()) {
    if (it == t.size()) break;
    if (t[it] == s[is]) it++;
  }
  is.push_back(it - 1);

  it = t.size() - 1;
  for (int is = s.size() - 1; is >= 0; is--) {
    if (it == -1) break;
    if (t[it] == s[is]) it--;
  }
  ris.push_back(it + 1);
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  cin >> n;
  cin >> t;
  vector<string> ss(n);
  rep(i, n) cin >> ss[i];

  rep(i, t.size()) {
    char c = t[i];
    mem[c - 'a'].push_back(i);
  }

  for (auto s : ss) {
    calcIs(s);
  }
  sort(all(is));
  sort(all(ris));
  ll ans = 0;
  for (auto i : is) {
    int num = upper_bound(all(ris), i + 1) - ris.begin();
    ans += num;
  }
  out(ans);
}
