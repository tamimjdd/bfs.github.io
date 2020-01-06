
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a,b;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int>q;
    q.push(0);
    bool visited[n];
    visited[0]=true;
    int arr[n+1],p[n+1];
    memset(arr,0,sizeof(arr));

    memset(visited,false,sizeof(visited));
    int val=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        val=1;
        for(auto v:adj[u]){
            if(!visited[v]){
                        if(arr[u]==val){val++;arr[v]=val;}
                        else{
                            arr[v]=val;
                            val++;
                        }

                visited[v]=true;
                q.push(v);
            }

        }
    }
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
