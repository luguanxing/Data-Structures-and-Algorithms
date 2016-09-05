class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
    	int l2 = nums2.size();

    	vector<int> v;

    	while (nums1.size() && nums2.size()) {
    		if (nums1[0] < nums2[0]) {
	    		v.push_back(nums1[0]);
	    		nums1.erase(nums1.begin());
    		} else {
	    		v.push_back(nums2[0]);
	    		nums2.erase(nums2.begin());
	    	}
    	}

    	if (nums1.size()) {
    		while (nums1.size()) {
    			v.push_back(nums1[0]);
    			nums1.erase(nums1.begin());
    		}
    	} else {
	    	while (nums2.size()) {
	    		v.push_back(nums2[0]);
	    		nums2.erase(nums2.begin());
    		}
    	}

    	if ((l1 + l2) % 2)
    		return v[(l1 + l2) / 2];
    	else
    		return 0.5 * (v[(l1 + l2) / 2] + v[(l1 + l2) / 2 - 1]);
       }
};