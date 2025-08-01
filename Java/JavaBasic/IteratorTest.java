package JavaBasic;
import java.util.*;

public class IteratorTest {
    public static void main(String[] args) {
        // 创建一个 ArrayList 并添加元素
        List<String> list = new ArrayList<>();
        list.add("Apple");
        list.add("Banana");
        list.add("Cherry");

        // 获取迭代器
        Iterator<String> iterator = list.iterator();

        // 1. 使用 hasNext() 和 next() 遍历集合
        System.out.println("遍历集合元素：");
        while (iterator.hasNext()) {
            String element = iterator.next(); // 获取下一个元素
            System.out.println(element);
        }

        // 2. 使用 remove() 删除元素
        // 注意：每次 next() 后只能调用一次 remove()
        iterator = list.iterator(); // 重新获取迭代器
        while (iterator.hasNext()) {
            String element = iterator.next();
            if ("Banana".equals(element)) {
                iterator.remove(); // 删除当前元素
            }
        }
        System.out.println("删除 Banana 后的集合：" + list);

        // 3. forEachRemaining() 用法（Java 8+）
        list.add("Date");
        iterator = list.iterator();
        System.out.println("forEachRemaining 遍历：");
        iterator.forEachRemaining(e -> System.out.println(e));
    }
}
