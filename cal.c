#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct polynode{
	int coef;
	int exp;
	struct polynode* next;
}Node;

int Locate(Node* L,int e){
	Node* q;
	q=L;
	while(q->next!=NULL&&q->exp!=e){
		q=q->next;
	}
	if(q->next==NULL)return 1;
	else return 0;
}

int compare(int a,int b){
	if(a>b)return 1;
	else if(a==b)return 0;
	else return -1;
}

Node* Create(){
	Node* L,* y;
	Node* p,* q,* s;
	int c,e,n,i;
	i=1;
	printf("输入多项式项数：");
	scanf("%d",&n);
	L=(Node* )malloc(sizeof(Node));
	L->next=NULL;L->coef=0;L->exp=-1;
	y=(Node *)malloc(sizeof(Node));
	printf("输入常数项，没有的输入0：");
	scanf("%d",&y->coef);
	y->exp=0;
	L->next=y;y->next=NULL;
	p=y;
	while(i<=n){
		printf("输入系数%d:",i);
		scanf("%d",&c);
		printf("输入指数%d:",i);
		scanf("%d",&e);
		
		if(e==0){
			do{
			printf("输入有误！已输入过常数项，请输入非常数项：");
			printf("输入系数%d:",i);
		    scanf("%d",&c);
		    printf("输入指数%d:",i);
		    scanf("%d",&e);
			}while(e==0);
		}

		if(Locate(L,e)==0){
			do{
				printf("以输入过该指数，请重新输入不同指数：");
				scanf("%d",&e);
			}while(Locate(L,e)==0);
		}
		
		q=(Node* )malloc(sizeof(Node));	
		q->coef=c;
		q->exp=e;
		s=L;
		while(s->next!=NULL&&s->next->exp<e){
			s=s->next;
		}
		if(s->next==NULL){
			s->next=q;
			q->next=NULL;
		}
		else{
			q->next=s->next;
			s->next=q;
		}
		i=i+1;
	}
	printf("多项式建立成功！\n");
	return L;
}

int OutPut(Node* L){
	Node* p,* q;
	p=L->next;
	if(p->coef!=0){
		printf("%d",p->coef);
		p=p->next;
		while(p!=NULL){
			if(p->coef!=0){
				if(p->coef!=1&&p->exp!=1){
				printf("+%d",p->coef);
			    printf("x^%d",p->exp);
				}
				else if(p->exp!=1&&p->coef==1){printf("+x^%d",p->exp);}
				else if(p->coef!=1&&p->exp==1){
					printf("%d",p->coef);
					printf("+x",p->exp);}
				else printf("+x");
			}
			p=p->next;
		}
	}
	else{
		p=L->next;
		while(p!=NULL&&p->coef==0){
			p=p->next;
		}
		if(p==NULL)printf("0");
		else{
			if(p->coef!=1&&p->exp!=1){
			    printf("%d",p->coef);
			    printf("x^%d",p->exp);
			}
			else if(p->exp!=1){printf("x^%d",p->exp);}
			else if(p->coef!=1){
				printf("%d",p->coef);
				printf("x");}
			else printf("x");
		p=p->next;
			//printf("%d",p->coef)
		while(p!=NULL){
			  if(p->coef!=0){
				  if(p->coef!=1&&p->exp!=1){
			         printf("+%d",p->coef);
			         printf("x^%d",p->exp);
			       }
			      else if(p->exp!=1){printf("+x^%d",p->exp);}
				  else if(p->coef!=1){
					  printf("%d",p->coef);
					  printf("x");}
				  else{printf("x");}
			   }
			p=p->next;
		   }
		}
	}
	printf("\n");
	return 1;
}

int Insert(Node* L,int c,int e){
	Node* q,* s;
	q=(Node* )malloc(sizeof(Node));
	q->coef=c;q->exp=e;
	s=L;
	while(s->next!=NULL&&s->next->exp<e){
			s=s->next;
		}
	if(s->next==NULL){
		s->next=q;
		q->next=NULL;
	}
	else{
		q->next=s->next;
		s->next=q;
		}
	return 1;
}

Node* Add(Node* L1,Node* L2){
   Node* p1,* p2,* p,* a1,* a2;
   a1=L1;a2=L2;
   p1=L1->next;p2=L2->next;
   while(p1!=NULL&&p2!=NULL){
	   switch(compare(p1->exp,p2->exp)){
		  case 0:
			     p1->coef=p1->coef+p2->coef;
				 a1=p1;a2=p2;
				 p1=p1->next;p2=p2->next;
				 break;
		  case 1:
			     Insert(L1,p2->coef,p2->exp);
			     p=p2->next;
				 free(a2);
				 a2=p2;
				 p2=p;
				 break;
		  case -1:
			     a1=p1;
			     p1=p1->next;
				 break;
	   }
	}
   	if(a2!=NULL){
		   a1->next=p2;
		   free(a2);
    }
	OutPut(L1);
    return L1;
}

