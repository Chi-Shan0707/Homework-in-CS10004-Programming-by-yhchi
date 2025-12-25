//name、phone_number、address；
#include<stdio.h>
struct Contact
{
    char name[20];
    char phone_number[15];
    char address[50];
};
typedef struct Contact Cont;
void add(Cont contacts[],const Cont c,int *pn)
{
    ++(*pn);
    contacts[*pn]=c;
    return;
}
void query(const Cont contacts[],int id,const int *pn)
{
    if(id<1 || id>(*pn))
    {
        printf("Invalid ID\n");
        return;
    }
    printf("Name: %s\nPhone Number: %s\nAddress: %s\n", contacts[id].name, contacts[id].phone_number, contacts[id].address);
}
int main()
{
    int op;
    int n;
    Cont contacts[100];
    while(1)
    {
        printf("Input an op:\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            {
                /*
                大括号 {} 只是多了一层“块作用域”，里面可以单独定义变量，不会和别的 case 冲突，比如：
                */
                Cont c;
                printf("Input name, phone number, address:\n");
                scanf("%s %s %s", c.name, c.phone_number, c.address);
//                printf("Name: %s\nPhone Number: %s\nAddress: %s\n", c.name, c.phone_number, c.address);
                add(contacts,c,&n);
                break;
            }
            case 2:
            {
                int id;
                scanf("%d", &id); 
                query(contacts, id, &n);
                break;
            }
            default:
            {
                printf("Invalid operation\n");
                break;
            }
        }
    }
    return 0;
}