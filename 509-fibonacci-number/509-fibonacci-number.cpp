class Solution {
public:
    int fib(int n) {
        int prev1(1), prev2(0);
        for(int i(2);i<=n;i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return (n>1)?prev1:n;
    }
    
    /*
    Binet's Nth-term Formula
    Using Binet's Formula for the Nth Fibonacci involves the usage of our golden section number Phi.
    Phi = ( sqrt(5) + 1 ) / 2
    Using approximation equation is good enough here, since we know N >= 0 && N <= 30, we can safely use the following rounded function
    Fib(N) = round( ( Phi^N ) / sqrt(5) )
    Full mathematical explanation of Binet's Formula here
    Time Complexity - O(1)
    Space Complexity - O(1)

    int fib(int N) {
        double phi = (sqrt(5) + 1) / 2;     
        return round(pow(phi, N) / sqrt(5));
    }
    */
};