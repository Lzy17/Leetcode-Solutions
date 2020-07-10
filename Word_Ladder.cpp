#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = endWord.size();
        int step = 1;
        int num_layer = 0;
        vector<string> words = wordList;
        queue<string> layer;
        layer.push(beginWord);
        //indicate end of a layer
        layer.push("");
        while(layer.size() != 0){
            string temp = layer.front();
            //debugging messages
            cout<<"|| each step: ";
            cout<<temp;
            if(temp == ""){
                cout<< "end of layer";
            }
            cout<<" ||";
            if(temp == endWord){
                return step;
            }
            else if(temp == "" && layer.size() > 1){
                layer.pop();
                layer.push("");
                step++;
            }

            else if(temp == "" && layer.size() == 1){
                return 0;
            }
            else{
                for(int i = 0; i < words.size(); i++){
                    //debugging messages
                    /*cout<< "||check for:";
                    cout<< words[i];
                    cout<<"||";*/
                    if(words[i] == beginWord){
                        words.erase(words.begin() + i);
                        i--;
                        continue;
                    }
                    if(neighbor(temp,words[i])){
                        layer.push(words[i]);
                        words.erase(words.begin() + i);
                        i--;
                    }

                }
                layer.pop();
            }

        }
        return -1;
    }
    bool neighbor(string s1, string s2){
        int count = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                count++;
            }
            if(count > 1){
                return false;
            }

        }
        if(count == 1){
            return true;
        }
        else{
            return false;
        }

    }


};
