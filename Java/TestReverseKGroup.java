public class TestReverseKGroup {

    // 定义链表节点类
    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    // 引入你的解法
    static class Solution {
        public ListNode reverseKGroup(ListNode head, int k) {
            ListNode dummy = new ListNode();
            dummy.next = head;
            ListNode curr = dummy;

            while (curr != null) {
                System.out.println(curr.val);
                ListNode tail = curr;
                int i;
                ListNode nextCurr = null;
                for (i = 0; i < k && tail != null; ++i) {
                    tail = tail.next;
                }

                if (i < k || tail == null) break;

                nextCurr = curr.next;


                for (i = 0; i < k - 1; ++i) {
                    ListNode temp = curr.next;
                    curr.next = temp.next;
                    temp.next = tail.next;
                    tail.next = temp;
                    if (i == k - 2) {
                        curr = temp.next;
                    }
                }

                curr = nextCurr;
            }

            return dummy.next;
        }
    }

    // 工具：打印链表
    static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null) System.out.print(" -> ");
            head = head.next;
        }
        System.out.println();
    }

    // 构造链表并测试
    public static void main(String[] args) {
        // 构造链表：1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1,
                            new ListNode(2,
                            new ListNode(3,
                            new ListNode(4,
                            new ListNode(5)))));

        System.out.println("原链表:");
        printList(head);

        Solution sol = new Solution();
        int k = 3;
        ListNode result = sol.reverseKGroup(head, k);

        System.out.println("反转后的链表 (每 " + k + " 个一组):");
        printList(result);
    }
}
