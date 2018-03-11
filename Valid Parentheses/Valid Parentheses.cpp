class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it : s){
            if(it=='('||it=='['||it=='{'){
                st.push(it);
            }else{
                if(st.empty())
                    return false;
                switch(it){
                    case ')':
                        if(st.top()!='(') return false;
                        break;
                    case ']':
                        if(st.top()!='[') return false;
                        break;
                    case '}':
                        if(st.top()!='{') return false;
                        break;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};