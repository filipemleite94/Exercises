class Solution {
private:
    int intCompare(map<char, int> &m1, map<char, int> &m2){
        int size(m1.size());
        if(size!=m2.size())
            return m2.size() - size;
        auto it1(m1.begin());
        auto it2(m2.begin());
        while(it1!=m1.end()){
            if(it1->first!=it2->first){
                return it2->first - it1->first;
            }
            if(it1->second!=it2->second){
                return it1->second - it2->second;
            }
            it1++;
            it2++;
        }
        return 0;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<int, map<char, int>>> vec;
        int size(strs.size());
        vec.reserve(size);
        for(int i = 0; i<size; i++){
            map<char,int> auxMap;
            string &s = strs[i];
            for(int j = 0; j<s.length(); j++){
                auxMap[s[j]]++;
            }
            vec.push_back(make_pair(i,auxMap));
        }
        sort(vec.begin(), vec.end(), [&](pair<int, map<char, int>> &p1, pair<int, map<char, int>> &p2){return intCompare(p1.second,p2.second)<0;});
        
        vector<vector<string>> ans;
        for(int i = 0; i < size;){
            vector<string> v;
            v.push_back(strs[vec[i].first]);
            i++;
            while(i<size && !intCompare(vec[i].second, vec[i-1].second)){
                v.push_back(strs[vec[i].first]);
                i++;
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};