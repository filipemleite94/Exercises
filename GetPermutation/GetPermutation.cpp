class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> avaible(n+1, 0);
        int div = 1;
        avaible[0] = 0;
        for(int i = 1; i<n; i++){
            avaible[i] = i;
            div*=i;
        }
        string s(n, ' ');
        int i (0);
        k--;
        while(i<n){
            //cout<<avaible[0]<<" "<<k<<" "<<div<<endl;
            s[i] = avaible[k/div] + '1';
            avaible.erase(avaible.begin()+(k/div));
            k%=div;
            if(n==i+1)
                div = 1;
            else
                div/=(n-i-1);
            i++;
        }
        return s;
    }
};