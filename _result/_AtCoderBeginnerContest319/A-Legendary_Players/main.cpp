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

  map<string, int> mem;
  mem["tourist"] = 3858;
  mem["ksun48"] = 3679;
  mem["Benq"] = 3658;
  mem["Um_nik"] = 3648;
  mem["apiad"] = 3638;
  mem["Stonefeang"] = 3630;
  mem["ecnerwala"] = 3613;
  mem["mnbvmar"] = 3555;
  mem["newbiedmy"] = 3516;
  mem["semiexp"] = 3481;

  string s;
  cin >> s;
  out(mem[s]);
}
