class Solution {
public:
    bool checkValidString(string s) {
        int maxDiff = 0, minDiff = 0;
        for (char c : s) {
            maxDiff += (c == '(' || c == '*') ? 1 : -1;
            minDiff += (c == ')' || c == '*') ? -1 : 1;
            if (maxDiff < 0) 
                return false;
            minDiff = max(0, minDiff);
        }
        return minDiff == 0;
    }
};

/*

Let diff =  count (left parenthesis) - count (right parenthesis)

When we meet:
    (: we increment diff.
    ): we decrement diff.
    *: we have three choices which makes the diff become a range -- [diff - 1, diff + 1].
    
So we use maxDiff/minDiff to record the maximum/minimum diff we can get & use * accordingly

When we meet:
    (: ++maxDiff and ++minDiff.
    ): --maxDiff and --minDiff.
    *: ++maxDiff and --minDiff.
    
If maxDiff become negative, it means: count(')') > (count('(') + count('*')); we return false.

minDiff means the diff we got if we always try to replace * with ). 
If minDiff become -1, it means that this replacement results in more ) than (, so it should be avoided. 
To avoid it, we simply reset minDiff from -1 to 0 which implies we only replace * with ( or empty string.

After scanning through string s, as long as minDiff is 0, this string can be a valid one.

Example: (**)

Seeing (, the range becomes [1, 1].
Seeing *, the range becomes [0, 2]. 0 correponds to (), 1 to (_, 2 to ((.
Seeing *, the range becomes [-1,3]. But -1 is invalid because it means ()) and should be avoided. So we correct the range to [0, 3].
Seeing ), the range becomes [-1, 2]. Again, we correct the range to [0, 2] (because -1 means ()_) or (_)))
The final [0, 2] range means that we can either get a perfect string, or has 1 or 2 more ( available (which are created by *).
*/