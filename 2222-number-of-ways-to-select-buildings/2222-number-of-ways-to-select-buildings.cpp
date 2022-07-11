class Solution {
public:
    // greedy approach
    /*
    
    If the current building is '0', then the number of sequences of pattern "101" will be the product of the number of occurances of building '1' before the current building to the number of occurances of building '1' after the current building and viceversa.
    
    
    we are getting total 0 & 1 counts
    */
    
    long long numberOfWays(string s) {
        long long totalOneCount=0,totalZeroCount=0, ans=0;        
        for(auto curr : s)
            (curr == '1')? totalOneCount++: totalZeroCount++;
        // a and b are the number of occurances of '1' and '0' after the current building respectively.
        
        long long currOneCount=0,currZeroCount=0;
        for(auto el : s){
             // Counting the sequences of "010" = 
            if(el == '1'){
                ans+= (currZeroCount*totalZeroCount);
                currOneCount++;totalOneCount--;// increasing curr count and reducing totalCount.
            }
            else{                        
                // Counting the sequences of "101"
                ans+=(totalOneCount*currOneCount);
                currZeroCount++;totalZeroCount--;
            }
        }
        return ans;
    }
};