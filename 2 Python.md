- (11/5)程序设计点名脚本+作业提交检测脚本

  1. 学校系统和点名册各一个excel，遍历原始点名册，在学校系统系统excel中进行遍历，匹配姓名即可
  2. 获取坚果云文件夹内的姓名/学号列表，遍历原始点名册，在列表里面进行遍历，匹配姓名即可
  
- [b站从零写Python实用脚本视频教程](https://www.bilibili.com/video/BV1dV41127Sk?p=1&vd_source=726461adc26f0b0f56256c07f5a478dc)

- (10/19)Python和Java中万物皆对象，所有的对象传值都是引用传值

  - 以下代码输出b，也会显示xyz

    ```python
    a = "123"
    b = a
    a = "xyz"
    ```

  - 这里有一个奇怪的问题，首先基于[这个链接](https://www.cnblogs.com/gavanwanggw/p/7027074.html)已经理解了，**python的list等是引用类型**，将list作为参数，就是唯一的，会全局修改，但是自己却发现list作为整体是不行的

    ```python
    # list作为整体
    def swap(a,b):
        tmp = a
        a = b
        b = tmp
        print('a=', a, ' b=', b)s
        
    # 修改list具体值
    def swap(a,b):
        tmp = a[0]
        a[0] = b[0]
        b[0] = tmp
        print('a=', a, ' b=', b)
    ```

  - 运行测试程序，只有第二个程序才能交换值，后面才明白，第一个程序swap里面的a和b，**python会理解为是新定义的参数，与传进来的无关，所以无法改变main里面的内容**，第二个程序里面a[0]，只可能指向main中的a，所以能交换值

    ```python
    if __name__ == '__main__':
        a, b = [10], [20]
        swap(a, b)
        print('a=', a, ' b=', b)
    ```

- 进一步学习[Python的可变对象和不可变对象](https://blog.csdn.net/weixin_42009804/article/details/121078734)，**只有可变对象才可以进行引用传值并全局改变对象**

- python列表可以直接通过 `+` 拼接

- 程序设计课程点名脚本

  - 读取原始名单(李知霜和张涵勃之前有特殊符号)，遍历行，先获取学号后，在获取提交作业的文件夹内检索，有就下一行，没有就再按姓名找

  - 读取excel文件 + 获取文件夹内文件信息

  - mac路径 `'/Users/leizhenhao/Desktop/2022/程序设计助教/原始名单.xlsx'` 中分隔符是反斜杠，所以不需要反斜杠，只有需要把特殊字符打出来的时候才需要使用反斜杠`\`

  - vscode用起来不顺手，还是用pycharm吧，运行点名.py的时候直接右下角换个解释器即可



