#include <stdio.h>
#include <stdlib.h>

#define MAX 1000 
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

int visited[MAX];
int visitedCount = 0;


int existsInVisited(int val) {
    for (int i = 0; i < visitedCount; i++) {
        if (visited[i] == val) return 1;
    }
    return 0;
}
void addToVisited(int val) {
    visited[visitedCount++] = val;
}


int findPair(TreeNode* root, int target, int* x, int* y) {
    if (!root) return 0;

    int complement = target - root->val;
    if (existsInVisited(complement)) {
        *x = root->val;
        *y = complement;
        return 1;
    }

    addToVisited(root->val);

    return findPair(root->left, target, x, y) || findPair(root->right, target, x, y);
}


TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}


int main() {
   

    TreeNode* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(8);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->right = newNode(9);

    int target;
    printf("Enter target sum: ");
    scanf("%d", &target);

    int a, b;
    if (findPair(root, target, &a, &b)) {
        printf("Found pair: %d + %d = %d\n", a, b, target);
    } else {
        printf("No such pair found.\n");
    }

    return 0;
}
