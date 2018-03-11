class Solution {
private:
    bool containsPutRecErase(vector<vector<char>>& board, string &word, int pos, int i, int j, unordered_set<int> &set){
        const int num(board[0].size()*i+j);
        if(set.find(num)!=set.end())
            return false;
        set.insert(num);
        if(exist(board, word, pos+1, i, j, set))
            return true;
        set.erase(num);
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string &word, int pos, int i, int j, unordered_set<int> &set){
        if(pos==word.length())
            return true;
        if(j<board[0].size()-1 && word[pos]==board[i][j+1] && containsPutRecErase(board, word, pos, i, j+1, set))
            return true;
        if(i<board.size()-1 && word[pos]==board[i+1][j] && containsPutRecErase(board, word, pos, i+1, j, set))
            return true;
        if(j && word[pos]==board[i][j-1] && containsPutRecErase(board, word, pos, i, j-1, set))
            return true;
        if(i && word[pos]==board[i-1][j] && containsPutRecErase(board, word, pos, i-1, j, set))
            return true;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int i(-1), j(-1), sizeH(board.size());
        if(!sizeH || !word.length()) return false;
        int sizeW(board[0].size());
        while(++i<sizeH){
            j = -1;
            while(++j<sizeW){
                if(board[i][j]==word[0]){
                    unordered_set<int> set;
                    set.insert(i*sizeW+j);
                    if(exist(board, word, 1, i, j, set)) return true;
                }
            }
        }
        return false;
    }
};