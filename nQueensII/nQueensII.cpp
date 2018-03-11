class Solution {
private:
    vector<int> pos;
    int n;
    int q;
    
    bool checkPos(const int i, const int j){
        for(int k = 0; k<i; k++){
            if(j==pos[k])
                return false;
            if(max(pos[k]-j, j-pos[k])==i-k)
                return false;
        }
        return true;
    }
    
    void getSols(const int i){
        if(i==n){
            q++;
            return;
        }
        for(int j = 0; j<n; j++){
            if(checkPos(i,j)){
                pos[i] = j;
                getSols(i+1);
            }
        }
        return;
    }
public:
    int totalNQueens(int n) {
        if(n<2)
            return n;
        this->n = n;
        pos = vector<int>(n);
        q = 0;
        /*int half((n+1)/2);
        for(int i = 0; i<half; i++){
            pos[0] = i;
            getSols(1);
        }
        return 2*q;*/
        getSols(0);
        return q;
    }
};