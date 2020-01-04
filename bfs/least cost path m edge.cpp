#include<bits/stdc++.h>
using namespace std;
struct edge{
    int src,des,wei;
};
class graph{
public:
    vector<vector<edge>>vs;
    graph(vector<edge>const &es,int n){
        vs.resize(n);
        for(auto u:es){
            vs[u.src].push_back({u.src,u.des,u.wei});
            vs[u.des].push_back({u.des,u.src,u.wei});
        }
    }
};
struct vecs{
    int v,w,edges;
    set<int>s;
};
int bfs(graph const &g,int src,int k,int desti){
    queue<vecs>q;
    set<int>vertices;
    vertices.insert(src);
    int mini=INT_MAX;
    q.push({src,0,0,vertices});
    while(!q.empty()){
        vecs ob=q.front();
        q.pop();
        int vs=ob.v;
        int cost=ob.w;
        vertices=ob.s;
        int val=ob.edges;
        if(val==k && vs==desti){
            mini=min(mini,cost);
        }
        for(edge e:g.vs[vs]){
            if(vertices.find(e.des)==vertices.end()){
                set<int>s2=vertices;
                s2.insert(e.des);
                if(val+1<=k){
                    q.push({e.des,cost+e.wei,val+1,s2});
                }
            }
        }
    }
    return mini;
}
int main(){
    vector<edge>v;
    int n,m,a,b,c,ed;
    cin>>n>>m>>ed;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        v.push_back({a,b,c});
    }
    graph g(v,n);
    cout<<bfs(g,0,ed,4);
}
