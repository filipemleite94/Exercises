class Solution {
private:
    bool checkNum(int num){
        bool hasDif(false);
        int last = 0;
        int aux = 10;
        while(num){
            int aux2(num%10);
            num/=10;
//            cout<<last<<" "<<aux<<" "<<aux2<<" "<<num<<endl;
//            last += aux2;
            if(aux2==2||aux2==5||aux2==6||aux2==9){
                hasDif = true;
                continue;
            }
            if((aux2!=0)&& (aux2!=1)&& (aux2!=8)){
                return false;
            }
        }
        return hasDif;
    }
public:
    int rotatedDigits(int N) {
        int k(0);
        for(int i = 1; i<=N; i++){
            if(checkNum(i)){
                k++;
            }
        }
        return k;
    }
};