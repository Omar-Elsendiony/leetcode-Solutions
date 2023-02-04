#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int stringLength = s.length();
        unordered_map <char,int> umap;
        int maxCount, tempCount;
        maxCount = 0;
        if (stringLength == 1){
            return 1;
        }
        for (int i = 0 ; i < stringLength - 1 ; i++){
            umap[s[i]] = i;
            tempCount = 1;
            for (int j = i + 1 ; j < stringLength ; j++){
                if (umap.find(s[j]) == umap.end()){
                    umap[s[j]] = i;
                    tempCount += 1;
                }else if (umap[s[j]] != i){
                    umap[s[j]] = i;
                    tempCount += 1;
                }else{
                    break;
                }
            }
            maxCount = max(tempCount,maxCount);
        }
        return maxCount;
    }
};