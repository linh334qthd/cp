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

const int N = 2e5 + 5;

int bit[N];

void add(int i, int val) {
  for (; i < N; i |= i + 1) bit[i] += val;
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}

int func(char c) {
  if ('a' <= c && c <= 'z') return c - 'a';
  if ('A' <= c && c <= 'Z') return 26 + c - 'A';
  return 52 + c - '0';
}

char str[N];
set<int> s[70];

int main() {
  int n, q;
  scanf("%d %d %s", &n, &q, str + 1);
  for (int i = 1; i <= n; i++) {
    add(i, 1);
    int id = func(str[i]);
    s[id].insert(i);
  }
  
  while (q--) {
    int l, r;
    char c;
    scanf("%d %d %c", &l, &r, &c);
    int id = func(c);
    
    int lef = 1, rig = n;
    while (lef < rig) {
      int mid = (lef + rig) >> 1;
      if (find(mid) < l) {
        lef = mid + 1;
      } else {
        rig = mid;
      }
    }
    vector<int> rem;
    auto it = s[id].lower_bound(lef);
    while (it != s[id].end()) {
      if (find(*it) > r) break;
      rem.push_back(*it);
      it++;
    }
    for (auto it : rem) {
      s[id].erase(it);
      add(it, -1);
    }
  }
  int len = find(n);
  for (int i = 1; i <= len; i++) {
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (find(mid) < i) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    printf("%c", str[l]);
  }

  return 0;
}
