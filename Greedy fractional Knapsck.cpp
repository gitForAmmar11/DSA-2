#include <bits/stdc++.h>
using namespace std;

struct Product
{
    string PID;
    int weight;
    int value;
};

bool compare(Product p1, Product p2)
{
    double p1Ratio = p1.value/(double)p1.weight;
    double p2Ratio = p2.value/(double)p2.weight;
    if(p1Ratio>p2Ratio) return true;
    else return false;
}

void printProducts(vector< Product > products)
{
    for(Product product : products)
    {
        cout << product.PID << " ";
    }
    cout << endl;
}

double knapsackFractionalGreedy(vector< Product > products, int capacity)
{
    sort(products.begin(), products.end(), compare);
    double profit = 0;
    for(int i=0; i<products.size(); i++)
    {
        Product currentProduct = products[i];
        if(currentProduct.weight>capacity)
        {
            double ratio = currentProduct.value/(double)currentProduct.weight;
            profit = profit + (ratio*capacity);
            capacity = 0;
            break;
        }
        else
        {
            profit = profit + currentProduct.value;
            capacity = capacity - currentProduct.weight;
        }
    }
    return profit;
}

int main()
{
    int n; cin >> n;
    vector< Product > products(n);
    for(int i=0; i<n; i++)
    {
        getchar();
        cin >> products[i].PID;
        cin >> products[i].weight;
        cin >> products[i].value;
    }
    int capacity; cin >> capacity;
    double result = knapsackFractionalGreedy(products, capacity);
    cout << result << endl;
    return 0;
}
