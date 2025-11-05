#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.second != b.second)
            return a.second > b.second; // higher frequency first
        return a.first > b.first;       // if tie, higher value first
    }
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans;
        unordered_map<int,int> freq;
        multiset<pair<int,int>, Compare> top, rest;
        long long topSum = 0;

        auto addToTop = [&](pair<int,int> p) {
            top.insert(p);
            topSum += 1LL * p.first * p.second;
        };

        auto removeFromTop = [&](pair<int,int> p) {
            auto it = top.find(p);
            if (it != top.end()) {
                topSum -= 1LL * p.first * p.second;
                top.erase(it);
                return true;
            }
            return false;
        };

        auto removePair = [&](pair<int,int> p) {
            if (!removeFromTop(p)) {
                auto it = rest.find(p);
                if (it != rest.end()) rest.erase(it);
            }
        };

        auto rebalance = [&]() {
            // Move best from rest -> top if top has < x
            while ((int)top.size() < x && !rest.empty()) {
                auto it = rest.begin();
                addToTop(*it);
                rest.erase(it);
            }

            // Ensure correct boundary ordering
            while (!rest.empty() && !top.empty()) {
                auto worstTop = prev(top.end());
                auto bestRest = rest.begin();
                Compare cmp;
                if (cmp(*bestRest, *worstTop)) {
                    // Swap them
                    topSum -= 1LL * worstTop->first * worstTop->second;
                    topSum += 1LL * bestRest->first * bestRest->second;
                    top.insert(*bestRest);
                    rest.insert(*worstTop);
                    top.erase(worstTop);
                    rest.erase(bestRest);
                } else break;
            }

            // If top has more than x, move extras to rest
            while ((int)top.size() > x) {
                auto it = prev(top.end());
                rest.insert(*it);
                topSum -= 1LL * it->first * it->second;
                top.erase(it);
            }
        };

        auto update = [&](int num, int delta) {
            pair<int,int> oldPair = {num, freq[num]};
            if (freq[num] > 0) removePair(oldPair);
            freq[num] += delta;
            if (freq[num] == 0) freq.erase(num);
            else rest.insert({num, freq[num]});
            rebalance();
        };

        for (int i = 0; i < n; ++i) {
            update(nums[i], +1);
            if (i >= k) update(nums[i - k], -1);
            if (i >= k - 1) {
                // If less than x distinct numbers exist → take entire window sum
                if ((int)freq.size() < x) {
                    long long total = 0;
                    for (auto &p : freq) total += 1LL * p.first * p.second;
                    ans.push_back(total);
                } else ans.push_back(topSum);
            }
        }
        return ans;
    }
};
