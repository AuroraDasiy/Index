# ReadMe
算法 数据结构 方面的注意事项 技巧 和数学有关的技巧等(Tips)不是具体的知识;实际编程语言的Tips不写入
# Tips
## 指针(地址)的思想去考率类和对象
## 递归思想 while !:
while(!boudary case){update;}  一直更新直到边界条件;
经典例子  while(b!=0){gcd(a,b)=gcd(b,a mod b) update;}

## flag标记变量
## 数组可以考虑成 正半轴,元素索引的右边一位就是前边所有元素的个数,例如{4,3,5,567,4}索引(2,5) 右边一共3个元素 size-index 就是index前边所有元素的个数;
## new
对某个对象进行操作的时候,最好把结果弄到一个new的对象上例如矩阵转置结果,new在一个新矩阵里否则原矩阵操作困难;
```
#include<stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);  // 输入矩阵的行数和列数
    int arr[n][m];            // 原矩阵
    int transpose[m][n];      // 转置矩阵

    // 读入原矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // 进行转置
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transpose[j][i] = arr[i][j];
        }
    }

    // 输出转置矩阵
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j == n - 1) {
                printf("%d\n", transpose[i][j]);  // 最后一项输出换行
            } else {
                printf("%d ", transpose[i][j]);  // 其他项输出空格
            }
        }
    }

    return 0;
}

```

## temp
交换两个数需用道中间变量temp;
## if 最好要有 else 否则 没返回值error
## arr[i++] 可以实现数组后缀添加;




# 数论("%"(mod) and /) 
## 进制(mod)
- 10进制转2进制;
```c
int main(){
	int n=23;int d=2;// d是进制数
	int arr[1001]={0};
	int i=0;
	while(n!=0){
		arr[i++]=n%d;   // mod 一次 进位一次 boundary case是0
		n=n/d;
	}
}
```
## 质分解
奇数的奇数分解一定是素分解
```
#include <stdio.h>

// 函数：质因数分解
void prime_factors(int n) {
    // 找出2的所有因子
    while (n % 2 == 0) {
        printf("2 ");
        n = n / 2;
    }

    // 找出奇数的因子
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
    }

    // 如果剩下的n是一个质数并大于2
    if (n > 2) {
        printf("%d", n);
    }
}

int main() {
    int num;
    
    // 用户输入
    printf("请输入一个整数：");
    scanf("%d", &num);

    // 质因数分解
    printf("质因数分解结果：");
    prime_factors(num);

    return 0;
}

```

## 辗转相除法 gcd 和 lcm
辗转相除法（也称为欧几里得算法）

**定理**：两个整数 \(a\) 和 \(b\) 的最大公约数等于 \(b\) 和 \(a \mod b\) 的最大公约数（这里 \(a \mod b\) 表示 \(a\) 除以 \(b\) 的余数）。

即：
\[
\text{GCD}(a, b) = \text{GCD}(b, a \mod b)
\]
这个过程会不断迭代，直到余数为 0，此时 \(b\) 就是 \(a\) 和 \(b\) 的最大公约数。

---

