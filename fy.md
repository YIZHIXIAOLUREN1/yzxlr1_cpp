作为C++竞赛选手，转型C语言期中考完全没问题！我来帮你快速掌握重点内容。

## 1. printf 格式化输出详解

### 基本格式：
```c
int printf(const char *format, ...);
```

### 常用格式说明符：
```c
#include <stdio.h>

int main() {
    int a = 10;
    float b = 3.14159;
    char c = 'A';
    char str[] = "Hello";
    
    // 整数输出
    printf("十进制: %d\n", a);        // 10
    printf("八进制: %o\n", a);        // 12
    printf("十六进制: %x\n", a);      // a (小写)
    printf("十六进制: %X\n", a);      // A (大写)
    
    // 浮点数输出
    printf("浮点数: %f\n", b);        // 3.141590
    printf("科学计数法: %e\n", b);    // 3.141590e+00
    printf("自动选择: %g\n", b);      // 3.14159
    
    // 字符和字符串
    printf("字符: %c\n", c);          // A
    printf("字符串: %s\n", str);      // Hello
    
    // 指针
    printf("指针: %p\n", &a);
    
    return 0;
}
```

### 格式化修饰符：
```c
int main() {
    int num = 123;
    double pi = 3.1415926535;
    
    // 宽度和对齐
    printf("右对齐: |%5d|\n", num);     // |  123|
    printf("左对齐: |%-5d|\n", num);    // |123  |
    
    // 精度控制
    printf("浮点精度: %.2f\n", pi);     // 3.14
    printf("字符串精度: %.3s\n", "Hello"); // Hel
    
    // 填充0
    printf("填充0: %05d\n", num);       // 00123
    
    // 组合使用
    printf("组合: %-8.2f\n", pi);       // 3.14    (左对齐，宽度8，精度2)
    
    return 0;
}
```

## 2. string.h 字符串处理函数

### 常用函数速查：

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[20] = "Hello";
    char str2[20] = "World";
    char str3[20];
    char str4[] = "Hello,World,Test";
    
    // strlen - 字符串长度
    printf("str1长度: %zu\n", strlen(str1));  // 5
    
    // strcpy - 字符串复制
    strcpy(str3, str1);
    printf("复制后: %s\n", str3);  // Hello
    
    // strncpy - 安全复制
    strncpy(str3, str1, sizeof(str3)-1);
    str3[sizeof(str3)-1] = '\0';
    
    // strcat - 字符串连接
    strcat(str1, " ");
    strcat(str1, str2);
    printf("连接后: %s\n", str1);  // Hello World
    
    // strcmp - 字符串比较
    printf("比较结果: %d\n", strcmp("abc", "abd"));  // -1 (小于)
    printf("比较结果: %d\n", strcmp("abc", "abc"));  // 0 (等于)
    printf("比较结果: %d\n", strcmp("abd", "abc"));  // 1 (大于)
    
    // strchr - 查找字符
    char *pos = strchr("Hello", 'l');
    if(pos) printf("找到字符位置: %ld\n", pos - "Hello");  // 2
    
    // strstr - 查找子串
    pos = strstr("Hello World", "World");
    if(pos) printf("找到子串: %s\n", pos);  // World
    
    // strtok - 字符串分割
    char copy[50];
    strcpy(copy, str4);
    char *token = strtok(copy, ",");
    while(token) {
        printf("分割: %s\n", token);
        token = strtok(NULL, ",");
    }
    
    // memset - 内存设置
    char buffer[10];
    memset(buffer, 'A', 9);
    buffer[9] = '\0';
    printf("memset后: %s\n", buffer);  // AAAAAAAA
    
    // memcpy - 内存复制
    char src[] = "Source";
    char dest[10];
    memcpy(dest, src, strlen(src)+1);
    printf("memcpy后: %s\n", dest);  // Source
    
    return 0;
}
```

## 3. 其他重要头文件

### math.h - 数学函数
```c
#include <stdio.h>
#include <math.h>

int main() {
    double x = 4.0, y = 2.0;
    
    printf("平方根: %.2f\n", sqrt(x));      // 2.00
    printf("幂运算: %.2f\n", pow(x, y));    // 16.00
    printf("自然对数: %.2f\n", log(x));     // 1.39
    printf("以10为底对数: %.2f\n", log10(x)); // 0.60
    printf("绝对值: %.2f\n", fabs(-3.14));  // 3.14
    printf("向上取整: %.2f\n", ceil(3.14)); // 4.00
    printf("向下取整: %.2f\n", floor(3.14)); // 3.00
    printf("三角函数sin: %.2f\n", sin(3.14/2)); // 1.00
    
    return 0;
}
```

### stdlib.h - 标准库函数
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // 内存分配
    int *arr = (int*)malloc(5 * sizeof(int));
    for(int i = 0; i < 5; i++) arr[i] = i;
    free(arr);
    
    // 类型转换
    printf("字符串转整数: %d\n", atoi("123"));     // 123
    printf("字符串转浮点: %.2f\n", atof("3.14")); // 3.14
    
    // 随机数
    srand(time(NULL));  // 设置种子
    printf("随机数: %d\n", rand() % 100);  // 0-99的随机数
    
    // 系统命令
    system("pause");  // Windows下暂停
    
    return 0;
}
```

### ctype.h - 字符处理
```c
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 'A';
    
    printf("是大写字母吗? %d\n", isupper(ch));  // 1 (true)
    printf("是小写字母吗? %d\n", islower(ch));  // 0 (false)
    printf("是数字吗? %d\n", isdigit('5'));     // 1 (true)
    printf("是字母数字吗? %d\n", isalnum(ch));  // 1 (true)
    
    printf("转小写: %c\n", tolower(ch));        // a
    printf("转大写: %c\n", toupper('b'));       // B
    
    return 0;
}
```

### time.h - 时间函数
```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t now;
    struct tm *timeinfo;
    char buffer[80];
    
    // 获取当前时间
    time(&now);
    timeinfo = localtime(&now);
    
    // 格式化时间
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    printf("当前时间: %s\n", buffer);
    
    // 计算时间差
    time_t start = time(NULL);
    // 模拟一些操作
    for(int i = 0; i < 1000000; i++);
    time_t end = time(NULL);
    printf("执行时间: %.2f秒\n", difftime(end, start));
    
    return 0;
}
```

## 4. C vs C++ 重要区别

```c
// C语言注意事项：
#include <stdio.h>  // 不是<iostream>
#include <stdlib.h> // 不是<cstdlib>

// 没有namespace
// 没有cout/cin，使用printf/scanf
// 没有bool类型（C99前），用int代替
// 没有引用，只有指针
// 没有new/delete，用malloc/free
// 没有string类，用char数组
// 函数必须声明返回类型

int main() {
    // 变量声明必须在代码块开头（C89标准）
    int a = 10;
    printf("%d\n", a);
    return 0;
}
```

## 5. 期中考常见题型

### 字符串操作题：
```c
// 实现字符串反转
void reverse_string(char *str) {
    if(!str) return;
    char *end = str;
    while(*end) end++;
    end--;
    
    while(str < end) {
        char temp = *str;
        *str = *end;
        *end = temp;
        str++;
        end--;
    }
}
```

### 内存操作题：
```c
// 实现memcpy
void *my_memcpy(void *dest, const void *src, size_t n) {
    char *d = (char*)dest;
    const char *s = (const char*)src;
    for(size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
    return dest;
}
```

记住这些重点，期中考就没问题了！需要我详细讲解哪个部分吗？