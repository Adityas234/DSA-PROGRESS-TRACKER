class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If the start or end cell has a thief, the safeness factor is automatically 0
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

        // dist[r][c] will store the minimum Manhattan distance to any thief
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Step 1: Push all thieves into the queue to start Multi-source BFS
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }

        // Direction vectors for moving up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Calculate distance map from any thief
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2: Use a Max-Heap (Priority Queue) to find the path that maximizes the minimum safeness
        // Priority Queue stores: {safeness_factor, {r, c}}
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        maxHeap.push({dist[0][0], {0, 0}});
        visited[0][0] = true;

        while (!maxHeap.empty()) {
            auto [safeness, cell] = maxHeap.top();
            auto [r, c] = cell;
            maxHeap.pop();

            // If we reached the destination, return the safeness factor
            if (r == n - 1 && c == n - 1) {
                return safeness;
            }

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    // The safeness of the path to the neighbor is limited by the minimum safeness seen so far
                    int nextSafeness = min(safeness, dist[nr][nc]);
                    maxHeap.push({nextSafeness, {nr, nc}});
                }
            }
        }

        return 0;
    }
};