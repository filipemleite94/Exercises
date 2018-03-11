class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(src==dst)
            return 0;
        int fsize(flights.size());
        unordered_multimap<int,pair<int,int>> map;
        for(int i = 0; i < fsize; i++){
            map.insert(make_pair(flights[i][0], make_pair(flights[i][1], flights[i][2])));
        }
        int i = 0;
        int price = INT_MAX;
        int k = K+1;
        stack<pair<int,int>> current, next;
        current.push(make_pair(src,0));
        while(i++<k){
            if(current.empty())
                break;
            while(!current.empty()){
                int sr = current.top().first;
                int pr = current.top().second;
                current.pop();
                auto range = map.equal_range(sr);
                for (auto it = range.first; it != range.second; ++it){
                    int pr2 = pr + it->second.second;
                    int sr2 = it->second.first;
                    if(pr2<price){
                        if(sr2==dst)
                            price = pr2;
                        else{
                            next.push(make_pair(sr2, pr2));
                        }
                    }
                }
            }
            while(!next.empty()){
                current.push(next.top());
                next.pop();
            }
        }
        if(price==INT_MAX)
            price = -1;
        return price;
    }
};