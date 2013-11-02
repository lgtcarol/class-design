#include"build1.h"						//一些头文件，宏处理，构造类型定义
#include"build2.h"                                              //所有用到的函数的声明

/*主界面*/
void main(void)
{
	char _choice;						//存放所选项
	do
	{
		system("clear");		
       		//printf("     	*   *   *   *                                               \n");
printf("           *     * *     *     						\n");
printf("          *  ¡ï   *  ¡ï   *    						\n");
printf("           *      ¡ï     *     						\n");
printf(">>>------ --欢迎使用房产公司员工管理系统-----  ----> 			\n");
printf("             *         *       						\n");
printf("               *  ¡ï *       						\n");
printf("                *   *          						\n");
printf("                 * *          						\n");
printf("                  *   							\n");
printf("\n\n");	

		printf("			***************	 管理员登录          ************* 1 **************\n");
		printf("			***************	 普通员工登录        ************* 2 **************\n");
		printf("			***************	 退出系统            ************* 3 **************\n");
		printf("\n\n");
		printf(">>>>>>>	>>>请输入相应序号进行选择...>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		scanf("%c",&_choice);
		
		
		while(!(_choice=='1' || _choice=='2' || _choice=='3'))                
		{
			printf("!!!!!对不起，你选择的功能模块序号异常");
			printf(">>>>>>请重新作出选择....\n")
				;
			scanf("%c",&_choice);
			
		}

		switch(_choice)
		{
			case '1' : _administer(); break;
			case '2' : _worker();     break;
			case '3' : return;
		}
	}while(1);

	
}


/*管理员登录*/
void _administer(void)
{

	char _ncod[S],_npas[R];				//登录时的口令及密码
	char _ocod[S],_opas[R];				//系统原先的口令及密码
	FILE *fp;
	int i;                                           //输入次数的限定

	_initial();
	fp=fopen("管理员.txt","rt");
	if(fp==NULL)
		{
			printf("打开  管理员.txt  时出错\n");
			exit(0);
		}
	fscanf(fp,"%s %s",_ocod,_opas);
	printf("!!!!!!!!!!开始进行信息检测，注意：第三次输错后您将被强行退出系统.\n");
	for(i=0;i<3;i++)
   {
	printf("...........第%d次信息检测..............",i+1);

	printf("请输入您的登录口令：\n");
	scanf("%s",_ncod);
	printf("请输入您的密码：\n");
	system ("stty -echo");//关闭回显
	scanf("%s",_npas);
	system ("stty echo");//打开回显


	if(strcmp(_ocod,_ncod)==0 && strcmp(_opas,_npas)==0)
	{
		getchar();
		_mansta(); 									//成功进入管理界面
		getchar();
		return ;
	}
	if(i==2)
	{
		getchar();
		printf("!!!!!!!对不起，您的身份验证有误，您即将被强行退出\n");
		printf(">>>>>>>按回车键返回上级界面>>>>>>>>>>>>>>>>>>>>>>>>>：\n");
		getchar();
		return;
	}
    }
}




/*普通员工登录*/
void _worker(void)
{
	char _ncod[S],_npas[R];				//输入的口令及密码
	stafff *h,*p;  					//用已存的信息进行核对
	int i;
	h=_reastafil();
	
	_huanyuanpas(h);
	printf("!!!!!!!!!!!开始进行信息检测，注意：第三次输错后您将被强行退出系统.\n");
	for(i=0;i<3;i++)
   {
	printf("...........第%d次信息检测......................\n",i+1);

	printf("请输入您的登录口令：\n");
	scanf("%s",_ncod);
	printf("请输入您的密码：\n");
	system ("stty -echo");//关闭回显
	scanf("%s",_npas);
	//getchar();
	system ("stty echo");//打开回显
	//scanf("%s",_npas);
	for(p=h->next;p!=NULL;p=p->next)										//检验密码，然后核对口令
	      if(strcmp(_npas,p->staffpas)==0)
			if(strcmp(_ncod,p->staffnam)==0 )
			{
				getchar();
				_mansta();
				getchar();
				return ;
			}
	if(i==2)
	{
		getchar();
		printf("!!!!!!!!!!!对不起，您的身份验证有误，您即将被强行退出\n");
		printf(">>>>>>>>>>>按回车键返回上级界面>>>>>>>>>>>>>>>>>>>>>>>>>>>：\n");
		getchar();
		return;
	}
    }
}


/*管理员身份验证的初始化*/
void _initial(void)
{
	FILE *fp;
	char _ocode[S]="superman";
	char _opas[R]="851554";

	fp=fopen("管理员.txt","wt");
	if(fp==NULL)
	{
		printf("打开文件失败。\n");
		exit(0);
	}
	fprintf(fp,"%s %s",_ocode,_opas);
	fclose(fp);
	return;

}

/*员工管理系统的主界面*/
void _mansta(void)
{
	char _choice;

	do
	{
		system ("clear");
		printf("\n");
		printf("-------------------------------------------------------------------------------\n");
		printf("><><><><><><><><><><><<><><><><><><><><><><><><<><><><><><><><><><><><><><><><>\n");
		printf(" ><                                                                       ><             \n");
		printf(" ><		欢迎进入员工管理系统                                      ><                  \n");
		printf(" ><                                                                       ><         \n");
		printf("><><><><><><><><><>><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><>\n");
		printf("-------------------------------------------------------------------------------\n");
		printf("	((((	1     ))))    创建员工信息\n");
		printf("	((((	2     ))))    添加员工\n");
		printf("	((((	3     ))))    查找员工\n");
		printf("	((((	4     ))))    删除员工\n");
		printf("	((((	5     ))))    员工业绩排名\n");
		printf("	((((	6     ))))    查看所有信息\n");
		printf(" 	((((	7     ))))    修改员工信息\n");
		printf("	((((	8     ))))    退出\n");
		printf("\n\n");
		printf(">>>>>>>> >>>>>>>>>请按序号作出你的选择>>>>>>>>>>>\n");
		scanf("%c",&_choice);
		while(_choice<49 || _choice>56)
		{
			
			printf("!!!!!!对不起，你的选择异常,请重新选择>>>>>>>>\n");
			scanf("%c",&_choice);
	
		}
		
		switch(_choice)
		{
			case '1' : _cresta(); break;
			case '2' : _addsta(); break;
			case '3' : _seasta(); break;
			case '4' : _delsta(); break;
			case '5' : _sorsta(); break;          
			case '6' : _outsta(); break;
			case '7' : _modsta(); break;
			case '8' : return;
		}
		
	}while(1);
}


/*1.创建员工信息*/
void  _cresta(void)							
{
	stafff *head,*p,*q;
	FILE *fp;
	int i=0,n;
	if(limit())
	{
	   printf(">>>>>>> >>>>>>>>>>请输入要记录的员工数目>>>>>>>>>>>>>>：\n");
	   scanf("%d",&n);
	   getchar();
	   head=p=(stafff *)malloc(sizeof(stafff));
	   do
	   {	
		printf("\n -------------第%d个员工信息开始录入----------------\n",i+1);	
		q=(stafff *)malloc(sizeof(stafff));
		printf("请输入%d位工作号\n",S-1);
		_check145(S-1);
		strcpy(q->staffnum,a);
		strcpy(a,"0");
		
		printf("请输入姓名（不多于%d个字符)\n",A-1);
		scanf("%s",q->staffnam);
		
		printf("请分别输入性别（‘M’代表男性，‘w’代表女性）\n");
		scanf("%s",q->staffsex);
		while(strcmp(q->staffsex,"w")!=0 && strcmp(q->staffsex,"m")!=0 )
		{
			printf("请按要求重新输入：\n");
			scanf("%s",q->staffsex);
		}
	
		printf("请输入员工的%d位登录密码\n",R-1);
		_check145(R-1);
		strcpy(q->staffpas,a);
		strcpy(a,"0");

		printf("请输入%d位手机号码\n",D-1);
		_check145(D-1);
		strcpy(q->stafftel,a);
		strcpy(a,"0");
	
		printf("请输入该员工的售房数目\n");
		scanf("%s",q->staffhou);
		p->next=q;
		p=q;
		i++;

	}while(i<n);

	p->next=NULL;
	
	_openstafil(head);					//1 保存到文件函数
	getchar();
	return;
   }
   else
	{
	 _byocon();                                            //无相应权限 
	 getchar();
	}
}


/*2.添加员工 信息*/
void _addsta(void)
{
	stafff *h,*p,*q;
	int n,i;
	q=h=_reastafil();
	
	if(limit())
	{
	printf(">>>>>>>> >>>>>>>>>请输入要添加的员工个数:>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n -----------------------请输入第%d个要添加的员工信息------------------------------\n",i+1);
		p=(stafff *)malloc(sizeof(stafff));

		printf("请输入%d位工作号\n",S-1);
		scanf("%s",p->staffnum);

		printf("请输入姓名（不多于%d个字符)\n",A-1);
		scanf("%s",p->staffnam);
		
		printf("请分别输入性别（‘m’代表男性，‘w’代表女性）\n");
		scanf("%s",p->staffsex);
		while(strcmp(p->staffsex,"w")!=0 && strcmp(p->staffsex,"m")!=0 )
		{
			printf("请按要求重新输入：\n");
			scanf("%s",p->staffsex);
		}
	
		printf("请输入员工的%d位登录密码\n",R-1);
		system ("stty -echo");
		scanf("%s",p->staffpas);
		system("stty echo");

		printf("请输入%d位手机号码\n",D-1);
		scanf("%s",p->stafftel);

		printf("请输入该员工的售房数目\n");
		scanf("%s",p->staffhou);
		
		/*先进行条件查找再添加*/
	        while(q->next!=NULL && strcmp(q->next->staffnum,p->staffnum)<0)
	             q=q->next;
	        while(q->next!=NULL && strcmp(q->next->staffnum,p->staffnum)==0)
	       {
		     free(p);
		      printf("已含其信息。\n");
		      continue;
	       }

	p->next=q->next;
	q->next=p;
	}

	/*存入文件*/
	_openstafil(h);
	getchar();
	return ;
	}

	else
	{
		_byocon();
		getchar();
	}
}	

