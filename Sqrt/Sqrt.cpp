class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int ini(0), end(x), mid((ini+end)/2);
        while(1){
            //cout<<mid<<" "<<ini<<" "<<end<<" "<<endl;
            mid = (ini+end)/2;
            long long prod(mid*static_cast<long>(mid));
            if(prod<=x){
                if(prod+2*mid+1>x)
                    return mid;
                ini = mid;
            }
            else
                end = mid;
        }
        return 0;
    }
};