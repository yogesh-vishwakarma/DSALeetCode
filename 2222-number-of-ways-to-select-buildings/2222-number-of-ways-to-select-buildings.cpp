class Solution {
public:
    long long numberOfWays(string s) {
        long long a=0,b=0,ans=0;        
        // a and b are the number of occurances of '1' and '0' after the current building respectively.
        for(auto curr : s){
            (curr == '1')? a++: b++;
        }
        long long c=0,d=0;              
        // c and d are the number of occurances of '1' and '0' before the current building respectively.
        for(auto el : s){
             // Counting the sequences of "010"
            if(el == '1'){
                ans+= (d*b);
                a--;c++;
            }
            else{                        
                // Counting the sequences of "101"
                ans+=(a*c);
                b--;d++;
            }
        }
        return ans;
    }
};