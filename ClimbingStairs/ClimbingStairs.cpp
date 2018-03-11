class Solution {
public:
    int climbStairs(int n) {
        if(n<3)
            return n;
        int current(2), next(1), i(n-2);
        while(i--){
            int temp(current);
            current += next;
            next = temp;
        }
        return current;
    }
};