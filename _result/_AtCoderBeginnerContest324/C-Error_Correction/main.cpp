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

bool judge1(string s, string t) {
  int n = t.size();
  int count = 0;
  rep(i, n) {
    if (s[i] != t[i]) {
      count++;
      if (count > 1) return false;
    }
  }
  return count == 1;
}

bool judge2(string s, string t) {
  if (t.size() > s.size()) swap(t, s);
  int n = t.size();
  int add = 0;
  rep(i, n) {
    while (i + add <= s.size() && s[i + add] != t[i]) {
      add++;
      if (add > 1) return false;
    }
  }
  return true;
}

int main() {
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif
  int n;
  cin >> n;
  string t;
  cin >> t;

  vector<int> ans;
  rep(i, n) {
    string s;
    cin >> s;
    if (s == t) {
      ans.push_back(i + 1);
      continue;
    }
    if (t.size() == s.size()) {
      if (judge1(s, t)) ans.push_back(i + 1);
    } else if (abs(int(t.size() - s.size())) == 1) {
      if (judge2(s, t)) ans.push_back(i + 1);
    }
  }
  out(ans.size());
  for (auto a : ans) {
    cout << a << " ";
  }
  cout << endl;
}
