#include <stdio.h>
void squeeze(char *s, const char *t) {
    char *read = s;  // 读指针，用于遍历 s
    char *write = s; // 写指针，用于重写 s
    const char *p;   // 临时指针，用于遍历 t
    int found;       // 标记是否找到

    while (*read != '\0') {
        found = 0;
        // 遍历 t，检查当前字符 *read 是否存在于 t 中
        for (p = t; *p != '\0'; p++) {
            if (*read == *p) {
                found = 1;
                break; // 找到了，不需要继续检查 t
            }
        }

        // 如果当前字符不在 t 中，则保留它
        if (!found) {
            *write = *read;
            write++; // 写指针向后移动
        }
        
        read++; // 读指针始终向后移动
    }

    // 关键步骤：在新的结尾处添加字符串结束符
    *write = '\0';
}

int main() {
    // 定义测试样例
    char s[] = "ABCXABCZABC";
    
    printf("原始字符串: %s\n", s);
    
    // 调用函数，删除 'A' 和 'C'
    squeeze(s, "AC");
    
    printf("处理后结果: %s\n", s);

    return 0;
}