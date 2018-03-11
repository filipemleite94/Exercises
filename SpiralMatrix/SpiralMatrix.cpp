class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        int i(0), j(0), lSize(matrix.size());
        if(lSize<1)
            return vec;
        int cSize(matrix[0].size());
        int l(lSize-1), c(cSize-1);
        vec.reserve((l+1)*(c+1));
        int aux;
        int iMid(lSize/2), jMid(cSize/2);
        while(i<iMid&&j<jMid){
            aux = j + c;
            while(j<aux)
                vec.push_back(matrix[i][j++]);
            aux = i + l;
            while(i<aux)
                vec.push_back(matrix[i++][j]);
            aux = j - c;
            while(j>aux)
                vec.push_back(matrix[i][j--]);
            aux = i-l;
            while(i>aux)
                vec.push_back(matrix[i--][j]);
            i++;
            j++;
            c-=2;
            l-=2;
        }
        if(lSize%2 && cSize%2 && lSize==cSize){
            vec.push_back(matrix[i][j]);
            return vec;
        }
        bool doCol(lSize%2 && lSize<cSize), doLine(cSize%2 && cSize<lSize);
        cout<<i<<" "<<iMid<<" "<<j<<" "<<jMid<<" "<<c<<" "<<l<<" "<<doCol<<" "<<doLine<<endl;
        if(doCol){
            aux = j + c;
            while(j<=aux)
                vec.push_back(matrix[i][j++]);
        }
        if(doLine){
            aux = i + l;
            while(i<=aux)
                vec.push_back(matrix[i++][j]);
        }
        return vec;
    }
};