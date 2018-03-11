class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> count;
		int sSize(s.length()), wSize(words.size());
		if(!sSize || ! wSize){
			return vector<int>();
		}
		
        {
			count.reserve(wSize);
            unordered_map <string, int> sMap;
			int i(0);
            for(; i< wSize; i++){
                auto it= sMap.find(words[i]);
                if(it == sMap.end()){
                    sMap[words[i]] = i;
                    count.push_back(1);
                }else{
                    count.push_back(0);
                    count[it->second]++;
                }
            }
			for(i = wSize; i;i--) if(count[i-1]) break;
			count.resize(i);
        }
        
        stack<int> st;
        unordered_map<int,int> map;
        for(int i = 0; i < sSize; i++){
            for(int j = 0; j < wSize; j++){
                if(!s.compare(i, words[j].length(), words[j])){
                    map[i] = j;
                    st.push(i);
                    break;
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            int j = st.top();
            st.pop();
            vector<int> vec (count);
            int i = map[j];
            vec[i]--;
            int k = wSize;
            int aux = j;
            while(--k){
                aux += words[i].length();
                auto it = map.find(aux);
                if(it==map.end() || !vec[it->second]){
                    break;
                }
                i = it->second;
                vec[i]--;
                
            }
            if(!k){
                ans.push_back(j);
            }
        }
        return ans;
    }
};