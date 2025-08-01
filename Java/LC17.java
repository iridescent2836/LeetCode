import java.util.*;

public class LC17 {
    private static final Map<Character, String> num2char = new HashMap<>();

    static {
        num2char.put('2', "abc");
        num2char.put('3', "def");
        num2char.put('4', "ghi");
        num2char.put('5', "jkl");
        num2char.put('6', "mno");
        num2char.put('7', "pqrs");
        num2char.put('8', "tuv");
        num2char.put('9', "wxyz");
    }

    private void dfs(List<String> ret, StringBuilder temp, String digits, int idx) {
        if(idx == digits.length()) {
            ret.add(temp.toString());
            return;
        }

        String chars = num2char.get(digits.charAt(idx));

        if(chars != null) {
            for(char ch : chars.toCharArray()) {
                temp.append((ch));
                dfs(ret, temp, digits, idx+1);
                temp.deleteCharAt(temp.length()-1);
            }
        }
    }
    public List<String> letterCombinations(String digits) {
        List<String> ret = new ArrayList<>();

        if(digits == null || digits.length() == 0) return ret;
        dfs(ret, new StringBuilder(), digits, 0);
        return ret;
    }
}
