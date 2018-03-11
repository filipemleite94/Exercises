class Solution {
    vector<int> queens;
    vector<vector<string>> ans;
    int n;
    
    bool checkPos(int i, int j){
        for(int k = 0; k<i;k++){
            if(queens[k]==j)
                return false;
            if(max(queens[k]-j, j-queens[k])==i-k)
                return false;
        }
        return true;
    }    
    
    void printSol(){
        vector<string> vec(n, string(n, '.'));
        for(int i = 0; i< n; i++){
            vec[i][queens[i]] = 'Q';
        }
        
        ans.push_back(vec);
    }
    
    void getSols(const int i){
        if(i==n){
            printSol();
            return;
        }
        for(int j = 0; j < n; j++){
            if(checkPos(i, j)){
                queens[i] = j;
                getSols(i+1);
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        queens = vector<int>(n, -1);
        ans.clear();
        this->n = n;
        getSols(0);
        return ans;
    }
};