//coin change in DP

#include<bits/stdc++.h>
#define NOT_SET -1
using namespace std;

int cache[107];
int coinChange(const vector< int > coins, int amount)
{
    if(cache[amount]!=NOT_SET)
    {
        return cache[amount];
    }
    if(amount==0) return 0;

    int minCoins = NOT_SET;

    for(int i=0; i<coins.size(); i++)
    {
        int currentCoin = coins[i];
        if(currentCoin>amount) // for example: coin = 25, amount = 20
        continue;
        else
        {
            int remainingAmount = amount - currentCoin;
            int friend_ = coinChange(coins, remainingAmount);
            int totalAnswer = friend_ +1;

            if(minCoins==NOT_SET)
            minCoins = totalAnswer;
            else
            {
                if(totalAnswer < minCoins)
                minCoins = totalAnswer;
            }
        }
    }
    cache[amount] = minCoins;
    return minCoins;
}

int main()
{
    memset (cache, NOT_SET, sizeof(cache));

    vector < int > coins{25, 10, 1};
    int amount = 30;

    int result = coinChange(coins, amount);
    cout << result << endl;

    return 0;
}
