# 1 shell基础
## 1）定义 
> shell是一个**连接用户和Linux内核**的**基于内核开发**的用C语言开发的应用程序
## 2）原理
> shell通过**内核暴露的程序**接口来调用文件操作、输入输出和进程管理等功能
## 3）内部命令和外部命令
* 内置命令：shell本身自带的命令
* 外部命令：可以通过命令调用的其他应用程序
[!图1. shell工作图示](./source/1.gif)
## 4）shell编程
> shell是一门解释型脚本编程语言，它的解释器是shell应用程序本身
> shell常用于开发实用的、自动化的小工具，不适用于具有复杂业务逻辑的大中型软件开发
> 从事Linux运维的工程人员必须掌握shell，已方便服务器的集群管理
## 5）shell解释器分类
shell种类众多，本文专指Bourne Again Shell，同时也是大多数Linux系统默认的shell
- Bourne Shell（/usr/bin/sh或/bin/sh）
- Bourne Again Shell（/bin/bash）
- C Shell（/usr/bin/csh）
- K Shell（/usr/bin/ksh）
- Shell for Root（/sbin/sh）
## 6）shell脚本运行方式
### I 作为可执行程序
```
chmod +x ./test.sh # 使脚本具有执行权限
./test.sh # 执行脚本
```
**注意：**一定要写成 ./test.sh，而不是 test.sh，运行其它二进制的程序也一样，直接写 test.sh，linux 系统会去 PATH 里寻找有没有叫 test.sh 的，而只有 /bin, /sbin, /usr/bin，/usr/sbin 等在 PATH 里，你的当前目录通常不在 PATH 里，所以写成 test.sh 是会找不到命令的，要用 ./test.sh 告诉系统说，就在当前目录找

### II 作为解释器参数
`/bin/sh test.sh`
**注意：**这种方式的重点是，直接运行解释器，参数就是脚本的文件名。通过这种方式运行的脚本，不许要在第一行指定解释器信息，写了也不生效
## 7）shell提示符
默认为 # 或 $
## 8）shell脚本与shebang
"#!"符号，其中"#"称为哈希，"!"称为bang，合称shebang，编写shell脚本时要把shebang放第一行指定脚本解释器
## 9）shell注释
- 单行注释：shell脚本以"#"为注释
- 多行注释：以":>>!"开头，以"!"结尾

# 2 shell与Linux运维
## 1）服务器发展趋势
> Linux服务器是IT服务器领域的主流发展趋势
> Linux运维工程师（OPS）负责搭建运行环境，让程序代码高效、稳定、安全地在服务器上运行
## 2）OPS相关
### I 工作内容
- 安装操作系统
- 部署代码运行环境，安装运行时
- 及时修复漏洞，防止服务器被攻击
- 根据项目需求升级软件
- 监控服务器压力，防止服务器宕机
- 分析日志，及时发现代码或者环境的问题，通知相关人员修复
- ...
### II shell/python/perl
- perl已经是过去式
- python开发也是运维必备技能，优势是开发复杂的运维软件
- shell的优势是处理操作系统底层的业务

# 3 shell语法
## 1) shell变量
### I 变量名定义规则
- 命名只能使用英文字母，数字和下划线，首个字符不能以数字开头
- 中间不能有空格，可以使用下划线（_）
- 不能使用标点符号
- 不能使用bash里的关键字（可用help命令查看保留关键字）
### II 变量作用域
- 局部变量：在脚本或命令中定义的变量，仅在当前shell实例中生效，其他shell启动的应用程序不能访问局部变量
- 环境变量：所有程序（包括shell启动的程序）都能访问环境变量，有些程序依赖环境变量保证其正常运行。shell脚本也可以定义环境变量
- shell变量：由shell程序为了保证自身正常运行而设置的特殊变量，既有环境变量也有局部变量
### III 变量定义、赋值、只读设置和访问
- 定义与赋值：形式，变量名 = 变量值；示例：`var_name = var_value`
- 访问：形式，$变量名；示例 `echo var_name`
- 只读设置：不可二次赋值的变量，示例：
```
#!/bin/bash
myUrl="http://www.google.com"
readonly myUrl
myUrl="http://www.runoob.com"
:>>!
运行结果：
/bin/sh: NAME: This variable is read only.
!
```
### IV 删除变量
形式：unset 变量名，示例：unset var_name
**注意：**
- 变量一旦删除之后不可以再访问
- unset不可删除只读变量
## 2）Shell参数传递
- 我们可以在执行 Shell 脚本时，向脚本传递参数，参数之间用空格隔开
- 脚本内获取参数的格式为：$n。$0 为脚本文件名，$1 为第一个输入参数，以此类推...
- 特殊的参数处理字符：
| 符号 | 意义 | 备注 |
| --- | ---- | ---- |
| $# | 传递到脚本的参数个数，不包括脚本文件名 |  |
| $* | 以一个单字符串的形式输出所有向脚本传递的参数 | 形式为"$1 $2 ... $n" |
| $@ | 以独立字符串的形式输出所有向脚本传递的参数 | 形式为"$1" "$2" ... "$n" |
| $$ | 当前shell实例的进程ID |  |
| $! | 后台运行的最后一个进程的ID | 验证无效 |
| $- | 显示shell使用的当前选项 | 与set命令功能相同 |
| $? | 显示最后命令（前一个命令）的退出状态 | 0表示没有错，其他任何值表示有错误 |
**注意：**
- 相同点：都是引用所有参数
- 不同点：只有在双引号中体现出来。则 " $* " 等价于 "$1 $2 $3"，而 "$@" 等价于 "$1" "$2" "$3"
## 3）shell数组
### I 定义数组
  - 形式1： `arr_name=[item1, item2, ..., itemn]`
  - 形式2：
