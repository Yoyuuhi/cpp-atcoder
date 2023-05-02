// https://algo-logic.info/is-prime/
/*  is_prime(n)
    入力：整数 n
    出力：nが素数かの真偽値
    計算量：O(√n)
*/
bool is_prime(long long n) {  // is n prime or not
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

/*  make_is_prime(N)
    入力：整数 N
    出力：N までの数字が素数か判定したベクトル（i番目がtrueならiは素数）
    計算量：O(nloglogn)
*/
vector<bool> make_is_prime(int N) {
  vector<bool> prime(N + 1, true);
  if (n >= 0) prime[0] = false;
  if (n >= 1) prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (!prime[i]) continue;
    for (int j = i * i; j <= N; j += i) {
      prime[j] = false;
    }
  }
  return prime;
}

vector<int> get_primes(int N) {
  vector<int> primes;
  vector<bool> prime(N + 1, true);
  if (n >= 0) prime[0] = false;
  if (n >= 1) prime[1] = false;
  for (int i = 2; i <= N; i++) {
    if (!prime[i]) continue;
    for (int j = i * i; j <= N; j += i) {
      prime[j] = false;
    }
    primes.push_back(i);
  }
  return primes;
}

// https://algo-logic.info/euclidean-algolithm/
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
