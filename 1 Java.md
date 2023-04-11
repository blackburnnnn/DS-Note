> Coding&Theory/MyCode

#### Java学习路线

- 参考 [谷粒学院官方评论](https://www.bilibili.com/video/BV1dQ4y1A75e/?spm_id_from=333.999.0.0&vd_source=726461adc26f0b0f56256c07f5a478dc)
- 参考 [尚硅谷官方Java 2023学习路线](https://www.bilibili.com/read/cv5216534)

#### 基础语法

- 除法运算符`/`遵从向下取整 `3/2 = 1`

- 一个.java文件只能有一个public class

- 布尔类型 `boolean`$\Rightarrow$`true` or `false`

  - 与`&&`；或`||`

- 三目运算符 `a?b:c`

- 空值`null`

- `public static void main(String[] args)`

  1. 使用public修饰符是告诉其他类可以访问该方法
  2. 使用static修饰符表示该方法是静态的，不需要实例化即可使用
  3. void关键字表明main()的返回值无类型
  4. String[] args：用于接收命令行状态下的参数

- `s instanceof String` 判断变量s是否是String类型

- `public class`中的`public static final int x`用于声明常量

- 增强for循环

  ```java
  int[] ns = { 1, 4, 9, 16, 25 };
  for (int item : ns) {
    System.out.println(item);
  }
  ```

- java中没有`const`，只有`final`，在修饰变量时作用一样，但前者不能修饰C中的类

- 不能在类中嵌套类，类与类要分离

  <img src="/Users/leizhenhao/Library/Containers/com.tencent.qq/Data/Library/Application Support/QQ/Users/625779422/QQ/Temp.db/3E7AA33C-0377-4D38-B396-18C17CD531B8.png" alt="3E7AA33C-0377-4D38-B396-18C17CD531B8" style="zoom:33%;" />

- 输出数组内容 `Arrays.toString()`

- 输出集合对象如`List`，直接`println`

- 注意 `i++` 和 `++i` 的区别

- 使用`implements`关键字后，除了实现接口外，当前类还是一个类，其他功能和之前没有区别

- 类`ListNode`的构造方法

  - 空的构造方法(默认存在) `ListNode(){}`
  - 非空的构造方法 `ListNode(int val){this.val = val;}`

- `this.x` 类的成员变量

- 三目运算符的优先级>赋值优先级 `prev.next = l1 == null ? l2 : l1;`

- (6/22)[Java通配符`<T>`学习](https://blog.csdn.net/NeiHan2020/article/details/123102632)

- `java.util.Arrays`包针对不可变数组

- (6/27)[javac命令](https://blog.csdn.net/qq_39505245/article/details/121542240)

#### 字符串

- (5/6)**一定要区分单引号`''`和双引号`""`！！！**

- 一个`char`只能存储一个字符，使用单引号`'c'`，数据类型为`Character` 

- 一个`String`可以存储0到任意个字符，使用双引号`"s"`

- `String`是引用类型，不能使用`==`进行相等判断，必须使用使用`s1.equals(s2)`

- 每个`Object`都有`toString()`方法，可将其转化为字符串表示

- Java程序执行时会维护一个String池，对于一些可以共享的字符串对象，会先在String池中查找是否存在相同的String内容（字符相同），**如果有就直接返回，不创建新对象**

  ```java
  String a1=“abcdefg”；
  String a2=“abcdefg”；
  System.out.println(a1==a2）；
  ```

  - 运行结果是`true` ，因为a2是直接引用的a1，自己并没有创建对象，所以对象判定相等


#### 数组

- 一维数组声明方式

  1. 数组类型 [] 数组名 = {em1,em2,em3,…,emN}

     `int[] array = {3,5,4,8,12,5};`

  2. 数组类型[] 数组名 = new 数组类型[N]

     `String[] str = new String[6];`

  3. 数组类型[] 数组名 = new 数组类型[]{em1,em2,em3,…,emN}

     `int[] array = new int[]{2,4,5,6,8,9};`

- `int[] a = new int[3]`&`int[][] a = new int[3][4]`

  - `int[] a = new int[]{123,525};`

  - 这样声明之后数组长度不可再变化

  - C语言数组声明方式 `int a[3] = {1,2,3}`&`int arr[2][2] = {{1,2},{3,4}};`

  - Java数组也是对象，必须要用`new`关键字

  - Java也可以直接赋值

    ```java
    String[] names = {"ABC", "XYZ", "zoo"};
    String s = names[1];
    ```

- `.length`获取数组长度

- 二维数组&增强for循环遍历

  ```java
  int[][] ns = {
    		{ 1, 2, 3, 4 },
    		{ 5, 6 },
    		{ 7, 8, 9 }
  };
  for(int[] arr : ns){
    for(int a : arr){
      System.out.println(a);
    }
  }
  ```

- 遍历数组或者字符串可以先获取长度 `int n = nums.length`

- 用 `new int[]{xxx}` 进行任意包装 `return new int[]{hashtable.get(target - nums[i]), i};`

#### 内部类

- 在其他类内部的类就是内部类

  ```java
  class Outer {
      class Inner {
          // 定义了一个Inner Class
      }
  }
  ```

- Inner Class的实例不能单独存在，必须依附于一个Outer Class的实例

#### 集合

- java.util包主要提供了以下三种类型的集合

  - `List`：一种有序列表的集合
  - `Set`：一种确保没有重复元素的集合
  - `Map`：一种通过键值(key-value)查找的映射表集合

- List是接口，ArrayList才是实现类，所以`new List`会报错，在实例化接口的时候都按如下方式声明

  `List<String> list = new ArrayList<>(); // 只能放入String类型`

##### List

- 主要是`ArrayList`和`LinkedList`这两种实现类，通常情况下优先使用`ArrayList`

- 创建List `List<Integer> list = List.of(1,2,5);`

- 遍历使用增强for循环

- 直接sout也可以输出完整值 <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220417005611499.png" alt="image-20220417005611499" style="zoom:50%;" />

- [`Arrays.asList()`详解](https://blog.csdn.net/kzadmxz/article/details/80394351)

  1. **就是将数组对象(只能是Integer等对象型数据)转化为ArrayList**
  2. 但是这个ArrayList不是java.util包下的！而是java.util.Arrays.ArrayList！所以不支持add()、remove()、clear()等方法

- 单纯的数组对象直接sout是无法输出具体值的，但是用以上方法转化为ArrayList(无论是两种ArrayList中的哪一种)都可以直接把具体数据sout出来 

  ​					<img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220417010056038.png" alt="image-20220417010056038" style="zoom:33%;" />	<img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220417010115692.png" alt="image-20220417010115692" style="zoom:50%;" />

- 最稳定的操作还是`new ArrayList<>()`

##### Map

- `Map<key,Object>` ，第一项是键，第二项是键映射的对象，这两项都不能为基本数据类型

  ```java
  Student s = new Student("Xiao Ming", 99);
  Map<String, Student> map = new HashMap<>();
  map.put("Xiao Ming", s); // 将"Xiao Ming"和Student实例映射并关联
  Student target = map.get("Xiao Ming"); // 通过key查找并返回映射的Student实例
  ```

- 声明方式 `Map<String, Integer> map = new HashMap<>();`

- Map中不能存在重复的key，虽然放入相同的key不会报错，但会把原有的key-value对应的value给替换掉，因为一个key也只能关联一个value

- Map的遍历

  - 遍历键的集合，因为每个键都有唯一的对象与其绑定，依次获取到每个键后，使用`map.get(key)`，获取到该键映射的对象

    ```java
    for (String key : map.keySet()) {
      Integer value = map.get(key);
      System.out.println(key + " = " + value);
    }
    ```

- 判断哈希表中是否存在key `map.containsKey(Object)`

##### Set

- 可以用来去除重复元素

##### LinkedList

- `LinkedList<String> linkedList = new LinkedList<>(Arrays.asList(arr));` 其中的`Arrays.asList`就是把包含对象的数组转化为集合