Node* Minor(Node* L1,Node* L2){
   Node* p1,* p2,* p,* a1,* a2,* s;
   s=L2;
   while(s!=NULL){
	   s->coef=-s->coef;
	   s=s->next;
   }
   OutPut(L2);
   a1=L1;a2=L2;
   p1=L1->next;p2=L2->next;
   while(p1!=NULL&&p2!=NULL){
	   switch(compare(p1->exp,p2->exp)){
		  case 0:
			     p1->coef=p1->coef+p2->coef;
				 a1=p1;a2=p2;
				 p1=p1->next;p2=p2->next;
				 break;
		  case 1:
			     Insert(L1,p2->coef,p2->exp);
			     p=p2->next;
				 free(a2);
				 a2=p2;
				 p2=p;
				 break;
		  case -1:
			     a1=p1;
			     p1=p1->next;
				 break;
	   }
	}
   	if(a2!=NULL){
		   a1->next=p2;
		   free(a2);
    }
	OutPut(L1);
    return L1;
}

void menu(){
     system("cls");
	 printf("\t|=======================================================|\t\n");
	 printf("\t|                                                       |\t\n");
	 printf("\t|                       多项式计算器                    |\t\n");
	 printf("\t|                                                       |\t\n");
	 printf("\t|=======================================================|\t\n");
	 printf("\n\t【1】输入多项式\t\t\t【2】输出多项式\n");
	 printf("\n\t【3】多项式加法\t\t\t【4】多项式减法\n");
	 printf("\n\t【0】退出程序\n");
}

int main()
{
	int a;
	Node* L,* L1,* L2;
	system("color 8F");
	while(1){
		menu();
		printf("\n\n\t\t\t请选择操作：");
		scanf("%d",&a);
		switch(a){
		case 1: L=Create();
                system("pause");
				break;
		case 2: if(L==NULL)
			    {
					printf("错误！没有输入过多项式");
			        L=Create();
				}
			    OutPut(L);
			    system("pause");
				break;
		case 3: L1=Create();
			    OutPut(L1);
			    L2=Create();
				OutPut(L2);
				Add(L1,L2);
				system("pause");
				break;
		case 4: L1=Create();
       			OutPut(L1);
				L2=Create();
				OutPut(L2);
				Minor(L1,L2);
			    system("pause");
				break;
		default:
			    printf("退出");
			    return 1;
		}
		}

}#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct polynode{
	int coef;
	int exp;
	struct polynode* next;
}Node;

int Locate(Node* L,int e){
	Node* q;
	q=L;
	while(q->next!=NULL&&q->exp!=e){
		q=q->next;
	}
	if(q->next==NULL)return 1;
	else return 0;
}

int compare(int a,int b){
	if(a>b)return 1;
	else if(a==b)return 0;
	else return -1;
}

Node* Create(){
	Node* L,* y;
	Node* p,* q,* s;
	int c,e,n,i;
	i=1;
	printf("输入多项式项数：");
	scanf("%d",&n);
	L=(Node* )malloc(sizeof(Node));
	L->next=NULL;L->coef=0;L->exp=-1;
	y=(Node *)malloc(sizeof(Node));
	printf("输入常数项，没有的输入0：");
	scanf("%d",&y->coef);
	y->exp=0;
	L->next=y;y->next=NULL;
	p=y;
	while(i<=n){
		printf("输入系数%d:",i);
		scanf("%d",&c);
		printf("输入指数%d:",i);
		scanf("%d",&e);
		
		if(e==0){
			do{
			printf("输入有误！已输入过常数项，请输入非常数项：");
			printf("输入系数%d:",i);
		    scanf("%d",&c);
		    printf("输入指数%d:",i);
		    scanf("%d",&e);
			}while(e==0);
		}

		if(Locate(L,e)==0){
			do{
				printf("以输入过该指数，请重新输入不同指数：");
				scanf("%d",&e);
			}while(Locate(L,e)==0);
		}
		
		q=(Node* )malloc(sizeof(Node));	
		q->coef=c;
		q->exp=e;
		s=L;
		while(s->next!=NULL&&s->next->exp<e){
			s=s->next;
		}
		if(s->next==NULL){
			s->next=q;
			q->next=NULL;
		}
		else{
			q->next=s->next;
			s->next=q;
		}
		i=i+1;
	}
	printf("多项式建立成功！\n");
	return L;
}

