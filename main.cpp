#include <iostream>
using namespace std;

class BST {
public:
    int value;
    BST *left;
    BST *right;

    explicit BST(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// AVERAGE: O(log(n)) time | O(log(n)) space
// WORST: O(n) time | O(n) space
int recursiveHelperMethod(BST *node, int target, int closest) {
    if(abs(target - closest) > abs(target - node->value)) {
        closest = node->value;
    }
    if(target < node->value && node->left != nullptr) {
        return recursiveHelperMethod(node->left, target, closest);// O(log(n) time || O(n) time (if only 1 branch)
    } else if(target > node->value && node->right != nullptr) {
        return recursiveHelperMethod(node->right, target, closest);// O(log(n) time || O(n) time (if only 1 branch)
    } else {
        return closest;
    }
}

// AVERAGE: O(log(n)) time | O(log(n)) space
// WORST: O(n) time | O(n) space
int findClosestValueInBstRecursive(BST *node, int target) {
    return recursiveHelperMethod(node, target, node->value);
}

// AVERAGE: O(log(n)) time | O(1) space
// WORST: O(n) time | O(1) space
int iterativeHelperMethod(BST *node, int target, int closest) {
    BST *currentNode = node;
    while(currentNode != nullptr) {// O(log(n) time || O(n) time (if only 1 branch)
        if(abs(target - closest) > abs(target - currentNode->value)) {
            closest = currentNode->value;
        }
        if(currentNode->value < target) {
            currentNode = currentNode->right;
        } else if(currentNode->value > target) {
            currentNode = currentNode->left;
        } else {
            break;
        }
    }
    return (int) closest;
}

// AVERAGE: O(log(n)) time | O(1) space
// WORST: O(n) time | O(1) space
int findClosestValueInBstIterative(BST *node, int target) {
    return iterativeHelperMethod(node, target, node->value);
}

int main() {
    BST *root = new BST(10);
    root->left = new BST(5);
    root->left->left = new BST(2);
    root->left->left->left = new BST(1);
    root->left->right = new BST(5);
    root->right = new BST(15);
    root->right->left = new BST(13);
    root->right->left->right = new BST(14);
    root->right->right = new BST(22);
    int target = 12;

    cout << findClosestValueInBstRecursive(root,target) << endl;
    cout << findClosestValueInBstIterative(root, target) << endl;

    return 0;
}
