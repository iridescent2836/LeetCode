import java.util.ArrayList;
import java.util.List;

public class LC118 {

    class Solution {
        public List<List<Integer>> generate(int numRows) {
            List<List<Integer>> ans = new ArrayList<>();
            
            for(int i = 0; i < numRows; i++) {
                List<Integer> temp = new ArrayList<>();
                
                // First element is always 1
                temp.add(1);
                
                // Add middle elements (except for first row)
                if(i > 0) {
                    List<Integer> prevRow = ans.get(i-1);
                    for(int j = 1; j < i; j++) {
                        temp.add(prevRow.get(j) + prevRow.get(j-1));
                    }
                    // Last element is always 1
                    temp.add(1);
                }
                
                ans.add(temp);
            }

            return ans;
        }
    }

}