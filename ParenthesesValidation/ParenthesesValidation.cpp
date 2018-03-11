class Solution {
public:
    int longestValidParentheses(string s) {
        int size(s.length());
        if(size<2)
            return 0;
        int max(0), left(0), right(0), i(-1);
        while(++i<size){
            if(s[i]=='('){
                right++;
            }else{
                left++;
                if(left==right){
                    if(2*left>max)
                        max = 2*left;
                }else{
                    if(left>right){
                        left = 0;
                        right = 0;
                    }
                }
            }
        }
        left = 0;
        right = 0;
        i = size;
        while(i--){
            if(s[i]=='('){
                right++;
                if(left==right){
                    if(2*left>max)
                        max = 2*left;
                }else{
                    if(right>left){
                        left = 0;
                        right = 0;
                    }
                }
            }else{
                left++;
            }
        }
        return max;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int size(s.length());
        if(size<2) return 0;
        int max(0);
        stack<int> st;
        int i(-1),  j;
        st.push(-1);
        while(++i<size){
            if(s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                    continue;
                }
                if(i - st.top() >max){
                    max=i-st.top();
                }
            }
        }
        return max;
    }
};