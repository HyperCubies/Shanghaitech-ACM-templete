#include "macros.cpp"

ll mulmod(ll a, ll b, ll c) { return (b == 0) ? 0 : (((b & 1) * a + 2 * mulmod(a, b >> 1, c)) % c); }
ll expmod(ll a, ll b, ll c) { return (b == 0) ? 1 : ((b & 1) ? a : 1) * expmod(mulmod(a, a, c), b >> 1, c) % c;}

// should convince that gcd(a, b) = 1
ll inv(ll a, ll b) { return (a == 1) ? 1 : (inv(b % a, b) * (b - b / a) % b); }

bool *not_prime (int n) {
	bool *np = new bool[n + 1]();
	for (ll i = 2; i <= n; ++i)
	{
		if (np[i]) continue;
		for (ll j = i * i; j <= n; j += i)
			np[j] = 1;
	}
	return np;
}

vi prime_list(int n) {
	bool *np = not_prime(n);
	vi pl;
	for (int i = 2; i < n; ++i)
		if (!np[i]) pl.pb(i);
	delete[] np;
	return pl;
}

vpii prime_factor(vi pl, int n) {
	vpii fl;
	pii fp;
	for (auto p: pl) {
		fp = {p, 0};
		while (n % p == 0) {
			fp.se++;
			n /= p;
		}
		if (fp.se) fl.pb(fp);
		if (n < p) break;
	}
	if (n > 1) fl.pb({n, 1});
	return fl;
}

short *mobius(int n) {
	bool *np = new bool[n + 1]();
	short *m = new short[n + 1];
	fill_n(m, n + 1, 1);
	ll square;
	for (ll i = 2; i <= n; i++) {
		if (np[i]) continue;
		square = i * i;
		for (ll j = i; j <= n; j += i) {
			if (j >= square) np[j] = 1;
			m[j] *= -1;
			if (j % square == 0) m[j] = 0;
		}
	}
	delete[] np;
	return m;
}

void test() {
	auto pl = prime_list(4000);
	auto fl = prime_factor(pl, 354654);
	fora(p, fl) {
		cout << p.fi << ' ' << p.se << endl;
	}
}

int main() {
	test();
	system("pause");
	return 0;
}