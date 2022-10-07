#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        auto result{ 0ll };
        sort(transactions.begin(), transactions.end(), [](vector<int>& val1, vector<int>& val2)
            {
                if ((val1.at(0) - val1.at(1)) > (val2.at(0) - val2.at(1))) {
                    return true;
                }
                return false;
            });
        
        for (auto i{ 0 }; i < transactions.size(); ++i){
            
            result += transactions.at(i).at(0)- transactions.at(i).at(1);
            
   
        
        
        }




        return result;

    }
};