int OutPut(Node* L){
	Node* p,* q;
	p=L->next;
	if(p->coef!=0){
		printf("%d",p->coef);
		p=p->next;
		while(p!=NULL){
			if(p->coef!=0){
				if(p->coef!=1&&p->exp!=1){
				printf("+%d",p->coef);
			    printf("x^%d",p->exp);
				}
				else if(p->exp!=1&&p->coef==1){printf("+x^%d",p->exp);}
				else if(p->coef!=1&&p->exp==1){
					printf("%d",p->coef);
					printf("+x",p->exp);}
				else printf("+x");
			}
			p=p->next;
		}
	}
	else{
		p=L->next;
		while(p!=NULL&&p->coef==0){
			p=p->next;
		}
		if(p==NULL)printf("0");
		else{
			if(p->coef!=1&&p->exp!=1){
			    printf("%d",p->coef);
			    printf("x^%d",p->exp);
			}
			else if(p->exp!=1){printf("x^%d",p->exp);}
			else if(p->coef!=1){
				printf("%d",p->coef);
				printf("x");}
			else printf("x");
		p=p->next;
			//printf("%d",p->coef)
		while(p!=NULL){
			  if(p->coef!=0){
				  if(p->coef!=1&&p->exp!=1){
			         printf("+%d",p->coef);
			         printf("x^%d",p->exp);
			       }
			      else if(p->exp!=1){printf("+x^%d",p->exp);}
				  else if(p->coef!=1){
					  printf("%d",p->coef);
					  printf("x");}
				  else{printf("x");}
			   }
			p=p->next;
		   }
		}
	}
	printf("\n");
	return 1;
}

int Insert(Node* L,int c,int e){
	Node* q,* s;
	q=(Node* )malloc(sizeof(Node));
	q->coef=c;q->exp=e;
	s=L;
	while(s->next!=NULL&&s->next->exp<e){
			s=s->next;
		}
	if(s->next==NULL){
		s->next=q;
		q->next=NULL;
	}
	else{
		q->next=s->next;
		s->next=q;
		}
	return 1;
}

Node* Add(Node* L1,Node* L2){
   Node* p1,* p2,* p,* a1,* a2;
   a1=L1;a2=L2;
   p1=L1->next;p2=L2->next;
   while(p1!=NULL&&p2!=NULL){
	   switch(compare(p1->exp,p2->exp)){
		  case 0:
			     p1->coef=p1->coef+p2->coef;
				 a1=p1;a2=p2;
				 p1=p1->next;p2=p2->next;
				 break;
		  case 1:
			     Insert(L1,p2->coef,p2->exp);
			     p=p2->next;
				 free(a2);
				 a2=p2;
				 p2=p;
				 break;
		  case -1:
			     a1=p1;
			     p1=p1->next;
				 break;
	   }
	}
   	if(a2!=NULL){
		   a1->next=p2;
		   free(a2);
    }
	OutPut(L1);
    return L1;
}

Node* Minor(Node* L1,Node* L2){
   Node* p1,* p2,* p,* a1,* a2,* s;
   s=L2;
   while(s!=NULL){
	   s->coef=-s->coef;
	   s=s->next;
   }
   OutPut(L2);
   a1=L1;a2=L2;
   p1=L1->next;p2=L2->next;
   while(p1!=NULL&&p2!=NULL){
	   switch(compare(p1->exp,p2->exp)){
		  case 0:
			     p1->coef=p1->coef+p2->coef;
				 a1=p1;a2=p2;
				 p1=p1->next;p2=p2->next;
				 break;
		  case 1:
			     Insert(L1,p2->coef,p2->exp);
			     p=p2->next;
				 free(a2);
				 a2=p2;
				 p2=p;
				 break;
		  case -1:
			     a1=p1;
			     p1=p1->next;
				 break;
	   }
	}
   	if(a2!=NULL){
		   a1->next=p2;
		   free(a2);
    }
	OutPut(L1);
    return L1;
}

void menu(){
     system("cls");
	 printf("\t|=======================================================|\t\n");
	 printf("\t|                                                       |\t\n");
	 printf("\t|                       多项式计算器                    |\t\n");
	 printf("\t|                                                       |\t\n");
	 printf("\t|=======================================================|\t\n");
	 printf("\n\t【1】输入多项式\t\t\t【2】输出多项式\n");
	 printf("\n\t【3】多项式加法\t\t\t【4】多项式减法\n");
	 printf("\n\t【0】退出程序\n");
}

int main()
{
	int a;
	Node* L,* L1,* L2;
	system("color 8F");
	while(1){
		menu();
		printf("\n\n\t\t\t请选择操作：");
		scanf("%d",&a);
		switch(a){
		case 1: L=Create();
                system("pause");
				break;
		case 2: if(L==NULL)
			    {
					printf("错误！没有输入过多项式");
			        L=Create();
				}
			    OutPut(L);
			    system("pause");
				break;
		case 3: L1=Create();
			    OutPut(L1);
			    L2=Create();
				OutPut(L2);
				Add(L1,L2);
				system("pause");
				break;
		case 4: L1=Create();
       			OutPut(L1);
				L2=Create();
				OutPut(L2);
				Minor(L1,L2);
			    system("pause");
				break;
		default:
			    printf("退出");
			    return 1;
		}
		}

}
