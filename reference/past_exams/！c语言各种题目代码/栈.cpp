#include <stdio.h>
#include <string.h>

void removeAdjacentDuplicates(char* s) {
    int n = strlen(s);
    int top = -1; // 栈顶指针
    for (int i = 0; i < n; i++) {
        if (top == -1 || s[i] != s[top]) {
            // 当前字符与栈顶字符不相同，压入栈中
            top++;
            s[top] = s[i];
        } else {
            // 当前字符与栈顶字符相同，弹出栈顶字符
            top--;
        }
    }
    // 栈中剩下的字符即为结果
    s[top + 1] = '\0'; // 添加字符串结束符
}

int main() {
    char s1[100];
    gets(s1);
    removeAdjacentDuplicates(s1);
    puts(s1);

    return 0;
}

