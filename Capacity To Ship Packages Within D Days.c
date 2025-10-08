int count_days(int *weights, int weightsSize, int capacity) {
    int days = 1;
    int current_load = 0;
    
    for (int i = 0; i < weightsSize; i++) {
        if (current_load + weights[i] > capacity) {
            days++;
            current_load = 0;
        }
        current_load += weights[i];
    }
    return days;
}

int shipWithinDays(int* weights, int weightsSize, int D) {
    int left = 0;
    int right = 0;
    
    for (int i = 0; i < weightsSize; i++) {
        if (left < weights[i]) {
            left = weights[i];
        }
        right += weights[i];
    }
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (count_days(weights, weightsSize, mid) <= D) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}
