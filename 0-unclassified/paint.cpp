#include <bits/stdc++.h>

/**
 * Codeforces Round #256 (Div. 2)
 * Problem : C
 * Luqman Arifin (kadalbonek)
 */
 
typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[5005];

LL paint(int l, int r, int now) {
	if(l > r) return 0;
	LL high = inf, i, pos, cnt = r - l + 1;
	bool rata = 1;
	FOR(i, l, r) {
		if(i > l && a[i] != a[i-1]) rata = 0;
		if(a[i] < high) {
			high = a[i];
			pos = i;
		}
	}
	if(rata) return min(cnt, high - now);
	LL cur = paint(l, pos - 1, high) + paint(pos + 1, r, high) + high - now;
	if(cnt < cur) cur = cnt;
	return cur;
}

int main(void)
{
	int i, n; sf("%d", &n);
	FORS(i, n) sf("%d", a + i);
	pf("%d\n", paint(0, n - 1, 0));
	return 0;
}
