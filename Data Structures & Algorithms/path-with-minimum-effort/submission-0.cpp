class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n,m;
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()) {
            pair<int, pair<int,int>> x = pq.top();
            pq.pop();
            int eff = x.first;
            int row,col;
            row = x.second.first;
            col = x.second.second;
            if(row == n-1 && col == m-1) {
                return eff;
            }
            for(int d=0;d<4;d++) {
                int nr = row+dr[d];
                int nc = col+dc[d];
                if(nr>= n || nc >= m || nr<0 || nc<0) {
                    continue;
                }
                int ne = max(eff,abs(heights[nr][nc]-heights[row][col]));
                if(ne<dist[nr][nc]) {
                    dist[nr][nc] = ne;
                    pq.push({ne,{nr,nc}});
                }
            }
        }
        
        return 0;
    }
};