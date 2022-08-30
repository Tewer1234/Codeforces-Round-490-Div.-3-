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
    typedef pair<int,int> pp;
    ll ary[1000000];
    int check[1000000];
    vector <int> cnt;
    vector <pp> pos[1000000];
    vector <pp> fre; 
    int main() {
      ios::sync_with_stdio(false);
      cin.tie(0);
      int n,m,k;
      cin>>n>>m;
      k=n/m;
      for (int i=1;i<=n;i++) cin>>ary[i];
      
      map <ll,ll> mp;
      for (int i=1;i<=n;i++){
        // mp[ary[i]%m]++;
        check[ary[i]%m]++;
        pos[ary[i]%m].pb(make_pair(ary[i]%m,i));
      }
      
      ll ans=0;
      for (int i=0;i<2*m;i++){
        int cur=i%m;
        pp last;
        while (check[cur]>k){
          check[cur]--;
          last=make_pair(pos[cur].back().first,pos[cur].back().second);
          pos[cur].pop_back();
          fre.pb(make_pair(i,last.second));
        }
        
        while (check[cur]<k and !fre.empty()){
          check[cur]++;
          last=fre.back();
          fre.pop_back();
          int temp=i-last.first;
          int p=last.second;
          ary[p]+=temp;
          ans+=temp;
        }
      }
      cout<<ans<<"\n";
      for (int i=1;i<=n;i++) cout<<ary[i]<<" ";
      return 0; 
      
    }
     
