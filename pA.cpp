#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <set>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,ll> pp;
ll ary[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  for (int i=1;i<=n;i++){
    cin>>ary[i];
  }
  
  int l=1,r=n,flag=1,ans=0,pick;
  while (flag and l<=r){
    pick=1;
    if (ary[l]<=k){
      ans++;
      l++;
      pick=0;
    }else if (ary[r]<=k){
      ans++;
      r--;
      pick=0;
    }
    if (pick){
      flag=0;
      break;
    }
  }
  
  cout<<ans;
  return 0; 
}
