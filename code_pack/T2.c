#include <stdio.h>
void get_record(int (*a)[5], int rows, int id, int out[5]){int i; for(i = 0; i < rows; ++i){if(a[i][0] == id){int j; for(j = 0; j < 5; ++j) out[j] = a[i][j]; return;}} out[0] = -1;}
void print_record(int rec[5]){if(rec[0] == -1){printf("NA\n"); return;} int i; printf("%d", rec[0]); for(i = 1; i < 5; ++i) printf(" %d", rec[i]); printf("\n");}
int main(){int a[3][5] = {{1001, 90, 85, 88, 92}, {1002, 76, 80, 79, 81}, {1003, 99, 97, 95, 93}}; int id; scanf(" %d", &id); int rec[5]; get_record(a, 3, id, rec); print_record(rec); return 0;}
#include <stdio.h>

// 函数原型
int* find_student_grades(int (*grades)[5], int num_students, int student_id);
void print_student_record(int *student_record);

/**
 * @brief 根据学号查找学生的成绩记录
 * @param grades 指向成绩表的指针，每行5个元素（学号 + 4门课）
 * @param num_students 学生总数
 * @param student_id 要查找的学号
 * @return 如果找到，返回指向该学生记录（一行）的指针；否则返回NULL
 */
int* find_student_grades(int (*grades)[5], int num_students, int student_id)
{
    for (int i = 0; i < num_students; ++i)
    {
        // 使用指针访问学号 grades[i][0]
        if (*(*(grades + i)) == student_id)
        {
            return *(grades + i); // 返回指向该学生记录的指针
        }
    }
    return NULL; // 未找到
}

/**
 * @brief 打印单个学生的学号和成绩
 * @param student_record 指向单个学生记录的指针（包含5个整数的数组）
 */
void print_student_record(int *student_record)
{
    if (student_record == NULL)
    {
        printf("Invalid student record.\n");
        return;
    }
    printf("Student ID: %d, Grades: %d, %d, %d, %d\n",
           *(student_record + 0),
           *(student_record + 1),
           *(student_record + 2),
           *(student_record + 3),
           *(student_record + 4));
}

int main()
{
    // 示例数据：3个学生，每人4门课
    // 每行第一个是学号
    int student_grades[3][5] = {
        {101, 88, 76, 92, 85},
        {102, 91, 89, 94, 88},
        {103, 78, 85, 80, 90}
    };

    int student_id_to_find;
    int *found_record;

    // 测试1：查找存在的学生
    printf("Enter student ID to find: ");
    scanf("%d", &student_id_to_find);

    found_record = find_student_grades(student_grades, 3, student_id_to_find);

    if (found_record != NULL)
    {
        printf("Found student record:\n");
        print_student_record(found_record);
    }
    else
    {
        printf("Student with ID %d not found.\n", student_id_to_find);
    }

    // 测试2：打印第一个学生的成绩
    printf("\nPrinting the first student's record directly:\n");
    print_student_record(student_grades[0]);

    return 0;
}
