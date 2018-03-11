class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m(obstacleGrid.size()), n(obstacleGrid[0].size());
        int i(m), j(n);
        vector<int> last(n, 0);
        
        i--;
        j--;
        if(!obstacleGrid[i][j])
            last[j] = 1;
        while(j--){
            if(last[j+1]&&!obstacleGrid[i][j]){
                last[j] = 1;
            }
        }
        int temp;
        while(i--){
            j = n-1;
            temp = 0;
            if(last[j]&&!obstacleGrid[i][j])
                temp = last[j];
            last[j] = temp;
            while(j--){
                temp = 0;
                if(!obstacleGrid[i][j]){
                    temp = last[j]+last[j+1];
                }
                last[j] = temp;
            }
        }
        return last[0];
    }
};