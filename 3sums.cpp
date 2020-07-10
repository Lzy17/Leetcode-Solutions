class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sols;
        int num_sol = 0;
        for(int index1 = 0; index1 < nums.size() ; index1++){
            for(int index2 = index1 + 1; index2 < nums.size(); index2++){
                for(int index3 = index2 + 1; index3 < nums.size(); index3++){
                    if(nums[index1] + nums[index2] + nums[index3] == 0){
                        vector<int> temps;
                        temps.push_back(nums[index1]);
                        temps.push_back(nums[index2]);
                        temps.push_back(nums[index3]);
                        sort(temps.begin(), temps.end());
                        if(num_sol == 0){
                            sols.push_back(temps);
                            num_sol++;
                        }
                        else {
                            int sth = 0;
                            for(int var = 0; var < sols.size(); var++){
                            if(equal(sols[var].begin(), sols[var].end(), temps.begin(), temps.end())){
                                sth++;
                                break;
                                }
                            }
                            if (sth == 0){
                               sols.push_back(temps);
                            }
                        }
                    }

                }

            }

        }
        return sols;
    }
};
