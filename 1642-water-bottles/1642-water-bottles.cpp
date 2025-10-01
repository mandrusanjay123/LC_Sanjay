class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total=numBottles;
        int carry=0;
        while(numBottles>=numExchange){
            total+=numBottles/numExchange;
            carry=numBottles%numExchange;
            numBottles/=numExchange;
            numBottles+=carry;
        }
        return total;
    }
};