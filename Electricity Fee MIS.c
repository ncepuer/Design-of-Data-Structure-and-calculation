#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void maintain(char add1[]);
void count(int k,char add1[]);
void search(int k,int year1,int month1,int day1,int year2,int month2,int day2);
void statistics_month(int k);
void statistics_quarter(int k);
void statistics_year(int k);

int menu();
float count1(float price,float num);
float count2(float price,float num);
float count3(float price,float num);
float count4(float price,float num,float num1,float num2);
float count5(float price,float num,float num1,float num2,float price1,float cap);
void draw_month1(float a[]);
void draw_month2(float a[]);
void draw_month3(float a[]);
void draw_month4(float a[]);
void draw_month5(float a[]);
void draw_quarter1(float a[]);
void draw_quarter2(float a[]);
void draw_quarter3(float a[]);
void draw_quarter4(float a[]);
void draw_quarter5(float a[]);

/////////////////////////////////////////////
void main()
{
	menu();
}

int menu()
{
	int m,k,year1,year2,month1,month2,day1,day2;
	char flag;
	char add_data[100];
	do
	{
		system("cls");
		printf("\n\t\t******************************************\n");
		printf("\t\t*          ��ӭʹ�õ�Ѻ���ϵͳ!         *\n");
		printf("\t\t*                                        *\n");
		printf("\t\t*          ����:   ������                *\n");
		printf("\t\t*          ѧ��:   120181080214          *\n");
		printf("\t\t*          �༶:   �����1802��          *\n");
		printf("\t\t******************************************\n");
		printf("\n**********************************************************************************\n");
		printf("\n\t\t******************************************\n");
		printf("\t\t*                                        *\n");
		printf("\t\t*    1.����ά��        2.������        *\n");
		printf("\t\t*                                        *\n");
		printf("\t\t*    3.��ѯ��Ѽ�¼    4.ͳ��(��/��/��)  *\n");
		printf("\t\t*                                        *\n");
		printf("\t\t******************************************\n\n");
		printf("��ѡ����:");
		scanf("%d",&k);getchar();
		switch(k)
		{
		    case 1:{
				system("cls");
				printf("\n***************************************����ά��*************************************\n\n");
				maintain(add_data);break;}
			case 2:{
				system("cls");
				printf("\n***************************************������*************************************\n\n");
				printf("\n 1.����ͻ�\n 2.�Ǿ���ͻ�\n 3.��ҵ�ͻ�\n 4.���չ�ҵ�ͻ�\n 5.��ҵ�ͻ�\n��ѡ��ͻ�����:");
				scanf("%d",&k);getchar();
				count(k,add_data);
				break;}
			case 3:{
				system("cls");
				printf("\n*************************************��ѯ��Ѽ�¼*************************************\n\n");
				printf("\n 1.����ͻ�\n 2.�Ǿ���ͻ�\n 3.��ҵ�ͻ�\n 4.���չ�ҵ�ͻ�\n 5.��ҵ�ͻ�\n��ѡ��ͻ�����:");
				scanf("%d",&k);getchar();
				printf("\n\t2017��01��01����2018��12��31��\n��������ʼ����(�� �� ��):");
				scanf("%d%d%d",&year1,&month1,&day1);
				printf("�������������(�� �� ��):");
				scanf("%d%d%d",&year2,&month2,&day2);
				search(k,year1,month1,day1,year2,month2,day2);
				break;}
			case 4:{
				system("cls");
				printf("\n*****************************************ͳ��*************************************\n\n");
				printf("\n 1.����ͻ�\n 2.�Ǿ���ͻ�\n 3.��ҵ�ͻ�\n 4.���չ�ҵ�ͻ�\n 5.��ҵ�ͻ�\n��ѡ��ͻ�����:");
				scanf("%d",&k);getchar();
				printf("\n 1.���¶�ͳ��\n 2.������ͳ��\n 3.�����ͳ��\n��ѡ����Ŀ:");
				scanf("%d",&m);getchar();
				switch(m)
				{
					case 1:statistics_month(k);break;
					case 2:statistics_quarter(k);break;
					case 3:statistics_year(k);break;
					default:printf("�޴����!\n");
				}
				break;}
			default:printf("�޴����!\n");
		}
		getchar();
		printf("����������?(Y/N):");
		flag=getchar();
		getchar();
	}while(flag=='y'||flag=='Y');
	printf("\n");
	return 0;
}

