#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2)
{
    vector<int> ans;
    for(auto x: nums1)
        ans.push_back(x);
    for(auto x: nums2)
        ans.push_back(x);

    sort(ans.begin(),ans.end());

    int n = ans.size();
    if(n%2 == 0)
        return (double)(ans[(n-1)/2]+ans[(n-1)/2+1])/2;
    return ans[n/2];
}
int main()
{
    int m,n;
    cout<<"Enter the size of array 1:";
    cin>>m;
    cout<<"Enter the size of array 2:";
    cin>>n;
    vector<int> nums1;
    vector<int> nums2;
    cout<<"Enter the Array 1 elements :";
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        nums1.push_back(x);
    }
    cout<<"Enter the Array 2 elements :";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        nums2.push_back(x);
    }
    cout<<findMedianSortedArrays(nums1,nums2);

}
