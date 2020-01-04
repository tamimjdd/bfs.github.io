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



        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){


                        if((i-1>=0 && i-1<=n-1)&&(j>=0 && j<=m-1) ){
                            //cout<<i-1<<" "<<j<<endl;
                            adjs n={i-1,j};
                            adj[i][j].push_back(n);
                        }
                        if((i>=0 && i<=n-1)&&(j-1>=0 && j-1<=m-1)){
                            //cout<<i<<" "<<j-1<<endl;
                            adjs n={i,j-1};
                            adj[i][j].push_back(n);
                        }
                        if((i+1>=0 && i+1<=n-1)&&(j>=0 && j<=m-1)){
                            //cout<<i+1<<" "<<j<<endl;
                            adjs n={i+1,j};
                            adj[i][j].push_back(n);
                        }
                        if((i>=0 && i<=n-1)&&(j+1>=0 && j+1<=m-1)){
                            //cout<<i<<" "<<j+1<<endl;
                            adjs n={i,j+1};
                            adj[i][j].push_back(n);
                        }
                        if((i-1>=0 && i-1<=n-1)&&(j-1>=0 && j-1<=m-1)){
                            //cout<<i<<" "<<j+1<<endl;
                            adjs n={i-1,j-1};
                            adj[i][j].push_back(n);
                        }
                        if((i-1>=0 && i-1<=n-1)&&(j+1>=0 && j+1<=m-1)){
                            //cout<<i<<" "<<j+1<<endl;
                            adjs n={i-1,j+1};
                            adj[i][j].push_back(n);
                        }
                        if((i+1>=0 && i+1<=n-1)&&(j-1>=0 && j-1<=m-1)){
                            //cout<<i<<" "<<j+1<<endl;
                            adjs n={i+1,j-1};
                            adj[i][j].push_back(n);
                        }
                        if((i+1>=0 && i+1<=n-1)&&(j+1>=0 && j+1<=m-1)){
                            //cout<<i<<" "<<j+1<<endl;
                            adjs n={i+1,j+1};
                            adj[i][j].push_back(n);
                        }
                    }

        }


        bool visited[n+1][m+1];
        memset(visited,false,sizeof(visited));
        queue<qs>q;
        int counts=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1 && visited[i][j]==0){
                        counts++;
                    qs no={i,j};
                    q.push(no);
                    visited[i][j]=true;
                    while(!q.empty()){
                        no=q.front();
                        q.pop();
                        for(auto u:adj[no.x][no.y]){
                            if(!visited[u.x][u.y] && arr[u.x][u.y]==1){
                                visited[u.x][u.y]=true;
                                qs aaas={u.x,u.y};
                                q.push(aaas);
                            }
                        }
                    }
                }
            }
        }

        cout<<counts<<endl;
    }
    return 0;
}

