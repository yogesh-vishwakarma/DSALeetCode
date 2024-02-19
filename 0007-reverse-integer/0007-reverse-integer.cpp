class Solution {
public:
    int reverse(int x) {
        if (x>pow(2,31)-1 || x<-pow(2,31))
        return 0;
        int flag=1;
        long long int num=0;
        while (x!=0){
        num=num*10+x%10;
        x=x/10;
        }
        if (num>pow(2,31)-1 || num<-pow(2,31))
        return 0;
        return num;
    }
};