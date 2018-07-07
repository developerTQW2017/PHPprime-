#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OVERFLOW -2
#define MAXSIZE 100
#define stack_init_size  100 
#define stackincrement   10 

typedef char selemtype;
typedef char qelemtype;
typedef char elemtype;
typedef int status;

char  e;
char demon[MAXSIZE];

///栈结构体
typedef struct
{
	char bfa[20]="0";
	char afa[20]="0";
	char bfb[20]="0";
	char afb[20]="0";
}rules;

typedef struct
{
	selemtype *base;
	selemtype *top;
	int stacksize;
 } sqstack;
 
 //初始化栈
 status initStack(sqstack *stack)
 {
 	stack->base = (selemtype *) malloc (stack_init_size*sizeof(selemtype));
 	if(!stack->base) exit(OVERFLOW);
 	stack->top = stack->base;
 	stack->stacksize = stack_init_size;
 	return 1;
  } 
  
  //进栈
  status push(sqstack *stack, selemtype e)
  {
  	if(stack->top - stack->base == stack->stacksize)
  	{
  		stack->base =(selemtype *) realloc(stack->base,(stack->stacksize+stackincrement)*sizeof(selemtype));
  		if(!stack->base) exit(OVERFLOW);
  		stack->top = stack->base + stack->stacksize;
  		stack->stacksize+=stackincrement; 
	}
	*(stack->top++)=e;
	return 1;
   } 
   
   //出栈
   status pop(sqstack *stack, selemtype *e)
   {
   	if(stack->top == stack->base) return -1;
   	*e=*(--(stack->top));
   	return 1;
	} 
	
	//队列结构(链表)
	typedef struct qNode{
		qelemtype data;
		struct qNode *next;
	}qNode,*queueptr;
	
	typedef struct
	{
		queueptr front;
		queueptr rear;	
	}linkqueue;
	
	//初始化队列
	status initQueue(linkqueue *queue)
	{
		queue->front = queue->rear = (queueptr)malloc(sizeof(qNode));
		if(!(queue->front)) exit(OVERFLOW);
		queue->front->next = NULL;
	 } 
	 
	 //入队
	 status qPush(linkqueue *queue, qelemtype e)
	 {
	 	if(!queue->front) exit(OVERFLOW);
	 	queueptr p;
	 	p = (queueptr)malloc(sizeof(qNode));
	 	if(!p) exit(OVERFLOW);
	 	p->data = e;
	 	p->next = NULL;
	 	queue->rear->next = p;
	 	queue->rear=p;
	 	return 1;
	  } 
	  
	  //出队
	  status qPop(linkqueue *queue,qelemtype *e)
	  {
	  	queueptr p;
	  	if(queue->front == queue->rear) return -1;
	  	p = queue->front->next;
	  	*e = p->data;
	  	queue->front->next = p->next;
	  	if(queue->rear == p) queue->rear = queue->front;
	  	free(p);
	  	return 1;
	   } 
	   
	//括号内元素入栈处理
	void tempStack(sqstack *temp)
	{
		int i=0;
		char t;
		char c;
		c=demon[i];
		for(i=0;c != '#';i++)
		{
			c=demon[i];
			if(c=='(') //遇到左括号 
			{
				t=demon[i+1];
				push(temp,t);
				i++;
			
			do
			{
				i++;
				c=demon[i];
				push(temp,c);
				push(temp,t);
			}while(c != ')');
			pop(temp,&t);		//将多余的首字母出栈 
			pop(temp,&t);		//将多余的）出栈 
		}
	 } 
}
	 
	 //特殊入队函数
	 void spenqueue(linkqueue *queue, char key,rules rule)
	 {
	 	int j = 0;
	 	char a[20];
	 	if(key==rule.bfa[0])
		{strcpy(a,rule.afa);
		}else if(key==rule.bfb[0])
		{
		strcpy(a,rule.afb);
		}
		 while(a[j]!='\0')
		 {
		 	qPush(queue,a[j]);
		 	j++;
		 }
	  } 
	  
	  status sort(sqstack *stack, linkqueue *queue,rules rule)
	  {
	  	qNode b;
	  	int flag=0; //判断大写字母
		int i;
		for(i=0;demon[i]!='#';i++)
		{
			b.data=demon[i];
			if(('a'<=b.data&&b.data<='z') || b.data=='?') qPush(queue,b.data);
			else
			{
				if('A'<=b.data && b.data<='Z')
				{
					spenqueue(queue,b.data,rule);
					flag=1;
				}
				else{
					if(b.data=='(')
					{
						do{
							pop(stack,&e);
							qPush(queue,e);
						}while(!(stack->top==stack->base));
						while(b.data!=')'){
							i++;
							b.data=demon[i];
						}
					}
				}
			}
		 } 
		 return flag;
	  }