/*3.查找员工信息*/
void _seasta(void)
{
	stafff *h,*p;
	char _choice; 								//查找所遵循的条件选择
	int n,i;

	h=_reastafil();
	p=h->next;
	

	printf(">>>>>>> >>>>>>>>>>>>>请输入要查找的员工个数>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
   {
 	p=h->next;
	getchar();
	printf(">>>>>>请选择(输入回车键确认)\n****** a ******按工作号查找	****** b ******按姓名查找\n");
	_choice=getchar();
	getchar();

	/*按工作号查找*/
	if(_choice=='a')
	{
	   printf("-----------------请输入第%d个要查找员工的工作号：--------------------------------\n",i+1);
	   scanf("%s",seainf.num);
	   while(p!=NULL && strcmp(p->staffnum,seainf.num)!=0)
	         p=p->next;
	   if(p==NULL)
	   {
		 getchar();
	         printf("!!!!!!对不起，无此信息!!!!!!!!!!!!!!!!\n");
	   }
	   else
	  {
	     
	         printf("该员工信息如下：\n");
	      
	         printf("工作号      姓名           性别   登录密码  联系方式       已售房户数\n ");
	         printf("%-s     %-13s  %s   %-10s%-16s%s",p->staffnum,p->staffnam,p->staffsex,p->staffpas,p->stafftel,p->staffhou);
	         printf("\n>>>>>>>>>>>>>>>>>>>按回车键继续...>>>>>>>>>>>\n");
	         getchar();
	  }
	  
       }


	/*按姓名查找*/
	else
	{
	   printf("------------------请输入第%d个要查找员工的姓名：---------------------------------\n",i+1);
	   scanf("%s",seainf.nam);
	   while(p!=NULL && strcmp(p->staffnam,seainf.nam)!=0)
	         p=p->next;
	   if(p==NULL)
	   {
	
		   getchar();
	         printf("!!!!!!对不起，无此信息!!!!!!!!!!!!!!!!\n");
	   }
	   else
	  {
	     
	      printf("该员工信息如下：\n");
	      
	      printf("工作号      姓名           性别   登录密码  联系方式       已售房户数\n ");
	      printf("%-s     %-13s  %s   %-10s%-16s%s",p->staffnum,p->staffnam,p->staffsex,p->staffpas,p->stafftel,p->staffhou);
	      printf("\n按回车键继续...\n");
	      getchar();
	  }
	}
   }
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>按 回车键返回界面..>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	getchar();
	return ;
}

/*4.删除员工信息*/
void _delsta(void)
{
	
	stafff *h,*p,*q;
	int n,i;
	char _choice; 						//条件选择变量

   if(limit())
    {
	p=h=_reastafil();
	
	printf("******************请输入要删除的人数*********************：\n");
	scanf("%d",&n);
	getchar();

	for(i=0;i<n;i++)
	{
	printf(">>>>>>>>>>>>请选择(输入回车键确认)\n **** a **** 按工作号删除 	 **** b **** 按姓名删除\n");
	_choice=getchar();
	getchar();


	if(_choice=='a')
	{
		printf("请输入删除人员的工作号：\n");
		scanf("%s",seainf.num);
	
		while(p->next!=NULL && strcmp(p->next->staffnum,seainf.num)!=0)
		p=p->next;
		if(p->next!=NULL)
		{
			q=p->next;
			p->next=q->next;
			free(q);
		}
		else
	      		printf("!!!!!!无此信息!!!!!!!!!!\n");
	
	}

	else
	{
		printf("请输入删除人员的姓名：\n");
		scanf("%s",seainf.nam);
	
		while(p->next!=NULL && strcmp(p->next->staffnam,seainf.nam)!=0)
		p=p->next;
		if(p->next!=NULL)
		{
			q=p->next;
			p->next=q->next;
			free(q);
		}
		else
	      		printf("!!!!!!!无此信息!!!!!!!!!!!!!!!!\n");
	}

	getchar(); 						//清空缓存区
	}

	_openstafil(h);

	return ;
	}

   else
	{
		_byocon();
		getchar();
	}
}

/*5.对员工信息进行排序*/
void _sorsta(void)
{
	stafff *h,*p,*q,*r;
	int i,k=0;
	

	p=h=_reastafil();
	
	while(p!=NULL)
	{
		k++;
		p=p->next;
	}


	/*冒泡排序法*/
	for(i=0;i<k-1;i++) 					//k为链表的有效结点数
   {
	p=h;
	q=p->next;
	r=q->next;
	
	if(r==NULL)
	{
		print(h);
		return ;
	}
	
	while(r!=NULL)
	{
	   if(strcmp(q->staffhou,r->staffhou)<0)
	   {
		q->next =r->next;
		r->next=q;
		p->next=r;
	   }
	   
	   p=p->next;
	   q=p->next;
	   r=q->next;
	}

	/*   for(p =h ;p->next->next != NULL; p = p->next)
	   {
		q = p->next;
	   	if(strcmp(q->staffhou ,p->next->next->staffhou) < 0)
		{
		
		q->next =p->next->next->next;
		p->next->next->next=q;
		p->next=p->next->next;
		}
	   }*/
   }
	print(h);
	_openstafil(h);
	getchar();
	printf(">>>>>>>>>>>>按 回车键 返回主界面>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	getchar();
	return ;
 
}

/*排序后的结果显示*/
void print(stafff *h)
{
	stafff *p=h->next;
	//int i;

	printf("*************************按售房数排序后信息如下：****************************\n");
	printf("工作号       姓名         性别  登录密码  联系方式       已售房户数\n");
	while(p!=NULL)
	{
	
	   printf("%s     %-13s  %s   %-10s%-16s%s\n",p->staffnum,p->staffnam,p->staffsex,p->staffpas,p->stafftel,p->staffhou);
	   p=p->next;
	}
}


/*6.查看所有信息*/
void _outsta(void)
{
	stafff *p,*h;
	h=_reastafil();
	p=h->next;

	printf("*****************************员工信息表如下：************************************\n");
	printf("工作号       姓名         性别  登录密码  联系方式       已售房户数\n");
	while(p!=NULL)
	{
	   
	   printf("%s     %-13s  %s   %-10s%-16s%s\n",p->staffnum,p->staffnam,p->staffsex,p->staffpas,p->stafftel,p->staffhou);
	   p=p->next;
	}
	getchar();
	printf(">>>>>>>>>>>>>>>>>按 回车键 返回主界面>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	getchar();
}


/*7.修改员工信息*/
void _modsta(void)
{
	stafff *h,*p;
	char sea[S]; 								//用来保存修改信息
	h=_reastafil();
	p=h->next;
	int n,i;

	printf(">>>>>>>>> >>>>>>>>>>>>>>请输入要修改的员工个数>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	scanf("%d",&n);


	for(i=0;i<n;i++)
	{
	p=h->next;
	printf("------------------------请输入第%d个要修改的员工工作号--------------------------：\n",i+1);
	scanf("%s",sea);
	while(p!=NULL && strcmp(p->staffnum,sea)!=0)
	      p=p->next;
	if(p==NULL)
	{
	      printf("!!!!!!!对不起，无此信息!!!!!!!!!!!!!!!\n");
	      getchar();
	}
	else
	{
	      _modface(p);
	      system("clear");
	      printf("***************************改后该员工信息如下：**************************************\n");
	      printf("工作号      姓名           性别   登录密码  联系方式       已售房户数\n ");
	      
	      printf("%-s     %-13s  %s   %-10s%-16s%s",p->staffnum,p->staffnam,p->staffsex,p->staffpas,p->stafftel,p->staffhou);
	      printf("\n");
	      getchar();
}
	}
	
	_openstafil(h);
	printf(">>>>>>>>>>>>>>>>>>>>>>按 回车键 返回界面..>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	getchar();
	return ;
}

/*修改选择界面*/
void _modface(stafff *h)
{
	char _choice;
	char modify[A]; 						//存放修改数据

	if(limit())
	{
	do
	{
		system ("clear");
		printf("\n");
		printf("-------------------------------------------------------------------------------\n");
		printf("><><><><><><><><><><><<><><><><><><><><><><><><<><><><><><><><><><><><><><><><>\n");
		printf(" ><                                                                       ><             \n");
		printf(" ><		 您好，您当前位于修改信息界面                               ><                  \n");
		printf(" ><                                                                        ><         \n");
		printf("><><><><><><><><><>><><><><><><><><><><><><><><<><><><><><><><><><><><><><><><>\n");
		printf("-------------------------------------------------------------------------------\n");
		printf("	((((	1     ))))    修改姓名\n");
		printf("	((((	2     ))))    修改性别\n");
		printf("	((((	3     ))))    修改登录密码\n");
		printf("	((((	4     ))))    修改联系方式\n");
		printf("	((((	5     ))))    修改售楼成绩\n");
		printf("	((((	6     ))))    退出\n");
		printf("\n\n");
		printf(">>>>>>>> >>>>>>>>>请按序号作出你的选择>>>>>>>>>>>\n");
		getchar();
		scanf("%c",&_choice);


		while(_choice<49 || _choice>54)
		{
			
			printf("对不起，你的选择异常,请重新选择\n");
			scanf("%c",&_choice);
		}

		if(_choice=='1')
		{
			printf("请输入修改后的姓名：\n");
			scanf("%s",modify);
			strcpy(h->staffnam,modify);
			strcpy(modify,"0");
		}
		
		if(_choice=='2')
		{
			printf("请输入修改后的性别：\n");
			scanf("%s",modify);
			while(strcmp(modify,"w")!=0 && strcmp(modify,"m")!=0 )
			{
			printf("请按要求重新输入：\n");
			scanf("%s",modify);
		        }
			strcpy(h->staffsex,modify);
			strcpy(modify,"0");
			
		}
		if(_choice=='3')
		{
			printf("请输入修改后的登录密码：\n");
			system ("stty -echo");//关闭回显
			scanf("%s",modify);
			system ("stty echo");//打开回显

			strcpy(h->staffpas,modify);
			strcpy(modify,"0");
		}
		if(_choice=='4')
		{
			printf("请输入修改后的联系方式：\n");
			scanf("%s",modify);
			strcpy(h->stafftel,modify);
			strcpy(modify,"0");
		}
		if(_choice=='5')
		{
			printf("请输入修改后的售房数目：\n");
			scanf("%s",modify);
			strcpy(h->staffhou,modify);
			strcpy(modify,"0");
		}
		
		if(_choice=='6')
		
			return ;
		
	}while(1);
	}

	else 
	 {
	 	_byocon();
		getchar();
	 }
}


/*保存到文件*/
void _openstafil(stafff *h)
{
	FILE *fp;
	stafff *p=h->next;
	int i;

	fp=fopen("员工信息.txt","wt");
	if(fp==NULL)
		{
			printf("打开  员工信息.txt  时出错\n");
			exit(0);
		}

	while(p!=NULL)
	{
		for(i=0;i<strlen(p->staffpas);i++)
		      (p->staffpas)[i]+=i;
	   fprintf(fp,"%s %s %s %s %s %s\n",p->staffnum,p->staffnam,p->staffsex,p->staffpas,p->stafftel,p->staffhou);
	   p=p->next;
	}

	fclose(fp);
	return ;
}


/*从文件调入内存*/
stafff* _reastafil(void)
{
	FILE *fp;
	stafff *head,*p,*q;


	fp=fopen("员工信息.txt","at+");
	if(fp==NULL)
		{
			printf("打开  员工信息.txt  时出错\n");
			exit(0);
		}

	/*读取数据并还原链表*/
	head=p=(stafff *)malloc(sizeof(stafff));						
	q=(stafff *)malloc(sizeof(stafff));
	
	while(!feof(fp))
	{
	   fscanf(fp,"%s   %s   %s %s %s %s\n",q->staffnum,q->staffnam,q->staffsex,q->staffpas,q->stafftel,q->staffhou);
	   p->next=q;
	   p=q;
	   q=(stafff *)malloc(sizeof(stafff));
	}
	p->next=NULL;	
	fclose(fp);
												

	return head;
}

/*将密码进行还原，以便进行身份验证*/
void _huanyuanpas(stafff *h)
{
	int i;
	stafff *p=h->next;

	while(p!=NULL)
	{
	 for(i=0;i<strlen(p->staffpas);i++)
		      (p->staffpas)[i]-=i;
	 p=p->next;
	}

	return ;
}

/*检查每次输入是否合理，并给予修改*/
void _check145(int n)
	{
		int i;
		int flag=1;

		printf("...............进入检测函数...........\n");
		scanf("%s",a);
		do
		{
			if(strlen(a)==n)
			{
				flag=1;
				for(i=0;i<strlen(a);i++)
					if(!isdigit(a[i]))
					{
					    flag=0;
					    break;
					}
				if(flag)
					return ;
				else
				{
			      	    printf("!!!!!!!!输入不符要求,请重新输入：\n");
			            	scanf("%s",a);
				}
			}
				     
			else
		    	{
			      printf("!!!!!!!!输入不符要求,请重新输入：\n");
			      		   scanf("%s",a);
			}
		  }while(strlen(a)!=n);
	}



/*无权限反映*/
void _byocon(void)
   {
   	printf("!!!!!对不起，您无此权限，输入回车返回。。！！！！");
	getchar();
	return;
  }

/*权限测试*/
int limit(void)
	{
		char _opas[R]="851554";
		char _npas[R];
		int i;
		
		printf("！！！！为保证信息安全，此项功能有权限设置，您将有两次核对机会!!!!!\n");
		for(i=0;i<2;i++)
		{
		   printf(">>>>>>>>>>>>>>>>>请先输入管理员密码：>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		   system ("stty -echo");//关闭回显
		   scanf("%s",_npas);
		   system("stty echo");//打开回显
		   if(strcmp(_npas,_opas)==0)
			 return 1;
		   else
			 printf("!!!!!!密码错误\n");
		   if(i==1)
		   {
			   return 0;
		   }
		 }
	}



