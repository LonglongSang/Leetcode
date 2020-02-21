class Solution {
public:
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int count,int &row,int &col,int now_r,int now_c,vector<vector<char>> &board,string &word,bool &good){
        if(count==word.length()) good=true;
        if(!good && count<word.length() && now_r>=0 && now_r<row && now_c>=0 && now_c<col && board[now_r][now_c]==word[count]){
            char a=board[now_r][now_c];
            board[now_r][now_c]=255;
            for(int i=0;i<4;i++) dfs(count+1,row,col,now_r+dir[i][0],now_c+dir[i][1],board,word,good);
            board[now_r][now_c]=a;
        }else{
            return;
        }
    }
    bool exist(vector<vector<char>>& board, string word){
        bool good=false;
        int row=board.size(),col=board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    dfs(0,row,col,i,j,board,word,good);
                    if(good) return true;
                }
            }
        }
        return false;
    }
};
