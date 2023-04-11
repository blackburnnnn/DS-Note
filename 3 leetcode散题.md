> leetcode账号 180/老密码/警官好我到二仙桥

#### Java

- for循环初始化多个变量 `for(int i=0,j=1,k=2;...)`

- int和Integer互通

- 哈希表(字典)，字典的存储结构就是哈希表(k-v对)

  ```java
  Map<Integer,String> dict = new HashMap<>();
  Map<String,Integer> dict = new HashMap<>();
  dict.put(key,value);无序添加，key重复则覆盖掉；
  dict.get(key);通过key获取对应的value;
  dict.remove(key);删除指定key;
  dict.size();返回数组长度;
  dict.replace(key,value);修改指定键的值;
  dict.keySet();返回包含所有key值的hashSet数组;
  dict.isEmpty();判断字典是否为空;
  dict.containsKey();判断字典是否包含指定key,返回true/false;
  ```

- 数组排序 `Arrays.sort(nums)`

#### Log

1. (2/7)三数之和

   - 三重循环暴力解法，但是唯一性没有确定正确
   - 双指针官方解法(比较难理解)

2. (95)(10/19)不同的二叉搜索树 II

   - `class TreeNode(object)` 在python3中，如果当前类没有继承父类，则不需要写`object`

   - 创建类时使用魔术方法`__init__`，且第一个参数必须是`self`，**当创建该类的实例时，会自动调用这个方法**

     ```python
     # 创建类
     class Terminator:
         def __init__(self):
             print("我是T-800")
     
     terminator = Terminator() # 调用类时要加括号
     # 控制台会输出我是T-800
     ```

   - python里面对象为空不是Null，而是None

   - n为0和None时，if n都为False

3. (Of 4)(10/18)二维数组中的查找

   - python定义二维数组的方式更自由

   - 遍历二维数组(列表)

     ```python
     for i in range(len(matrix)):
       for j in range(len(matrix[i])):
         sum += matrix[i][j]
     ```

   - 按照python新规范，如if、while等中不该加的括号就不要加，习惯就好

   - 利用矩阵从左至右&从上至下递增的特点，将时间复杂度由m\*n优化为m+n，空间复杂度一直是**O(1)**

     <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20221018162136073.png" alt="image-20221018162136073" style="zoom:25%;" />

