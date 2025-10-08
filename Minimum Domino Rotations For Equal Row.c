#include <stdbool.h>

int minDominoRotations(int* A, int ASize, int* B, int BSize) {
    bool a_ok = true, b_ok = true;
    int i, a_up = 0, a_down = 0, b_down = 0, b_up = 0;
    
    for (i = 0; i < ASize; i++) {
        if (a_ok && A[i] != A[0] && B[i] != A[0]) a_ok = false;
        if (b_ok && B[i] != B[0] && A[i] != B[0]) b_ok = false;
        
        if (!a_ok && !b_ok) return -1;
        
        if (a_ok) {
            if (A[i] != A[0]) a_up++;
            else if (B[i] != A[0]) a_down++;
        }
        if (b_ok) {
            if (B[i] != B[0]) b_down++;
            else if (A[i] != B[0]) b_up++;
        }
    }
    
    if (a_ok) return a_up < a_down ? a_up : a_down;
    return b_up < b_down ? b_up : b_down;
}
