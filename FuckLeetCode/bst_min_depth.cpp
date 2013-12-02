/*
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root
 * node down to the nearest leaf node.
 */
int MinDepth(TreeNode *root) {
    if (!root)
        return 0;
    int left_depth = root->left? MinDepth(root->left) : 0;
    int right_depth = root->right? MinDepth(root->right) : 0;
    if (left_depth == 0 && right_depth == 0) {
        return 1;
    } else {
        if (left_depth == 0)
            return right_depth + 1;
        else if (right_depth == 0)
            return left_depth + 1;
        else
            return std::min(left_depth, right_depth) + 1;
    }
}

int main() {
    return 0;
}
