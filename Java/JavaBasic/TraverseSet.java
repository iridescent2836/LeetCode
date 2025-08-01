package JavaBasic;
import java.util.*;

public class TraverseSet {

    public static void main(String[] args) {
        // 创建一个Set并添加元素
        Set<String> set = new HashSet<>();
        set.add("Apple");
        set.add("Banana");
        set.add("Orange");

        // 方式1：使用增强for循环遍历
        System.out.println("方式1：增强for循环遍历");
        for (String item : set) {
            System.out.println(item);
        }

        // 方式2：使用迭代器遍历
        System.out.println("方式2：迭代器遍历");
        Iterator<String> iterator = set.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }

        // 方式3：使用forEach方法遍历（Java 8及以上）
        System.out.println("方式3：forEach方法遍历");
        set.forEach(System.out::println);
    }
}