### **算法步骤**
1. 假设我们需要计算两个正整数 \(a\) 和 \(b\) 的最大公约数（假设 \(a > b\））。
2. 求 \(a \mod b\)。
3. 将 \(a\) 更新为 \(b\)，\(b\) 更新为 \(a \mod b\)。
4. 重复上述步骤，直到 \(b = 0\)。
5. 此时，\(a\) 的值就是最大公约数。

---

### **C语言实现**
以下是辗转相除法的 C 语言实现：

```c
#include <stdio.h>

// 函数定义：计算两个整数的最大公约数
int gcd(int a, int b) {
    while (b != 0) {  // 当 b 不为 0 时继续迭代
        int temp = a % b;  // 计算 a 除以 b 的余数
        a = b;             // 更新 a 为 b
        b = temp;          // 更新 b 为余数
    }
    return a;  // 当 b 为 0 时，a 即为最大公约数
}

int main() {
    int num1, num2;
    
    // 输入两个整数
    printf("请输入两个整数：");
    scanf("%d %d", &num1, &num2);
    
    // 调用 gcd 函数计算最大公约数
    int result = gcd(num1, num2);
    
    // 输出结果
    printf("最大公约数是：%d\n", result);
    
    return 0;
}
```

---

### **代码说明**
1. **函数 `gcd`**：
   - 输入两个整数 \(a\) 和 \(b\)。
   - 使用 `while` 循环不断计算 \(a \mod b\)，并更新 \(a\) 和 \(b\) 的值。
   - 当 \(b = 0\) 时，循环结束，此时 \(a\) 即为最大公约数。

2. **主函数 `main`**：
   - 通过 `scanf` 获取用户输入的两个整数。
   - 调用 `gcd` 函数计算最大公约数。
   - 使用 `printf` 输出结果。

---

### **运行示例**
假设输入两个整数 56 和 98：

```plaintext
请输入两个整数：56 98
最大公约数是：14
```

**过程分析**：
1. 初始值：\(a = 56\), \(b = 98\)。
2. 第一次迭代：\(a \mod b = 56 \mod 98 = 56\)，更新为 \(a = 98\), \(b = 56\)。
3. 第二次迭代：\(a \mod b = 98 \mod 56 = 42\)，更新为 \(a = 56\), \(b = 42\)。
4. 第三次迭代：\(a \mod b = 56 \mod 42 = 14\)，更新为 \(a = 42\), \(b = 14\)。
5. 第四次迭代：\(a \mod b = 42 \mod 14 = 0\)，更新为 \(a = 14\), \(b = 0\)。
6. 结束：此时 \(b = 0\)，最大公约数为 \(a = 14\)。

---

### **递归实现**
辗转相除法也可以用递归方式实现：

```c
#include <stdio.h>

// 递归函数定义
int gcd(int a, int b) {
    if (b == 0) {
        return a;  // 当 b 为 0 时，a 即为最大公约数
    }
    return gcd(b, a % b);  // 递归调用
}

int main() {
    int num1, num2;
    
    // 输入两个整数
    printf("请输入两个整数：");
    scanf("%d %d", &num1, &num2);
    
    // 调用 gcd 函数计算最大公约数
    int result = gcd(num1, num2);
    
    // 输出结果
    printf("最大公约数是：%d\n", result);
    
    return 0;
}
```
在 C 语言中，可以通过 **最大公约数（GCD）** 来计算 **最小公倍数（LCM）**。公式如下：

\[
\text{LCM}(a, b) = \frac{|a \cdot b|}{\text{GCD}(a, b)}
\]

以下是一个完整的 C 语言实现，用于计算两个正整数的最小公倍数。

### 代码实现

```c
#include <stdio.h>

// 求最大公约数（使用欧几里得算法）
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 求最小公倍数
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b; // 防止溢出，先除以 gcd
}

int main() {
    int num1, num2;
    
    // 输入两个正整数
    printf("请输入两个正整数：");
    scanf("%d %d", &num1, &num2);

    if (num1 <= 0 || num2 <= 0) {
        printf("输入的数字必须是正整数！\n");
        return 1;
    }

    // 计算并输出最小公倍数
    int result = lcm(num1, num2);
    printf("最小公倍数是：%d\n", result);

    return 0;
}
```

---

### 代码说明

1. **最大公约数函数 `gcd`**:
   - 使用 **欧几里得算法** 计算两个数的最大公约数。
   - 算法的核心是：\(\text{GCD}(a, b) = \text{GCD}(b, a \% b)\)，直到 \(b = 0\) 时，\(a\) 即为最大公约数。

2. **最小公倍数函数 `lcm`**:
   - 根据公式 \(\text{LCM}(a, b) = \frac{|a \cdot b|}{\text{GCD}(a, b)}\) 计算最小公倍数。
   - 为了防止整数溢出，先将 \(a\) 除以 \(\text{GCD}(a, b)\)，再乘以 \(b\)。

3. **主函数 `main`**:
   - 提示用户输入两个正整数。
   - 检查输入是否合法（正整数）。
   - 调用 `lcm` 函数计算最小公倍数，并输出结果。

---

### 示例运行

#### 输入：
```
请输入两个正整数：12 18
```

#### 输出：
```
最小公倍数是：36
```

#### 输入：
```
请输入两个正整数：7 5
```

#### 输出：
```
最小公倍数是：35
``` 

---

### 注意事项
1. 输入的数必须是正整数，代码中已做简单的输入检查。
2. 如果需要支持更大的数，建议使用 64 位整数（`long long`）。

## 判断素数
判断素数用开方优化 mod 一定要考虑边界条件 2等
```int jug(int ipt){
	if(ipt==2) return 1;
	int flag=0;
	for(int i=2;i<=sqrt(ipt);i++){
		if(ipt % i==0) return 0;
		else{continue;
	}
	}return 1;
} 
```
还有一种 6k+-1的算法太难先不学  








---


















# 线性代数(向量)

## 两数最值的向量表示
```
int max=(a+b+abs(a-b))/2;
int min=(a+b-abs(a-b))/2;
```


# 分析学(Function)
## 数组映射(自然数集)
### 统计字符串字母出现次数
```
#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	char ipt;
	int arr[1001]={0};
	char str[1001]="abc";
//	scanf()
	for(int i=0;i<strlen(str);i++){
		arr[str[i]]+=1;
	}
	printf("%d %d %d",arr[97],strlen(str),(int)'A');
}

String str=new String("abc");
        int[] arr=new int[1001];
        for(int i=0;i<str.length();i++){
            arr[(int)str.charAt(i)]+=1;
        }
        Scanner sc=new Scanner(System.in);
        String x=sc.nextLine();
        System.out.println(arr[(int)x.charAt(0)]);
```
