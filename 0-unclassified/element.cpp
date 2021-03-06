#include <bits/stdc++.h>

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
const double eps = 1e-13;
const int N = 105;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N];

int main(void)
{
	int t, tt;
	sf("%d", &t);
	FOR(tt, 1, t) {
		int i, j, n;
		reset(a, 0);
		sf("%d", &n);
		FORS(i, n) sf("%d", &a[i]);
		sort(a, a + n);
		reverse(a, a + n);
		pf("Case %d: %d\n", tt, a[0] + a[1] + a[2]);
	}
	
	return 0;
}
