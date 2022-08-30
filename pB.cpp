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
      int n;
      string s;
      cin>>n>>s;
      
      for (int i=1;i<=n;i++){
        if (n%i==0){
          string sub="",temp;
          for (int j=i-1;j>=0;j--){
            sub+=s[j];
          }
          temp=s.substr(i);
          s=sub+temp;
        }
      }
      cout<<s;
      
      return 0; 
    }
     
