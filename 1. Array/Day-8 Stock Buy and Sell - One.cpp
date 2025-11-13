#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int profit = 0;
        int minPrice = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return profit;
    }
};


int main(){
    Solution sol; 
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    cout << sol.maximumProfit(prices) << endl;
    return 0;
}