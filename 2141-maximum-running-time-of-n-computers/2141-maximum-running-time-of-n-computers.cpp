class Solution {
public:
    long long possible(vector<int>& batteries,long long mid,int n){
      long long total=0;
      for(int battery:batteries){
        total+=min((long long)battery,mid);
      }
      return total>=mid*n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=0;
        long long low=LLONG_MAX;
        for(int charge:batteries)
        {   low=min((long long)charge,low);
            sum+=charge;
        }
        long long high=sum;
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(possible(batteries,mid,n)){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};