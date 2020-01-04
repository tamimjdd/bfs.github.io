#include<bits/stdc++.h>
using namespace std;
//solved
struct adjs{
    int x,y;
};
struct qs{
    int x,y;
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n+1][m+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }

        vector<adjs>adj[n+1][m+1];

        int a,b,x,val;
        cin>>a>>b>>x;
        val=arr[a][b];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){


                        if((i-1>=0 && i-1<=n-1)&&(j>=0 && j<=m-1) && (arr[i-1][j]==val)){
                            //cout<<i-1<<" "<<j<<endl;
                            adjs n={i-1,j};
                            adj[i][j].push_back(n);
                        }
                        if((i>=0 && i<=n-1)&&(j-1>=0 && j-1<=m-1)&& (arr[i][j-1]==val)){
                            //cout<<i<<" "<<j-1<<endl;
                            adjs n={i,j-1};
                            adj[i][j].push_back(n);
                        }
                        if((i+1>=0 && i+1<=n-1)&&(j>=0 && j<=m-1)&& (arr[i+1][j]==val)){
                            //cout<<i+1<<" "<<j<<endl;
                            adjs n={i+1,j};
                            adj[i][j].push_back(n);
                        }
                        if((i>=0 && i<=n-1)&&(j+1>=0 && j+1<=m-1)&& (arr[i][j+1]==val)){
                            //cout<<i<<" "<<j+1<<endl;
                            adjs n={i,j+1};
                            adj[i][j].push_back(n);
                        }
                       /* if((i-1>=0 && i-1<=n-1)&&(j-1>=0 && j-1<=m-1)&& (arr[i-1][j-1]==val)){
                            //cout<<i<<" "<<j+1<<endl;
                            adjs n={i-1,j-1};
                            adj[i][j].push_back(n);
                        }
                        if((i-1>=0 && i-1<=n-1)&&(j+1>=0 && j+1<=m-1)&& (arr[i-1][j+1]==val)){
                            //cout<<i<<" "<<j+1<<endl;
                            adjs n={i-1,j+1};
                            adj[i][j].push_back(n);
                        }
                        if((i+1>=0 && i+1<=n-1)&&(j-1>=0 && j-1<=m-1)&& (arr[i+1][j-1]==val)){
                            //cout<<i<<" "<<j+1<<endl;
                            adjs n={i+1,j-1};
                            adj[i][j].push_back(n);
                        }
                        if((i+1>=0 && i+1<=n-1)&&(j+1>=0 && j+1<=m-1)&& (arr[i+1][j+1]==val)){
                            //cout<<i<<" "<<j+1<<endl;
                            adjs n={i+1,j+1};
                            adj[i][j].push_back(n);
                        }*/
                    }

        }


        bool visited[n+1][m+1];
        memset(visited,false,sizeof(visited));
        queue<qs>q;
        qs no={a,b};
        q.push(no);
        visited[a][b]=true;
        arr[a][b]=x;
        while(!q.empty()){
            no=q.front();
            q.pop();
            for(auto u:adj[no.x][no.y]){
                if(!visited[u.x][u.y] && arr[u.x][u.y]==val){
                    visited[u.x][u.y]=true;
                    qs ns={u.x,u.y};
                    arr[u.x][u.y]=x;
                    q.push(ns);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
