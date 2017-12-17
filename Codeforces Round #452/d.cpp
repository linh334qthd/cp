/*

Our shadows stretch out on the pavement
As I walk in the twilight with you
If we could be together like this forever
Holding hands
It's almost enough to make me cry

The wind grows colder
I can smell winter
Soon the season will come to this town
When I can get close to you

This moment
When the two of us cuddle up
To gaze at the first snow flower of the year
Is overflowing with happiness

It's not dependence or weakness
I just love you
I thought so with all my heart

I feel like when I'm with you
I can overcome anything
I pray that these days
Will continue forever

The wind rattled the window
The night shakes you awake
I will change any sorrow
Into a smile

The snow flowers fell
Outside the window
Unceasing
And colored our town
I realized that love means
Wanting to do something
For someone else

If I should lose you
I'll become a star and shine on you
I'll be with you even on nights
When your smile is wet with tears

This moment
When the two of us cuddle up
To gaze at the first snow flower of the year
Is overflowing with happiness

It's not dependence or weakness
I just want to be like this
With you forever
I can honestly think that now

The pure white snow flowers
Bury this town
Softly drawing memories in our hearts
Together forever with you...

*/

#include <bits/stdc++.h>

using namespace std;

long long n;

long long make(int nine, int at, int num) {
  long long ret = 0;
  for (int i = 0; i < nine; i++) {
    if (i == at) {
      ret = ret * 10 + num;
    }
    ret = ret * 10 + 9;
  }
  if (nine == at) {
    ret = ret * 10 + num;
  }
  return ret;
}

long long solve(long long sum) {
  long long l = max(1LL, sum - n);
  long long r = (sum - 1) / 2;
  return (l > r? 0 : r - l + 1);
}

int dig(long long n) {
  if (n < 10) return 1;
  return 1 + dig(n / 10);
}

int main() {
  scanf("%lld", &n);
  int d = dig(n);
  if (make(d, 0, 0) > 2 * n - 1) d--;
  if (d == 0) {
    cout << n * (n - 1) / 2 << endl;
    return 0;
  }
  long long ans = 0;
  for (int at = 0; at <= 0; at++) {
    for (int num = 0; num <= 8; num++) {
      long long sum = make(d, at, num);
      if (sum > 2 * n - 1) continue;
      ans += solve(sum);
    }
  }
  cout << ans << endl;
  return 0;
}
