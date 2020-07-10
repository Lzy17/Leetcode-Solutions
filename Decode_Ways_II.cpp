class Solution {
public:
    int numDecodings(string s) {
        int count = 1;
        int final_ans = 1;
        vector<int> ans;
        for(int i = 0; i<s.size(); i++){
            if(s[i] - 48 < 0){
                return 0;
            }
            if(s[i] - 48 != 0 && i != s.size() - 1){
                if((s[i]-48)*10 + s[i+1] - 48 <= 26 && s[i+1] - 48 > 0){
                    count++;

                }
                else{

                    ans.push_back(count);
                    count = 1;
                }

            }
            else if(i == s.size() - 1 && s[i] - 48 != 0){
                ans.push_back(count);
            }
            else if(s[i] - 48 == 0 && i == 0){
                return 0;
            }
            else if(s[i] == '0' && s[i-1] == '0'){
                return 0;
            }
            else if(s[i] - 48 == 0 && i != 0 && (s[i-1] - 48)*10 + s[i] - 48 <= 26 && (s[i-1] - 48)*10 + s[i] - 48 > 0){

                if(ans.size() > 0){

                    ans[ans.size()-1]--;
                }
                continue;
            }
            else if(s[i] - 48 == 0 && i != 0 && (s[i-1] - 48)*10 + s[i] - 48 > 26 ){

                return 0;
            }

        }
        for(int j = 0; j < ans.size(); j++){

            final_ans = final_ans*Fib(ans[j]);
        }

        return final_ans;

    }

    int Fib(int n){
        return n < 2 ? 1 : (Fib(n-1) + Fib(n-2));
    }

};
