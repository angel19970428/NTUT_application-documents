#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//我現在完成的部分是:記帳、記事的紀錄和檔案輸出，除錯:記事記帳，記帳的大選項，記帳的小選項， 
//還需完成的地方，除錯:輸入日期，輸入金額 
//輸入日期那邊沒有防呆  
void Acctime(int *year,int *month,int *day);//記帳時間function
void Memotime(int *year,int *month,int *day);//記事時間function
void Item(char content[]);//記事標題function


int main2(void){
	int select1,select2,money,yesno;
	//select1:選擇記帳/記事, select2:選擇記帳分類 , money:金額 , yesno:是否繼續 
	int year1=0,month1=0,day1=0;
	//year1代表記帳的年,month1代表記帳的月份,day1代表記帳的日期
	int year2=0,month2=0,day2=0;
	//year2代表記事的年,month2代表記事的月份,day2代表記事的日期
	int yearanalysis=0,monthanalysis=0;
	//yearanalysis代表要分析的年,monthanalysis代表要分析的月份
	int statusMain,statusyearanalysis,statusmonthanalysis; 
	char select3,content[81];
	
	//select3:記帳分類細項 
	do//利用do-while迴圈使程式可以重複執行 
	{
		printf("請選擇分類:1.記帳 2.記事 3.看財務分析 4.行事曆 5.說明書 6.離開\n");
		//利用數字選擇記帳或記事 
		//除錯 
		do{
		   select1=0;
		   statusMain=0;
		   scanf("%d",&select1);
		   if(select1<1||select1>6){
		   fflush(stdin);
		   printf("輸入錯誤請重新輸入:\n");
		   statusMain=1;//表示true
		   }
		   else
		   statusMain=0;//表示false 
        }while(statusMain==1);
		//將選擇結果存入select1變數 
		if(select1==1){
		   //使用if迴圈進行邏輯判斷使用者選擇記帳或記事                     
		   select2=Accounting(&select3);
		   //回傳Accounting()的值  
		   if(select2>=1&&select2<=6){
                //若select2的值為1~6，執行Acctime()和Amount() 
				Acctime(&year1,&month1,&day1);
				money=Amount();
				//printf("%s\n%d\n%c\n%d\n",dateacc,select2,select3,money);//測試輸出結果 
				char fname[30]="output.txt";
				FILE *fp;
				fp=fopen(fname,"a");
				fprintf(fp,"%d/%d/%d\n%d%c\n%d\n",year1,month1,day1,select2,select3,money);
				if(fp) 
					fclose(fp);
				//將記帳結果新增到output.txt中 
				printf("是否繼續記錄? 1.是 其他.否\n");
				scanf("%d",&yesno);
				if(yesno==1)
					continue;
				else
					break;
	 			}	
			}
		if(select1==2)  //選擇記事，則執行Memotime()及Item() 
		{
			Memotime(&year2,&month2,&day2);
			Item(content);
			//printf("%s\n%s\n",datememo,item);//測試輸出結果 
			char fname[30]="memo.txt";
				FILE *fp;
				fp=fopen(fname,"a");
				fprintf(fp,"%d/%d/%d\n%s\n",year2,month2,day2,content);
				if(fp)
					fclose(fp);
			printf("是否繼續記錄? 1.是 其他.否\n");
				scanf("%d",&yesno);
				if(yesno==1)
					continue;
				else
					break;
		}
		if(select1==3){
			fflush(stdin);
			printf("請問你要看幾年的分析:\n");
			do{
		  		yearanalysis=0;
				statusyearanalysis=0;
		  		scanf("%d",&yearanalysis);
		   		if(yearanalysis<1||yearanalysis>9999){
		   			fflush(stdin);
		   			printf("輸入年份錯誤請重新輸入:\n");
		   			statusyearanalysis=1;//表示true
		   			}
		   		else
		   			statusyearanalysis=0;//表示false 
        	}while(statusyearanalysis==1);
			printf("請問你要看%d年幾月的分析:\n",yearanalysis);
			do{
		  		statusmonthanalysis=0;
		  		monthanalysis=0;
		  		scanf("%d",&monthanalysis);
		   		if(monthanalysis<1||monthanalysis>9999){
		   			fflush(stdin);
		   			printf("輸入月份錯誤請重新輸入:\n");
		   			statusmonthanalysis=1;//表示true
		   			}
		   		else
		   			statusmonthanalysis=0;//表示false 
        	}while(statusmonthanalysis==1);
			main3(&yearanalysis,&monthanalysis);
			main4(&yearanalysis,&monthanalysis);
		}
		if(select1==4){
			calendar();
		}
		if(select1==5){
			description();
		}
		if(select1==6){
			return;
		}
	}while(select1>=1&&select1<=5); 
	printf("\n");
	//system("pause");
	return 0;
	
}//main

