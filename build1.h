
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define S 9					//员工工作号位数
#define R 7					//密码位数
#define A 21				//姓名字符个数
#define D 12				//电话位数
#define Z 4
static char a[A+4];




/*员工信息*/
typedef struct _person
{
	char staffnum[S];					//员工工作号
	char staffnam[A];						//员工姓名
	char staffsex[2];							//员工性别

	char staffpas[R];					//员工登录密码
	char stafftel[D];					//员工联系方式
	char  staffhou[Z];						//已售房户数
	struct _person *next;
}stafff;

union
		{
			char num[S];
			char nam[A];
		}seainf;  					//为条件查找定义的共用体


	
