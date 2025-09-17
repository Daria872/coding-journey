class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st;
        for(int i=0;i<nums1.size();i++){
            st.insert(nums1[i]);
        }
        vector<int>intersection;
        for(int i=0;i<nums2.size();i++){
            if(st.find(nums2[i])!=st.end()){
                intersection.push_back(nums2[i]);
            }
        }
        set<int>st2;
        for(int i=0;i<intersection.size();i++){
            st2.insert(intersection[i]);
        }
        vector<int>v(st2.begin(),st2.end());
        return v;
    }
};