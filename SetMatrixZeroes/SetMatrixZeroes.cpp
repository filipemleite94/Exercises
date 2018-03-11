class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int hSize(matrix.size());
        if(!hSize)
            return;
        const int wSize(matrix[0].size());
        bool zero(false);
        int i(0), j(0);
        for(i = 0; i < hSize; i++){
            if(!matrix[i][0])
                zero = true;
            for(j = 1; j < wSize; j++){
                if(!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(i = hSize-1; i>=0; i--){
            for(j = wSize-1; j>=1; j--){
                if(!matrix[i][0]||!matrix[0][j])
                    matrix[i][j] = 0;
            }
            if(zero)
                matrix[i][0] = 0;
        }
        //cout<<"Here";
        return;    
    }
};