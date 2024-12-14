八股 算法 算法 项目 实习 学历 科研 竞赛 开源 个人博客  剑指offer hot100


jetbrain 快捷键:
https://www.bilibili.com/video/BV1dL411E7Qg/?vd_source=4b9929a93a68ea46743a8ef1b0d86cba

ctrl+/ 注释    ctrl+D  shift + ctrl+↑...  

关掉提示区分大小写  注释改为绿色   加入自动导入包

右.左操作   :
"helloworld".sout
boolean flag = true;   flag.while   循环
int[] x ={...};  x.for   迭代
...



cmd 常用命令cmd
![alt text](image.png)
环境变量Path 让cmd等能直接找到 不用在相应目录启动cmd;  

安装路径一般不要中文 因为中文菜 就多练;
![alt text](image-1.png)

bug 的历史 : oh bug     卧槽


%appdata%   类似与 #define ...    是个预处理变量


制表符  \t  把前边的内容补齐到8或者8的倍数
name    185
abc     456        能够好看  对其    

数据类型:
byte 8bit   short 16bit   int 32bit   long  64bit
float 32bit    double 64bit
char 32bit  
long x =9999999999L
float x  =10.34F
double x= 12.434      long  double 需要加后缀  因为java 默认 int 和double
![alt text](image-2.png)

identifier 和C语言类似
Alibaba 变量命名规范:
小驼峰命名  变量 方法:   name   firstName    secondDadName
大驼峰命名  类:   Student    GoodStudent


全是整数 / 是整除   有小数就是除法
隐式转换
不同数据类型运算 小的转换为大的取值范围 eg.  'A'+10==75;   byte short char 直接转为int
强制转换
double x=12.3      (int)x==12;  截断

+  有数学和字符串串联两种运算

a++先用后加   ++a先加在用

逻辑运算
& 有0则0 ∩      | 有1则1  ∪      ^(异或)  相同false  不同 true    false 是空集
短路逻辑运算符   && 判断第一个有0直接返回0   ||同理    提高效率用的有概率不用判断第二个的boolean
![alt text](image-3.png)

int x= a>b ? a : b;  三元表达式

if elseif  else   是个整体分支语句 一个成立其他的都不执行   if if if 是互相独立的;
int x= 0;  
switch(x){
    case 1,2,3:
    sout("123");
    break;
    case 0;
    sout("0")
    break;
    default:
    sout("...")
    break;
}


![alt text](image-4.png)

栈;

![alt text](image-5.png)


循环判断条件写开头 i++写结尾  写开头的好处是判断还用不用执行下次循环  i初值为0结尾写可以用数轴的点线段来考虑如何计数   这个处理方式 和for的一样
while(){

    ++;
}                   括号里取反 可加入break写入{}内达到相同的条件;
循环计数问题可以通过向量建立映射考虑 条件判断一定要写前边;![alt text](image-6.png)


循环的flag变量  可以boolean 或者int  boolean
Random r =new Random() 
int number =r.nextInt(10);  //左闭右开 0~9;
7~15   int number = r. nextInt(9);

随机数用向量考虑
12~43     ->   0~31     nexInt()+12
1.5~5.7  ->    0.0~4.2    nextdouble*4.2+1.5


基本数据类型和引用数据类型
引用数据类型:
int[] array=new int[] {1,2,3};
int[] array=new int[10]  10长度的空数组
int[] array= {1,2,3}
![alt text](image-7.png)
array.length





