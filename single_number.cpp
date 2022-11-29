//approach no: 1 with Map and Frequencies
// TC : O(n)
// MC : O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        map<int, int> mp;
        for(int k=0; k<nums.size(); k++){
            int val = nums[k];
            if(mp.find(val)!=mp.end()){
                mp[val]++;
            }
            else {
                mp.insert({val,1});
            }
        }
        int s_number =0;
        for(auto pr : mp){
            if(pr.second==1){
                s_number = pr.first;
            }
        }
        return s_number;
    }

};



//approach no: 2 with sort and count
// TC : O(n)
// MC : O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {

       int s_number = 0;
       int counter = 0;
       sort(nums.begin(),nums.end());
       for(int i=1; i<nums.size() ; i+=2 ){
           if(nums[i]!=nums[i-1]){
               s_number = nums[i-1];
               counter+=1;
               break;
           }
       }

       if((nums.size()%2!=0) && (counter == 0)){
           s_number = nums[nums.size()-1];
       }

       return s_number;

    }

};




//approach no: 3 with XOR
// TC : O(n)
// MC : O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int s_number =0;
        for(auto xr : nums ){
            s_number^=xr;
        }

        return s_number;
    }

};
