#include <stdlib.h>

struct TreeNode* helper(int* preorder, int* idx, int min, int max, int size) {
    if (*idx >= size) return NULL;
    
    int val = preorder[*idx];
    if (val < min || val > max) return NULL;
    
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    if (!node) return NULL;
    
    node->val = val;
    (*idx)++;
    
    node->left = helper(preorder, idx, min, val, size);
    node->right = helper(preorder, idx, val, max, size);
    
    return node;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    int idx = 0;
    return helper(preorder, &idx, INT_MIN, INT_MAX, preorderSize);
}
