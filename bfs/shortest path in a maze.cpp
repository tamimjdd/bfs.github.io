#include<bits/stdc++.h>
using namespace std;
struct vecs{
    int x,y;
};

struct ques{
    int x,y,value;
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;

        int arr[11][11];
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cin>>arr[i][j];
            }
        }

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(arr[i][j]==0){
                    arr[i-1][j]=2;
                    arr[i-1][j+1]=2;
                    arr[i-1][j-1]=2;
                    arr[i][j-1]=2;
                    arr[i][j+1]=2;
                    arr[i+1][j-1]=2;
                    arr[i+1][j]=2;
                    arr[i+1][j+1]=2;
                }
            }
        }


        bool visited[11][11];
        memset(visited,false,sizeof(visited));
        vector<vecs>adj[11][11];
        int t1=0,t2=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){

                    if(arr[i][j]==1){

                            if(j==0 && t1==0){
                                t1=1;
                                a=i;
                                b=j;
                            }
                            else if(j==9 && t2==0){
                                t2=1;
                                c=i;
                                d=j;
                            }
                        if((i-1>=0 && i-1<=9)&&(j>=0 && j<=9) && (arr[i-1][j]==1)){
                            //cout<<i-1<<" "<<j<<endl;
                            vecs n={i-1,j};
                            adj[i][j].push_back(n);
                        }
                        if((i>=0 && i<=9)&&(j-1>=0 && j-1<=9)&& (arr[i][j-1]==1)){
                            //cout<<i<<" "<<j-1<<endl;
                            vecs n={i,j-1};
                            adj[i][j].push_back(n);
                        }
                        if((i+1>=0 && i+1<=9)&&(j>=0 && j<=9)&& (arr[i+1][j]==1)){
                            //cout<<i+1<<" "<<j<<endl;
                            vecs n={i+1,j};
                            adj[i][j].push_back(n);
                        }
                        if((i>=0 && i<=9)&&(j+1>=0 && j+1<=9)&& (arr[i][j+1]==1)){
                            //cout<<i<<" "<<j+1<<endl;
                            vecs n={i,j+1};
                            adj[i][j].push_back(n);
                        }
                    }
            }

        }

        queue<ques>q;
        ques n={a,b,0};
        visited[a][b]=true;
        q.push(n);
        while(!q.empty()){
            n=q.front();
            q.pop();
            if(n.x==c && n.y==d){
                cout<<n.value<<endl;
                //break;
            }
            for(auto u:adj[n.x][n.y]){
                if(!visited[u.x][u.y]){
                    visited[u.x][u.y]=true;
                    ques ns={u.x,u.y,n.value+1};
                    q.push(ns);
                }
            }
        }
    }
    return 0;
}
