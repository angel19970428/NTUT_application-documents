#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int status;
	int debugstatus;
	main2();
	do{
		fflush(stdin);
		printf("�O�_���}?(1:�O,2:�_)\n");
		do{
		   status=0;
		   debugstatus=0;
		   scanf("%d",&status);
		   if(status<1||status>2){
		   fflush(stdin);
		   printf("�S�����ﶵ�A�Э��s��J1��2:\n");
		   debugstatus=1;//���true
		   }
		   else
		   debugstatus=0;//���false 
        }while(debugstatus==1);
		if(status==2){
			main2();
		}	
	}while(status==2);
	
	system("PAUSE");
	return 0;
}
