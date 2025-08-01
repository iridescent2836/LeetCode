package JavaBasic;
public class TraverseMap {
    
    public static void main(String[] args) {
        java.util.HashMap<String, Integer> map = new java.util.HashMap<>();
        map.put("apple", 3);
        map.put("banana", 2);
        map.put("orange", 5);

        System.out.println("遍历方式一：通过entrySet");
        for (java.util.Map.Entry<String, Integer> entry : map.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }

        System.out.println("\n遍历方式二：通过keySet");
        for (String key : map.keySet()) {
            System.out.println(key + ": " + map.get(key));
        }

        System.out.println("\n遍历方式三：通过values");
        for (Integer value : map.values()) {
            System.out.println(value);
        }
    }
}
