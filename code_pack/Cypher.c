#include<stdio.h>
#include<string.h>

// 函数原型
char* encrypt(char* str);
char* decrypt(char* str);
void test(char* str);
int is_uppercase(const char ch){return 'A'<=ch&&ch<='Z';}
int is_lowercase(const char ch){return 'a'<=ch&&ch<='z';}
int is_digit(const char ch){return '0'<=ch&&ch<='9';}
char* encrypt(char* str)
{
    //加密
    int i=0;
    while(str[i]!='\0')
    {
        if(is_uppercase(str[i]))str[i]=(str[i] -'A'+3)%26+'A';
        else if(is_lowercase(str[i]))str[i]=(str[i] -'a'+5)%26+'a';
        else if (is_digit(str[i]))str[i]=(9-(str[i]-'0'))+'0';
        ++i;
    }
    return str;
}
// 解密函数
char* decrypt(char* str)
{

    int i=0;
    while(str[i]!='\0')
    {
        if(is_uppercase(str[i]))str[i]=(str[i] -'A'-3)%26+'A';
        else if(is_lowercase(str[i]))str[i]=(str[i] -'a'-5)%26+'a';
        else if (is_digit(str[i]))str[i]=(9-(str[i]-'0'))+'0';
        ++i;
    }
    return str;
}

// 测试函数
void test(char* str)
{
    char original_str[200];
    strcpy(original_str, str);
//crosscheck!!!!
    printf("Original text:\t\"%s\"\n", original_str);
//学会反斜杠输出"
    char* encrypted_str = encrypt(str);
    printf("Encrypted text:\t\"%s\"\n", encrypted_str);

    char* decrypted_str = decrypt(encrypted_str);
    printf("Decrypted text:\t\"%s\"\n", decrypted_str);

    printf("\n");
}

int main()
{
    char toy1[]="Hello123!";

    char toy2[]="1905Fudan@Shanghai2025";
    test(toy1);
    test(toy2);

    return 0;
}
