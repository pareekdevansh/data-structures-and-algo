#include <bits/stdc++.h>
using namespace std;

int firstZero(vector<int> row)
{
    int s = 0, e = row.size(), mid, ans;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (row[mid] == 1)
        {
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return s;
}
vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    vector<pair<int, int>> data;
    for (int i = 0; i < mat.size(); i++)
    {
        int iZero = firstZero(mat[i]);
        data.push_back({iZero, i});
    }
    sort(data.begin(), data.end());
    vector<int> k_weakest_rows;
    for (int i = 0; i < k; i++)
    {
        k_weakest_rows.push_back(data[i].second);
    }
    return k_weakest_rows;
}

vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
{
    int diff = 0;
    for (auto x : aliceSizes)
        diff += x;
    for (auto x : bobSizes)
        diff -= x;
    diff /= 2;
    sort(aliceSizes.begin(), aliceSizes.end());
    sort(bobSizes.begin(), bobSizes.end());
    int i = 0, j = 0, n = aliceSizes.size(), m = bobSizes.size();
    while (i < n and j < m)
    {
        int boxDiff = aliceSizes[i] - bobSizes[j];
        if (diff == boxDiff)
        {
            return {i, j};
        }
        else if (diff < boxDiff)
        {
            i++;
        }
        else
            j++;
    }
    return {-1, -1};
}

int search(vector<int> &nums, int target)
{
    int s = 0, n = nums.size(), e = n - 1, mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}
int rotateCount(vector<int> arr)
{
    int s = 0, e = arr.size() - 1, n = arr.size(), mid, a = arr[s], b = arr[e];
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        // n = s-e+1;
        int next = (mid + 1) % n, prev = (mid + n - 1) % n;
        if (arr[mid] <= arr[prev] and arr[mid] <= arr[next])
        {
            return mid;
        }
        if (arr[mid] <= arr[e])
        {
            e = prev;
        }
        else
            s = next;
    }
    return -1;
}

