#include<bits/stdc++.h>
using namespace std;
class adjlist{
    int v;
    int w;
public:
    adjlist(int V,int W){
        v=V;
        w=W;
    }
    int getv(){return v;}
    int getw(){return w;}
};

class Graph{
    int V;
    list<adjlist> *adj;
    void topo(int v,bool visited[],stack<int>&s){
        visited[v]=true;
        list<adjlist>::iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++){
            adjlist ob=*i;
            if(!visited[ob.getv()]){
                topo(ob.getv(),visited,s);
            }
        }
        s.push(v);
    }
public:
    Graph(int v){
        this->V=v;
        adj=new list<adjlist>[V];
    }
    void addEdge(int v,int u,int w){
        adjlist ob(u,w);
        adj[v].push_back(ob);
        adjlist ob2(v,w);
        adj[u].push_back(ob2);
    }
    void shortestPath(int sor){
        int dist[V];

        for(int i=0;i<V;i++){
            dist[i]=-100;
        }
        dist[sor]=0;
        bool *visited=new bool[V];
        memset(visited,0,sizeof(visited));
        stack<int>s;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topo(i,visited,s);
            }
        }
        while(s.empty()==false){
            int u=s.top();
            s.pop();
            list<adjlist>::iterator i;
            for(i=adj[u].begin();i!=adj[u].end();i++){
                if(dist[i->getv()]<dist[u]+i->getw()){
                    dist[i->getv()]=dist[u]+i->getw();
                }
            }
        }
        for(int i=0;i<V;i++){
            cout<<dist[i]<<" ";
        }
    }

};

int main(){
Graph g(8);
    g.addEdge(0, 6, 11);
    g.addEdge(0, 1, 5);
    g.addEdge(1, 6, 3);
    g.addEdge(1, 5, 5);
    g.addEdge(1, 2, 7);
    g.addEdge(2, 3, -8);
    g.addEdge(3, 4, 10);
    g.addEdge(5, 2, -1);
    g.addEdge(5, 3, 9);
        g.addEdge(5, 4, 1);
            g.addEdge(6, 5, 2);
                g.addEdge(7, 6, 9);
                    g.addEdge(7, 1, 6);

    int s = 0;
    cout << "Following are shortest distances from source " << s <<" n";
    g.shortestPath(s);
}
