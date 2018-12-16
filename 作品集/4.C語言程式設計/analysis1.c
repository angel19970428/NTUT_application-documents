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
	int count=0;//���
	//�]��l�Ȭ�0
	f1.breakfast=0;
  	f1.dinner=0;
  	f1.drink=0;
  	f1.lunch=0;
  	f1.nfood=0;
  	f1.snak=0;
  	c1.coat=0;
  	c1.daily=0;
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
	fclose(fp);
	
	//��output.txt��� 
	count=count/3;//3��@����� 
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
  	//����output.txt 
	fclose(fp);
    
	//system("PAUSE");
    return 0;
}//main

void foodanalysis(FILE* fp,food f1,int year[],int month[],int date[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis){
	//Local Declarations   
	int i;
	//Statements
	//���I 
	for(i=0;i<count;i++){
		if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==1&&sort2[i]=='a'){ 
        	f1.breakfast+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d ���I %d��\n",year[i],month[i],date[i],money[i]);
			}
        }       
	}
	if(f1.breakfast>=1500)
	printf("���I�`�@%d��=>���I�Y�Ӧh�F��\n",f1.breakfast);
	else 
	printf("���I�`�@%d��=>���Y���I�|�ܲ�\n",f1.breakfast);
	printf("----------------------------\n");
	 
    //�ȶ� 
	for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==1&&sort2[i]=='b'){
            f1.lunch+=money[i];
            if(money[i]!=0){
        		printf("%d/%d/%d �ȶ� %d��\n",year[i],month[i],date[i],money[i]);
			}
        }
    } 
	if(f1.lunch>=1500)
	printf("�ȶ��`�@%d��=>�ȶ��Y�Ӧh �|�Q��ı\n",f1.lunch);
	else 
	printf("�ȶ��`�@%d��=>�ȶ��Y���Ӥ֤F��ή@?\n",f1.lunch);
	printf("----------------------------\n");
    //�߶�        
    for(i=0;i<count;i++){
		if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==1&&sort2[i]=='c'){
			f1.dinner+=money[i];
			if(money[i]!=0){
        		printf("%d/%d/%d �߶� %d��\n",year[i],month[i],date[i],money[i]);
			}	 
		}
	}
	if(f1.dinner>=3000)
    printf("�߶��`�@%d��=>�߶��Y�Ӧh�|�D\n",f1.dinner);
    else 
    printf("�߶��`�@%d��=>�߶��Y�o�� ���d\n",f1.dinner);
    printf("----------------------------\n");
	//�d�]		      
    for(i=0;i<count;i++){
        if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==1&&sort2[i]=='d'){
        	f1.nfood+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d �d�] %d��\n",year[i],month[i],date[i],money[i]);
			}
		}
            
    }
	if(f1.nfood>=1500)
    printf("�d�]�`�@%d��=>�d�]�֦Y�I\n",f1.nfood);
    else if(f1.nfood<=1500)
    printf("�d�]�`�@%d��=>�ٿ��ٿ�\n",f1.nfood);
    printf("----------------------------\n");
    //����     
    for(i=0;i<count;i++){
        if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==1&&sort2[i]=='e'){
            f1.drink+=money[i];
            if(money[i]!=0){
        		printf("%d/%d/%d ���� %d��\n",year[i],month[i],date[i],money[i]);
			}
		}
    }
	if(f1.drink>=1500)
    printf("�����`�@%d��=>�ܶ��Ʒ|�D\n",f1.drink);
    else 
    printf("�����`�@%d��=>�ܬٿ���I\n",f1.drink);
    printf("----------------------------\n");
    //�s��     
    for(i=0;i<count;i++){
        if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==1&&sort2[i]=='f'){
            f1.snak+=money[i];
            if(money[i]!=0){
        		printf("%d/%d/%d �s�� %d��\n",year[i],month[i],date[i],money[i]);
			}
		}
    }
	if(f1.snak>=1500)
    printf("�s���`�@%d��=>���n�ӷR�Y\n",f1.snak);
    else 
    printf("�s���`�@%d��=>�ٿ��S���d\n",f1.snak);
    printf("----------------------------\n");
    return;     
}//food foodanalysis
	 
void clothanalysis1(FILE* fp,cloth c1,int year[],int month[],int date[],int sort1[],char sort2[],int money[],int count,int **yearanalysis,int ** monthanalysis){
   	//Local Declarations 
    int i;
    //Statements
    //�ͬ��Ϋ~ 
    for(i=0;i<count;i++){
    	if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==2&&sort2[i]=='a'){
        	c1.daily+=money[i];
        	if(money[i]!=0){
        		printf("%d/%d/%d �ͬ��Ϋ~ %d��\n",year[i],month[i],date[i],money[i]);
			}
		}
    }
	if(c1.daily>=2000)
    printf("�ͬ��Ϋ~�`�@%d��=>�̪�R�}�G�@\n",c1.daily);
    else 
    printf("�ͬ��Ϋ~�`�@%d��=>�ͬ��٬O�n�L\n",c1.daily);
    printf("----------------------------\n");
    //��A    
	for(i=0;i<count;i++){
        if(year[i]==**yearanalysis&&month[i]==**monthanalysis&&sort1[i]==2&&sort2[i]=='b'){
            c1.coat+=money[i];
            if(money[i]!=0){
        		printf("%d/%d/%d ��A %d��\n",year[i],month[i],date[i],money[i]);
			}
		}
    }
	if(c1.coat>=2000)
    printf("��A�`�@%d��=>���`�ʪ��N�n\n",c1.coat);
    else 
    printf("��A�`�@%d��=>�ٿ��ٿ�\n",c1.coat);
    printf("----------------------------\n");
    return;    
}//cloth clothanalysis1
