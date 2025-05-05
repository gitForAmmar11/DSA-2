#include <bits/stdc++.h>
#define NOT_SET -1
using namespace std;

struct Product
{
    string PID;
    int price;
    int discount;
};

int cache[107][107];

int knapsack0_1(int it, vector< Product > products, int capacity)
{
    if(cache[it][capacity]!=NOT_SET)
    {
        return cache[it][capacity];
    }
    if(capacity==0 || it==products.size())
    {
        cache[it][capacity] = 0;
        return 0;
    }
    Product currentProduct = products[it];
    if(currentProduct.price>capacity)
    {
        int frnd = knapsack0_1(it+1, products, capacity);
        cache[it][capacity] = frnd;
        return frnd;
    }
    else
    {
        int friend1 = currentProduct.discount + knapsack0_1(it+1, products,
        capacity - currentProduct.price);
        int friend2 = knapsack0_1(it+1, products, capacity);
        if(friend1>friend2)
        {
            cache[it][capacity] = friend1;
            return friend1;
        }
        else
        {
            cache[it][capacity] = friend2;
            return friend2;
        }
    }
}

int main()
{
    memset(cache, NOT_SET, sizeof(cache));
    int n;
    cin >> n;
    vector< Product > products(n);
    for(int i=0; i<n; i++)
    {
        getchar();
        cin >> products[i].PID;
        cin >> products[i].price;
        cin >> products[i].discount;
    }
    int capacity;
    cin >> capacity;
    int result = knapsack0_1(0, products, capacity);
    cout << result << endl;
    return 0;
}
