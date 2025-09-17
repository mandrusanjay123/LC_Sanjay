#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    struct Item {
        string name;
        int rating;
        // order: higher rating first; on tie, lexicographically smaller name first
        bool operator<(Item const& other) const {
            if (rating != other.rating) return rating > other.rating; // desc
            return name < other.name;                                 // asc
        }
    };

    // food -> (cuisine, rating)
    unordered_map<string, pair<string,int>> f2cr;
    // cuisine -> ordered foods by (rating desc, name asc)
    unordered_map<string, set<Item>> c2set;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = (int)foods.size();
        f2cr.reserve(n * 2);
        c2set.reserve(n * 2);
        for (int i = 0; i < n; ++i) {
            f2cr[foods[i]] = {cuisines[i], ratings[i]};
            c2set[cuisines[i]].insert({foods[i], ratings[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& [cuisine, oldRating] = f2cr[food];
        auto& s = c2set[cuisine];
        // erase old (name, oldRating)
        s.erase(Item{food, oldRating});
        // insert new (name, newRating)
        s.insert(Item{food, newRating});
        oldRating = newRating;
    }
    
    string highestRated(string cuisine) {
        auto& s = c2set[cuisine];
        return s.begin()->name; // set never empty per problem guarantees
    }
};
