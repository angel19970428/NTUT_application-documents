#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�ڲ{�b�����������O:�O�b�B�O�ƪ������M�ɮ׿�X�A����:�O�ưO�b�A�O�b���j�ﶵ�A�O�b���p�ﶵ�A 
//�ٻݧ������a��A����:��J����A��J���B 
//��J�������S�����b  
void Acctime(int *year,int *month,int *day);//�O�b�ɶ�function
void Memotime(int *year,int *month,int *day);//�O�Ʈɶ�function
void Item(char content[]);//�O�Ƽ��Dfunction


int main2(void){
	int select1,select2,money,yesno;
	//select1:��ܰO�b/�O��, select2:��ܰO�b���� , money:���B , yesno:�O�_�~�� 
	int year1=0,month1=0,day1=0;
	//year1�N��O�b���~,month1�N��O�b�����,day1�N��O�b�����
	int year2=0,month2=0,day2=0;
	//year2�N��O�ƪ��~,month2�N��O�ƪ����,day2�N��O�ƪ����
	int yearanalysis=0,monthanalysis=0;
	//yearanalysis�N��n���R���~,monthanalysis�N��n���R�����
	int statusMain,statusyearanalysis,statusmonthanalysis; 
	char select3,content[81];
	
	//select3:�O�b�����Ӷ� 
	do//�Q��do-while�j��ϵ{���i�H���ư��� 
	{
		printf("�п�ܤ���:1.�O�b 2.�O�� 3.�ݰ]�Ȥ��R 4.��ƾ� 5.������ 6.���}\n");
		//�Q�μƦr��ܰO�b�ΰO�� 
		//���� 
		do{
		   select1=0;
		   statusMain=0;
		   scanf("%d",&select1);
		   if(select1<1||select1>6){
		   fflush(stdin);
		   printf("��J���~�Э��s��J:\n");
		   statusMain=1;//���true
		   }
		   else
		   statusMain=0;//���false 
        }while(statusMain==1);
		//�N��ܵ��G�s�Jselect1�ܼ� 
		if(select1==1){
		   //�ϥ�if�j��i���޿�P�_�ϥΪ̿�ܰO�b�ΰO��                     
		   select2=Accounting(&select3);
		   //�^��Accounting()����  
		   if(select2>=1&&select2<=6){
                //�Yselect2���Ȭ�1~6�A����Acctime()�MAmount() 
				Acctime(&year1,&month1,&day1);
				money=Amount();
				//printf("%s\n%d\n%c\n%d\n",dateacc,select2,select3,money);//���տ�X���G 
				char fname[30]="output.txt";
				FILE *fp;
				fp=fopen(fname,"a");
				fprintf(fp,"%d/%d/%d\n%d%c\n%d\n",year1,month1,day1,select2,select3,money);
				if(fp) 
					fclose(fp);
				//�N�O�b���G�s�W��output.txt�� 
				printf("�O�_�~��O��? 1.�O ��L.�_\n");
				scanf("%d",&yesno);
				if(yesno==1)
					continue;
				else
					break;
	 			}	
			}
		if(select1==2)  //��ܰO�ơA�h����Memotime()��Item() 
		{
			Memotime(&year2,&month2,&day2);
			Item(content);
			//printf("%s\n%s\n",datememo,item);//���տ�X���G 
			char fname[30]="memo.txt";
				FILE *fp;
				fp=fopen(fname,"a");
				fprintf(fp,"%d/%d/%d\n%s\n",year2,month2,day2,content);
				if(fp)
					fclose(fp);
			printf("�O�_�~��O��? 1.�O ��L.�_\n");
				scanf("%d",&yesno);
				if(yesno==1)
					continue;
				else
					break;
		}
		if(select1==3){
			fflush(stdin);
			printf("�аݧA�n�ݴX�~�����R:\n");
			do{
		  		yearanalysis=0;
				statusyearanalysis=0;
		  		scanf("%d",&yearanalysis);
		   		if(yearanalysis<1||yearanalysis>9999){
		   			fflush(stdin);
		   			printf("��J�~�����~�Э��s��J:\n");
		   			statusyearanalysis=1;//���true
		   			}
		   		else
		   			statusyearanalysis=0;//���false 
        	}while(statusyearanalysis==1);
			printf("�аݧA�n��%d�~�X�몺���R:\n",yearanalysis);
			do{
		  		statusmonthanalysis=0;
		  		monthanalysis=0;
		  		scanf("%d",&monthanalysis);
		   		if(monthanalysis<1||monthanalysis>9999){
		   			fflush(stdin);
		   			printf("��J������~�Э��s��J:\n");
		   			statusmonthanalysis=1;//���true
		   			}
		   		else
		   			statusmonthanalysis=0;//���false 
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
 	//�O�bfunction,�i�J�O�b�����βӶ������,�ñN�����s�Jselect2, �Ӷ��s�Jselect3 
	fflush(stdin);
	int s2;
	int statusAccounting;
	//s2�N���������æ^�ǵ�select2 
	char c[6]={'a','b','c','d','e','f'};
	//�إ߰}�C�s��a~f�^��r��,�H���˵��ﶵ�O�_���T 
	printf("�п�ܤ���:1.�� 2.�� 3.�� 4.�� 5.�| 6.�� 7.��^����\n");
	//����	
	do{
		s2=0;
		statusAccounting=0;
		scanf("%d",&s2);
		if(s2<1||s2>7){
		fflush(stdin);
		printf("��J���~�Э��s��J:\n");
		statusAccounting=1;//���true
		}
		else
		statusAccounting=0;//���false 
	}while(statusAccounting==1);
	
	switch (s2)//�Q��switch�j��P�_�ϥΪ̿�ܨ��Ӥ��� 
	{
		case 1 :
			printf("�п�ܤ���:a.���I b.�ȶ� c.�߿� d.���� e.�d�] f.�s�� \n");
			scanf("%c",s3);
			scanf("%c",s3);
			break;
		case 2 :
			printf("�п�ܤ���:a.��`�Ϋ~ b.��A \n");
			scanf("%c",s3);
			scanf("%c",s3);
			break;
		case 3 :
			printf("�п�ܤ���:a.���q b.�Я� c.�q�� \n");
			scanf("%c",s3);
			scanf("%c",s3);
			break;
		case 4 :
			printf("�п�ܤ���:a.��q b.�o�� \n");
			scanf("%c",s3);
			scanf("%c",s3);
			break;
		case 5 :
			printf("�п�ܤ���:a.�ѶOb.�ǶOc.��� \n");
			scanf("%c",s3);
			scanf("%c",s3);
			break;
		case 6 :
			printf("�п�ܤ���:a.�T�ֶOb.��L \n");
			scanf("%c",s3);
			scanf("%c",s3);
			break;
		case 7 :
			return;
			break;
		default ://�Y��ܤ���1~7,�h����switch 	
			break;
	}
	int i,j;
	if(s2==1)
		j=6;
	else if(s2==3||s2==5)
		j=3;
	else
		j=2;
	for(i=0;i<j;i++) //�z�Lfor�j���˵���J�O�b�Ӷ��O�_���T,�Y���~�h��^�{���_�l�I 
	{
		if(*s3==c[i])
			return s2;		
	}
	printf("��J�Ӷ����~�Э��s��J\n");
	s2=0; 
	return s2;
	
}//Accounting




void Acctime(int *year,int *month,int *day){
	//�O�b�ɶ�function
	int statusAcctime;
	printf("�п�J���(�~/��/��):\n");
	do{
		*year=0;
		*month=0;
		*day=0; 
		statusAcctime=0;
		scanf("%d/%d/%d",year,month,day);
		if(*year<1||*year>9999){//�ˬd�~�� 
		fflush(stdin);
		printf("��J�~�����~�Э��s��J:\n");
		statusAcctime=1;//���true
		}else if(*month<1||*month>12){//�ˬd��� 
		fflush(stdin);
		printf("��J������~�Э��s��J:\n");
		statusAcctime=1;//���true 
		}else if(*day<1||*day>31){//�ˬd�@������� 
		fflush(stdin);
		printf("��J������~�Э��s��J:\n");
		statusAcctime=1;//���true 
		}else if((*month==4||*month==6||*month==9||*month==11)&&*day>30){//�ˬd�S��31�骺��� 
		fflush(stdin);
		printf("��J������~�Э��s��J:\n");
		statusAcctime=1;//���true 	
		}else if((*year%400==0||(*year%4==0&&*year%100!=0))&&*month==2&&*day>29){//�ˬd�|�~2�몺��� 
		fflush(stdin);
		printf("��J������~�Э��s��J:\n");
		statusAcctime=1;//���true 
		}else if(!(*year%400==0||(*year%4==0&&*year%100!=0))&&*month==2&&*day>28){//�ˬd���~2�몺��� 
		fflush(stdin);
		printf("��J������~�Э��s��J:\n");
		statusAcctime=1;	
		}else
		statusAcctime=0;//���false 
	}while(statusAcctime==1);
}//Acctime

int Amount(void){
	//�O�b���Bfunction
	int amount,statusAmount;
	printf("�п�J���B:\n");
	do{
		amount=0;
		statusAmount=0;
		scanf("%d",&amount);
		if(amount==0){
		fflush(stdin);
		printf("��J���B���~�A�Э��s��J:\n");
		statusAmount=1;//���true
		}
		else
		statusAmount=0;//���false 
	}while(statusAmount==1);
	printf("\n");
	return amount;
}//Amount

void Memotime(int *year,int *month,int *day){
	//�O�Ʈɶ�function
	int statusMemotime;
	printf("�п�J���(�~/��/��):\n");
	do{
		*year=0;
		*month=0;
		*day=0;
		statusMemotime=0;
		scanf("%d/%d/%d",year,month,day);
		if(*year<1||*year>9999){//�ˬd�~�� 
		fflush(stdin);
		printf("��J�~�����~�Э��s��J:\n");
		statusMemotime=1;//���true
		}else if(*month<1||*month>12){//�ˬd��� 
		fflush(stdin);
		printf("��J������~�Э��s��J:\n");
		statusMemotime=1;//���true 
		}else if(*day<1||*day>31){//�ˬd�@������� 
		fflush(stdin);
		printf("��J������~�Э��s��J:\n");
		statusMemotime=1;//���true 
		}else if((*month==4||*month==6||*month==9||*month==11)&&*day>30){//�ˬd�S��31�骺��� 
		fflush(stdin);
		printf("��J������~�Э��s��J:\n");
		statusMemotime=1;//���true 	
		}else if((*year%400==0||(*year%4==0&&*year%100!=0))&&*month==2&&*day>29){//�ˬd�|�~2�몺��� 
		fflush(stdin);
		printf("��J������~�Э��s��J:\n");
		statusMemotime=1;//���true 
		}else if(!(*year%400==0||(*year%4==0&&*year%100!=0))&&*month==2&&*day>28){//�ˬd���~2�몺��� 
		fflush(stdin);
		printf("��J������~�Э��s��J:\n");
		statusMemotime=1;	
		}else
		statusMemotime=0;//���false 
	}while(statusMemotime==1);
	return;		
}//Memotime
void Item(char content[]){
	//�O�Ƽ��Dfunction
	printf("�п�J�O�Ƥ��e:\n");
	scanf("%s",content);
	return;
}//Item


