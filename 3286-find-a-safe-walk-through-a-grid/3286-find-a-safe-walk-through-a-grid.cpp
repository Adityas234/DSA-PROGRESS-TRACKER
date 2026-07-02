class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Directions for moving up, down, left, and right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // minCost[i][j] stores the minimum health lost to reach cell (i, j)
        vector<vector<int>> minCost(m, vector<int>(n, 1e9));
        
        // Double-ended queue for 0-1 BFS: stores pairs of {row, col}
        deque<pair<int, int>> dq;
        
        // Initialize the starting cell
        minCost[0][0] = grid[0][0];
        dq.push_back({0, 0});
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            
            // If we reached the destination, we can break early
            if (r == m - 1 && c == n - 1) {
                break;
            }
            
            // Explore all 4 neighbors
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                
                // Check boundaries
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int weight = grid[nr][nc];
                    
                    // If a safer path to the neighbor is found
                    if (minCost[r][c] + weight < minCost[nr][nc]) {
                        minCost[nr][nc] = minCost[r][c] + weight;
                        
                        // 0-1 BFS optimization: 
                        // If weight is 0, push to front. If weight is 1, push to back.
                        if (weight == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }
        
        // We need remaining health to be >= 1, meaning health lost must be < health
        return minCost[m - 1][n - 1] < health;
    }
};