#include<bits/stdc++.h>
using namespace std;

struct minMax{
    int minimum;
    int maximum;
};

minMax findMinMax(int arra[], int idx, int n){
    if(idx==n-1){
        minMax result;
        result.minimum = arra[idx];
        result.maximum = arra[idx];
        return result;
    }
    else{
        minMax frnd = findMinMax(arra, idx+1, n);
            if(arra[idx]<frnd.minimum){
                frnd.minimum = arra[idx];
            }
            if(arra[idx]>frnd.maximum){
                frnd.maximum = arra[idx];
            }
            return frnd;
        }
}
int main(){
    int n=3;
    int arra[n] = {-27, -72, 5};
    minMax rslt = findMinMax(arra, 0, n);
    cout << "Minimum: " << rslt.minimum << endl;
    cout << "Maximum: " << rslt.maximum << endl;

    return 0;
}
