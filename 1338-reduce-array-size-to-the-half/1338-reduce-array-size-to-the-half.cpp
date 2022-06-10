class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]=m[arr[i]]+1;
        }
        priority_queue<int>q;
        for(auto i:m){
            q.push(i.second);
        }
        int z=q.size();
        int count=0;
        for(int i=0;i<z;i++){
            count +=q.top();
            q.pop();
            if(count>=n/2){
                return i+1;
            }
        }
        return -1;
    }
};