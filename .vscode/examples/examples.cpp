#include <iostream>
#include <vector>
using namespace std;

long long sumloop(long long n)
{
    long long sum=0;
    for( int i = 1; i <= n; i++)
    {
        sum += i;
    }

    return sum;

}


long long sumFormula( long long n)
{


}


int linearSearch(vector<int> &arr, int key)
{
    for(int i = 0; i< arr.size(); i++)
    {
        if (arr[i]== key)
        return i;
    }
    return -1;

}
//binarySearch is more efficent (breaks an array in half with L side and Right Side of array )
int binarySearch(vector<int> &arr, int key)
{
    int left =0, right = arr.size() - 1;
    while(left < right)
    {
        int mid = left + (right -left) /2;
        if( arr[mid] == key)
        return mid;
        else if(arr[mid] < key)
        left = mid + 1;
        else
        right = mid -1;  
    }

    return -1;
}


int main()
{


    return 0;
}