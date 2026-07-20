class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k = k % total; // Eliminate redundant full rotations
        
        // Initialize result grid with the same dimensions
        std::vector<std::vector<int>> result(m, std::vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Flatten 2D to 1D, shift, and wrap around
                int new_1d_idx = (i * n + j + k) % total;
                
                // Convert 1D back to 2D coordinates
                int new_r = new_1d_idx / n;
                int new_c = new_1d_idx % n;
                
                result[new_r][new_c] = grid[i][j];
            }
        }
        return result;
    }
};