void print(char word[100]){
	int i=0;
	while(word[i] != NULL )
	{
		switch(word[i])
		{
			case 't':
				printf("天");
				i++;
				break;
			case 'd':
				printf("地");
				i++;
				break;
			case 's':
				printf("上");
				i++;
				break;
			case 'a':
				printf("一只");
				i++;
				break;
			case 'e':
				printf("鹅");
				i++;
				break;
			case 'z':
				printf("追");
				i++;
				break;
			case 'g':
				printf("赶");
				i++;
				break;
			case 'x':
				printf("下");
				i++;
				break;
			case 'n':
				printf("蛋");
				i++;
				break;
			case 'h':
				printf("恨");
				i++;
				break;
			default :
				printf(" ");
				i++;
				break; 
		}
	}
}
rules choicerule()
{
	char rule1[20];
	char rule2[20];
	char rule3[20];
	char rule4[20];
	
	rules rule;

	int choicerule;
	FILE *fp = fopen("rules","r");
	if(!fp){printf("当前未保存规则!");return rule;}
	int rulenum=0;
	while(!feof(fp)){
		fscanf(fp,"%s",rule1);
		fscanf(fp,"%s",rule2);
		fscanf(fp,"%s",rule3);
		fscanf(fp,"%s",rule4);
		rulenum++;
		printf("##%d 规则 %s->%s %s->%s\n",rulenum,rule1,rule2,rule3,rule4);
	
	}
	fclose(fp);
	fp = fopen("rules","r");
	printf("载入你想使用的规则序号(不输入为默认规则)");
	scanf("%d",&choicerule);
	while(choicerule>=rulenum&&choicerule<1)
	{
		printf("请不要选择错误的序号！请重新输入");
		scanf("%d",&choicerule);
	}
	for(int i=0;i<choicerule;i++){
		fscanf(fp,"%s",rule1);
		fscanf(fp,"%s",rule2);
		fscanf(fp,"%s",rule3);
		fscanf(fp,"%s",rule4);
	}
	fclose(fp);
	printf("你选择了规则 | %s->%s %s->%s",rule1,rule2,rule3,rule4);
	strcpy(rule.bfa,rule1);
	strcpy(rule.afa,rule2);
	strcpy(rule.bfb,rule3);
	strcpy(rule.afb,rule4);
	return rule;
}


status main(){
	sqstack stack1;
	linkqueue queue1;
	int k=0;
	int flag=1;
	int menuchoice;
	while(1){
	printf("1.选择解释规则");
	printf("2.自定义解释规则");
	printf("4.退出");
	scanf("%d",&menuchoice);
	rules rule;
	switch(menuchoice){
		case 1:
			rule = choicerule();
			break;
		case 2:
			printf("请输入规则!");
			printf("格式如下x xxxx");
			scanf("%s %s %s %s",rule.bfa,rule.afa,rule.bfb,rule.afb);
			break;
		case 4:
			printf("推出");
			return 0;
	}
	printf("你选择了规则 | %s->%s %s->%s",rule.bfa,rule.afa,rule.bfb,rule.afb);
	printf("\n\n\n\t\t\t魔王语言！\n");
	 printf("\t***************************************\n");
	 printf("\t输入魔王的语言：\n\t"); 
    printf("！请以‘#’作为结束 \n\t");
	printf("例子：B(ehnxgz)B\n") ;
    printf("\t***************************************\n\t");
    scanf("%s",demon); 
	char tep[100];
	strcpy(tep,demon);
    printf("\n\t***************************************"); 
    initStack(&stack1);
    initQueue(&queue1);
    tempStack(&stack1);
    while(flag==1)
    {
    	k=0;
    	flag=sort(&stack1,&queue1,rule);
    	 while(queue1.front!=queue1.rear) /*重写demon[i ]*/ 
            { 
            qPop(&queue1,&e); 
            demon[k]=e; 
            k++; 
            } 
        demon[k]='#'; 
        } 
        demon[k]='\0';
        printf("\n\t翻译成人话!!为:\n\t%s",demon); 
    printf("\n\n\t***************************************\n");
    //if(!strcmp(demon,"tsaedsaeezegexenehetsaedsae")){ printf("\t只鹅地上一只鹅鹅追鹅赶鹅下鹅蛋鹅恨鹅天上一只鹅地上一只鹅\n");} 
    print(demon);
	FILE *fp = fopen("trans","a");
    	fprintf(fp,"魔王语言:%s 翻译后%s\n",tep,demon);
	printf("翻译结果已保存");
	fclose(fp);
	printf("\n\t\t\t欢迎使用!\n\t");
}
    printf("回车键退出！");
if(getchar()) exit(1);
	}
