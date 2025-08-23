import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class LC2561_failToUnderstand {
    class Solution {
        public long minCost(int[] basket1, int[] basket2) {
            TreeMap<Integer, Integer> freq = new TreeMap<>(); // store the diff
            int minFruit = Integer.MAX_VALUE;
            for (int b1 : basket1) {
                freq.put(b1, freq.getOrDefault(b1, 0) + 1);
                minFruit = Math.min(minFruit, b1);
            }
            for (int b2 : basket2) {
                freq.put(b2, freq.getOrDefault(b2, 0) - 1);
                minFruit = Math.min(minFruit, b2);
            }
    
            List<Integer> merge = new ArrayList<>();
            for (Map.Entry<Integer, Integer> entry : freq.entrySet()) {
                int count = entry.getValue(); 
                if (count % 2 != 0) return -1;

                // 将需要交换的fruit都加入
                for (int i = 0; i < Math.abs(count) / 2; i++) {
                    merge.add(entry.getKey());
                }
            }
            

            // 贪心的核心概念
            Collections.sort(merge);
            long res = 0;
            /*
             * 示例说明：
             * basket1 = [10,10,2,2]  → 2个10，2个2
             * basket2 = [8,8,1,1]    → 2个8，2个1
             * 
             * freq统计差异：
             * - 水果1: -2 (篮子2多2个)
             * - 水果2: +2 (篮子1多2个)  
             * - 水果8: -2 (篮子2多2个)
             * - 水果10: +2 (篮子1多2个)
             * 
             * merge = [1,2,8,10]  // 排序后按价值升序
             * 
             * 配对结果
             * [1,10]
             * [2, 8]
             * 
             * 
             * 贪心贪的莫名奇妙？？
             */
            for (int i = 0; i < merge.size() / 2; i++) {
                res += Math.min(2 * minFruit, merge.get(i));
            }
            return res;
        }
    }
    
}
