class FoodRatings {
public:
/*
need to have a data structure for mapping food items to a respective cusine
need a ds to store the highest food rated maintined like a priority queue this is for like every cusine type

*/  struct comp{
    bool operator()(pair<int,string>&a,pair<int,string>&b)const{
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}
};
    unordered_map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,comp>>cusinemap;
    unordered_map<string,string>foodtocusine;
    unordered_map<string,int>currentrating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=cuisines.size();
        for(int i=0;i<n;i++){
            cusinemap[cuisines[i]].push({ratings[i],foods[i]});
            foodtocusine[foods[i]]=cuisines[i];
            currentrating[foods[i]]=ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
         auto & pq=cusinemap[foodtocusine[food]];
         pq.push({newRating,food});
         currentrating[food]=newRating;
         
    }
    
    string highestRated(string cuisine) {
        auto &pq=cusinemap[cuisine];
        while(!pq.empty()){
            auto& top=pq.top();
            if(currentrating.count(top.second)&&top.first==currentrating[top.second]){
                return top.second;
            }
            pq.pop();
        }
        return "";    
        }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */