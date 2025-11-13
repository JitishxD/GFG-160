#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int profit = 0;
        
        for(int i=1; i<prices.size(); i++){
            if(prices[i] > prices[i-1]){
                profit += prices[i] - prices[i-1];
            }
        }
        
        return profit;
    }
};


int main(){
    Solution sol; 
    vector<int> prices = {100, 180, 260, 310, 40, 535, 6950};
    cout << sol.maximumProfit(prices) << endl;
    return 0;
}