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

  vector<string> ss = {"H" , "2B" , "3B" , "HR"};
  vector<bool> mem(4, false);
  rep(i, 4) {
    string s;
    cin>>s;
    rep(j, 4) {
      if (ss[j] == s) mem[j] = true;
    }
  }
  bool poss = true;
  for (auto m : mem) if (!m) poss = false;
  cout<< (poss ? "Yes" : "No") << endl;
}