int Accounting(char *s3){
 	//記帳function,進入記帳分類及細項的選擇,並將分類存入select2, 細項存入select3 
	fflush(stdin);
	int s2;
	int statusAccounting;
	//s2將紀錄分類並回傳給select2 
	char c[6]={'a','b','c','d','e','f'};
	//建立陣列存取a~f英文字母,以供檢視選項是否正確 
	printf("請選擇分類:1.食 2.衣 3.住 4.行 5.育 6.樂 7.返回首頁\n");
	//除錯	
	do{
		s2=0;
		statusAccounting=0;
		scanf("%d",&s2);
		if(s2<1||s2>7){
		fflush(stdin);
		printf("輸入錯誤請重新輸入:\n");
		statusAccounting=1;//表示true
		}
		else
		statusAccounting=0;//表示false 
	}while(statusAccounting==1);
	
	switch (s2)//利用switch迴圈判斷使用者選擇那個分類 
	{
		case 1 :
			printf("請選擇分類:a.早點 b.午飯 c.晚膳 d.飲料 e.宵夜 f.零食 \n");
			scanf("%c",s3);
			scanf("%c",s3);
			break;
		case 2 :
			printf("請選擇分類:a.日常用品 b.衣服 \n");
			scanf("%c",s3);
			scanf("%c",s3);
			break;
		case 3 :
			printf("請選擇分類:a.水電 b.房租 c.電話 \n");
			scanf("%c",s3);
			scanf("%c",s3);
			break;
		case 4 :
			printf("請選擇分類:a.交通 b.油料 \n");
			scanf("%c",s3);
			scanf("%c",s3);
			break;
		case 5 :
			printf("請選擇分類:a.書費b.學費c.文具 \n");
			scanf("%c",s3);
			scanf("%c",s3);
			break;
		case 6 :
			printf("請選擇分類:a.娛樂費b.其他 \n");
			scanf("%c",s3);
			scanf("%c",s3);
			break;
		case 7 :
			return;
			break;
		default ://若選擇不為1~7,則結束switch 	
			break;
	}
	int i,j;
	if(s2==1)
		j=6;
	else if(s2==3||s2==5)
		j=3;
	else
		j=2;
	for(i=0;i<j;i++) //透過for迴圈檢視輸入記帳細項是否正確,若錯誤則返回程式起始點 
	{
		if(*s3==c[i])
			return s2;		
	}
	printf("輸入細項錯誤請重新輸入\n");
	s2=0; 
	return s2;
	
}//Accounting




void Acctime(int *year,int *month,int *day){
	//記帳時間function
	int statusAcctime;
	printf("請輸入日期(年/月/日):\n");
	do{
		*year=0;
		*month=0;
		*day=0; 
		statusAcctime=0;
		scanf("%d/%d/%d",year,month,day);
		if(*year<1||*year>9999){//檢查年分 
		fflush(stdin);
		printf("輸入年份錯誤請重新輸入:\n");
		statusAcctime=1;//表示true
		}else if(*month<1||*month>12){//檢查月份 
		fflush(stdin);
		printf("輸入月份錯誤請重新輸入:\n");
		statusAcctime=1;//表示true 
		}else if(*day<1||*day>31){//檢查一般月份日期 
		fflush(stdin);
		printf("輸入日期錯誤請重新輸入:\n");
		statusAcctime=1;//表示true 
		}else if((*month==4||*month==6||*month==9||*month==11)&&*day>30){//檢查沒有31日的日期 
		fflush(stdin);
		printf("輸入日期錯誤請重新輸入:\n");
		statusAcctime=1;//表示true 	
		}else if((*year%400==0||(*year%4==0&&*year%100!=0))&&*month==2&&*day>29){//檢查閏年2月的日期 
		fflush(stdin);
		printf("輸入日期錯誤請重新輸入:\n");
		statusAcctime=1;//表示true 
		}else if(!(*year%400==0||(*year%4==0&&*year%100!=0))&&*month==2&&*day>28){//檢查平年2月的日期 
		fflush(stdin);
		printf("輸入日期錯誤請重新輸入:\n");
		statusAcctime=1;	
		}else
		statusAcctime=0;//表示false 
	}while(statusAcctime==1);
}//Acctime

int Amount(void){
	//記帳金額function
	int amount,statusAmount;
	printf("請輸入金額:\n");
	do{
		amount=0;
		statusAmount=0;
		scanf("%d",&amount);
		if(amount==0){
		fflush(stdin);
		printf("輸入金額錯誤，請重新輸入:\n");
		statusAmount=1;//表示true
		}
		else
		statusAmount=0;//表示false 
	}while(statusAmount==1);
	printf("\n");
	return amount;
}//Amount

void Memotime(int *year,int *month,int *day){
	//記事時間function
	int statusMemotime;
	printf("請輸入日期(年/月/日):\n");
	do{
		*year=0;
		*month=0;
		*day=0;
		statusMemotime=0;
		scanf("%d/%d/%d",year,month,day);
		if(*year<1||*year>9999){//檢查年分 
		fflush(stdin);
		printf("輸入年份錯誤請重新輸入:\n");
		statusMemotime=1;//表示true
		}else if(*month<1||*month>12){//檢查月份 
		fflush(stdin);
		printf("輸入月份錯誤請重新輸入:\n");
		statusMemotime=1;//表示true 
		}else if(*day<1||*day>31){//檢查一般月份日期 
		fflush(stdin);
		printf("輸入日期錯誤請重新輸入:\n");
		statusMemotime=1;//表示true 
		}else if((*month==4||*month==6||*month==9||*month==11)&&*day>30){//檢查沒有31日的日期 
		fflush(stdin);
		printf("輸入日期錯誤請重新輸入:\n");
		statusMemotime=1;//表示true 	
		}else if((*year%400==0||(*year%4==0&&*year%100!=0))&&*month==2&&*day>29){//檢查閏年2月的日期 
		fflush(stdin);
		printf("輸入日期錯誤請重新輸入:\n");
		statusMemotime=1;//表示true 
		}else if(!(*year%400==0||(*year%4==0&&*year%100!=0))&&*month==2&&*day>28){//檢查平年2月的日期 
		fflush(stdin);
		printf("輸入日期錯誤請重新輸入:\n");
		statusMemotime=1;	
		}else
		statusMemotime=0;//表示false 
	}while(statusMemotime==1);
	return;		
}//Memotime
void Item(char content[]){
	//記事標題function
	printf("請輸入記事內容:\n");
	scanf("%s",content);
	return;
}//Item


