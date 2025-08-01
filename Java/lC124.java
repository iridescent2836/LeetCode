
public class lC124 {
    
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    class Solution {

        int maxSum = Integer.MIN_VALUE;

        int max(int... nums) {
            if (nums.length == 0) throw new IllegalArgumentException("empty input");
            int max = nums[0];
            for (int n : nums) {
                if (n > max) max = n;
            }
            return max;
        }
        // 为什么这个算法是正确的，就是正确的，每个节点比较带上root的值，
        // 虽然可能因为 root->val < 0 导致 
        // lleftMax+rightMax+root.val < max(leftMax + rightMax)，
        // 但是 leftMax 和 rightMax 已经分别在左右子树的时候比较过了
        int helper(TreeNode root) {
            if(root == null) return 0;

            int leftMax = helper(root.left);
            int rightMax = helper(root.right);

            // 每个子树只比较带 root 的值
            maxSum = Math.max(maxSum, leftMax+rightMax+root.val);

            // 如果该子树会导致父节点的值减小，返回 0
            return Math.max(Math.max(leftMax, rightMax) + root.val, 0);
        }

        public int maxPathSum(TreeNode root) {
            helper(root);

            return maxSum;
        }
    }
}