```
arr_name[0]=item1
arr_name[1]=item2
...
arr_name[n]=itemn+1
```
### II 访问数组变量
  + 访问所有变量：`echo ${arr[*]} # 或echo ${arr[@]}`
  + 访问指定下标的变量：`echo ${arr[idx]} # idx为访问数组元素的下标，从0开始`
**注意：**变量名和变量值中间的等号两边不要有空格
## 4）shell运算符
### I 算数运算符
+ 常规四则（表达式两边都有倒逗号`）：
  - 加法：`expr $a + $b`
  - 减法：`expr $a - $b`
  - 乘法：`expr $a \* $b`
  - 除法：`expr $a / $b`
  - 取模：`expr $a % $b`
+ 赋值运算
  - `a=$b`
+ 条件运算
  - 等于：`[$a==$b]`
  - 不等：`[$a!=$b]`
### II 关系运算符
**注意：**关系运算符只支持数字，不支持字符串，除非字符串的值是数字；两侧有单括号，形如`[expr]`
- 相等：eq，`[$a -eq $b]`
- 不等：ne，`[$a -ne $b]`
- 大于：gt，`[$a -gt $b]`
- 小于：lt，`[$a -lt $b]`
- 大于等于：ge，`[$a -ge $b]`
- 小于等于：le，`[$a -le $b]`
### III 布尔运算符
- 逻辑与：-a，`[$a -a $b]` 或 `[$a && $b]`
- 逻辑或：-o，`[$a -o $b]` 或 `[$a || $b]`
- 逻辑非：!，`[!$a]`
### IV 字符串运算符
- 相等：=，`[$a = $b]`
- 不等：!=，`[$a != $b]`
- 长度是否为0：-z，`[-z $a]`
- 长度是否不为0：-n，`[-n $a]`
- 是否为空：$，`[$a]`
### V 文件测试操作
**注意：**此处仅列举常用的文件测试操作
- 是否是目录：-d，`[-d $file]`
- 是否普通文件：-f，`[-f $file]`，既不是目录也不是设备文件
- 是否可读：-r，`[-r $file]`
- 是否可写：-w，`[-w $file]`
- 是否可执行：-x，`[-x $file]`
- 是否为空：-s，`[-s $file]`
- 是否存在（包括目录）：-e，`[-e $file]`
### VI 运算符优先级

|优先级|运算符|说 明|
|------|------|-------|
|13|-, + | 单目负、单目正 |
|12|!, ~|逻辑非、按位取反或补码|
|11|*, /, %|乘、除、取模|
|10|+, -|加、减|
|9|<<, >>|按位左移、按位右移|
|8|<=, >=, <, >|小于或等于、大于或等于、小于、大于|
|7|==, !=|等于、不等于|
|6|&|按位与|
|S|^|按位异或|
|4|\||按位或|
|3|&&|逻辑与|
|2|\|\||逻辑或|
|1|=, +=, -=, *=, /=, %=, &=, \|=, <<=, >>=|赋值、运算且赋值|
## 5）echo命令
### I 显示普通字符串
`echo "Hello, Jackie" # 双引号可以省略`
### II 显示转义字符
`echo -e "\"Hello, Jackie\"" # 显示转义字符双引号`
### III 显示变量
```
echo "What is your name?"
read name
echo "Welcome, $name!"
```
### IV 显示换行
```
echo -e "Hello, Jackie! \n" # -e 开启转义
echo "Is there a blank line above?"
```
### V 显示不换行
```
echo -e "OK! \c"
echo "There is no line above."
```
### VI 显示结果定向至文件
`echo "Print this to file" > ./test.txt`
### VII 原样输出，不进行转义或取变量（单引号）
`echo '$name\"`
`# 输出 $name\"`
### VIII 显示命令执行结果（反引号）
`echo `date``

## 6）printf命令
### I 形式
`printf  format-string  [arguments...]`
### II 格式替代符
- %s，字符串（右对齐，%-s为左对齐，%10s限制字符串长度）
- %c，字符
- %d，整数（十进制）
- %f，浮点数
### III 转义字符
**PS：**自行查阅文档
## 7) test命令
### I 定义
检查某个条件是否成立，可以进行数值、字符串、文件三方面的测试
### II 运算符
与上文运算符中列举的数值、字符串、文件运算符保持一致
### III 形式
```
if test expr # expr为表达式
then
  echo "test passed"
else
  echo "test not passed"
fi
```
## 4 流程控制
**注意：**shell代码可以合并为一行，语句（命令）之间用分号 ; 隔开

