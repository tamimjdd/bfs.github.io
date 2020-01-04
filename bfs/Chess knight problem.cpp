//solved by tamim wasif

#include<bits/stdc++.h>
using namespace std;

struct q{
    int x,y,value;
};
struct vectors{
    int x,y;
};
int main(){
    int t,n,pos1_x,pos1_y,pos2_x,pos2_y;
    cin>>t;
    while(t--){
            cin>>n;
            cin>>pos1_x>>pos1_y>>pos2_x>>pos2_y;
            vector<vectors>adj[21][21];
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if((i-1>=1 && i-1<=n)&&(j-2>=1 && j-2<=n)){
                        //cout<<i-1<<" "<<j-2<<endl;
                        //adj[i-1].push_back(j-2);
                        vectors n={i-1,j-2};
                        adj[i][j].push_back(n);
                    }
                    if((i+2>=1 && i+2<=n)&&(j-1>=1 && j-1<=n)){
                        //cout<<i+2<<" "<<j-1<<endl;
                        //adj[i+2].push_back(j-1);
                        vectors n={i+2,j-1};
                        adj[i][j].push_back(n);
                    }
                    if((i+2>=1 && i+2<=n)&&(j+1>=1 && j+1<=n)){
                       // cout<<i+2<<" "<<j+1<<endl;
                        //adj[i+2].push_back(j+1);
                        vectors n={i+2,j+1};
                        adj[i][j].push_back(n);
                    }
                    if((i+1>=1 && i+1<=n)&&(j+2>=1 && j+2<=n)){
                        //cout<<i+1<<" "<<j+2<<endl;
                        //adj[i+1].push_back(j+2);
                        vectors n={i+1,j+2};
                        adj[i][j].push_back(n);
                    }
                    if((i-1>=1 && i-1<=n)&&(j+2>=1 && j+2<=n)){
                        //cout<<i-1<<" "<<j+2<<endl;
                        //adj[i-1].push_back(j+2);
                        vectors n={i-1,j+2};
                        adj[i][j].push_back(n);
                    }
                    if((i-2>=1 && i-2<=n)&&(j-1>=1 && j-1<=n)){
                        //cout<<i-2<<" "<<j-1<<endl;
                        //adj[i-2].push_back(j-1);
                        vectors n={i-2,j-1};
                        adj[i][j].push_back(n);
                    }
                    if((i+1>=1 && i+1<=n)&&(j-2>=1 && j-2<=n)){
                        //cout<<i+1<<" "<<j-2<<endl;
                        //adj[i+1].push_back(j-2);
                        vectors n={i+1,j-2};
                        adj[i][j].push_back(n);
                    }
                    if((i-2>=1 && i-2<=n)&&(j+1>=1 && j+1<=n)){
                        //cout<<i-2<<" "<<j+1<<endl;
                        //adj[i-2].push_back(j+1);
                        vectors n={i-2,j+1};
                        adj[i][j].push_back(n);
                    }
                }
            }
            bool visited[n+1][n+1];
            memset(visited,false,sizeof(visited));
            visited[pos1_x][pos1_y]=true;
            queue<q>que;
            q node={pos1_x,pos1_y,0};
            que.push(node);
            while(!que.empty()){
                node=que.front();
                que.pop();
                if(node.x==pos2_x && node.y==pos2_y){
                    cout<<node.value<<endl;
                    break;
                }
                for(auto u:adj[node.x][node.y]){
                    if(!visited[u.x][u.y]){
                        visited[u.x][u.y]=true;
                        q n={u.x,u.y,node.value+1};
                        que.push(n);
                    }
                }
            }
    }
    return 0;
}
