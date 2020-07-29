#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.size() < 2) return 0;

    vector<int> buy(prices.size(), 0);
    vector<int> sell(prices.size(), 0);
    vector<int> cooldown(prices.size(), 0);

    buy[0] = 0;
    sell[0] = -prices[0];
    cooldown[0] = INT_MIN;

    for(int i=1; i<prices.size(); i++) {
        buy[i] = max(buy[i-1], cooldown[i-1]);
        sell[i] = max(sell[i-1], buy[i-1] - prices[i]);
        cooldown[i] = sell[i-1] + prices[i];
    }

    return max(buy[prices.size()-1], cooldown[prices.size()-1]);
}

int main() {
    vector<int> input = {1,2,3,0,2};
    int res = maxProfit(input);
    cout<<res<<endl;

    return 0;
}
