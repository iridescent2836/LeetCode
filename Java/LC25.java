

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

public class LC25 {
    class Solution {
        public ListNode reverseKGroup(ListNode head, int k) {
            ListNode dummy = new ListNode();

            dummy.next = head;

            ListNode curr = dummy;

            while(curr != null) {
                ListNode tail = curr;
                int i;
                ListNode nextCurr = null;
                for(i = 0; i < k && tail != null; ++i) {
                    tail = tail.next;
                }

                // there are not enough nodes, break
                if(i < k || tail == null) break;

                // the first node of the current k nodes will be
                // the last node in the reversed list
                nextCurr = curr.next;

                // reverse the k nodes
                for (i = 0; i < k - 1; ++i) {
                    ListNode temp = curr.next;
                    // release temp from the list
                    curr.next = temp.next;
                    // add temp to the end of tail
                    temp.next = tail.next;
                    tail.next = temp;
                    if(i == k - 2) {
                        curr = temp.next;
                    }                
                }

                // move curr
                curr = nextCurr;
            }

            
            return dummy.next;
        }
    }
    
}
