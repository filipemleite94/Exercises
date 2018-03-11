class Solution {
private:
    int pace;
    int div(int dividend){
        if(dividend > pace) return 0;
        int divisor(pace);
        int q(1);
        while(dividend-divisor<divisor){
            divisor+=divisor;
            q+=q;
        }
        return q + div(dividend-divisor);
    }
public:
    int divide(int dividend, int divisor) {
        if(!dividend)
            return 0;
        if(!divisor)
            return INT_MAX;
        bool sameSignal(dividend>0 == divisor>0);
        if(dividend>0)
            dividend = -dividend;
        if(divisor>0)
            divisor = -divisor;
        if(divisor==-1 && dividend == INT_MIN) return sameSignal? INT_MAX:INT_MIN;
        pace = divisor;
        int q(div(dividend));
        return (sameSignal)? q:-q;
    }
};