### 1）条件结构
- if语法
```
if condition
then
  command1 
  command2
  ...
  commandN 
fi
```
- if-else语法
```
if condition
then
  command1 
  command2
  ...
  commandN
else
  command
fi
```
- if-elif-else语法
```
if condition1
then
    command1
elif condition2 
then 
    command2
else
    commandN
fi
```
### 2）循环结构
- for-in语法
```
for var in item1 item2 ... itemN
do
  command1
  command2
  ...
  commandN
done
```
- for语法
```
for ((assignment; condition; next))
do
  command_1
  command_2
  commond_..
done
```
- while语法
```
while condition
do
  command
done
```
- until语法
```
until condition
do
  command
done
```
- case-esac语法
```
case 值 in
模式1)
  command1
  command2
  ...
  commandN
  ;;
模式2）
  command1
  command2
  ...
  commandN
  ;;
esac
```
- select-case
```
#!/bin/bash

select DRINK in tea cofee water juice appe all none
do
  case $DRINK in
    tea|cofee|water|all) 
      echo "Go to canteen"
      ;;
    juice|appe)
      echo "Available at home"
      ;;
    none) 
      break 
      ;;
    *) echo "ERROR: Invalid selection" 
      ;;
  esac
done
```
- 跳出循环
  + break 跳出所有循环
  + continue 跳出当前循环

## 5 输入/输出重定向
### 1）标准输入输出设备
- 标准输入设备：键盘
- 标准输出设备：显示器
### 2）文件
> Linux中万物皆文件

**如何查看文件类型：**
- 命令：ls -l [path]
- 形式：形如`drwxr-xr-x`
- 解释：
  + 第1个字母：代表文件类型
  + 第2 ~ 4字母：代表用户的权限
  + 第5 ~ 7字母：代表用户组的权限
  + 第8 ~ 10字母：代表其他的用户的权限
- 文件类型：
|文件属性|文件类型|
|--------|-------|
|-|常规文件，即file|
|d|目录文件|
|b|block device 即块设备文件，如硬盘。支持以block为单位进行随机访问|
|c|character device 即字符设备文件，如键盘支持以character为单位进行线性访问|
|l|symbolic link 即符号链接文件，又称软链接文件|
|p|pipe 即命名管道文件|
|s|socket 即套接字文件，用于实现两个进程进行通信|
### 3）文件描述符
- 0：stbin，标准输入文件（键盘）
- 1：stdout，标准输出文件（显示器）
- 2：stderr，标准输出文件（显示器）
### 4）输出重定向
|类 型|符 号|作 用|
|-----|-----|-----|
|标准输出重定向|command >file|以覆盖的方式，把 command 的正确输出结果输出到 file 文件中|
|标准输出重定向|command >>file|以追加的方式，把 command 的正确输出结果输出到 file 文件中|
|标准错误输出重定向|command 2>file|以覆盖的方式，把 command 的错误信息输出到 file 文件中|
|标准错误输出重定向|command 2>>file|以追加的方式，把 command 的错误信息输出到 file 文件中|
|正确输出和错误信息同时保存|command >file 2>&1|以覆盖的方式，把正确输出和错误信息同时保存到同一个文件（file）中|
|标准错误输出重定向|command >>file 2>&1|以追加的方式，把正确输出和错误信息同时保存到同一个文件（file）中|
|标准错误输出重定向|command >file1 2>file2|以覆盖的方式，把正确的输出结果输出到 file1 文件中，把错误信息输出到 file2 文件中|
|标准正确输出和错误输出分别重定向|command >>file1  2>>file2|以追加的方式，把正确的输出结果输出到 file1 文件中，把错误信息输出到 file2 文件中|
**注意：**重定向符号 > 之前不要有空格，应该是文件描述符fd（0/1/2）
### 5）输入重定向
|符号|说明|
|---|----|
|command <file|将 file 文件中的内容作为 command 的输入|
|command <<END|从标准输入（键盘）中读取数据，直到遇见分界符 END 才停止（分界符可以是任意的字符串，用户自己定义）|
|command <file1 >file2|将 file1 作为 command 的输入，并将 command 的处理结果输出到 file2|
## 6 函数
### 1）定义
> linux shell 可以用户定义函数，然后在shell脚本中可以随便调用
### 2）形式
```
funname()
{
  # actions
  # return int
}
```
### 3）实例
- 无返回值函数
```
demoFuncWithoutRet(){
  echo "demo func without ret is called"
}
```
- 有返回值函数
```
demoFuncWithRet(){
  echo "demo func with ret is called"
  return 1
}
```
- 不传参函数
```
demoFuncWithoutInput(){
  echo "demo func without input is called"
  echo "params num $#"
}
```
- 传参函数
```
demoFuncWithInput(){
  echo "demo func with input is called"
  echo "params num $#"
}
```