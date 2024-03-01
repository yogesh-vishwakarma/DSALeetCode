class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int remainingEmptyBottle = numBottles, totalBottle = numBottles;
        while(remainingEmptyBottle >= numExchange){
            int newBottles = remainingEmptyBottle/numExchange;
            remainingEmptyBottle = newBottles + remainingEmptyBottle%numExchange;
            totalBottle += newBottles;
        }
        return totalBottle;
    }
};