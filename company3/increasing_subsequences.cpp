class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool first = false, second = false, temp = false; 
        int tmp;
        vector<int> fill(2, INT_MAX);

        for(int& ele: nums){
            if(!first or (!second and ele < fill[0])) {
                first = true;
                fill[0] = ele;
            }
            else if(!second and ele > fill[0]){
                second = true;
                fill[1] = ele;
            }
            else if(first and second){
                if(fill[1] < ele) return true;
                else if(ele > fill[0] and ele < fill[1]) fill[1] = ele;
                else if(ele < fill[0] and !temp){
                    temp = true;
                    tmp = ele;
                }
                else if(temp and tmp < ele and ele < fill[1]){
                    temp = false;
                    fill[0] = tmp;
                    fill[1] = ele;
                }
            }
        }
        cout << fill[0] << " " << fill[1] << "\n";
        return false;
    }
};
