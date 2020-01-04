#include<bits/stdc++.h>
using namespace std;
//solved

struct node{
    int x;
    int y;
};

struct new2{
    int id;
    int value;
};

int main(){
    int arr[31],t,n;

    cin>>t;
    while(t--){
        cin>>n;
        int a,b,temp=1;
        memset(arr,0,sizeof(arr));

        for(int i=0;i<n;i++){
            cin>>a>>b;
            if(a<b){
                arr[a]=b;
            }
        }

        vector<node>edge;

        int sor,des;
        for(int i=0;i<30;i++){
            for(int j=i+1;j<=(i+6)&&j<=30;j++){
                    sor=i;
                if(arr[j]==0){
                    des=j;
                }
                else{
                    des=arr[j];
                }
                node n={sor,des};
                edge.push_back(n);
            }
        }
        vector<int>adj[31];
        for(int i=0;i<edge.size();i++){
            sor=edge[i].x;
            des=edge[i].y;
            adj[sor].push_back(des);
        }

        bool visited[31];
        memset(visited,false,sizeof(visited));
        visited[1]=true;
        queue<new2>q;
        new2 news={1,0};
        q.push(news);

        while(!q.empty()){
               // cout<<"adsf"<<endl;
            news=q.front();
            q.pop();
            if(news.id==30){
                cout<<news.value<<endl;
                break;
            }
            for(auto i:adj[news.id]){
                if(!visited[i]){
                    visited[i]=true;
                    new2 n={i,news.value+1};
                    q.push(n);
                }
            }
        }

    }
    return 0;
}

