#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int status;
	int debugstatus;
	main2();
	do{
		fflush(stdin);
		printf("是否離開?(1:是,2:否)\n");
		do{
		   status=0;
		   debugstatus=0;
		   scanf("%d",&status);
		   if(status<1||status>2){
		   fflush(stdin);
		   printf("沒有此選項，請重新輸入1或2:\n");
		   debugstatus=1;//表示true
		   }
		   else
		   debugstatus=0;//表示false 
        }while(debugstatus==1);
		if(status==2){
			main2();
		}	
	}while(status==2);
	
	system("PAUSE");
	return 0;
}
