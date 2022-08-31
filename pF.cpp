#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,ll> pp;
int ary[1000000];
int fav[1000000];
int h[1000000];
int dp[1005][5020];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  map <int,int> oc;
  map <int,int> f;
  for (int i=1;i<=n*k;i++){
    cin>>ary[i];
    oc[ary[i]]++;
  }
  for (int i=1;i<=n;i++){
    cin>>fav[i];
    f[fav[i]]++;
  }
  
  for (int i=1;i<=k;i++) cin>>h[i];
  
  for (int i=0;i<=n;i++){
    for (int j=0;j<=n*k;j++){
      for (int l=0;l<=k;l++){
        dp[i+1][j+l]=max(dp[i+1][j+l],dp[i][j]+h[l]);
      }
    }
  }
  
  // for (int i=1;i<=n;i++){
  //   for (int j=1;j<=n*k;j++){
      // cout<<i<<" "<<j<<": "<<dp[i][j]<<"\n";
    // }
    // cout<<"\n";
  // }
  int ans=0;
  for (auto it:f){
    int ff=it.first;
    int cnt=it.second;
    int cards=oc[ff];
    // cout<<it.first<<": "<<cnt<<" "<<cards<<" "<<dp[cnt][cards]<<"\n";
    ans+=dp[cnt][cards];
  }
  cout<<ans;
  return 0; 
}
