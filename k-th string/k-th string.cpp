class Solution {
private:
    int getInt(int n, int k){
        if(n == 0)
            return 0;
        int aux = getInt(n-1, k/2);
        if(!aux)
            return k%2;
        else
            return (k+1)%2;
    }
public:
    int kthGrammar(int N, int K) {
        return getInt(N-1, K-1);
    }
};