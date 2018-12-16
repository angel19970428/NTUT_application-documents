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
	int count=0;//���
    //�]��l�Ȭ�0
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
    //��output.txt���X��
    if((fp=fopen("output.txt","r"))==NULL)
    {
        printf("Error opening output.txt for reading\n");
        system("PAUSE");
        return 0;
    }
    while(fgets(a,999,fp)!=NULL){ 
		count++; 
	}
	//printf("%d ���",count);//���ե� 
	//����output.txt 
	fclose(fp);
    
	//��output.txt��� 
	count=count/3;//3��@����� 
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
    //����output.txt
	fclose(fp);
    
    system("pause");
    return 0;
}//main
void lanaly(FILE* fp,LIVING l1,int year[],int month[],int day[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis){
    //Local Declarations
	int i;
	//Statements
	//���q�O 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==3&&sort2[i]=='a'){ 
    		l1.hydropower+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d ���q�O %d��\n",year[i],month[i],day[i],money[i]);
			}
		}   
    }
    if(l1.hydropower==0)
    printf("���q�O�`�@0��=>�A�T�w�Aú���F�ܡH\n");
    else
    printf("���q�O�`�@%d��=>�ܴγ�~���O�oú��\n",l1.hydropower);
    printf("----------------------------\n");
    //�Я� 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==3&&sort2[i]=='b'){ 
    		l1.rent+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d �Я� %d��\n",year[i],month[i],day[i],money[i]);
			}
		}     
    }   
    if(l1.rent==0)
    printf("�Я��`�@0��=>�A�T�w�Aú���F�ܡH�p�ߩЪF�ӰQ��\n");
    else
    printf("�Я��`�@%d��=>�n�~���Ӧn�Ыȳ�\n",l1.rent);
	printf("----------------------------\n");   
    //�q�ܶO 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==3&&sort2[i]=='c'){ 
        	l1.phone+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d �q�ܶO %d��\n",year[i],month[i],day[i],money[i]);
			}
		} 
    }    
    if(l1.phone==0)
    printf("�q�ܶO�`�@0��=>�A�T�w�Aú���F�ܡH�p�߳Q�_��\n");
    else
    printf("�q�ܶO�`�@%d��=>�O�o�O��Ӧh�ɶ��b����W�A�����n�𮧳�\n",l1.phone);
    printf("----------------------------\n");
    return;
}//lanaly
void wanaly(FILE* fp,WALKING w1,int year[],int month[],int day[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis){
    //Local Declarations
	int i;
	//Statements
	//��q�O 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==4&&sort2[i]=='a'){ 
        	w1.transportation+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d ��q�O %d��\n",year[i],month[i],day[i],money[i]);
			}
		}    
    }    
    if(w1.transportation==0)
    printf("��q�O�`�@0��=>�O���v�b�и̡A�h�X��������\n");
    else
    printf("��q�O�`�@%d��\n",w1.transportation);
    printf("----------------------------\n");
    //�o�� 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==4&&sort2[i]=='b'){ 
        	w1.oil+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d �o�� %d��\n",year[i],month[i],day[i],money[i]);
			}
		}   
    }    
    if(w1.oil==0)
    printf("�o���`�@0��=>�O���v�b�и̡A�h�X��������\n");
    else
    printf("�o���`�@%d��=>�M���}���n�p�߳�\n",w1.oil);
	printf("----------------------------\n");   
    return;
}//wanaly  
void eanaly(FILE* fp,EDUCATION e1,int year[],int month[],int day[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis){
    //Local Declaration
	int i;
	//Statements
	//�ǶO 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==5&&sort2[i]=='a'){ 
        	e1.tuition+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d �ǶO %d��\n",year[i],month[i],day[i],money[i]);
			}
		}
    }    
    if(e1.tuition==0)
    printf("�ǶO�`�@0��\n");
    else
    printf("�ǶO�`�@%d��=>�n�O�o�h�W�ҳ�\n",e1.tuition);
	printf("----------------------------\n"); 
    //�ѶO   
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==5&&sort2[i]=='b'){ 
        	e1.book+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d �ѶO %d��\n",year[i],month[i],day[i],money[i]);
			}
		}      
    }   
    if(e1.book==0)
    printf("�ѶO�`�@0��\n");
    else
    printf("�ѶO�`�@%d��\n",e1.book);
	printf("----------------------------\n"); 
    //���Ϋ~ 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==5&&sort2[i]=='c'){
        	e1.pen+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d ���Ϋ~ %d��\n",year[i],month[i],day[i],money[i]);
			}
		}
    }   
    if(e1.pen==0)
    printf("���Ϋ~�`�@0��\n");
    else
    printf("���Ϋ~�`�@%d��\n",e1.pen);
    printf("----------------------------\n");
    return; 
}//eanaly  
void fanaly(FILE* fp,FUN f1,int year[],int month[],int day[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis){
    //Local Declarations
	int i;
	//Statements
    //�T�ֶO 
	for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==6&&sort2[i]=='a'){
        	f1.entertainment+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d �T�ֶO %d��\n",year[i],month[i],day[i],money[i]);
			}
		}
    }    
    if(f1.entertainment==0)
    printf("�T�ֶO�`�@0��=>�n�h��B�ͥX�h����\n");
    else
    printf("�T�ֶO�`�@%d��\n",f1.entertainment);
    printf("----------------------------\n");
    //��L 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==6&&sort2[i]=='b'){
        	f1.other+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d ��L %d��\n",year[i],month[i],day[i],money[i]);
			}
		}
    }    
    if(f1.other==0)
    printf("��L�`�@0��\n");
    else
    printf("��L�`�@%d��\n",f1.other);
	printf("----------------------------\n");  
    return;  
}//fanaly     
