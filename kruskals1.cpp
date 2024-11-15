#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent,rank,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v)    return;
        if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v)    return;
        if(size[ulp_v]>size[ulp_u]){
            parent[ulp_u]=ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class MST{
    public:
    int spanningTree(int V,vector<vector<int>> adj[]){
        //1-2wt=5
        //1-(2,5)
        //2-(1,5)

        //5,1,2
        //5,2,1

        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                
                edges.push_back({wt,{node,adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstwt=0;
        for(auto it: edges){
            int wt = it.first;
            int u=it.second.first;
            int v=it.second.second;

            if(ds.findUParent(u)!=ds.findUParent(v)){
                mstwt+=wt;
                ds.unionBySize(u,v);
            }
        }
        return mstwt;
    }
    
};

int main() {

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    MST obj;
    int mstWt = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}