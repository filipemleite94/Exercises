class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int i(0), j(0), b(n), k(1);
        while(b>0){
            int aux(j+b);
            while(j<aux){
                v[i][j++] = k++;
            }
            j--;
            i++;
            b--;
            //if(!b) break;
            aux = i + b; 
            while(i<aux){
                v[i++][j] = k++;
            }
            i--;
            j--;
            aux = j-b;
            while(j>aux){
                v[i][j--] = k++;
            }
            b--;
            i--;
            j++;
            aux = i-b;
            while(i>aux){
                v[i--][j] = k++;
            }
            i++;
            j++;
        }
        return v;
    }
};