typedef struct {
    struct TreeNode **data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue *q = malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->data = malloc(q->capacity * sizeof(struct TreeNode*));
    return q;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, struct TreeNode *node) {
    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->data = realloc(q->data, q->capacity * sizeof(struct TreeNode*));
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = node;
    q->size++;
}

struct TreeNode* dequeue(Queue *q) {
    struct TreeNode *node = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    *returnSize = 0;
    if (!root) return NULL;
    
    int **result = malloc(2000 * sizeof(int*));
    int *colSizes = malloc(2000 * sizeof(int));
    Queue *q = createQueue(1000);
    
    enqueue(q, root);
    
    while (!isEmpty(q)) {
        int levelSize = q->size;
        int *level = malloc(levelSize * sizeof(int));
        colSizes[*returnSize] = levelSize;
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode *node = dequeue(q);
            level[i] = node->val;
            
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        
        result[*returnSize] = level;
        (*returnSize)++;
    }
    
    free(q->data);
    free(q);
    
    *columnSizes = colSizes;
    return result;
}
