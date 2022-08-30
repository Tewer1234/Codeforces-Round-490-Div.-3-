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
    ll ary[1000000];
    int used[100000];
    vector <int> nodes[1000000];
    stack <int> st;
    void dfs(int n){
      int nxt;
      for (int i=0;i<nodes[n].size();i++){
        nxt=nodes[n][i];
        if (!used[nxt]){
          used[nxt]=1;
          dfs(nxt);
        }
      }
    }
     
    void dfs2(int n){
      int nxt;
      for (int i=0;i<nodes[n].size();i++){
        nxt=nodes[n][i];
        if (!used[nxt]){
          used[nxt]=1;
          // st.push(nxt);
          dfs(nxt);
        }
      }
    }
    int main() {
      ios::sync_with_stdio(false);
      cin.tie(0);
      int n,m,cap,x,y;
      cin>>n>>m>>cap;
      for (int i=1;i<=m;i++){
        cin>>x>>y;
        nodes[x].pb(y);
      }
      
      int ans=0;
      used[cap]=1;
      dfs(cap);
     
      for (int i=1;i<=n;i++){
        if (!used[i]){
          used[i]=1;
          st.push(i);
          dfs2(i);
        }
      }
      
      memset(used,0,sizeof(used));
      while (!st.empty()){
        // cout<<st.top()<<" ";
        int t=st.top();
        st.pop();
        if (!used[t]){
          // cout<<t<<"\n";
          used[t]=1;
          ans++;
          dfs(t);
        }
      }
      // cout<<"\n";
      cout<<ans;
      return 0; 
    }
