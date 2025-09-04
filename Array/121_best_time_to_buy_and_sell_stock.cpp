
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            // minimum price found
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }

   public:
    int maxProfitBrute(vector<int>& prices) {
        int profit = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            int stockBuyed = prices[i];

            for (int j = i + 1; j < prices.size(); j++) {
                int stockSell = prices[j];
                profit = max(profit, stockSell - stockBuyed);
            }
        }
        if (profit <= 0) profit = 0;
        return profit;
    }
};

int main() {
    Solution s;
    vector<int> v = {7, 6, 4, 3, 1};
    cout << s.maxProfitBrute(v) << endl;
    cout << s.maxProfit(v) << endl;

    return 0;
}