#include <stdio.h>  
#include <stdlib.h>  
#include <string.h> 
//歌曲信息包括：歌名、演唱者、作词、作曲、所属专辑、出版时间、出版公司  
typedef struct music  
{  
    char name[20];    //歌名  
    char singer[20];  //演唱者  
    char authors[20]; //作词  
    char compose[30]; //作曲  
    char album[20];   //所属专辑  
    char time[15];    //出版时间  
    char company[30]; //出版公司  
    struct music *next;  
}music;  
music *head=NULL;  
int length;   //链表的长度  
void create()  
{  
    music *p1,*p2;  
    length=0;  
    p1=(music *)malloc(sizeof(music));  
    strcpy(p1->name,"-1");  
    if(head==NULL)  
        head=p1;  
    printf("请输入音乐的歌名、演唱者、作词、作曲、所属专辑、出版时间、出版公司：/n");  
    while(1)  //歌名为0的时候退出  
    {  
        p2=(music *)malloc(sizeof(music));  
        //输入歌曲信息  
        scanf("%s %s %s %s %s %s %s",p2->name,p2->singer,p2->authors,p2->compose,p2->album,p2->time,p2->company);  
        if(strcmp(p2->name,"0")==0)  
        {  
            printf("链表创建完成！/n");  
            break;  
        }  
        length++; //链表的长度  
        p1->next=p2;  
        p2->next=NULL;  
        p1=p1->next;  
    }  
    return ;  
}  
void ModifymusicInfo()  
{  
    music *p=head->next;  
    char name[20];  
    printf("请输入要修改的歌曲的歌名：");  
    getchar();  
    scanf("%s",name);  
    while(p!=NULL)  
    {  
        if(strcmp(p->name,name)==0)  
        {  
            printf("修改前，歌名为%s的歌曲的信息如下：/n",name);  
            printf("音乐的歌名、演唱者、作词、作曲、所属专辑、出版时间、出版公司：/n");  
            printf("%s %s %s %s %s %s %s/n",p->name,p->singer,p->authors,p->compose,p->album,p->time,p->company);  
            printf("请输入歌曲的新的所属专辑：");  
            getchar();  
            scanf("%s",p->album);  
            printf("请输入歌曲的新出版公司：");  
            getchar();  
            scanf("%s",p->company);  
            printf("修改后，歌名为%s的歌曲的信息如下：/n",name);  
            printf("音乐的歌名、演唱者、作词、作曲、所属专辑、出版时间、出版公司：/n");  
            printf("%s %s %s %s %s %s %s/n",p->name,p->singer,p->authors,p->compose,p->album,p->time,p->company);  
            return ;  
        }  
        p=p->next;  
    }  
    if(p==NULL)  
    {  
        printf("该歌曲不存在！/n");  
        return ;  
    }  
}  
  
void display()  
{  
    music *p=head->next;  
    printf("链表中所有的歌曲信息如下:/n");  
    printf("音乐的歌名、演唱者、作词、作曲、所属专辑、出版时间、出版公司：/n");  
    while(p!=NULL)  
    {  
        printf("%s %s %s %s %s %s %s/n",p->name,p->singer,p->authors,p->compose,p->album,p->time,p->company);  
        p=p->next;  
    }  
    return ;  
}  
void search()  
{  
    int num,x,flag;  
    char name[20];  
    music *p=head->next;  
    printf("请选择查询的方式：/n");  
    printf("1、按歌名查询/t 2、按演唱者查询/n");  
    scanf("%d",&x);  
    if(x==1)  
    {  
        printf("需要查找的歌曲歌名为：");  
        getchar();  
        scanf("%s",name);  
        while(p!=NULL)  
        {  
  
            if(strcmp(p->name,name)==0)  
            {  
                printf("歌名为%s的歌曲的信息如下：/n",name);  
                printf("音乐的歌名、演唱者、作词、作曲、所属专辑、出版时间、出版公司：/n");  
                printf("%s %s %s %s %s %s %s/n",p->name,p->singer,p->authors,p->compose,p->album,p->time,p->company);  
                return ;  
            }     
            p=p->next;  
        }  
        if(p==NULL)  
            printf("没有这首歌曲的记录！/n");  
    }  
    else if(x==2)  
    {  
        flag=0;  
        printf("需要查找的演唱者为：");  
        getchar();  
        scanf("%s",name);  
        p=head->next;  
        while(p!=NULL)  
        {  
            if(strcmp(p->singer,name)==0)  
            {  
                if(flag==0)  
                {  
                    printf("演唱者为%s的歌曲的信息如下：/n",name);  
                    printf("音乐的歌名、演唱者、作词、作曲、所属专辑、出版时间、出版公司：/n");  
                    flag=1;  
                }  
                printf("%s %s %s %s %s %s %s/n",p->name,p->singer,p->authors,p->compose,p->album,p->time,p->company);  
            }     
            p=p->next;  
        }  
        if(p==NULL && flag==0)  
        {  
            printf("没有该演唱者的歌曲记录！/n");  
            return;  
        }  
    }  
    return ;  
}  
  
