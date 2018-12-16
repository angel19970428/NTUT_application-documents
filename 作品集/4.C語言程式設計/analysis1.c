#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Global Declaration
typedef struct{
    int breakfast;
    int lunch;
    int snak;
    int dinner;
    int nfood;
    int drink;
}food;
typedef struct{
    int daily;
    int coat;
}cloth;
//Function Declaration
void foodanalysis(FILE* fp,food f1,int year[],int month[],int date[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis);
void clothanalysis1(FILE* fp,cloth c1,int year[],int month[],int date[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis);


int main3(int* yearanalysis,int* monthanalysis){
	//Local Declarations
	FILE *fp;
    food f1;
	cloth c1;
	int i;
	char a[999];
	int count=0;//行數
	//設初始值為0
	f1.breakfast=0;
  	f1.dinner=0;
  	f1.drink=0;
  	f1.lunch=0;
  	f1.nfood=0;
  	f1.snak=0;
  	c1.coat=0;
  	c1.daily=0;
    //Statements
    //抓output.txt有幾行
	if((fp=fopen("output.txt","r"))==NULL)
    {
        printf("Error opening output.txt for reading\n");
        system("PAUSE");
        return 0;
    }
    while(fgets(a,999,fp)!=NULL){ 
		count++; 
	}
	//printf("%d 行數",count);//測試用 
	fclose(fp);
	
	//抓output.txt資料 
	count=count/3;//3行一筆資料 
    if((fp=fopen("output.txt","r"))==NULL)
    {
        printf("Error opening output.txt for reading\n");
        system("PAUSE");
        return 0;
    }
    int money[count];
    int sort1[count];
    char sort2[count];
    int year[count];
    int month[count];
    int date[count];
 
    for(i=0;i<count;i++)
    {
	    fscanf(fp,"%d/%d/%d\n%d%c\n%d\n",&year[i],&month[i],&date[i],&sort1[i],&sort2[i],&money[i]);
	} 
	foodanalysis(fp,f1,year,month,date,sort1,sort2,money,count,&yearanalysis,&monthanalysis);
  	clothanalysis1(fp,c1,year,month,date,sort1,sort2,money,count,&yearanalysis,&monthanalysis);
  	//關閉output.txt 
	fclose(fp);
    
	//system("PAUSE");
    return 0;
}//main

void foodanalysis(FILE* fp,food f1,int year[],int month[],int date[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis){
	//Local Declarations   
	int i;
	//Statements
	//早點 
	for(i=0;i<count;i++){
		if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==1&&sort2[i]=='a'){ 
        	f1.breakfast+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d 早點 %d元\n",year[i],month[i],date[i],money[i]);
			}
        }       
	}
	if(f1.breakfast>=1500)
	printf("早點總共%d元=>早點吃太多了喔\n",f1.breakfast);
	else 
	printf("早點總共%d元=>不吃早點會變笨\n",f1.breakfast);
	printf("----------------------------\n");
	 
    //午飯 
	for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==1&&sort2[i]=='b'){
            f1.lunch+=money[i];
            if(money[i]!=0){
        		printf("%d/%d/%d 午飯 %d元\n",year[i],month[i],date[i],money[i]);
			}
        }
    } 
	if(f1.lunch>=1500)
	printf("午飯總共%d元=>午飯吃太多 會想睡覺\n",f1.lunch);
	else 
	printf("午飯總共%d元=>午飯吃的太少了減肥哦?\n",f1.lunch);
	printf("----------------------------\n");
    //晚飯        
    for(i=0;i<count;i++){
		if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==1&&sort2[i]=='c'){
			f1.dinner+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d 晚飯 %d元\n",year[i],month[i],date[i],money[i]);
			}	 
		}
	}
	if(f1.dinner>=3000)
    printf("晚飯總共%d元=>晚飯吃太多會胖\n",f1.dinner);
    else 
    printf("晚飯總共%d元=>晚飯吃得少 健康\n",f1.dinner);
    printf("----------------------------\n");
	//宵夜		      
    for(i=0;i<count;i++){
        if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==1&&sort2[i]=='d'){
        	f1.nfood+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d 宵夜 %d元\n",year[i],month[i],date[i],money[i]);
			}
		}
            
    }
	if(f1.nfood>=1500)
    printf("宵夜總共%d元=>宵夜少吃點\n",f1.nfood);
    else if(f1.nfood<=1500)
    printf("宵夜總共%d元=>省錢省錢\n",f1.nfood);
    printf("----------------------------\n");
    //飲料     
    for(i=0;i<count;i++){
        if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==1&&sort2[i]=='e'){
            f1.drink+=money[i];
            if(money[i]!=0){
        		printf("%d/%d/%d 飲料 %d元\n",year[i],month[i],date[i],money[i]);
			}
		}
    }
	if(f1.drink>=1500)
    printf("飲料總共%d元=>喝飲料會胖\n",f1.drink);
    else 
    printf("飲料總共%d元=>很省錢喔！\n",f1.drink);
    printf("----------------------------\n");
    //零食     
    for(i=0;i<count;i++){
        if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==1&&sort2[i]=='f'){
            f1.snak+=money[i];
            if(money[i]!=0){
        		printf("%d/%d/%d 零食 %d元\n",year[i],month[i],date[i],money[i]);
			}
		}
    }
	if(f1.snak>=1500)
    printf("零食總共%d元=>不要太愛吃\n",f1.snak);
    else 
    printf("零食總共%d元=>省錢又健康\n",f1.snak);
    printf("----------------------------\n");
    return;     
}//food foodanalysis
	 
void clothanalysis1(FILE* fp,cloth c1,int year[],int month[],int date[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis){
   	//Local Declarations 
    int i;
    //Statements
    //生活用品 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==2&&sort2[i]=='a'){
        	c1.daily+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d 生活用品 %d元\n",year[i],month[i],date[i],money[i]);
			}
		}
    }
	if(c1.daily>=2000)
    printf("生活用品總共%d元=>最近愛漂亮哦\n",c1.daily);
    else 
    printf("生活用品總共%d元=>生活還是要過\n",c1.daily);
    printf("----------------------------\n");
    //衣服    
	for(i=0;i<count;i++){
        if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==2&&sort2[i]=='b'){
            c1.coat+=money[i];
            if(money[i]!=0){
        		printf("%d/%d/%d 衣服 %d元\n",year[i],month[i],date[i],money[i]);
			}
		}
    }
	if(c1.coat>=2000)
    printf("衣服總共%d元=>正常購物就好\n",c1.coat);
    else 
    printf("衣服總共%d元=>省錢省錢\n",c1.coat);
    printf("----------------------------\n");
    return;    
}//cloth clothanalysis1
