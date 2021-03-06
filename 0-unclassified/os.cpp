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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[105];

int main(void)
{
	int i, n;
	sf("%d", &n);
	FORS(i, n) sf("%d", a + i);
	int m; sf("%d", &m);
	while(m--) {
		int x, y;
		sf("%d %d", &x, &y);
		x--;
		if(x) a[x-1] += y-1;
		a[x+1] += a[x] - y;
		a[x] = 0;
	}
	FORS(i, n) pf("%d\n", a[i]);
	return 0;
}
