#pragma once
//https://leetcode.com/problems/reverse-pairs/

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    using vec = vector<int>;
    int reversePairs(vec& nums) {
        auto tempVec{ vec(nums.size()) };
        long long counter{0};

        split(0, nums.size()-1, tempVec,nums, counter);

        return counter;
    }


    void split(int start, int end, vec &tempVec, vec &array, long long& counter) {
        if (start < end) {
            int mid{ (start+ end)/2 };

            split(mid+1, end, tempVec, array,counter);
            split(start, mid, tempVec, array,counter);

            merge(start, mid, end, tempVec, array, counter);

        
        }
    
    }

    void merge(int start, int mid, int end, vec& tempVec, vec& array, long long&counter) {
        auto index{ 0 };
        auto tempMid{ mid++ };
        auto tempStart{ start };
        while (start <= tempMid && mid <= end) {
            if (array.at(start) <= array.at(mid))
                tempVec.at(index++) = array.at(start++);
            else {
                if (array.at(start) > 2 * (array.at(mid)))
                {
                    counter += mid - start - (mid - tempMid - 1);
                }
                tempVec.at(index++) = array.at(mid++);
            }
        }

        while (start <= tempMid)
        {
            tempVec.at(index++) = array.at(start++);
        }
        while (mid <= end)
        {
            tempVec.at(index++) = array.at(mid++);
        }

        swap_ranges(array.begin() + tempStart, array.begin()+end+1, tempVec.begin());
    }
};