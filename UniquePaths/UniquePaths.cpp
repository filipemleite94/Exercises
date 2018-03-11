
class Solution {
public:
    int uniquePaths(int m, int n) {
        //The robot can take (m-1) downs and (n-1) rights.
        if(n<2||m<2)
            return 1;
        long long div(1), q(1);
        int sum = m+n-2;
        int max = std::max(m-1, n-1), i(0);
        while(max++<sum){
            div*=++i;
            q*=max;
        }
        return q/div;
    }
};