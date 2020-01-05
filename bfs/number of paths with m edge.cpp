#include<bits/stdc++.h>
using namespace std;
struct edge{
    int src,des,wei;
};
class graph{
public:
    vector<vector<edge>>edges;
    graph(vector<edge>const &s,int n){
        edges.resize(n);
        for(auto u:s){
            edges[u.src].push_back({u.src,u.des,u.wei});
            //edges[u.des].push_back({u.des,u.src,u.wei});
        }
    }
};
struct que{
    int v,w,edge;
    set<int>s;
};
int bfs(graph const &g,int src,int k,int dest){
    queue<que>q;
    set<int>vertices;
    vertices.insert(src);
    int maxval=0;
    q.push({src,0,0,vertices});
    while(!q.empty()){
        que n=q.front();
        q.pop();
        int vs=n.v;
        int cost=n.w;
        vertices=n.s;
        int ms=n.edge;
        if(ms==k && vs==dest){
            maxval++;
        }
        for(edge e:g.edges[vs]){
            if(vertices.find(e.des)==vertices.end()){
                set<int>s2=vertices;
                s2.insert(e.des);
                if(n.edge+1<=k){
                    q.push({e.des,cost+e.wei,n.edge+1,s2});
                }
            }
        }
    }
    return maxval;
}
int main(){
    int n,m,a,b,c,k,dest;
    cin>>n>>m>>k>>dest;
    vector<edge>v;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v.push_back({a,b,c});
    }
    graph g(v,n);
    cout<<bfs(g,0,k,dest)<<endl;
}
