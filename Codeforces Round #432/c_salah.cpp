#include <bits/stdc++.h>

using namespace std;

const int N = 32000;

map<int, int> dp; 

int find(int k) {
  if (dp.count(k)) return dp[k];
  if (k == 0) return 0;
  int maks = -1;
  for (int i = 31; i >= 0; i--) {
    if (k & (1 << i)) {
      maks = i;
      break;
    }
  }
  set<int> nim;
  for (int i = 1; i < 29; i++) {
    if (i > maks) break;
    int bit = (-1) ^ ((1 << i) - 1);
    int ges = (k & bit);
    int be = ((k & (~bit)) | (k >> i));
    nim.insert(find(be));
  }
  for (int i = 0; ; i++) {
    if (!nim.count(i)) {
      dp[k] = i;
      break;
    }
  }
  return dp[k];
}

bool is[N];
vector<int> p;
map<int, set<int> > s;

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      p.push_back(i);
      for (long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    for (auto it : p) {
      int cur = 0;
      while (v % it == 0) {
        cur++;
        v /= it;
      }
      if (cur > 0) {
        s[it].insert(cur);
      }
    }
    if (v > 1) {
      s[v].insert(1);
    }
  }
  int nim = 0;
  for (auto it : s) {
    int num = 0;
    for (auto i : it.second) {
      num |= (1 << i);
    }
    nim ^= find(num);
  }
  puts(nim? "Mojtaba" : "Arpa");
  return 0;
}