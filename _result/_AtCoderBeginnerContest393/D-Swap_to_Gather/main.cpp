#include <bits/stdc++.h>

#include <atcoder/all>
#define outl cout << endl;
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
using mint = atcoder::modint1000000007;
const int INF = numeric_limits<int>::max() / 2;
const ll INFLL = numeric_limits<ll>::max() / 2;
template <typename T>
vector<T> nis(T n)
{
  vector<T> ret(n);
  rep(i, n) cin >> ret[i];
  return ret;
}
template <typename T>
typename enable_if<is_same_v<T, ll> || is_same_v<T, int> ||
                       is_same_v<T, unsigned int>,
                   void>::type
out(T value)
{
  cout << value << endl;
}
template <typename T>
typename enable_if<is_same_v<T, mint>, void>::type out(T value)
{
  cout << value.val() << endl;
}
template <typename T>
typename enable_if<is_same_v<T, vector<ll>> || is_same_v<T, vector<int>>,
                   void>::type
out(T value)
{
  for (auto v : value)
    cout << v << " ";
  cout << endl;
}

int main()
{
#ifdef __LOCAL
  freopen("input", "r", stdin);
#endif

  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<ll> sum1(n, 0), sum2(n, 0);
  ll tcnt = 0;
  rep(i, n)
  {
    auto c = s[i];
    if (c == '1')
    {
      sum1[i] += i;
      tcnt++;
    }
    if (i)
      sum1[i] += sum1[i - 1];
  }
  for (int i = n - 1; i >= 0; i--)
  {
    auto c = s[i];
    if (c == '1')
      sum2[i] += i;
    if (i + 1 < n)
      sum2[i] += sum2[i + 1];
  }

  ll ans = INFLL, cnt = 0;
  rep(i, n)
  {
    ll ta = 0;
    if (cnt)
      ta += (i - 1 + i - cnt) * cnt / 2 - sum1[i - 1];
    if (tcnt - cnt)
      ta += sum2[i] - (i + (i + tcnt - cnt - 1)) * (tcnt - cnt) / 2;
    ans = min(ans, ta);

    if (s[i] == '1')
      cnt++;
  }
  out(ans);
}
