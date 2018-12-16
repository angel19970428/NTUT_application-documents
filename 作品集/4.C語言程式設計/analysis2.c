#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Global Declaration
typedef struct{
    int hydropower;
    int rent;
    int phone;
}LIVING;
typedef struct{ 
    int transportation;
    int oil;
}WALKING;
typedef struct{
    int tuition;
    int book;
    int pen;
}EDUCATION;
typedef struct{
    int entertainment;
    int other;
}FUN;
//Function Declaration
void lanaly(FILE* fp,LIVING l1,int year[],int month[],int day[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis);
void wanaly(FILE* fp,WALKING w1,int year[],int month[],int day[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis);
void eanaly(FILE* fp,EDUCATION e1,int year[],int month[],int day[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis);
void fanaly(FILE* fp,FUN f1,int year[],int month[],int day[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis);


int main4(int* yearanalysis,int* monthanalysis){
    //Local Declarations
    FILE* fp;
    LIVING l1;
    WALKING w1;
    EDUCATION e1;
    FUN f1;
    int i;
    char a[999];
	int count=0;//行數
    //設初始值為0
    l1.hydropower=0;
    l1.phone=0;
    l1.rent=0;
    w1.oil=0;
    w1.transportation=0;
    e1.book=0;
    e1.pen=0;
    e1.tuition=0;
    f1.entertainment=0;
    f1.other=0;
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
	//關閉output.txt 
	fclose(fp);
    
	//抓output.txt資料 
	count=count/3;//3行一筆資料 
    if(!(fp=fopen("output.txt", "r")))
    {
	    printf("Error opening output.txt for reading");
	    system("pause");
        return 0;
    }
    int year[count];
    int month[count];
    int day[count];
    int sort1[count];
    char sort2[count];
    int money[count];
    for(i=0;i<count;i++)
    {
	    fscanf(fp,"%d/%d/%d\n%d%c\n%d\n",&year[i],&month[i],&day[i],&sort1[i],&sort2[i],&money[i]);
	}
    lanaly(fp,l1,year,month,day,sort1,sort2,money,count,&yearanalysis,&monthanalysis);
    wanaly(fp,w1,year,month,day,sort1,sort2,money,count,&yearanalysis,&monthanalysis);
    eanaly(fp,e1,year,month,day,sort1,sort2,money,count,&yearanalysis,&monthanalysis);
    fanaly(fp,f1,year,month,day,sort1,sort2,money,count,&yearanalysis,&monthanalysis);
    //關閉output.txt
	fclose(fp);
    
    system("pause");
    return 0;
}//main
void lanaly(FILE* fp,LIVING l1,int year[],int month[],int day[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis){
    //Local Declarations
	int i;
	//Statements
	//水電費 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==3&&sort2[i]=='a'){ 
    		l1.hydropower+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d 水電費 %d元\n",year[i],month[i],day[i],money[i]);
			}
		}   
    }
    if(l1.hydropower==0)
    printf("水電費總共0元=>你確定你繳錢了嗎？\n");
    else
    printf("水電費總共%d元=>很棒喔~有記得繳錢\n",l1.hydropower);
    printf("----------------------------\n");
    //房租 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==3&&sort2[i]=='b'){ 
    		l1.rent+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d 房租 %d元\n",year[i],month[i],day[i],money[i]);
			}
		}     
    }   
    if(l1.rent==0)
    printf("房租總共0元=>你確定你繳錢了嗎？小心房東來討債\n");
    else
    printf("房租總共%d元=>要繼續當個好房客喔\n",l1.rent);
	printf("----------------------------\n");   
    //電話費 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==3&&sort2[i]=='c'){ 
        	l1.phone+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d 電話費 %d元\n",year[i],month[i],day[i],money[i]);
			}
		} 
    }    
    if(l1.phone==0)
    printf("電話費總共0元=>你確定你繳錢了嗎？小心被斷網\n");
    else
    printf("電話費總共%d元=>記得別花太多時間在手機上，眼睛要休息喔\n",l1.phone);
    printf("----------------------------\n");
    return;
}//lanaly
void wanaly(FILE* fp,WALKING w1,int year[],int month[],int day[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis){
    //Local Declarations
	int i;
	//Statements
	//交通費 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==4&&sort2[i]=='a'){ 
        	w1.transportation+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d 交通費 %d元\n",year[i],month[i],day[i],money[i]);
			}
		}    
    }    
    if(w1.transportation==0)
    printf("交通費總共0元=>別都宅在房裡，多出門走走啦\n");
    else
    printf("交通費總共%d元\n",w1.transportation);
    printf("----------------------------\n");
    //油錢 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==4&&sort2[i]=='b'){ 
        	w1.oil+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d 油錢 %d元\n",year[i],month[i],day[i],money[i]);
			}
		}   
    }    
    if(w1.oil==0)
    printf("油錢總共0元=>別都宅在房裡，多出門走走啦\n");
    else
    printf("油錢總共%d元=>騎車開車要小心喔\n",w1.oil);
	printf("----------------------------\n");   
    return;
}//wanaly  
void eanaly(FILE* fp,EDUCATION e1,int year[],int month[],int day[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis){
    //Local Declaration
	int i;
	//Statements
	//學費 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==5&&sort2[i]=='a'){ 
        	e1.tuition+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d 學費 %d元\n",year[i],month[i],day[i],money[i]);
			}
		}
    }    
    if(e1.tuition==0)
    printf("學費總共0元\n");
    else
    printf("學費總共%d元=>要記得去上課喔\n",e1.tuition);
	printf("----------------------------\n"); 
    //書費   
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==5&&sort2[i]=='b'){ 
        	e1.book+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d 書費 %d元\n",year[i],month[i],day[i],money[i]);
			}
		}      
    }   
    if(e1.book==0)
    printf("書費總共0元\n");
    else
    printf("書費總共%d元\n",e1.book);
	printf("----------------------------\n"); 
    //文具用品 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==5&&sort2[i]=='c'){
        	e1.pen+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d 文具用品 %d元\n",year[i],month[i],day[i],money[i]);
			}
		}
    }   
    if(e1.pen==0)
    printf("文具用品總共0元\n");
    else
    printf("文具用品總共%d元\n",e1.pen);
    printf("----------------------------\n");
    return; 
}//eanaly  
void fanaly(FILE* fp,FUN f1,int year[],int month[],int day[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis){
    //Local Declarations
	int i;
	//Statements
    //娛樂費 
	for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==6&&sort2[i]=='a'){
        	f1.entertainment+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d 娛樂費 %d元\n",year[i],month[i],day[i],money[i]);
			}
		}
    }    
    if(f1.entertainment==0)
    printf("娛樂費總共0元=>要多跟朋友出去玩啊\n");
    else
    printf("娛樂費總共%d元\n",f1.entertainment);
    printf("----------------------------\n");
    //其他 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==6&&sort2[i]=='b'){
        	f1.other+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d 其他 %d元\n",year[i],month[i],day[i],money[i]);
			}
		}
    }    
    if(f1.other==0)
    printf("其他總共0元\n");
    else
    printf("其他總共%d元\n",f1.other);
	printf("----------------------------\n");  
    return;  
}//fanaly     
