class Solution {
public:
    bool check(vector<int>& dist, double hour, int speed){
        double sum = 0.0;
        for(int i=0;i<dist.size()-1;i++){
            sum += ceil(double(dist[i])/double(speed));
        }
        sum += double(dist.back())/double(speed);
        return sum<=hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(dist.size()-1>=hour)
            return -1;
        int low = 1;
        int high = *max_element(dist.begin(),dist.end())*100;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low + high)/2;
            if(check(dist,hour,mid)){
                ans = min(ans,mid);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};