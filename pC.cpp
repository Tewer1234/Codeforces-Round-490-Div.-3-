

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
    vector <int> oc[1000000];
    int cur[1000000],step[1000000],used[1000000];
    string alpha="abcdefghijklmnopqrstuvwxyz";
    int main() {
      ios::sync_with_stdio(false);
      cin.tie(0);
      int n,times;
      string s;
      cin>>n>>times>>s;
      for (int i=0;i<s.size();i++){
        oc[s[i]].pb(i);
      }
      for (int i=0;i<alpha.size();i++){
        if (oc[alpha[i]].size()){
          cur[alpha[i]]=oc[alpha[i]][0];
        }
      }
      // for (int i=0;i<alpha.size();i++){
      //   cout<<alpha[i]<<": ";
      //   for (int j=0;j<oc[alpha[i]].size();j++){
      //     cout<<oc[alpha[i]][j]<<" ";
      //   }
      //   cout<<"\n";
      // }
      for (int i=1;i<=times;i++){
        int flag=1,cnt=0;
        char c;
        while (flag){
          if (cnt>=alpha.size()){
            flag=0;
            break;
          }
          c=alpha[cnt];
          int l=step[c],r=oc[c].size()-1,mid,temp=-1;
          while (l<=r){
            mid=(l+r)/2;
            if (oc[c][mid]>=cur[c]){
              temp=mid;
              r=mid-1;
            }else{
              l=mid+1;
            }
          }
          if (temp==-1) cnt++;
          else{
            flag=0;
            cur[c]=oc[c][temp];
            used[cur[c]]=1;
            step[c]++;
            break;
          }
        }
        // cout<<s<<"\n";
      }
      for (int i=0;i<s.size();i++){
        if (!used[i]) cout<<s[i];
      }
      return 0; 
    }
     
