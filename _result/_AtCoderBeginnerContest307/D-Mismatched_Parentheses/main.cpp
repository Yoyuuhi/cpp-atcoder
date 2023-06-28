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

  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<char> cs;
  int lq = 0;
  rep(i, n) {
    char c = s[i];
    if (c == '(') lq++;
    cs.push_back(c);
    if (c == ')' && lq) {
      char cx = cs[cs.size() - 1];
      while (cx != '(') {
        cs.pop_back();
        cx = cs[cs.size() - 1];
      }
      cs.pop_back();
      lq--;
    }
  }
  for (auto c : cs) cout << c;
  cout << endl;
}