void insert()  
{  
    int num,i;  
    music *p,*q;  
    p=head;  
  
    printf("请输入你要插入位置: ");  
    scanf("%d",&num);  
    if(num>length)  
    {  
        printf("找不到要插入的位置/n");  
        return ;  
    }  
    else  
    {  
        printf("请输入你要插入的音乐的歌名、演唱者、作词、作曲、所属专辑、出版时间、出版公司：/n");  
        q=(music *)malloc(sizeof(music));  
        //输入歌曲信息  
        scanf("%s %s %s %s %s %s %s",q->name,q->singer,q->authors,q->compose,q->album,q->time,q->company);  
        while(p!=NULL)  
        {  
            if(strcmp(p->name,q->name)==0)  
            {  
                printf("该歌曲已经存在，无法插入！/n");  
                return ;  
            }  
            p=p->next;  
        }  
        p=head;  
        for(i=0;i<num;i++)  
            p=p->next;  
        q->next=p->next;  
        p->next=q;  
        length++;  
        printf("插入成功！/n");  
        return ;  
    }  
}    
  
void Delete()  
{  
    char name[20];  
    music *p,*q;  
    q=head,p=head->next;  
    printf("请输入要删除的歌曲的歌名:/n");  
    getchar();  
    scanf("%s",name);  
  
    while(p!=NULL)  
    {  
        if(strcmp(p->name,name)==0)  
        {  
            q->next=p->next;  
            free(p);  
            length--;  
            printf("删除成功！/n");  
            return ;  
        }  
        p=p->next;  
        q=q->next;  
    }  
    if(p==NULL)  
    {  
        printf("找不到要删除的歌曲！/n");  
        return ;  
    }  
}  
void menu()  
{  
    printf("________________________________________________________________/n");  
    printf("|              歌厅歌曲管理系统                                |/n");  
    printf("|               0、 退出系统                                   |/n");  
    printf("|               1、 录入歌曲信息                               |/n");  
    printf("|               2、 显示歌曲信息                               |/n");  
    printf("|               3、 查找链表中的某一首歌曲                     |/n");  
    printf("|               4、 删除链表中指定歌曲                         |/n");  
    printf("|               5、 指定的位置上插入一个新结点                 |/n");  
    printf("|               6、 修改歌曲信息                               |/n");  
    printf("________________________________________________________________/n");  
    return ;  
}  
int main(void)  
{  
    int a;  
    menu();  
    while(1)  
    {  
        printf("请选择相应的功能：");  
        scanf("%d",&a);  
        switch(a)  
        {  
        case 0:  
            return 0;  
        case 1:  
            create();  
            menu();  
            break;  
        case 2:  
            if(head)  
            {  
                display();  
                menu();  
            }  
            else  
            {  
                printf("链表为空，请先建立链表！/n");  
                menu();  
            }  
            break;  
        case 3:  
            if(head)  
            {  
                search();  
                menu();  
            }  
            else  
            {  
                printf("链表为空，请先建立链表！/n");  
                menu();  
            }  
            break;  
        case 4:  
            if(head)  
            {  
                Delete();  
                menu();  
            }  
            else  
            {  
                printf("链表为空，请先建立链表！/n");  
                menu();  
            }  
            break;  
        case 5:  
            if(head)  
            {  
                insert();  
                menu();  
            }  
            else  
            {  
                printf("链表为空，请先建立链表！/n");  
                menu();  
            }  
            break;  
        case 6:  
            if(head)  
            {  
                ModifymusicInfo();  
                menu();  
            }  
            else  
            {  
                printf("链表为空，请先建立链表！/n");  
                menu();  
            }  
            break;  
        default:  
            break;  
        }  
    }  
    system("pause");  
    return 0;  
}  
