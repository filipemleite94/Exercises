class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        size--;
        while(size>0&&height[size-1]>=height[size]){
            size--;
        }
        if(size<=1) return 0;
        int index = 0;
        while(index<size&&height[index]<=height[index+1]){
            index++;
        }
        if(index==size)
            return 0;
        
        int sum = 0;
        stack<pair<int,int>> st;
        while(index<size){
            //cout<< "*" << index<< " " << sum <<" "<<size <<endl;
            st.push(make_pair(index, height[index]));
            index++;
            while(index<=size&&height[index]<=height[index-1]){
                if(height[index]!=height[index-1]){
                    st.push(make_pair(index, height[index]));
                }else{
                    st.pop();
                    st.push(make_pair(index, height[index]));
                }
                index++;
            }
            int baseheight(st.top().second);
            st.pop();
            while(index<=size&&height[index]==height[index-1])
                index++;
            if(index>size)
                return sum;
            //cout<< "**" <<index<< " " << sum <<" "<<size <<endl;
            while(index <= size && height[index]>=height[index-1]){
                if(st.empty()){
                    while(index <= size && height[index] >= height[index-1])
                        index++;
                    break;
                }
                auto it = st.top();
                if(height[index]<=it.second){
                    sum+=(height[index]-baseheight)*(index - it.first-1);
                    baseheight = height[index];
                    if(baseheight==it.second){
                        st.pop();
                    }
                }else{
                    sum+=(it.second-baseheight)*(index - it.first-1);
                    st.pop();
                    baseheight = it.second;
                    continue;
                }
                index++;
                while(index<=size&&height[index]==height[index-1])
                    index++;
            }
            //cout<< "***" <<index<< " " << sum <<" "<<size <<endl;
            index--;
        }
        return sum;
    }
};