int findMinRotated(vector<int> arr)
{
    int s = 0, n = arr.size(), e = n - 1, mid, first = arr[s], last = arr[e];
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        int next = (mid + 1) % n, prev = (mid + n - 1) % n;
        if (arr[mid] < arr[prev] and arr[mid] < arr[next])
            return mid;
        if (arr[mid] < last)
        {
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return -1;
}
int idxOfMin(vector<int> arr)
{
    int s = 0, n = arr.size(), e = n - 1, mid, end = arr[e];
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        int next = (mid + 1) % n, prev = (mid + n - 1) % n;
        if (arr[mid] < arr[next] and arr[mid] < arr[prev])
        {
            return mid;
        }
        if (arr[mid] < end)
        {
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return -1;
}
int binarySearch2(vector<int> arr, int start, int end, int key)
{

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int binaraySearch(int arr[], int n, int key)
{
    int s = 0, e = n - 1, mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}
int rBinaraySearch(int arr[], int n, int key)
{
    int s = 0, e = n - 1, mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}
int firstOcc(int arr[], int n, int key)
{
    int s = 0, e = n - 1, mid, ans = -1;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            e = mid - 1;
            ans = mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return s;
}
int lastOcc(int arr[], int n, int key)
{
    int s = 0, e = n - 1, mid, ans = -1;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            s = mid + 1, ans = mid;
        }
        else if (arr[mid] < key)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return ans;
}
// int countOcc(int arr[], int s, int e,  int key)
// {
// to count occurence of a particular element, do -> (last occurence index - first occurence index + 1);
//     int count =0;
//     int mid;
//     while(s <= e)
//     {
//         mid = s + (e - s) / 2;
//         if(arr[mid] == key)
//         {
//             count++;
//             count += countOcc(arr, n, )
//             e = mid -1;
//         }
//         else if(arr[mid] > key) e= mid - 1;
//         else s = mid + 1;
//     }
//     s = 0, e = n - 1;
//     while (s <= e)
//     {
//         mid = s + (e - s) / 2;
//         if (arr[mid] == key)
//         {
//             count++;
//             e = mid - 1;
//         }
//         else if (arr[mid] > key)
//             e = mid - 1;
//         else
//             s = mid + 1;
//     }
//     return count - 1;
// }
int bsNearySorted(vector<int> arr, int key)
{
    int s = 0, e = arr.size()-1, mid ;
    while (s<=e)
    {
        mid = s + (e -s) /2;
        if(arr[mid] == key) return mid;
        if(mid - 1 >=s and arr[mid - 1] == key) return mid - 1;
        if(mid + 1 <= e and arr[mid + 1] == key) return mid + 1;
        if(arr[mid] > key) e = mid - 2;
        else s = mid + 2;

    }
    return -1;
    
}
int findFloor(vector<int>  arr, int key)
{
    int s =0 ,e = arr.size() -1, n = arr.size(),ans = -1 , mid;
    while(s <= e)
    {
        mid = s + ( e- s)/2;
        if(arr[mid] == key) return arr[mid];
        if(arr[mid] > key) e = mid - 1;
        else {
            ans = mid;
            s = mid + 1;
        }
    }
    if(ans == -1) return -1;
    return arr[ans];
}
int findCeil(vector<int> arr, int key)
{
    int s = 0, e = arr.size() - 1, mid, ans = -1;
    while(s <= e){
        mid = s + (e-s) /2;
        if(arr[mid] == key) return arr[mid];
        if(arr[mid] > key) {
            ans = mid ;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    if(ans == -1) return ans;
    else return arr[ans];
}

char nextAlphabet(vector<char>  arr, char key)
{
    // agar key  se next greater alphabet arr me na ho to esa char return krna h jisse pta chal jaae ki answer nhi mila 
    int s =0, e = arr.size() -1, n = arr.size() , mid, ans = -1;
    while( s<= e){
        mid = s + ( e- s) /2;
        if (arr[mid] > key) e = mid - 1;
        else {
            ans = arr[(mid + 1) % n];
            s = mid + 1;
        }
    }
    return ans;
}
int rotatedSorted(vector<int> arr)
{
    int s = 0, e = arr.size() -1, last = arr[e];
    while(s < e)
    {
        int mid = s + (e -s ) /2;
        if(arr[mid] <= last) e = mid;
        else s = mid+1;
    }
    return s;
}
int bSearch(vector<int> arr, int s ,int e, int key)
{
    int mid;
    while(s <=e){
        mid = s + (e-s) /2;
        if(arr[mid] == key) return mid;
        if(arr[mid] > key) e = mid - 1;
        else s = mid + 1;
    }
    return -1;
}
int searchInRotated(vector<int> arr, int s , int e ,int key)
{
    int last = arr[e] ;
    int mid;
    while(s<=e)
    {
        mid = s + ( e -s) / 2;
        if(arr[mid] == key) return mid;
        if(arr[mid] < last)
        {
            if(key > arr[mid]){
                return bSearch(arr, mid+1,e,key);
            }
                return searchInRotated(arr, s, mid - 1, key);
        }
        else 
        {
            if(key < arr[mid])
            {
               return bSearch(arr, s, mid - 1, key);
            }
            return searchInRotated(arr, mid + 1,e, key);
        }
        
    }
    return -1;
}

int main()
{

    // int arr[] = {1,2,3,2,4,2,5,7,2,8,7};
    // int n = sizeof(arr)/ sizeof(int);

    // sort(arr, arr + n);
    // for (auto x : arr)
    //     cout << x << " ";
    // cout << endl;
    // cout<<binaraySearch(arr, n , 5)<<endl;

    // sort(arr, arr + n, greater<int>());
    // for (auto x : arr)
    //     cout << x << " ";
    // cout << endl;
    // cout<<rBinaraySearch(arr,n,5)<<endl;
    // cout << firstOcc(arr, n, 2)<<endl;
    // cout << lastOcc(arr, n, 2)<<endl;
    // cout<<countOcc(arr,n,2)<<endl;
    vector<int> nums = {20,22,24,14,18,19};
    cout<<searchInRotated(nums,0,nums.size() - 1, 20)<<endl;
    // cout << rotateCount(nums) << endl;
    // cout << findMinRotated(nums) << endl;
    // int a = idxOfMin(nums);
    // cout<<rotatedSorted(nums)<<endl;
    
    // if (a == -1)
    //     cout << "NOT FOUND\n";
    // else
    //     cout << max(binarySearch2(nums, 0, a - 1, 19), binarySearch2(nums, a, nums.size() -1, 19));

    // vector<int> nums = {2,3,4,7,8,9,10};
    // // cout << bsNearySorted(nums, 4) << endl;
    // // cout << bsNearySorted(nums, 21) << endl;
    // cout<<findFloor(nums,1)<<endl;
    // cout<<findCeil(nums, 1);
    
    //next greater alphabet
    // vector<char> v={'a','c','f','h/','j'};
    // cout<<nextAlphabet(v,'z')<<endl;
    
    return 0;
}



