class Solution {
    void merge(vector<int>& nums, int start, int mid, int end){
        int a1 = mid-start+1, a2 = end-mid;
        vector<int> a(nums.begin()+start, nums.begin()+mid+1), b(nums.begin()+mid+1, nums.begin()+end+1);

        int i = 0, j = 0, k = start;

        while(i < a1 or j < a2){
            if(i < a1 and j < a2){
                if(a[i] <= b[j]){
                    nums[k] = a[i++];
                }
                else nums[k] = b[j++];
            }
            else if(i < a1) nums[k] = a[i++];
            else nums[k] = b[j++];
            k++;
        }
        return;
    }
    void merge_sort(vector<int>& nums, int start, int end){
        if(start < end){
            int mid = (start + end)/2;
            merge_sort(nums, start, mid);
            merge_sort(nums, mid+1, end);
            merge(nums, start, mid, end);
            return;
        }
        return;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
a
