#include <stdio.h>
#include <string.h>
void countConsecutiveChars(char *str) {
    int len = strlen(str);
    int count = 1, i, flag=0;
    
    // 按原始顺序统计重复字符
    printf("%c", str[0]);
    for (i = 1; i < len; i++) {
        if (str[i] == str[i-1]) {
            count++;
        } 
		else 
		{
            if (count > 1) 
			{
                printf("%d", count);
            }
            printf("%c", str[i]);
            count = 1;
        }
    }
    
    if (count > 1) {
        printf("%d", count);
    }
    
    printf("\n");
	
}

void sortChars(char *str) {
    int len = strlen(str),i,j;
    
    // 对字符串进行排序
    for (i = 0; i < len - 1; i++) {
        for (j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    
    countConsecutiveChars(str);
}

int main() {
    char str[501];
    scanf("%s", str);

    countConsecutiveChars(str);
    
    sortChars(str);
    
    return 0;
}
