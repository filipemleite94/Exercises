class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size(matrix.size());
        int middleLin((size+1)/2);
        int middleCol((size+1)/2);
        int maxCol(middleCol), maxLin(size/2);
        int i1(0), j1(0), i2(size-1), j2(0), i3(size-1), j3(size-1), i4(0), j4(size-1);
        for(int i = 0; i<maxCol; i++){
            for(int j = 0; j<maxLin; j++){
                swap(matrix[i1][j1], matrix[i2][j2]);
                swap(matrix[i2][j2], matrix[i3][j3]);
                swap(matrix[i3][j3], matrix[i4][j4]);
                j1++; i2--;j3--; i4++;
            }
            i1++; j1 = 0; i2 = size-1; j2++; i3--; j3 = size-1; i4 =0; j4--;
        }
        return;
    }
};