int findPeakElement(int* nums, int numsSize) {
    int l, r, m;
    if (numsSize == 1) return 0;
    
    l = 0; r = numsSize - 1;
    while (l < r) {
        m = l + (r - l) / 2;
        if (nums[m] < nums[m + 1]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    
    return l;
}
