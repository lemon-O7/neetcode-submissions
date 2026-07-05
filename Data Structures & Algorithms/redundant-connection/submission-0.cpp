class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if(x == parent[x]) return x;
        return find(parent[x]);
    } 
    void unite(int x,int y) {
        int rootx = find(x), rooty = find(y);

        parent[rootx] = rooty;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;

        for(int i=0;i<edges.size();i++) {
            if(find(edges[i][0])==find(edges[i][1])) {
                return {edges[i][0],edges[i][1]};
            }
            unite(edges[i][0],edges[i][1]);
        }

        return {};
    }
};