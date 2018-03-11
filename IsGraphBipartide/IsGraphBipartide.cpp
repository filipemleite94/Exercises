class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size(graph.size());
        if(!size)
            return true;
        vector<bool> visited(size, false), color(size, false);
        stack<int> current, next;
        current.push(0);
        bool b = false;
        visited[0] = true;
        while(!current.empty()){
            b = !b;
            while(!current.empty()){
                vector<int> v = graph[current.top()];
                current.pop();
                for(int i = 0; i<v.size();i++){
                    int j = v[i];
                    if(visited[j]){
                        if(color[j]!=b)
                            return false;
                    }else{
                        visited[j] = true;
                        color[j] = b;
                        next.push(j);
                    }                    
                }
            }
            if(next.empty()){
                int i = 0;
                while(i<size&&visited[i]) i++;
                if(i<size){
                    visited[i] = true;
                    color[i] = b;
                    current.push(i);
                }
            }else{
                while(!next.empty()){
                    current.push(next.top());
                    next.pop();
                }
            }            
        }
        return true;
    }
};