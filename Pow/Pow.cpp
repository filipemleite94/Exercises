class Solution {
private:
    double recPow(double x, unsigned int n){
        if(n==0)
            return 1;
        unsigned int i = 1;
        double ans(x);
		while(2*i<n){
			i*=2;
			ans*=ans;
		}
        //cout<<ans<<" "<<i<<endl;
        return ans*recPow(x, n-i);
        
    }
public:
    double myPow(double x, int n) {
        if(x==0)
            return 0;
        if(n==0)
            return 1;
        double ans(x);
        unsigned int aux(0);
        if(n<0){
            ans = 1/ans;
            x = 1/x;
            if(n==INT_MIN){
                aux = static_cast<unsigned int>(INT_MAX)+1;
            }else{
                aux = -n;
            }
        }else{
            aux = n;
        }
        return recPow(x, aux);
    }
};

//A more intelligent solution
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)
            return 0;
        if(n==0)
            return 1;
        double ans(1);
        unsigned int aux(0);
        if(n<0){
            x = 1/x;
            if(n==INT_MIN){
                aux = static_cast<unsigned int>(INT_MAX)+1;
            }else{
                aux = -n;
            }
        }else{
            aux = n;
        }
        while(aux){
            if(aux%2==1){
                ans*=x;
            }
            aux/=2;
            x*=x;
        }
        return ans;
    }
};