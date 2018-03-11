class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n(grid.size()), m(grid[0].size());
        vector<int> last(m, -1);
        
        int i(n-1), j(m-1);
        
        last[j] = grid[i][j];
        while(j--){
            last[j] = grid[i][j]+last[j+1];
        }
        while(i--){
            j = m-1;
            last[j] += grid[i][j];
            while(j--){
                last[j] = grid[i][j] + min(last[j], last[j+1]);
            }
        }
        return last[0];
    }
};