class Solution {
public:
    int canCompleteCircuit1(vector<int>& gas, vector<int>& cost) {
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
    
    // same approach diffrent execution
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

       int start = gas.size()-1, end = 0;
       int sum = gas[start] - cost[start];
        
       while (start > end) {
          if (sum >= 0) {
             sum += gas[end] - cost[end];
             ++end;
          }
          else {
             --start;
             sum += gas[start] - cost[start];
          }
       }
       return sum >= 0 ? start : -1;
    }
};