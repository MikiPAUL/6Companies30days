class Solution {
    vector<int> primes;
    vector<bool> isPrime;
    
    void findPrime(){
        for(long long i = 2; i <= 1000005; i++){
            if(isPrime[i]){
                primes.push_back(i);
                for(long long j = i; j <= 1000005; j+=i){
                    isPrime[j] = false;
                }
            }
        }
    }

public:
    vector<int> closestPrimes(int left, int right) {
        isPrime.resize(1000005, true);
        findPrime();
        auto it = lower_bound(primes.begin(), primes.end(), left);
        vector<int> ans{-1, -1};
        int min = INT_MAX;

        while(it != primes.end() and it+1 != primes.end() and *(it+1) <= right){
            if(*(it+1) - *it < min){
                ans[0] = *it;
                ans[1] = *(it+1);
                min = *(it+1) - *it;
            }
            it++;
        }
        return ans;
    }
};