/////////////////////////////////////////////
void maintain(char add[])
{
	FILE *fp;
	float a,b;
	printf("����������ļ��Ĵ����ַ:");
	scanf("%s",add);
	if((fp=fopen(add,"w+"))==NULL)
	{printf("Error!\n");return;}
	fprintf(fp,"�û�����          ��ȵ��(Ԫ/kwh)          �������(Ԫ/kVA)\n");
	printf("�������������ĵ�ȵ��:");scanf("%f",&a);
	fprintf(fp,"��������            %10.2f                         \n",a);
	printf("������Ǿ�������ĵ�ȵ��:");scanf("%f",&a);
	fprintf(fp,"�Ǿ���                %10.2f                         \n",a);
	printf("��������ҵ�õ�ͻ��ĵ�ȵ��:");scanf("%f",&a);
	fprintf(fp,"��ҵ�õ�ͻ�      %10.2f                         \n",a);
	printf("��������չ�ҵ�ͻ��ĵ�ȵ��:");scanf("%f",&a);
	fprintf(fp,"���չ�ҵ�ͻ�      %10.2f                         \n",a);
	printf("�������ҵ�ͻ��ĵ�ȵ�ۼ��������:");scanf("%f%f",&a,&b);
	fprintf(fp,"��ҵ�ͻ�         %10.2f                         %10.2f\n",a,b);
	fclose(fp);
}

void count(int k,char add1[])
{
	int year,month,day;
	float total,price,price1,num,num1,num2,cap;
	char add2[100],add3[100],str[100];
	FILE *fp1,*fp2,*fp3;
	if((fp1=fopen(add1,"r"))==NULL)
	{printf("Error!\n");return;}
	switch(k)
	{
		case 1:{
			fgets(str,80,fp1);fgets(str,16,fp1);
			fscanf(fp1,"%f",&price);
			printf("��������������õ������ļ��ĵ�ַ:");
			scanf("%s",add2);
			printf("����������������ļ��ĵ�ַ:");
			scanf("%s",add3);
			if((fp2=fopen(add2,"r"))==NULL)
			{printf("Error!\n");return;}
			fp3=fopen(add3,"w+");
			fgets(str,80,fp2);
			fprintf(fp3,"ʱ��(������)                    �õ���(kw��h)                    ���(Ԫ)\n");
			while(!feof(fp2))
			{	fscanf(fp2,"%d%d%d%f",&year,&month,&day,&num);
				total=count1(price,num);
				fprintf(fp3,"%d %02d %02d                           %.2f                            %-6.3f\n",year,month,day,num,total);
			}
			fclose(fp2);fclose(fp3);break;}
		case 2:{
			fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,16,fp1);
			fscanf(fp1,"%f",&price);
			printf("������Ǿ��������õ������ļ��ĵ�ַ:");
			scanf("%s",add2);
			printf("����������������ļ��ĵ�ַ:");
			scanf("%s",add3);
			if((fp2=fopen(add2,"r"))==NULL)
			{printf("Error!\n");return;}
			fp3=fopen(add3,"w+");
			fgets(str,80,fp2);
			fprintf(fp3,"ʱ��(������)                    �õ���(kw��h)                    ���(Ԫ)\n");
			while(!feof(fp2))
			{	fscanf(fp2,"%d%d%d%f",&year,&month,&day,&num);
				total=count2(price,num);
				fprintf(fp3,"%d %02d %02d                           %.2f                            %-6.3f\n",year,month,day,num,total);
			}
			fclose(fp2);fclose(fp3);break;}
		case 3:{
			fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,16,fp1);
			fscanf(fp1,"%f",&price);
			printf("��������ҵ�ͻ��õ������ļ��ĵ�ַ:");
			scanf("%s",add2);
			printf("����������������ļ��ĵ�ַ:");
			scanf("%s",add3);
			if((fp2=fopen(add2,"r"))==NULL)
			{printf("Error!\n");return;}
			fp3=fopen(add3,"w+");
			fgets(str,80,fp2);
			fprintf(fp3,"ʱ��(������)                    �õ���(kw��h)                    ���(Ԫ)\n");
			while(!feof(fp2))
			{	fscanf(fp2,"%d%d%d%f",&year,&month,&day,&num);
				total=count3(price,num);
				fprintf(fp3,"%d %02d %02d                           %.2f                            %-6.3f\n",year,month,day,num,total);
			}
			fclose(fp2);fclose(fp3);break;}
		case 4:{
			fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,16,fp1);
			fscanf(fp1,"%f",&price);
			printf("��������չ�ҵ�ͻ��õ������ļ��ĵ�ַ:");
			scanf("%s",add2);
			printf("����������������ļ��ĵ�ַ:");
			scanf("%s",add3);
			if((fp2=fopen(add2,"r"))==NULL)
			{printf("Error!\n");return;}
			fp3=fopen(add3,"w+");
			fgets(str,80,fp2);fgets(str,80,fp2);
			fprintf(fp3,"ʱ��(������)                    �õ���(kw��h)                  �߷��õ���                    �͹��õ���                    ���(Ԫ)\n");
			while(!feof(fp2))
			{	fscanf(fp2,"%d%d%d%f%f%f",&year,&month,&day,&num,&num1,&num2);
				total=count4(price,num,num1,num2);
				fprintf(fp3,"%d %02d %02d                           %.2f                              %.2f                              %.2f                            %-6.3f\n",year,month,day,num,num1,num2,total);
			}
			fclose(fp2);fclose(fp3);break;}
		case 5:{
			fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,16,fp1);
			fscanf(fp1,"%f%f",&price,&price1);
			printf("�������ҵ�ͻ��õ������ļ��ĵ�ַ:");
			scanf("%s",add2);
			printf("����������������ļ��ĵ�ַ:");
			scanf("%s",add3);
			if((fp2=fopen(add2,"r"))==NULL)
			{printf("Error!\n");return;}
			fp3=fopen(add3,"w+");
			fgets(str,80,fp2);fgets(str,80,fp2);
			fscanf(fp2,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&cap);
			total=count5(price,num,num1,num2,price1,cap);
			fprintf(fp3,"ʱ��(������)                    �õ���(kw��h)                  �߷��õ���                    �͹��õ���                    ���(Ԫ)                    ��ѹ������:%.2fkVA\n",cap);
			fprintf(fp3,"%d %02d %02d                           %.2f                              %.2f                              %.2f                            %-6.3f\n",year,month,day,num,num1,num2,total);
			while(!feof(fp2))
			{	fscanf(fp2,"%d%d%d%f%f%f",&year,&month,&day,&num,&num1,&num2);
				total=count5(price,num,num1,num2,price1,cap);
				fprintf(fp3,"%d %02d %02d                           %.2f                              %.2f                              %.2f                            %-6.3f\n",year,month,day,num,num1,num2,total);
			}
			fclose(fp2);fclose(fp3);break;}
		default:printf("ѡ�����!\n");
	}
	fclose(fp1);
}

