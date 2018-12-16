#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getToday(int* year,int* month,int* day);
void sort(int year[],int month[],int day[],int* n);

int calendar(void){
	//Local Declaration
	int yearnow,monthnow,daynow;
	FILE * fp;
	int count=0;
	int i,j;
	char a[999];
	//Statements
	//取得現在的日期
	getToday(&yearnow,&monthnow,&daynow);
	//測試用 
	//printf("%d,%d,%d\n",year,month,day);
	
	//抓memo.txt行數 
	if((fp=fopen("memo.txt","r"))==NULL)
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
	//抓memo.txt資料
	count=count/2;//2行一筆資料 
    if((fp=fopen("memo.txt","r"))==NULL)
    {
        printf("Error opening output.txt for reading\n");
        system("PAUSE");
        return 0;
    }
	int year[count];
    int month[count];
    int day[count];
    char content[count][81];
    int ncontent[count];//避免內容重複輸出 
    for(i=0;i<count;i++){
    	ncontent[i]=0;
	}
	for(i=0;i<count;i++)
    {
	    fscanf(fp,"%d/%d/%d\n%s\n",&year[i],&month[i],&day[i],&content[i]);
	    
		//printf("%d/%d/%d\t%s\n",year[i],month[i],day[i],content[i]);
		
	}
	int year2[count];
	int month2[count];
	int day2[count];
	for(i=0;i<count;i++){
		year2[i]=year[i];//備份year 
		month2[i]=month[i];//備份month 
		day2[i]=day[i];//備份day 
	}
	sort(year,month,day,&count);
	for(i=0;i<count;i++){
	    if(year[i]>yearnow||(year[i]==yearnow&&month[i]>monthnow)||(year[i]==yearnow&&month[i]==monthnow&&day[i]>=daynow)){
		//判斷是否大於等於今天的日期 
			printf("%d/%d/%d\n",year[i],month[i],day[i]);	
			for(j=0;j<count;j++){
				if(year[i]==year2[j]&&month[i]==month2[j]&&day[i]==day2[j]&&ncontent[j]!=1){
					printf("\t%s\n",content[j]);
					ncontent[j]++;
				}
			}
			for(j=i+1;j<count;j++){
	    		if(year[i]==year[j]&&month[i]==month[j]&&day[i]==day[j]){
	    			year[j]=0;
	    			month[j]=0;
	    			day[j]=0;
				}
			}
			printf("------------------------\n");
		}
		
	}
	
	fclose(fp);
	system("PAUSE");
	return 0;
	
}//calendar

void getToday(int* year,int* month,int* day){
	//Local Declaration
	char c1[10];//星期幾 
	char c2[10];//month 
	int c3;//day
	int c4;//hour
	int c5;//min
	int c6;//sec
	int c7;//year
	int c8;//轉換後的month 
	char m1[]="Jan",m2[]="Feb",m3[]="Mar",m4[]="Apr",m5[]="May",m6[]="Jun";
	char m7[]="Jul",m8[]="Aug",m9[]="Sep",m10[]="Oct",m11[]="Nov",m12[]="Dec";
	time_t now;
	//Statements
	time(&now);
	//測試用 
	//printf("%s",ctime(&now));
	sscanf(ctime(&now),"%s %s %d %d:%d:%d %d",&c1,&c2,&c3,&c4,&c5,&c6,&c7);
	if(strcmp(c2,m1)==0){c8=1;}
	if(strcmp(c2,m2)==0){c8=2;}
	if(strcmp(c2,m3)==0){c8=3;}
	if(strcmp(c2,m4)==0){c8=4;}
	if(strcmp(c2,m5)==0){c8=5;}
	if(strcmp(c2,m6)==0){c8=6;}
	if(strcmp(c2,m7)==0){c8=7;}
	if(strcmp(c2,m8)==0){c8=8;}
	if(strcmp(c2,m9)==0){c8=9;}
	if(strcmp(c2,m10)==0){c8=10;}
	if(strcmp(c2,m11)==0){c8=11;}
	if(strcmp(c2,m12)==0){c8=12;}
	//測試用 
	//printf("%s %d %d",c2,c3,c7);
	*year=c7;
	*month=c8;
	*day=c3;
	return;
	
}//getToday

void sort(int year[],int month[],int day[],int* n){
	int i,j;
	int tempyear,tempmonth,tempday;
	int tempcontent=0;
	for(i=1;i<*n;i++){
		for(j=0;j<*n-1;j++){
			if(year[j]>year[j+1]||(year[j]==year[j+1]&&month[j]>month[j+1])||(year[j]==year[j+1]&&month[j]==month[j+1]&&day[j]>day[j+1])){
				tempyear=year[j];
				year[j]=year[j+1];
				year[j+1]=tempyear;
				tempmonth=month[j];
				month[j]=month[j+1];
				month[j+1]=tempmonth;
				tempday=day[j];
				day[j]=day[j+1];
				day[j+1]=tempday;	
			}
		}
	}

	return;
}//sort
