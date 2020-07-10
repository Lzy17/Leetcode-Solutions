class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        bool allzeros = true;
        while(n > 0){
        for(int i = 0; i < n; i++){
            //cout<<i;
            if(i != n-1){
                int temp = compare(nums[i], nums[i+1]);
                if(temp != nums[i]){
                    int temp2 = nums[i];
                    nums[i] = temp;
                    nums[i+1] = temp2;
                }

            }
           if(nums[i] != 0){
                //cout<<"noy hrtr";
                allzeros = false;
            }

        }
            n--;
        }
        if(!allzeros){
            stringstream ans;
            copy( nums.begin(), nums.end(), ostream_iterator<int>(ans, ""));
            string ss = ans.str();
            return ss;
        }
        else{
            return "0";
        }
    }


    int compare(int num1, int num2){
        vector<int> first;
        vector<int> second;
        vector<int> first_copy;
        vector<int> second_copy;
        int num1_copy = num1;
        int num2_copy = num2;
        int num2_pre_sig = -1;
        int num1_pre_sig = -1;
        if(num1 == 0){
            return num2;
        }
        else if(num2 == 0){
            return num1;
        }
        while(num1_copy > 0){
            first.push_back(num1_copy%10);
            //first_copy.push_back(num1_copy%10);
            num1_copy = num1_copy/10;
        }
        while(num2_copy > 0){
            second.push_back(num2_copy%10);
            //second_copy.push_back(num1_copy%10);
            num2_copy = num2_copy/10;
        }
        int len = min(second.size(), first.size());
        while(len != 0){
        len = min(second.size(), first.size());
        if(len == first.size()){
            for(int i = len - 1; i >= 0; i--){
                if(first[i] > second.back()){
                    return num1;
                }
                else if(first[i] < second.back()){
                    return num2;
                }
                else{
                    second.pop_back();
                }
            }
        }
        else{
            for(int i = len - 1; i >= 0; i--){
                if(second[i] > first.back()){
                    return num2;
                }
                else if(second[i] < first.back()){
                    return num1;
                }
                else{
                    first.pop_back();
                }
            }


        }
        }
        return num1;



    }


};
