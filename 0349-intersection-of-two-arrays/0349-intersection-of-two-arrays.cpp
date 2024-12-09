class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int i=0, j=0;
        int n = nums1.size(), m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(i < n && j < m) {
         if(i > 0 && nums1[i] == nums1[i-1]){
             i++;
             continue;
         }   
         
         if(j > 0 && nums2[j] == nums2[j-1]){
                j++;
                continue;
         }
            
         if(nums1[i] < nums2[j]) {
             i++;
         }
         else if(nums2[j] < nums1[i]){
             j++;
         }
            
        else {
               if(nums1[i] == nums2[j]) {
                   v.push_back(nums1[i]);
                   i++;
                   j++;
               } 
            }
            
            
        }    
        return v;
    }
};