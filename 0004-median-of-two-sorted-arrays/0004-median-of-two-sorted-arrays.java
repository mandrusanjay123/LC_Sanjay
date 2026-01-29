class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m=nums1.length,n=nums2.length;
        int tot=m+n,mid1=-1,mid2=-1;
        int i=0,j=0;
        for(int k=0;k<=tot/2;k++){
            mid1=mid2;
            if(i<m &&(j>=n || nums1[i]<nums2[j])){
                mid2=nums1[i++];
            }
            else{
                mid2=nums2[j++];
            }

        }
        if(tot %2==0) return (mid1+mid2)/2.0;
        else return mid2;
    }
}