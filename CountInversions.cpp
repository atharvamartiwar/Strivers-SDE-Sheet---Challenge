#include <bits/stdc++.h> 

long long merge(vector<long long> &arr, long long lo, long long mid, long long hi)
{
    long long count = 0;

    if (lo >= hi)
        return count;
    vector<long long> temp; // O(N)

    long long p1 = lo, p2 = mid + 1;

    while (p1 <= mid && p2 <= hi)
    {

        if (arr[p1] <= arr[p2])
        {
            temp.push_back(arr[p1]);
            p1++;
            continue;
        }

       else { 
        temp.push_back(arr[p2]);
        count+=(mid-p1+1);
        p2++;

       }
    }

    while (p1 <= mid)
    {
        temp.push_back(arr[p1]);
        p1++;
    }

    while (p2 <= hi)
    {
        temp.push_back(arr[p2]);
        p2++;
    }

    long long p3 = 0;

    // O(N)
    for (int i = lo; i <= hi; i++)
    {
        arr[i] = temp[p3];
        p3++;
    }

    return count;
}

long long merge_sort(vector<long long> &arr, long long lo, long long hi)
{
    long long count = 0;

    long long n = (long long)arr.size();

    if (lo >= hi)
        return count;

    long long mid = (lo + hi) / 2;

    long long ans = 0;

    count+=merge_sort(arr, lo, mid); // THREAD 1

    count+=merge_sort(arr, mid + 1, hi); // thread 2

    count+=merge(arr, lo, mid, hi); // O(n)

    return count;
}
long long getInversions(long long *arr, long long n){
    // Write your code here.
    
    vector<long long> arrr(arr,arr+n);
    long long count = merge_sort(arrr,0,n-1);
    return count;
}
