#include<bits/stdc++.h>
using namespace std;

struct Result{
    int sum;
    int leftIndex;
    int rightIndex;
};

Result crossingSum(int arra[], int left, int right, int mid){
    int sum = arra[mid];
    int ls = arra[mid];
    int lidx = mid;

    for(int i=mid-1; i>=left; i--){
            sum = sum+arra[i];
        if(sum>ls){
            ls = sum;
            lidx = i;
        }
    }

    sum = arra[mid+1];
    int rs = arra[mid+1];
    int ridx = mid+1;

    for(int i=mid+2; i<=right; i++){
        sum = sum+arra[i];
        if(sum>rs){
            rs = sum;
            ridx = i;
        }
    }

    Result cs;
    cs.sum = rs+ls;
    cs.leftIndex = lidx;
    cs.rightIndex = ridx;

    return cs;
}

Result maxSumSubArra(int arra[], int left, int right){
    if(left == right){
        Result result;
        result.sum = arra[left];
        result.leftIndex = left;
        result.rightIndex = right;

        return result;
    }
    else{
        int mid = left+(right-left)/2;
        Result leftside = maxSumSubArra(arra, left, mid);
        Result rightSide = maxSumSubArra(arra, mid+1, right);
        Result crossing = crossingSum(arra, left, right, mid);

        if(leftside.sum >= rightSide.sum && leftside.sum >= crossing.sum)
            return leftside;
        else if(rightSide.sum >= leftside.sum && rightSide.sum >= crossing.sum)
            return rightSide;
        else
            return crossing;
    }
}
int main(){
    int n=10;
    int arra[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Result result = maxSumSubArra(arra, 0, n-1);
    cout << "Sumation is: " << result.sum << " " << result.leftIndex << " " << result.rightIndex << endl;

    return 0;
}