4. (Of 3)(10/18)数组中重复的数字

   - 方法的数据类型提示：[from typing import Dict, Tuple, List, Optional](https://blog.csdn.net/weixin_46713695/article/details/125032851)

   - import和方法、方法与主函数之间，均要有两个空行

   - 在类中定义方法，调用方法前要调用类，且类后面记得加括号，如`S.()`

     <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20221018103923587.png" alt="image-20221018103923587" style="zoom:33%;" />

5. (剑指offer 09)(7/16)用两个栈实现队列

   - leetcode直接用Queue弄虚作假也是可以通过的，对具体的方法不会进行验证

   - 需要实现构造函数`public CQueue()`，只需要初始化数据类型即可

   - 除了使用`Stack`类，也可以使用`LinkedList`类，都用到泛型

     <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220716185935912.png" alt="image-20220716185935912" style="zoom:50%;" />		<img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220716185946160.png" alt="image-20220716185946160" style="zoom:40%;" />

   - [本地ide测试leetcode这种含有其他类的题目](https://blog.csdn.net/X_xiaojuzi/article/details/125752561)

   - [b站栈&队列讲解](https://www.bilibili.com/video/BV1jJ411C7V2?spm_id_from=333.337.search-card.all.click&vd_source=726461adc26f0b0f56256c07f5a478dc)

   - [Java Stack类](https://m.runoob.com/java/java-stack-class.html)、[Queue类](https://blog.csdn.net/weixin_44895586/article/details/108263570)

   - 不应在类的构造方法中声明属性，应在构造方法前声明，构造方法只是进行初始化

     ```java
     class CQueue{
         Stack<Integer> stack1;
         Stack<Integer> stack2;
         public CQueue() {
             stack1 = new Stack<>();
             stack2 = new Stack<>();
         }
        	...
     }
     ```

   - (7/25)别人一步到位的思路比我更简捷，每一次出队的操作，先将stack1的元素全部入stack2，在完成出队后，再将stack2的元素全部入stack1

6. (剑指offerⅡ 9)(6/30)乘积小于K的子数组

   - java int型连续相乘可能发生下溢出，需要提前终止

     ```java
     int count = 0;
     int length = nums.length;
     for(int i=0; i<length; i++){
       boolean over = false;
       for(int j=0; j<length-i; j++){
         if(over == true){
           over = false;// 更新over
           break;
         }
         int product = 1;
         if(j == 0){// 判断单个元素
           if(nums[i] < k) count++;
         }
         else{
           for(int q=0; q<=j; q++){
             product *= nums[i+q];
             if(product >= k){// 内外层均提前终止
               over = true;
               break;
             }
           }
           if(product < k) count++;
         }
       }
     }
     return count;
     ```

   - **自己的以上解法**依然超出时间限制

   - (7/9)大体思路相似，但是标准解法左右双指针的思路很清晰，自己就只知道死套循环，不可取，**而且最开始自己也没看清楚题目前提，很不严谨**，超时的原因就是自己之前的代码直接套了两层循环，**真正的思路应该是滑动窗口+双指针**，这样之只需要一层循环，虽然思路相似，但是这样的实现方式显然能大幅缩减时间复杂度，**滑动窗口+双指针**的这种思路非常经典，值得积累

   - (7/16)思路更新：**为什么只需要一层循环！是因为在这一层循环中，左右指针会回退！这才是减少复杂度的核心！**和while、for的使用也没关系

   - [更好的题解](https://leetcode.cn/problems/ZVAVXX/solution/by-cranky-ptolemylu3-1wjl/)，这个解法其实也和上面的理解有点出入了，所以为什么之前我的代码耗时太长，可能纯纯是因为里面太冗余吧

7. (28)(6/27)实现strStr()

   - 提取某位置的字符：`charAt()`

   - 双重循环同步前移 `i+j`

     ```java
     for(int j=0;j<length2;j++){
       if((i+j)>=length1 || haystack.charAt(i+j) != needle.charAt(j)){
         flag = 0;
         break;
       }
     }
     ```

   - Venn图逻辑关系理解

     - A或B的否定是非A且非B
     - A且B的否定是非A或非B

   - [KMP算法](https://leetcode.cn/problems/implement-strstr/solution/shi-xian-strstr-by-leetcode-solution-ds6y/)，有空再学习

8. (121)(5/25)买卖股票的最佳时机

   - 暴力遍历超出时间限制，通常所说的时间复杂度$O(n^2)$就是1+2+3+...+n=n(n-2)/2，空间复杂度就是用的开辟个的变量个数

     <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220525202301443.png" alt="image-20220525202301443" style="zoom:35%;" />

   - 以真实买股票的思路去分析，只需遍历一遍

9. (9)(5/6)回文数

10. (26)(4/23)删除有序数组中的重复项

   - `int[] a = {}` 花括号创建数组

   - 增强for循环 `for (int num : nums) {}`

   - Java引用传值，就算这里不是数组也会修改实际值  <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220423000845422.png" alt="image-20220423000845422" style="zoom:28%;" />

   - 代码规范就按自己的来，for循环也不用讲究，逻辑符号前后有空格就行了，如`nums[j] = nums[j+1];`和`while(nums[i]==nums[i+1] && i<length-1){}`

   - 与或非分逻辑和按位，逻辑与是`&&`，逻辑或是`||`

   - 边界条件没考虑完善，最后通过debug解决

   - (5/1)java字符串必须要用双引号！！！

     <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220501234631487.png" alt="image-20220501234631487" style="zoom:30%;" />

11. (1)两数之和

   - 理解哈希表解法
   - `return new int[0];` 返回垃圾值防止编译器报错

11. (21)拼接两个升序链表

    - 链表数据结构

    - leetcode刷题是写接口，像链表这种题目需要统一的创建链表等测试程序

      > 参考 https://www.jianshu.com/p/6428838003f2

    - 类中的引用型属性，默认构造是null

      <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220131221733094.png" alt="image-20220131221733094" style="zoom:33%;" />

    - 注意java对象的赋值就是引用，作用完全等价于C的指针，所以在赋值`q=p`后，它们虽然名字不同，但是实际上是同一个东西了(地址完全相同)，这个思维理解之后本科学习的怎样构建各种数据结构就清晰了

    1. 迭代法
       - 所以要使用好ListNode类中的next属性，用于指向。比如声明的对象p是开头，q就直接从p开始，不断的更新p.next，这样就完成了链表的连接，所以只需要专注于q的移动
       - 在q移动的同时，list1和list2也需要不断移动更新，移动的方法就是直接给这三个变量赋值
    2. 递归法
       - 递归需要满足待解决问题可以拆分为结构相同的子问题，且由合理的返回值完成递归的回溯
       - 设置好边界条件的返回值
       - 递归思路和程序结构只要构建好了，其实只需要考虑最上层的程序

12. (13)罗马数字转整数

    - 哈希表数据结构

    - 给定一个罗马数字，将其转化为整数

    - 不同的问题，最重要的获取逻辑思路，比如这道题你就必须知道罗马数字转化为阿拉伯数字的固定方法才行，然后用代码去实现

      <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220201173916977.png" alt="image-20220201173916977" style="zoom: 25%;" />

    - 在具体方法前可以先定义好匿名内部类备用，注意这种语法(匿名内部类)

      <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220201205045028.png" alt="image-20220201205045028" style="zoom:25%;" />

    - 不过也没什么用，反而直接在方法里面定义更好

      <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220201205142551.png" alt="image-20220201205142551" style="zoom:25%;" />

    - 注意哈希表，第一个是键，第二个是想要映射的值，使用`put`把键值对打进去，这里第一个元素是罗马字符(Character)，第二个字符是对应的阿拉伯数字(Integer)

    - 字符串的遍历(先定义好长度n)&自带方法、map的put&get

    - 哈希表的作用就是进行不同值的映射，将这些关系存储起来备用

13. (94)二叉树的中序遍历

   - leetcode烦就烦在它只测试接口，需要自己去搞测试主程序，而且它的输入基本都是列表，输入输出也需要严格满足它的要求，所以要满足它的格式，又不被递归等程序逻辑影响，就可以在leetcode接口下面再写方法去实现逻辑

     <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220203215919457.png" alt="image-20220203215919457" style="zoom:25%;" />

   - 这道题需要用List形式返回，那么就可以在主接口里面声明一个List，然后再写一个没有返回值的函数去实现中序遍历的逻辑

   - 方法可加public，也可以不加

   - static方法不能调用非static方法，但是非static方法可以调用非static方法或static方法

   - Java引用的不变性(以递归为例)

     <img src="/Users/leizhenhao/Library/Application Support/typora-user-images/image-20220203220838442.png" alt="image-20220203220838442" style="zoom:25%;" />

11. (105)前序&中序遍历构造二叉树

    - 本科数据结构是降低难度的井号创建法，因为可以用井号来作为终止符
    - 前序+中序、后序+中序都能唯一确定一颗二叉树，但是前序+后序不能唯一确定一颗二叉树，见[反例](https://blog.csdn.net/weixin_38853761/article/details/107491173)







