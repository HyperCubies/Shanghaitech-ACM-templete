#include "macros.cpp"

ll ilg2(ll n) { return (n == 1) ? 0 : ilg2(n >> 1) + 1; }

ll lowbit(ll x) { return x & (-x); };

class BIT
{
	ll *b;
	int n, lgn;
public:
	BIT(int a[], int n);
	BIT(ll a[], int n);
	int size() { return n; }
	void edit(int k, ll delta);
	ll presum(int k);
	ll lower_bound(ll target);
};

BIT::BIT(int a[], int n) {
	lgn = ilg2(n);
	b = new ll[n + 1]();
	forn(i, 1, n + 1) 
		forn(j, i - lowbit(i) + 1, i)
			b[i] += a[j]; 
}

BIT::BIT(ll a[], int n) {
	lgn = ilg2(n);
	b = new ll[n + 1]();
	forn(i, 1, n + 1) 
		forn(j, i - lowbit(i) + 1, i)
			b[i] += a[j]; 
}

void BIT::edit(int k, ll delta) {
	while (k <= n) {
		b[k] += delta;
		k += lowbit(k);
	}
}

ll BIT::presum(int k) { return (k == 0) ? 0 : (b[k] + this->presum(k - lowbit(k))); }

ll BIT::lower_bound(ll target) {
	ll sum = 0;
	int i = 0;
	for (int j = 1 << lgn; j > 0; j >>= 1)
	{
		if (sum + b[i] <= target) {
			sum += b[i];
			i += j;
		}
	}
	return sum;
}


void test() {
	int a = 2;
	print(lowbit(a));
}


int main() {
	test();
	system("pause");
	return 0;
}