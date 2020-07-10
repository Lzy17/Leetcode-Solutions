class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()){
            return;
        }
        int num_row = board.size();
        int num_col = board[0].size();
        vector<vector<int>> in_progress;
        vector<vector<int>> surrounding;
        vector<int> pos;
        pos.push_back(-1);
        pos.push_back(-1);
        int row = 0;
        int col = 0;
        int ki = 0;
        while(true){
            while(row < num_row &&　in_progress.size() == 0){
                while(col < num_col && in_progress.size() == 0){
                    if(board[row][col] == 'O'){
                        //itself
                        pos[0] = row;
                        pos[1] = col;
                        in_progress.push_back(pos);
                        surrounding.push_back(pos);
                        board[pos[0]][pos[1]] = 'i';
                    }
                    col++;
                }
                if(col == num_col){
                    col = 0;
                    row++;
                }
            }

            while(in_progress.size() != 0){
                    vector<int> temp;
                    temp.push_back(-1);
                    temp.push_back(-1);
                    pos = in_progress.back();

                    if(pos[0] == 0 || pos[1] == 0 || pos[0] == num_row - 1 || pos[1] == num_col -1 ){
                        ki++;
                    }
                    in_progress.pop_back();
                    if(pos[1]+1 <= num_col - 1){
                        if(board[pos[0]][pos[1] + 1] == 'O'){
                            temp[0] = pos[0];
                            temp[1] = pos[1]+1;
                            board[temp[0]][temp[1]] = 'i';
                            in_progress.push_back(temp);
                            surrounding.push_back(temp);
                        }
                    }
                    //bot
                    if(pos[0]+1 <= num_row - 1){
                        if(board[pos[0]+1][pos[1]] == 'O'){
                            temp[0] = pos[0]+1;
                            temp[1] = pos[1];
                            board[temp[0]][temp[1]] = 'i';
                            in_progress.push_back(temp);
                            surrounding.push_back(temp);
                        }
                    }
                    //left
                    if(pos[1] - 1 >= 0){
                        if(board[pos[0]][pos[1] - 1] == 'O'){
                            temp[0] = pos[0];
                            temp[1] = pos[1]-1;
                            board[temp[0]][temp[1]] = 'i';
                            in_progress.push_back(temp);
                            surrounding.push_back(temp);
                        }
                    }
                    //top
                    if(pos[0] - 1 >= 0){
                        if(board[pos[0]-1][pos[1]] == 'O'){
                            temp[0] = pos[0]-1;
                            temp[1] = pos[1];
                            board[temp[0]][temp[1]] = 'i';
                            in_progress.push_back(temp);
                            surrounding.push_back(temp);
                        }
                    }


            }

            if( ki == 0){
                //cout<<"||KI = 0 case||";
                int neiborsize = surrounding.size();
                for(int i = 0; i < neiborsize; i++){
                    auto temp = surrounding.back();
                    surrounding.pop_back();
                    board[temp[0]][temp[1]] = 'X';
                }
            }
            else{
                //cout<<"||KI != 0 case||";
                int neiborsize = surrounding.size();
                for(int i = 0; i < neiborsize; i++){
                    surrounding.pop_back();
                }
                ki = 0;
            }



            if(row == num_row && col == 0 && in_progress.size() == 0){
                //cout<<"enter final step";
                for(int r = 0; r < num_row; r++){
                    for(int c = 0; c < num_col; c++){
                        if(board[r][c] == 'i'){
                            board[r][c] = 'O';
                        }
                    }

                }
                return;

            }



    }
    }



};
