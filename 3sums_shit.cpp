class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sols;
        int num_sol = 0;
        sort(nums.begin(), nums.end());
        int olda;
        int oldb;
        int oldc;
        int firsta = 0;
        int firstb = 0;
        int firstc = 0;
        //cout<<nums.size();
        for(int index1 = 0; index1 < nums.size() ; index1++){
            if(firsta == 0){
                olda = nums[index1];
                firsta++;
            }
            else{
                if(nums[index1] == olda){continue;}
                else{olda = nums[index1];}
            }

            for(int index2 = index1 + 1; index2 < nums.size(); index2++){
                if(firstb == 0){
                    oldb = nums[index2];
                    firstb++;
                }
                else{
                    if(nums[index2] == oldb){continue;}
                    else{oldb = nums[index2];}
                }
                for(int index3 = index2 + 1; index3 < nums.size(); index3++){
                    if(firstc == 0){
                        oldc = nums[index3];
                        firstc++;
                    }
                    else{
                        if(nums[index3] == oldc){continue;}
                        else{oldc = nums[index3];}
                    }
                    if(nums[index1] + nums[index2] + nums[index3] == 0){
                        vector<int> temps;
                        temps.push_back(nums[index1]);
                        temps.push_back(nums[index2]);
                        temps.push_back(nums[index3]);
                        sort(temps.begin(), temps.end());
                        /*if(num_sol == 0){
                            sols.push_back(temps);
                            num_sol++;
                        }
                        else {
                            int sth = 0;
                            for(int var = sols.size()-1 ; var >= 0; var--){
                            if(sols[var][0] == temps[0]){
                                if(sols[var][1] == temps[1]){
                                    if(sols[var][2] == temps[2]){
                                        sth++;
                                        break;
                                    }
                                    else {continue;}
                                }
                                else{continue;}
                                }
                            else{ continue; }
                            }
                            if (sth == 0){
                               sols.push_back(temps);
                            }
                        }*/
                        sols.push_back(temps);
                    }
                    else if(nums[index1]+nums[index2]+nums[index3] > 0){
                        //cout<<"tell him eat shit jonny";
                        break;

                    }
                    else if (nums[index1] >= 0){
                        //cout<<"tell him eat shit jonny";
                        return sols;
                    }

                }

            }

        }
        //cout<<"tell him yourself";
        return sols;
    }


};
