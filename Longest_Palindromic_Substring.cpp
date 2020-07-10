class Solution {
public:
    string longestPalindrome(string s) {
        int start_store = -1;
        int end_store = -1;
        int max_len = 0;
        if(s.size() == 1 || s.size() == 0){
            return s;
        }
        for(int i = 0; i < s.size(); i++){
            for(int j = s.size() - 1; j >=0; j--){
                if(s[i] == s[j] && (i < start_store || j > end_store )){
                    if(checker(s.substr(i, j - i + 1))){
                        if(j - i + 1 > max_len){
                            start_store = i;
                            end_store = j;
                            max_len = j - i + 1;
                            if(max_len == s.size()){
                                return s;
                            }
                        }
                    }
                }

            }

        }
        return s.substr(start_store, end_store - start_store +1 );
    }
    bool checker(string s){

        for(int i = 0; i < (int) s.size()/2; i++){
            if(s.size()%2 == 1){
                if(s[s.size()/2 - 1 - i] != s[s.size()/2 + 1 + i]){
                    return false;
                }
            }
            else{
                if(s[s.size()/2 - i - 1] != s[s.size()/2 + i]){
                    return false;
                }
            }


        }
        return true;

    }
};
