class Solution {
public:
    bool valid(pair<int,int>p,char c,vector<vector<char>>&board){
        int i = p.first,j = p.second;
        for(int k=0;k<9;k++){
            if(board[k][j]==c||board[i][k]==c) return false;
        }
        i -= (i%3);
        j -= (j%3);
        int t1 = 3;
        while(t1--){
            int t2 = 3;
            int j1 = j;
            while(t2--){
                if(board[i][j1] == c) return false;
                j1++;
            }
            i++;
        }
        return true;
    }
    bool f(vector<vector<char>>&board,int i,vector<pair<int,int>>&v){
        if(i==v.size()) return true;
        for(char c='1';c<='9';c++){
            if(valid(v[i],c,board)){
                board[v[i].first][v[i].second] = c;
                if(f(board,i+1,v))
                    return true;
                board[v[i].first][v[i].second] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> v;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    v.push_back({i,j});
                }
            }
        }
       int k = f(board,0,v);
    }
};