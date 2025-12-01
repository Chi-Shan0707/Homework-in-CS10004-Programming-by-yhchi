#include <stdio.h>
int add(int a, int b){return a + b;}
int sub(int a, int b){return a - b;}
int mul(int a, int b){return a * b;}
int divi(int a, int b){return b == 0 ? 0 : a / b;}
int exec_calc(int a, int b, int (*operation)(int, int)){return operation(a, b);} 
int main(){
int a, b, c;
printf("1 add\n2 sub\n3 mul\n4 div\n");
scanf(" %d %d %d", &a, &b, &c);
int (*op)(int, int) = 0;
if(c == 1) op = add; else if(c == 2) op = sub; else if(c == 3) op = mul; else op = divi;
int r = exec_calc(a, b, op);
printf("%d\n", r);
return 0;
}
#include <stdio.h>

// 函数原型
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
void execute(int a, int b, int (*operation)(int, int));

// 加法
int add(int a, int b){
    return a + b;
}

// 减法
int subtract(int a, int b){
    return a - b;
}

// 乘法
int multiply(int a, int b){
    return a * b;
}

// 除法
int divide(int a, int b){
    if (b == 0){
        printf("Error: Division by zero!\n");
        return 0; // 返回0作为错误指示
    }
    return a / b;
}

// 执行函数，通过函数指针调用具体运算
void execute(int a, int b, int (*operation)(int, int)){
    int result = operation(a, b);
    // 对于除法错误，divide函数内部已经打印信息，这里不再重复打印结果
    if (operation != divide || b != 0){
        printf("Result: %d\n", result);
    }
}

int main(){
    int a, b, choice;
    int (*operation_ptr)(int, int); // 定义一个函数指针

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("\nSelect an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice){
        case 1:
            operation_ptr = add;
            break;
        case 2:
            operation_ptr = subtract;
            break;
        case 3:
            operation_ptr = multiply;
            break;
        case 4:
            operation_ptr = divide;
            break;
        default:
            printf("Invalid choice.\n");
            return 1; // 退出程序
    }

    // 调用execute函数，并将选定的函数指针作为参数
    execute(a, b, operation_ptr);

    return 0;
}
