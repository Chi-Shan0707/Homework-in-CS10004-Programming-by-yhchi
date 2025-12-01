#include <stdio.h>
#include <string.h>
char *encrypt(char *s){int i; for(i = 0; s[i]; ++i){char c = s[i]; if(c >= 'A' && c <= 'Z'){c = (char)('A' + (c - 'A' + 3) % 26);} else if(c >= 'a' && c <= 'z'){c = (char)('a' + (c - 'a' + 5) % 26);} else if(c >= '0' && c <= '9'){c = (char)('0' + (9 - (c - '0')));} s[i] = c;} return s;}
char *decrypt(char *s){int i; for(i = 0; s[i]; ++i){char c = s[i]; if(c >= 'A' && c <= 'Z'){c = (char)('A' + (c - 'A' - 3 + 26) % 26);} else if(c >= 'a' && c <= 'z'){c = (char)('a' + (c - 'a' - 5 + 26) % 26);} else if(c >= '0' && c <= '9'){c = (char)('0' + (9 - (c - '0')));} s[i] = c;} return s;}
void test(char *str){char a[1024], b[1024]; strncpy(a, str, 1023); a[1023] = '\0'; strncpy(b, str, 1023); b[1023] = '\0'; encrypt(a); printf("%s\n", a); decrypt(a); printf("%s\n", a); encrypt(b); printf("%s\n", b); decrypt(b); printf("%s\n", b);} 
int main(){char s[1024]; if(fgets(s, sizeof(s), stdin)){s[strcspn(s, "\n")] = '\0'; char t[1024]; strncpy(t, s, 1023); t[1023] = '\0'; printf("%s\n", encrypt(s)); printf("%s\n", decrypt(s)); test("Hello123!"); test("1905Fudan@Shanghai2025");}
return 0;}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 函数原型
char* encrypt(char* str);
char* decrypt(char* str);
void test(char* str);

// 加密函数
char* encrypt(char* str){
    int i = 0;
    while (str[i] != '\0'){
        if (isupper(str[i])){
            str[i] = (str[i] - 'A' + 3) % 26 + 'A';
        } else if (islower(str[i])){
            str[i] = (str[i] - 'a' + 5) % 26 + 'a';
        } else if (isdigit(str[i])){
            str[i] = (9 - (str[i] - '0')) + '0';
        }
        i++;
    }
    return str;
}

// 解密函数
char* decrypt(char* str){
    int i = 0;
    while (str[i] != '\0'){
        if (isupper(str[i])){
            str[i] = (str[i] - 'A' - 3 + 26) % 26 + 'A';
        } else if (islower(str[i])){
            str[i] = (str[i] - 'a' - 5 + 26) % 26 + 'a';
        } else if (isdigit(str[i])){
            str[i] = (9 - (str[i] - '0')) + '0'; // 数字的解密规则和加密相同
        }
        i++;
    }
    return str;
}

// 测试函数
void test(char* str){
    char original_str[200];
    strcpy(original_str, str); // 保存原始字符串

    printf("Original:  \"%s\"\n", original_str);

    // 加密并打印
    char* encrypted_str = encrypt(str);
    printf("Encrypted: \"%s\"\n", encrypted_str);

    // 解密并打印
    char* decrypted_str = decrypt(encrypted_str);
    printf("Decrypted: \"%s\"\n", decrypted_str);
    printf("\n");
}

int main(){
    char test_str1[] = "Hello123!";
    char test_str2[] = "1905Fudan@Shanghai2025";

    test(test_str1);
    test(test_str2);

    return 0;
}