void search(int k,int year1,int month1,int day1,int year2,int month2,int day2)
{
	FILE *fp;
	float num,total,num1,num2,num_,total_,num1_,num2_;
	int year,month,day;
	char add[100],str[100];
	switch(k)
	{
		case 1:{
			printf("��������������������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);
			do{
				fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
			}while(!(year==year1&&month==month1&&day==day1));
			num_=num;total_=total;
			while(!(year==year2&&month==month2&&day==day2))
			{
				fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
				num_+=num;	total_+=total;
			}
			printf("\n%d��%02d��%02d����%d��%02d��%02d��:\n �����������õ���Ϊ%.2fkWh\n ���������ܵ��Ϊ%.3fԪ\n",year1,month1,day1,year2,month2,day2,num_,total_);
			fclose(fp);break;}
		case 2:{
			printf("������Ǿ��������������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);
			do{
				fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
			}while(!(year==year1&&month==month1&&day==day1));
			num_=num;total_=total;
			while(!(year==year2&&month==month2&&day==day2))
			{
				fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
				num_+=num;	total_+=total;
			}
			printf("\n%d��%02d��%02d����%d��%02d��%02d��:\n �Ǿ����������õ���Ϊ%.2fkWh\n �Ǿ��������ܵ��Ϊ%.3fԪ\n",year1,month1,day1,year2,month2,day2,num_,total_);
			fclose(fp);break;}
		case 3:{
			printf("��������ҵ�ͻ���������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);
			do{
				fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
			}while(!(year==year1&&month==month1&&day==day1));
			num_=num;total_=total;
			while(!(year==year2&&month==month2&&day==day2))
			{
				fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
				num_+=num;	total_+=total;
			}
			printf("\n%d��%02d��%02d����%d��%02d��%02d��:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",year1,month1,day1,year2,month2,day2,num_,total_);
			fclose(fp);break;}
		case 4:{
			printf("��������չ�ҵ�ͻ���������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);fgets(str,80,fp);
			do{
				fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
			}while(!(year==year1&&month==month1&&day==day1));
			num_=num;num1_=num1;num2_=num2;total_=total;
			while(!(year==year2&&month==month2&&day==day2))
			{
				fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
				num_+=num;	num1_+=num1;	num2_+=num2;	total_+=total;
			}
			printf("\n%d��%02d��%02d����%d��%02d��%02d��:\n ���չ�ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ���չ�ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",year1,month1,day1,year2,month2,day2,num_,num1_,num2_,total_);
			fclose(fp);break;}
		case 5:{
			printf("�������ҵ�ͻ���������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,100,fp);fgets(str,100,fp);
			do{
				fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
			}while(!(year==year1&&month==month1&&day==day1));
			num_=num;num1_=num1;num2_=num2;total_=total;
			while(!(year==year2&&month==month2&&day==day2))
			{
				fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
				num_+=num;	num1_+=num1;	num2_+=num2;	total_+=total;
			}
			printf("\n%d��%02d��%02d����%d��%02d��%02d��:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",year1,month1,day1,year2,month2,day2,num_,num1_,num2_,total_);
			fclose(fp);break;}
		default:printf("ѡ�����!\n");
	}
}

void statistics_month(int k)
{
	FILE *fp;
	float num,total,num1,num2,num_[24],total_[24],num1_[24],num2_[24];
	int year,month,day,mon,i;
	char add[100],str[100];
	switch(k)
	{
		case 1:{
			printf("��������������������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");exit(1);}
			fgets(str,80,fp);
			fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
			for(i=0;!feof(fp);i++)
			{
				mon=month;	num_[i]=0;	total_[i]=0;
				while(month==mon&&!feof(fp))
				{
					num_[i]+=num;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
				}
			}
			for(i=0;i<12;i++)
			{
				printf("2017��%02d��:\n �����������õ���Ϊ%.2fkWh\n ���������ܵ��Ϊ%.3fԪ\n",i+1,num_[i],total_[i]);
			}
			for(i=12;i<24;i++)
			{
				printf("2018��%02d��:\n �����������õ���Ϊ%.2fkWh\n ���������ܵ��Ϊ%.3fԪ\n",i-11,num_[i],total_[i]);
			}
			draw_month1(num_);
			draw_month2(total_);
			fclose(fp);break;}
		case 2:{
			printf("������Ǿ��������������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);
			fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
			for(i=0;!feof(fp);i++)
			{
				mon=month;	num_[i]=0;	total_[i]=0;
				while(month==mon&&!feof(fp))
				{
					num_[i]+=num;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
				}
			}
			for(i=0;i<12;i++)
			{
				printf("2017��%02d��:\n �Ǿ����������õ���Ϊ%.2fkWh\n �Ǿ��������ܵ��Ϊ%.3fԪ\n",i+1,num_[i],total_[i]);
			}
			for(i=12;i<24;i++)
			{
				printf("2018��%02d��:\n �Ǿ����������õ���Ϊ%.2fkWh\n �Ǿ��������ܵ��Ϊ%.3fԪ\n",i-11,num_[i],total_[i]);
			}
			draw_month1(num_);
			draw_month2(total_);
			fclose(fp);break;}
		case 3:{
			printf("��������ҵ�ͻ���������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);
			fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
			for(i=0;!feof(fp);i++)
			{
				mon=month;	num_[i]=0;	total_[i]=0;
				while(month==mon&&!feof(fp))
				{
					num_[i]+=num;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
				}
			}
			for(i=0;i<12;i++)
			{
				printf("2017��%02d��:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",i+1,num_[i],total_[i]);
			}
			for(i=12;i<24;i++)
			{
				printf("2018��%02d��:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",i-11,num_[i],total_[i]);
			}
			draw_month1(num_);
			draw_month2(total_);
			fclose(fp);break;}
		case 4:{
			printf("��������չ�ҵ�ͻ���������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);fgets(str,80,fp);
			fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
			for(i=0;!feof(fp);i++)
			{
				mon=month;	num_[i]=0;	num1_[i]=0;	num2_[i]=0;	total_[i]=0;
				while(month==mon&&!feof(fp))
				{
					num_[i]+=num;	num1_[i]+=num1;	num2_[i]+=num2;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
				}
			}
			for(i=0;i<12;i++)
			{
				printf("2017��%02d��:\n ���չ�ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ���չ�ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",i+1,num_[i],num1_[i],num2_[i],total_[i]);
			}
			for(i=12;i<24;i++)
			{
				printf("2018��%02d��:\n ���չ�ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ���չ�ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",i-11,num_[i],num1_[i],num2_[i],total_[i]);
			}
			draw_month1(num_);
			draw_month3(num1_);
			draw_month4(num2_);
			draw_month2(total_);
			fclose(fp);break;}
		case 5:{
			printf("�������ҵ�ͻ���������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,100,fp);fgets(str,100,fp);
			fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
			for(i=0;!feof(fp);i++)
			{
				mon=month;	num_[i]=0;	num1_[i]=0;	num2_[i]=0;	total_[i]=0;
				while(month==mon&&!feof(fp))
				{
					num_[i]+=num;	num1_[i]+=num1;	num2_[i]+=num2;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
				}
			}
			for(i=0;i<12;i++)
			{
				printf("2017��%02d��:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",i+1,num_[i],num1_[i],num2_[i],total_[i]);
			}
			for(i=12;i<24;i++)
			{
				printf("2018��%02d��:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",i-11,num_[i],num1_[i],num2_[i],total_[i]);
			}
			draw_month1(num_);
			draw_month3(num1_);
			draw_month4(num2_);
			draw_month5(total_);
			fclose(fp);break;}
		default:printf("ѡ�����!\n");
	}
}

void statistics_quarter(int k)
{
	FILE *fp;
	float num,total,num1,num2,num_[8],total_[8],num1_[8],num2_[8];
	int year,month,day,mon,i;
	char add[100],str[100];
	switch(k)
	{
		case 1:{
			printf("��������������������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);
			fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
			for(i=0;!feof(fp);i++)
			{
				mon=month;	num_[i]=0;	total_[i]=0;
				while(mon<=month&&month<=mon+2&&!feof(fp))
				{
					num_[i]+=num;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
				}
			}
			for(i=0;i<4;i++)
			{
				printf("2017���%d����:\n �����������õ���Ϊ%.2fkWh\n ���������ܵ��Ϊ%.3fԪ\n",i+1,num_[i],total_[i]);
			}
			for(i=4;i<8;i++)
			{
				printf("2018���%d����:\n �����������õ���Ϊ%.2fkWh\n ���������ܵ��Ϊ%.3fԪ\n",i-3,num_[i],total_[i]);
			}
			draw_quarter1(num_);
			draw_quarter2(total_);
			fclose(fp);break;}
		case 2:{
			printf("������Ǿ��������������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);
			fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
			for(i=0;!feof(fp);i++)
			{
				mon=month;	num_[i]=0;	total_[i]=0;
				while(mon<=month&&month<=mon+2&&!feof(fp))
				{
					num_[i]+=num;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
				}
			}
			for(i=0;i<4;i++)
			{
				printf("2017���%d����:\n �Ǿ����������õ���Ϊ%.2fkWh\n �Ǿ��������ܵ��Ϊ%.3fԪ\n",i+1,num_[i],total_[i]);
			}
			for(i=4;i<8;i++)
			{
				printf("2018���%d����:\n �Ǿ����������õ���Ϊ%.2fkWh\n �Ǿ��������ܵ��Ϊ%.3fԪ\n",i-3,num_[i],total_[i]);
			}
			draw_quarter1(num_);
			draw_quarter2(total_);
			fclose(fp);break;}
		case 3:{
			printf("��������ҵ�ͻ���������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);
			fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
			for(i=0;!feof(fp);i++)
			{
				mon=month;	num_[i]=0;	total_[i]=0;
				while(mon<=month&&month<=mon+2&&!feof(fp))
				{
					num_[i]+=num;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
				}
			}
			for(i=0;i<4;i++)
			{
				printf("2017���%d����:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",i+1,num_[i],total_[i]);
			}
			for(i=4;i<8;i++)
			{
				printf("2018���%d����:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",i-3,num_[i],total_[i]);
			}
			draw_quarter1(num_);
			draw_quarter2(total_);
			fclose(fp);break;}
		case 4:{
			printf("��������չ�ҵ�ͻ���������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);fgets(str,80,fp);
			fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
			for(i=0;!feof(fp);i++)
			{
				mon=month;	num_[i]=0;	num1_[i]=0;	num2_[i]=0;	total_[i]=0;
				while(mon<=month&&month<=mon+2&&!feof(fp))
				{
					num_[i]+=num;	num1_[i]+=num1;	num2_[i]+=num2;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
				}
			}
			for(i=0;i<4;i++)
			{
				printf("2017���%d����:\n ���չ�ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ���չ�ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",i+1,num_[i],num1_[i],num2_[i],total_[i]);
			}
			for(i=4;i<8;i++)
			{
				printf("2018���%d����:\n ���չ�ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ���չ�ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",i-3,num_[i],num1_[i],num2_[i],total_[i]);
			}
			draw_quarter1(num_);
			draw_quarter3(num1_);
			draw_quarter4(num2_);
			draw_quarter2(total_);
			fclose(fp);break;}
		case 5:{
			printf("�������ҵ�ͻ���������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,100,fp);fgets(str,100,fp);
			fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
			for(i=0;!feof(fp);i++)
			{
				mon=month;	num_[i]=0;	num1_[i]=0;	num2_[i]=0;	total_[i]=0;
				while(mon<=month&&month<=mon+2&&!feof(fp))
				{
					num_[i]+=num;	num1_[i]+=num1;	num2_[i]+=num2;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
				}
			}
			for(i=0;i<4;i++)
			{
				printf("2017���%d����:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",i+1,num_[i],num1_[i],num2_[i],total_[i]);
			}
			for(i=4;i<8;i++)
			{
				printf("2018���%d����:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",i-3,num_[i],num1_[i],num2_[i],total_[i]);
			}
			draw_quarter1(num_);
			draw_quarter3(num1_);
			draw_quarter4(num2_);
			draw_quarter5(total_);
			fclose(fp);break;}
		default:printf("ѡ�����!\n");
	}
}

void statistics_year(int k)
{
	FILE *fp;
	float num,total,num1,num2,num_[2],total_[2],num1_[2],num2_[2];
	int year,month,day,ye,i;
	char add[100],str[100];
	switch(k)
	{
		case 1:{
			printf("��������������������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);
			fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
			for(i=0;!feof(fp);i++)
			{
				ye=year;	num_[i]=0;	total_[i]=0;
				while(year==ye&&!feof(fp))
				{
					num_[i]+=num;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
				}
			}
			printf("2017��:\n �����������õ���Ϊ%.2fkWh\n ���������ܵ��Ϊ%.3fԪ\n",num_[0],total_[0]);
			printf("2018��:\n �����������õ���Ϊ%.2fkWh\n ���������ܵ��Ϊ%.3fԪ\n",num_[1],total_[1]);
			fclose(fp);break;}
		case 2:{
			printf("������Ǿ��������������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);
			fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
			for(i=0;!feof(fp);i++)
			{
				ye=year;	num_[i]=0;	total_[i]=0;
				while(year==ye&&!feof(fp))
				{
					num_[i]+=num;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
				}
			}
			printf("2017��:\n �Ǿ����������õ���Ϊ%.2fkWh\n �Ǿ��������ܵ��Ϊ%.3fԪ\n",num_[0],total_[0]);
			printf("2018��:\n �Ǿ����������õ���Ϊ%.2fkWh\n �Ǿ��������ܵ��Ϊ%.3fԪ\n",num_[1],total_[1]);
			fclose(fp);break;}
		case 3:{
			printf("��������ҵ�ͻ���������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);
			fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
			for(i=0;!feof(fp);i++)
			{
				ye=year;	num_[i]=0;	total_[i]=0;
				while(year==ye&&!feof(fp))
				{
					num_[i]+=num;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f",&year,&month,&day,&num,&total);
				}
			}
			printf("2017��:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",num_[0],total_[0]);
			printf("2018��:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",num_[1],total_[1]);
			fclose(fp);break;}
		case 4:{
			printf("��������չ�ҵ�ͻ���������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,80,fp);fgets(str,80,fp);
			fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
			for(i=0;!feof(fp);i++)
			{
				ye=year;	num_[i]=0;	num1_[i]=0;	num2_[i]=0;	total_[i]=0;
				while(year==ye&&!feof(fp))
				{
					num_[i]+=num;	num1_[i]+=num1;	num2_[i]+=num2;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
				}
			}
			printf("2017��:\n ���չ�ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ���չ�ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",num_[0],num1_[0],num2_[0],total_[0]);
			printf("2018��:\n ���չ�ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ���չ�ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",num_[1],num1_[1],num2_[1],total_[1]);
			fclose(fp);break;}
		case 5:{
			printf("�������ҵ�ͻ���������ļ��ĵ�ַ:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("��ַ����!\n");return;}
			fgets(str,100,fp);fgets(str,100,fp);
			fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
			for(i=0;!feof(fp);i++)
			{
				ye=year;	num_[i]=0;	num1_[i]=0;	num2_[i]=0;	total_[i]=0;
				while(year==ye&&!feof(fp))
				{
					num_[i]+=num;	num1_[i]+=num1;	num2_[i]+=num2;	total_[i]+=total;
					fscanf(fp,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&total);
				}
			}
			printf("2017��:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",num_[0],num1_[0],num2_[0],total_[0]);
			printf("2018��:\n ��ҵ�ͻ����õ���Ϊ%.2fkWh  ���и߷��õ�����Ϊ%.2fkWh,�͹��õ�����Ϊ%.2fkWh\n ��ҵ�ͻ��ܵ��Ϊ%.3fԪ\n",num_[1],num1_[1],num2_[1],total_[1]);
			fclose(fp);break;}
		default:printf("ѡ�����!\n");
	}
}

///////////////////////////////////

float count1(float price,float num)
{
	return price*num;
}
float count2(float price,float num)
{
	return price*num;
}
float count3(float price,float num)
{
	return price*num;
}
float count4(float price,float num,float num1,float num2)
{
	return price*num+price*num1*0.5-price*num2*0.5;
}
float count5(float price,float num,float num1,float num2,float price1,float cap)
{
	return price1*cap/30+price*num+price*num1*0.5-price*num2*0.5;
}

void draw_month1(float a[])
{
	int i,j;
	printf("\n���õ���ͳ����״ͼΪ:\n\n");
	printf("       ʱ��^\n");
	printf("           |\n");
	for(i=11;i>=0;i--)
	{
		printf("2017��%02d�� |",i+1);
		for(j=0;j<(int)a[i]/10;j++)
			printf("**");
		printf("%.2f\n",a[i]);
	}
	printf("-----------+---------------------------------------------------->10kWh\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20  22  24\n");
		printf("\n\n       ʱ��^\n");
	printf("           |\n");
	for(i=23;i>=12;i--)
	{
		printf("2018��%02d�� |",i-11);
		for(j=0;j<(int)a[i]/10;j++)
			printf("**");
		printf("%.2f\n",a[i]);
	}
	printf("-----------+---------------------------------------------------->10kWh\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20  22  24\n");
}
void draw_month2(float a[])
{
	int i,j;
	printf("\n�µ��ͳ����״ͼΪ:\n\n");
	printf("       ʱ��^\n");
	printf("           |\n");
	for(i=11;i>=0;i--)
	{
		printf("2017��%02d�� |",i+1);
		for(j=0;j<(int)a[i]/10;j++)
			printf("**");
		printf("%.3f\n",a[i]);
	}
	printf("-----------+------------------------------------------------------------>10Ԫ\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20  22  24  26  28\n");
		printf("\n\n       ʱ��^\n");
	printf("           |\n");
	for(i=23;i>=12;i--)
	{
		printf("2018��%02d�� |",i-11);
		for(j=0;j<(int)a[i]/10;j++)
			printf("**");
		printf("%.3f\n",a[i]);
	}
	printf("-----------+------------------------------------------------------------>10Ԫ\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20  22  24  26  28\n");
}
void draw_month3(float a[])
{
	int i,j;
	printf("\n�¸߷��õ���ͳ����״ͼΪ:\n\n");
	printf("       ʱ��^\n");
	printf("           |\n");
	for(i=11;i>=0;i--)
	{
		printf("2017��%02d�� |",i+1);
		for(j=0;j<(int)a[i];j++)
			printf("**");
		printf("%.2f\n",a[i]);
	}
	printf("-----------+----------------------------------------------------------->kWh\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20  22  24  26  28  30\n");
		printf("\n\n       ʱ��^\n");
	printf("           |\n");
	for(i=23;i>=12;i--)
	{
		printf("2018��%02d�� |",i-11);
		for(j=0;j<(int)a[i];j++)
			printf("**");
		printf("%.2f\n",a[i]);
	}
	printf("-----------+----------------------------------------------------------->kWh\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20  22  24  26  28  30\n");
}
void draw_month4(float a[])
{
	int i,j;
	printf("\n�µ͹��õ���ͳ����״ͼΪ:\n\n");
	printf("       ʱ��^\n");
	printf("           |\n");
	for(i=11;i>=0;i--)
	{
		printf("2017��%02d�� |",i+1);
		for(j=0;j<(int)a[i];j++)
			printf("**");
		printf("%.2f\n",a[i]);
	}
	printf("-----------+---------------------------------------->kWh\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20\n");
		printf("\n\n       ʱ��^\n");
	printf("           |\n");
	for(i=23;i>=12;i--)
	{
		printf("2018��%02d�� |",i-11);
		for(j=0;j<(int)a[i];j++)
			printf("**");
		printf("%.2f\n",a[i]);
	}
	printf("-----------+---------------------------------------->kWh\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20\n");
}
void draw_month5(float a[])
{
	int i,j;
	printf("\n�µ��ͳ����״ͼΪ:\n\n");
	printf("       ʱ��^\n");
	printf("           |\n");
	for(i=11;i>=0;i--)
	{
		printf("2017��%02d�� |",i+1);
		for(j=0;j<((int)a[i]-22000)/100;j++)
			printf("**");
		printf("%.3f\n",a[i]);
	}
	printf("-----------+-------------------------------------------------------------->100Ԫ\n");
	printf("        220|  222 224 226 228 230 232 234 236 238 240 242 244 246 248 250\n");
		printf("\n\n       ʱ��^\n");
	printf("           |\n");
	for(i=23;i>=12;i--)
	{
		printf("2018��%02d�� |",i-11);
		for(j=0;j<((int)a[i]-22000)/100;j++)
			printf("**");
		printf("%.3f\n",a[i]);
	}
	printf("-----------+-------------------------------------------------------------->100Ԫ\n");
	printf("        220|  222 224 226 228 230 232 234 236 238 240 242 244 246 248 250\n");
}

void draw_quarter1(float a[])
{
	int i,j;
	printf("\n�����õ���ͳ����״ͼΪ:\n\n");
	printf("          ʱ��^\n");
	printf("              |\n");
	for(i=3;i>=0;i--)
	{
		printf("2017���%d���� |",i+1);
		for(j=0;j<(int)a[i]/50;j++)
			printf("****");
		printf("%.2f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+---------------------------------------------------->10kWh\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55  60  65\n");
	printf("\n\n          ʱ��^\n");
	printf("              |\n");
	for(i=7;i>=4;i--)
	{
		printf("2018���%d���� |",i-3);
		for(j=0;j<(int)a[i]/50;j++)
			printf("****");
		printf("%.2f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+---------------------------------------------------->10kWh\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55  60  65\n");
}
void draw_quarter2(float a[])
{
	int i,j;
	printf("\n���ȵ��ͳ����״ͼΪ:\n\n");
	printf("          ʱ��^\n");
	printf("              |\n");
	for(i=3;i>=0;i--)
	{
		printf("2017���%d���� |",i+1);
		for(j=0;j<(int)a[i]/50;j++)
			printf("****");
		printf("%.3f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+------------------------------------------------------------>10Ԫ\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55  60  65  70  75\n");
	printf("\n\n          ʱ��^\n");
	printf("              |\n");
	for(i=7;i>=4;i--)
	{
		printf("2018���%d���� |",i-3);
		for(j=0;j<(int)a[i]/50;j++)
			printf("****");
		printf("%.3f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+------------------------------------------------------------>10Ԫ\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55  60  65  70  75\n");
}
void draw_quarter3(float a[])
{
	int i,j;
	printf("\n���ȸ߷��õ���ͳ����״ͼΪ:\n\n");
	printf("          ʱ��^\n");
	printf("              |\n");
	for(i=3;i>=0;i--)
	{
		printf("2017���%d���� |",i+1);
		for(j=0;j<(int)a[i]/5;j++)
			printf("****");
		printf("%.2f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+---------------------------------------------------------------->kWh\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55  60  65  70  75  80\n");
	printf("\n\n          ʱ��^\n");
	printf("              |\n");
	for(i=7;i>=4;i--)
	{
		printf("2018���%d���� |",i-3);
		for(j=0;j<(int)a[i]/5;j++)
			printf("****");
		printf("%.2f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+---------------------------------------------------------------->kWh\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55  60  65  70  75  80\n");
}
void draw_quarter4(float a[])
{
	int i,j;
	printf("\n���ȵ͹��õ���ͳ����״ͼΪ:\n\n");
	printf("          ʱ��^\n");
	printf("              |\n");
	for(i=3;i>=0;i--)
	{
		printf("2017���%d���� |",i+1);
		for(j=0;j<(int)a[i]/5;j++)
			printf("****");
		printf("%.2f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+-------------------------------------------->kWh\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55\n");
	printf("\n\n          ʱ��^\n");
	printf("              |\n");
	for(i=7;i>=4;i--)
	{
		printf("2018���%d���� |",i-3);
		for(j=0;j<(int)a[i]/5;j++)
			printf("****");
		printf("%.2f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+-------------------------------------------->kWh\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55\n");
}
void draw_quarter5(float a[])
{
	int i,j;
	printf("\n���ȵ��ͳ����״ͼΪ:\n\n");
	printf("          ʱ��^\n");
	printf("              |\n");
	for(i=3;i>=0;i--)
	{
		printf("2017���%d���� |",i+1);
		for(j=0;j<((int)a[i]-70000)/300;j++)
			printf("****");
		printf("%.3f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+------------------------------------------------------------->100Ԫ\n");
	printf("           700|  703 706 709 712 715 718 721 724 727 730 733 736 739 742 745\n");
	printf("\n\n          ʱ��^\n");
	printf("              |\n");
	for(i=7;i>=4;i--)
	{
		printf("2018���%d���� |",i-3);
		for(j=0;j<((int)a[i]-70000)/300;j++)
			printf("****");
		printf("%.3f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+------------------------------------------------------------->100Ԫ\n");
	printf("           700|  703 706 709 712 715 718 721 724 727 730 733 736 739 742 745\n");
}
