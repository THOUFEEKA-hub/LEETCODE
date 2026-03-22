double findMedianSortedArrays(int* A, int m, int* B, int n) {
    if (m > n) return findMedianSortedArrays(B, n, A, m);
    int low = 0, high = m;
    while (low <= high) {
        int cutA = (low + high) / 2;
        int cutB = (m + n + 1) / 2 - cutA;
        int leftA = (cutA == 0) ? -2147483648 : A[cutA - 1];
        int rightA = (cutA == m) ? 2147483647 : A[cutA];
        int leftB = (cutB == 0) ? -2147483648 : B[cutB - 1];
        int rightB = (cutB == n) ? 2147483647 : B[cutB];
        if (leftA <= rightB && leftB <= rightA) {
            if ((m + n) % 2 == 0)
                return (fmax(leftA, leftB) + fmin(rightA, rightB)) / 2.0;
            else
                return fmax(leftA, leftB);
        }
        else if (leftA > rightB)
            high = cutA - 1;
        else
            low = cutA + 1;
    }
    return 0.0;
}
