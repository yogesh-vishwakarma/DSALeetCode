class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSum(0),start(0);
        for(int i =0;i<gas.size();i++){
            gas[i] = gas[i]-cost[i];
            totalSum +=gas[i];
        }
        
        int currGas(0);
        for(int i=0;i<gas.size();i++){
            currGas+=gas[i];
            if(currGas<0){ // means we can't use current path so we have to reset it
                currGas=0;
                start=i+1;
            }
        }
        // if totalSum < 0 so there is no possible solution.
        return (totalSum<0)? -1 : start;
    }
};