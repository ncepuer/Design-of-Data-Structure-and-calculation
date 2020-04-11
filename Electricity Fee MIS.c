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
		printf("\t\t*          欢迎使用电费核算系统!         *\n");
		printf("\t\t*                                        *\n");
		printf("\t\t*          作者:   杜若聪                *\n");
		printf("\t\t*          学号:   120181080214          *\n");
		printf("\t\t*          班级:   计算机1802班          *\n");
		printf("\t\t******************************************\n");
		printf("\n**********************************************************************************\n");
		printf("\n\t\t******************************************\n");
		printf("\t\t*                                        *\n");
		printf("\t\t*    1.参数维护        2.计算电费        *\n");
		printf("\t\t*                                        *\n");
		printf("\t\t*    3.查询电费记录    4.统计(月/季/年)  *\n");
		printf("\t\t*                                        *\n");
		printf("\t\t******************************************\n\n");
		printf("请选择功能:");
		scanf("%d",&k);getchar();
		switch(k)
		{
		    case 1:{
				system("cls");
				printf("\n***************************************参数维护*************************************\n\n");
				maintain(add_data);break;}
			case 2:{
				system("cls");
				printf("\n***************************************计算电费*************************************\n\n");
				printf("\n 1.居民客户\n 2.非居民客户\n 3.商业客户\n 4.非普工业客户\n 5.大工业客户\n请选择客户类型:");
				scanf("%d",&k);getchar();
				count(k,add_data);
				break;}
			case 3:{
				system("cls");
				printf("\n*************************************查询电费记录*************************************\n\n");
				printf("\n 1.居民客户\n 2.非居民客户\n 3.商业客户\n 4.非普工业客户\n 5.大工业客户\n请选择客户类型:");
				scanf("%d",&k);getchar();
				printf("\n\t2017年01月01日至2018年12月31日\n请输入起始日期(年 月 日):");
				scanf("%d%d%d",&year1,&month1,&day1);
				printf("请输入结束日期(年 月 日):");
				scanf("%d%d%d",&year2,&month2,&day2);
				search(k,year1,month1,day1,year2,month2,day2);
				break;}
			case 4:{
				system("cls");
				printf("\n*****************************************统计*************************************\n\n");
				printf("\n 1.居民客户\n 2.非居民客户\n 3.商业客户\n 4.非普工业客户\n 5.大工业客户\n请选择客户类型:");
				scanf("%d",&k);getchar();
				printf("\n 1.按月度统计\n 2.按季度统计\n 3.按年度统计\n请选择项目:");
				scanf("%d",&m);getchar();
				switch(m)
				{
					case 1:statistics_month(k);break;
					case 2:statistics_quarter(k);break;
					case 3:statistics_year(k);break;
					default:printf("无此项功能!\n");
				}
				break;}
			default:printf("无此项功能!\n");
		}
		getchar();
		printf("继续操作吗?(Y/N):");
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
	printf("请输入参数文件的储存地址:");
	scanf("%s",add);
	if((fp=fopen(add,"w+"))==NULL)
	{printf("Error!\n");return;}
	fprintf(fp,"用户类型          电度电价(元/kwh)          基本电价(元/kVA)\n");
	printf("请输入居民生活的电度电价:");scanf("%f",&a);
	fprintf(fp,"居民生活            %10.2f                         \n",a);
	printf("请输入非居民生活的电度电价:");scanf("%f",&a);
	fprintf(fp,"非居民                %10.2f                         \n",a);
	printf("请输入商业用电客户的电度电价:");scanf("%f",&a);
	fprintf(fp,"商业用电客户      %10.2f                         \n",a);
	printf("请输入非普工业客户的电度电价:");scanf("%f",&a);
	fprintf(fp,"非普工业客户      %10.2f                         \n",a);
	printf("请输入大工业客户的电度电价及基本电价:");scanf("%f%f",&a,&b);
	fprintf(fp,"大工业客户         %10.2f                         %10.2f\n",a,b);
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
			printf("请输入居民生活用电数据文件的地址:");
			scanf("%s",add2);
			printf("请输入计算结果数据文件的地址:");
			scanf("%s",add3);
			if((fp2=fopen(add2,"r"))==NULL)
			{printf("Error!\n");return;}
			fp3=fopen(add3,"w+");
			fgets(str,80,fp2);
			fprintf(fp3,"时间(年月日)                    用电量(kw·h)                    电费(元)\n");
			while(!feof(fp2))
			{	fscanf(fp2,"%d%d%d%f",&year,&month,&day,&num);
				total=count1(price,num);
				fprintf(fp3,"%d %02d %02d                           %.2f                            %-6.3f\n",year,month,day,num,total);
			}
			fclose(fp2);fclose(fp3);break;}
		case 2:{
			fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,16,fp1);
			fscanf(fp1,"%f",&price);
			printf("请输入非居民生活用电数据文件的地址:");
			scanf("%s",add2);
			printf("请输入计算结果数据文件的地址:");
			scanf("%s",add3);
			if((fp2=fopen(add2,"r"))==NULL)
			{printf("Error!\n");return;}
			fp3=fopen(add3,"w+");
			fgets(str,80,fp2);
			fprintf(fp3,"时间(年月日)                    用电量(kw·h)                    电费(元)\n");
			while(!feof(fp2))
			{	fscanf(fp2,"%d%d%d%f",&year,&month,&day,&num);
				total=count2(price,num);
				fprintf(fp3,"%d %02d %02d                           %.2f                            %-6.3f\n",year,month,day,num,total);
			}
			fclose(fp2);fclose(fp3);break;}
		case 3:{
			fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,16,fp1);
			fscanf(fp1,"%f",&price);
			printf("请输入商业客户用电数据文件的地址:");
			scanf("%s",add2);
			printf("请输入计算结果数据文件的地址:");
			scanf("%s",add3);
			if((fp2=fopen(add2,"r"))==NULL)
			{printf("Error!\n");return;}
			fp3=fopen(add3,"w+");
			fgets(str,80,fp2);
			fprintf(fp3,"时间(年月日)                    用电量(kw·h)                    电费(元)\n");
			while(!feof(fp2))
			{	fscanf(fp2,"%d%d%d%f",&year,&month,&day,&num);
				total=count3(price,num);
				fprintf(fp3,"%d %02d %02d                           %.2f                            %-6.3f\n",year,month,day,num,total);
			}
			fclose(fp2);fclose(fp3);break;}
		case 4:{
			fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,16,fp1);
			fscanf(fp1,"%f",&price);
			printf("请输入非普工业客户用电数据文件的地址:");
			scanf("%s",add2);
			printf("请输入计算结果数据文件的地址:");
			scanf("%s",add3);
			if((fp2=fopen(add2,"r"))==NULL)
			{printf("Error!\n");return;}
			fp3=fopen(add3,"w+");
			fgets(str,80,fp2);fgets(str,80,fp2);
			fprintf(fp3,"时间(年月日)                    用电量(kw·h)                  高峰用电量                    低谷用电量                    电费(元)\n");
			while(!feof(fp2))
			{	fscanf(fp2,"%d%d%d%f%f%f",&year,&month,&day,&num,&num1,&num2);
				total=count4(price,num,num1,num2);
				fprintf(fp3,"%d %02d %02d                           %.2f                              %.2f                              %.2f                            %-6.3f\n",year,month,day,num,num1,num2,total);
			}
			fclose(fp2);fclose(fp3);break;}
		case 5:{
			fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,80,fp1);fgets(str,16,fp1);
			fscanf(fp1,"%f%f",&price,&price1);
			printf("请输入大工业客户用电数据文件的地址:");
			scanf("%s",add2);
			printf("请输入计算结果数据文件的地址:");
			scanf("%s",add3);
			if((fp2=fopen(add2,"r"))==NULL)
			{printf("Error!\n");return;}
			fp3=fopen(add3,"w+");
			fgets(str,80,fp2);fgets(str,80,fp2);
			fscanf(fp2,"%d%d%d%f%f%f%f",&year,&month,&day,&num,&num1,&num2,&cap);
			total=count5(price,num,num1,num2,price1,cap);
			fprintf(fp3,"时间(年月日)                    用电量(kw·h)                  高峰用电量                    低谷用电量                    电费(元)                    变压器容量:%.2fkVA\n",cap);
			fprintf(fp3,"%d %02d %02d                           %.2f                              %.2f                              %.2f                            %-6.3f\n",year,month,day,num,num1,num2,total);
			while(!feof(fp2))
			{	fscanf(fp2,"%d%d%d%f%f%f",&year,&month,&day,&num,&num1,&num2);
				total=count5(price,num,num1,num2,price1,cap);
				fprintf(fp3,"%d %02d %02d                           %.2f                              %.2f                              %.2f                            %-6.3f\n",year,month,day,num,num1,num2,total);
			}
			fclose(fp2);fclose(fp3);break;}
		default:printf("选择错误!\n");
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
			printf("请输入居民生活电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
			printf("\n%d年%02d月%02d日至%d年%02d月%02d日:\n 居民生活总用电量为%.2fkWh\n 居民生活总电费为%.3f元\n",year1,month1,day1,year2,month2,day2,num_,total_);
			fclose(fp);break;}
		case 2:{
			printf("请输入非居民生活电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
			printf("\n%d年%02d月%02d日至%d年%02d月%02d日:\n 非居民生活总用电量为%.2fkWh\n 非居民生活总电费为%.3f元\n",year1,month1,day1,year2,month2,day2,num_,total_);
			fclose(fp);break;}
		case 3:{
			printf("请输入商业客户电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
			printf("\n%d年%02d月%02d日至%d年%02d月%02d日:\n 商业客户总用电量为%.2fkWh\n 商业客户总电费为%.3f元\n",year1,month1,day1,year2,month2,day2,num_,total_);
			fclose(fp);break;}
		case 4:{
			printf("请输入非普工业客户电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
			printf("\n%d年%02d月%02d日至%d年%02d月%02d日:\n 非普工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 非普工业客户总电费为%.3f元\n",year1,month1,day1,year2,month2,day2,num_,num1_,num2_,total_);
			fclose(fp);break;}
		case 5:{
			printf("请输入大工业客户电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
			printf("\n%d年%02d月%02d日至%d年%02d月%02d日:\n 大工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 大工业客户总电费为%.3f元\n",year1,month1,day1,year2,month2,day2,num_,num1_,num2_,total_);
			fclose(fp);break;}
		default:printf("选择错误!\n");
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
			printf("请输入居民生活电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");exit(1);}
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
				printf("2017年%02d月:\n 居民生活总用电量为%.2fkWh\n 居民生活总电费为%.3f元\n",i+1,num_[i],total_[i]);
			}
			for(i=12;i<24;i++)
			{
				printf("2018年%02d月:\n 居民生活总用电量为%.2fkWh\n 居民生活总电费为%.3f元\n",i-11,num_[i],total_[i]);
			}
			draw_month1(num_);
			draw_month2(total_);
			fclose(fp);break;}
		case 2:{
			printf("请输入非居民生活电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
				printf("2017年%02d月:\n 非居民生活总用电量为%.2fkWh\n 非居民生活总电费为%.3f元\n",i+1,num_[i],total_[i]);
			}
			for(i=12;i<24;i++)
			{
				printf("2018年%02d月:\n 非居民生活总用电量为%.2fkWh\n 非居民生活总电费为%.3f元\n",i-11,num_[i],total_[i]);
			}
			draw_month1(num_);
			draw_month2(total_);
			fclose(fp);break;}
		case 3:{
			printf("请输入商业客户电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
				printf("2017年%02d月:\n 商业客户总用电量为%.2fkWh\n 商业客户总电费为%.3f元\n",i+1,num_[i],total_[i]);
			}
			for(i=12;i<24;i++)
			{
				printf("2018年%02d月:\n 商业客户总用电量为%.2fkWh\n 商业客户总电费为%.3f元\n",i-11,num_[i],total_[i]);
			}
			draw_month1(num_);
			draw_month2(total_);
			fclose(fp);break;}
		case 4:{
			printf("请输入非普工业客户电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
				printf("2017年%02d月:\n 非普工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 非普工业客户总电费为%.3f元\n",i+1,num_[i],num1_[i],num2_[i],total_[i]);
			}
			for(i=12;i<24;i++)
			{
				printf("2018年%02d月:\n 非普工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 非普工业客户总电费为%.3f元\n",i-11,num_[i],num1_[i],num2_[i],total_[i]);
			}
			draw_month1(num_);
			draw_month3(num1_);
			draw_month4(num2_);
			draw_month2(total_);
			fclose(fp);break;}
		case 5:{
			printf("请输入大工业客户电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
				printf("2017年%02d月:\n 大工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 大工业客户总电费为%.3f元\n",i+1,num_[i],num1_[i],num2_[i],total_[i]);
			}
			for(i=12;i<24;i++)
			{
				printf("2018年%02d月:\n 大工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 大工业客户总电费为%.3f元\n",i-11,num_[i],num1_[i],num2_[i],total_[i]);
			}
			draw_month1(num_);
			draw_month3(num1_);
			draw_month4(num2_);
			draw_month5(total_);
			fclose(fp);break;}
		default:printf("选择错误!\n");
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
			printf("请输入居民生活电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
				printf("2017年第%d季度:\n 居民生活总用电量为%.2fkWh\n 居民生活总电费为%.3f元\n",i+1,num_[i],total_[i]);
			}
			for(i=4;i<8;i++)
			{
				printf("2018年第%d季度:\n 居民生活总用电量为%.2fkWh\n 居民生活总电费为%.3f元\n",i-3,num_[i],total_[i]);
			}
			draw_quarter1(num_);
			draw_quarter2(total_);
			fclose(fp);break;}
		case 2:{
			printf("请输入非居民生活电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
				printf("2017年第%d季度:\n 非居民生活总用电量为%.2fkWh\n 非居民生活总电费为%.3f元\n",i+1,num_[i],total_[i]);
			}
			for(i=4;i<8;i++)
			{
				printf("2018年第%d季度:\n 非居民生活总用电量为%.2fkWh\n 非居民生活总电费为%.3f元\n",i-3,num_[i],total_[i]);
			}
			draw_quarter1(num_);
			draw_quarter2(total_);
			fclose(fp);break;}
		case 3:{
			printf("请输入商业客户电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
				printf("2017年第%d季度:\n 商业客户总用电量为%.2fkWh\n 商业客户总电费为%.3f元\n",i+1,num_[i],total_[i]);
			}
			for(i=4;i<8;i++)
			{
				printf("2018年第%d季度:\n 商业客户总用电量为%.2fkWh\n 商业客户总电费为%.3f元\n",i-3,num_[i],total_[i]);
			}
			draw_quarter1(num_);
			draw_quarter2(total_);
			fclose(fp);break;}
		case 4:{
			printf("请输入非普工业客户电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
				printf("2017年第%d季度:\n 非普工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 非普工业客户总电费为%.3f元\n",i+1,num_[i],num1_[i],num2_[i],total_[i]);
			}
			for(i=4;i<8;i++)
			{
				printf("2018年第%d季度:\n 非普工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 非普工业客户总电费为%.3f元\n",i-3,num_[i],num1_[i],num2_[i],total_[i]);
			}
			draw_quarter1(num_);
			draw_quarter3(num1_);
			draw_quarter4(num2_);
			draw_quarter2(total_);
			fclose(fp);break;}
		case 5:{
			printf("请输入大工业客户电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
				printf("2017年第%d季度:\n 大工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 大工业客户总电费为%.3f元\n",i+1,num_[i],num1_[i],num2_[i],total_[i]);
			}
			for(i=4;i<8;i++)
			{
				printf("2018年第%d季度:\n 大工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 大工业客户总电费为%.3f元\n",i-3,num_[i],num1_[i],num2_[i],total_[i]);
			}
			draw_quarter1(num_);
			draw_quarter3(num1_);
			draw_quarter4(num2_);
			draw_quarter5(total_);
			fclose(fp);break;}
		default:printf("选择错误!\n");
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
			printf("请输入居民生活电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
			printf("2017年:\n 居民生活总用电量为%.2fkWh\n 居民生活总电费为%.3f元\n",num_[0],total_[0]);
			printf("2018年:\n 居民生活总用电量为%.2fkWh\n 居民生活总电费为%.3f元\n",num_[1],total_[1]);
			fclose(fp);break;}
		case 2:{
			printf("请输入非居民生活电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
			printf("2017年:\n 非居民生活总用电量为%.2fkWh\n 非居民生活总电费为%.3f元\n",num_[0],total_[0]);
			printf("2018年:\n 非居民生活总用电量为%.2fkWh\n 非居民生活总电费为%.3f元\n",num_[1],total_[1]);
			fclose(fp);break;}
		case 3:{
			printf("请输入商业客户电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
			printf("2017年:\n 商业客户总用电量为%.2fkWh\n 商业客户总电费为%.3f元\n",num_[0],total_[0]);
			printf("2018年:\n 商业客户总用电量为%.2fkWh\n 商业客户总电费为%.3f元\n",num_[1],total_[1]);
			fclose(fp);break;}
		case 4:{
			printf("请输入非普工业客户电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
			printf("2017年:\n 非普工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 非普工业客户总电费为%.3f元\n",num_[0],num1_[0],num2_[0],total_[0]);
			printf("2018年:\n 非普工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 非普工业客户总电费为%.3f元\n",num_[1],num1_[1],num2_[1],total_[1]);
			fclose(fp);break;}
		case 5:{
			printf("请输入大工业客户电费数据文件的地址:");
			scanf("%s",add);
			if((fp=fopen(add,"r"))==NULL)
			{printf("地址错误!\n");return;}
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
			printf("2017年:\n 大工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 大工业客户总电费为%.3f元\n",num_[0],num1_[0],num2_[0],total_[0]);
			printf("2018年:\n 大工业客户总用电量为%.2fkWh  其中高峰用电总量为%.2fkWh,低谷用电总量为%.2fkWh\n 大工业客户总电费为%.3f元\n",num_[1],num1_[1],num2_[1],total_[1]);
			fclose(fp);break;}
		default:printf("选择错误!\n");
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
	printf("\n月用电量统计柱状图为:\n\n");
	printf("       时间^\n");
	printf("           |\n");
	for(i=11;i>=0;i--)
	{
		printf("2017年%02d月 |",i+1);
		for(j=0;j<(int)a[i]/10;j++)
			printf("**");
		printf("%.2f\n",a[i]);
	}
	printf("-----------+---------------------------------------------------->10kWh\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20  22  24\n");
		printf("\n\n       时间^\n");
	printf("           |\n");
	for(i=23;i>=12;i--)
	{
		printf("2018年%02d月 |",i-11);
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
	printf("\n月电费统计柱状图为:\n\n");
	printf("       时间^\n");
	printf("           |\n");
	for(i=11;i>=0;i--)
	{
		printf("2017年%02d月 |",i+1);
		for(j=0;j<(int)a[i]/10;j++)
			printf("**");
		printf("%.3f\n",a[i]);
	}
	printf("-----------+------------------------------------------------------------>10元\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20  22  24  26  28\n");
		printf("\n\n       时间^\n");
	printf("           |\n");
	for(i=23;i>=12;i--)
	{
		printf("2018年%02d月 |",i-11);
		for(j=0;j<(int)a[i]/10;j++)
			printf("**");
		printf("%.3f\n",a[i]);
	}
	printf("-----------+------------------------------------------------------------>10元\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20  22  24  26  28\n");
}
void draw_month3(float a[])
{
	int i,j;
	printf("\n月高峰用电量统计柱状图为:\n\n");
	printf("       时间^\n");
	printf("           |\n");
	for(i=11;i>=0;i--)
	{
		printf("2017年%02d月 |",i+1);
		for(j=0;j<(int)a[i];j++)
			printf("**");
		printf("%.2f\n",a[i]);
	}
	printf("-----------+----------------------------------------------------------->kWh\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20  22  24  26  28  30\n");
		printf("\n\n       时间^\n");
	printf("           |\n");
	for(i=23;i>=12;i--)
	{
		printf("2018年%02d月 |",i-11);
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
	printf("\n月低谷用电量统计柱状图为:\n\n");
	printf("       时间^\n");
	printf("           |\n");
	for(i=11;i>=0;i--)
	{
		printf("2017年%02d月 |",i+1);
		for(j=0;j<(int)a[i];j++)
			printf("**");
		printf("%.2f\n",a[i]);
	}
	printf("-----------+---------------------------------------->kWh\n");
	printf("          0|   2   4   6   8  10  12  14  16  18  20\n");
		printf("\n\n       时间^\n");
	printf("           |\n");
	for(i=23;i>=12;i--)
	{
		printf("2018年%02d月 |",i-11);
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
	printf("\n月电费统计柱状图为:\n\n");
	printf("       时间^\n");
	printf("           |\n");
	for(i=11;i>=0;i--)
	{
		printf("2017年%02d月 |",i+1);
		for(j=0;j<((int)a[i]-22000)/100;j++)
			printf("**");
		printf("%.3f\n",a[i]);
	}
	printf("-----------+-------------------------------------------------------------->100元\n");
	printf("        220|  222 224 226 228 230 232 234 236 238 240 242 244 246 248 250\n");
		printf("\n\n       时间^\n");
	printf("           |\n");
	for(i=23;i>=12;i--)
	{
		printf("2018年%02d月 |",i-11);
		for(j=0;j<((int)a[i]-22000)/100;j++)
			printf("**");
		printf("%.3f\n",a[i]);
	}
	printf("-----------+-------------------------------------------------------------->100元\n");
	printf("        220|  222 224 226 228 230 232 234 236 238 240 242 244 246 248 250\n");
}

void draw_quarter1(float a[])
{
	int i,j;
	printf("\n季度用电量统计柱状图为:\n\n");
	printf("          时间^\n");
	printf("              |\n");
	for(i=3;i>=0;i--)
	{
		printf("2017年第%d季度 |",i+1);
		for(j=0;j<(int)a[i]/50;j++)
			printf("****");
		printf("%.2f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+---------------------------------------------------->10kWh\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55  60  65\n");
	printf("\n\n          时间^\n");
	printf("              |\n");
	for(i=7;i>=4;i--)
	{
		printf("2018年第%d季度 |",i-3);
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
	printf("\n季度电费统计柱状图为:\n\n");
	printf("          时间^\n");
	printf("              |\n");
	for(i=3;i>=0;i--)
	{
		printf("2017年第%d季度 |",i+1);
		for(j=0;j<(int)a[i]/50;j++)
			printf("****");
		printf("%.3f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+------------------------------------------------------------>10元\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55  60  65  70  75\n");
	printf("\n\n          时间^\n");
	printf("              |\n");
	for(i=7;i>=4;i--)
	{
		printf("2018年第%d季度 |",i-3);
		for(j=0;j<(int)a[i]/50;j++)
			printf("****");
		printf("%.3f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+------------------------------------------------------------>10元\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55  60  65  70  75\n");
}
void draw_quarter3(float a[])
{
	int i,j;
	printf("\n季度高峰用电量统计柱状图为:\n\n");
	printf("          时间^\n");
	printf("              |\n");
	for(i=3;i>=0;i--)
	{
		printf("2017年第%d季度 |",i+1);
		for(j=0;j<(int)a[i]/5;j++)
			printf("****");
		printf("%.2f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+---------------------------------------------------------------->kWh\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55  60  65  70  75  80\n");
	printf("\n\n          时间^\n");
	printf("              |\n");
	for(i=7;i>=4;i--)
	{
		printf("2018年第%d季度 |",i-3);
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
	printf("\n季度低谷用电量统计柱状图为:\n\n");
	printf("          时间^\n");
	printf("              |\n");
	for(i=3;i>=0;i--)
	{
		printf("2017年第%d季度 |",i+1);
		for(j=0;j<(int)a[i]/5;j++)
			printf("****");
		printf("%.2f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+-------------------------------------------->kWh\n");
	printf("             0|   5  10  15  20  25  30  35  40  45  50  55\n");
	printf("\n\n          时间^\n");
	printf("              |\n");
	for(i=7;i>=4;i--)
	{
		printf("2018年第%d季度 |",i-3);
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
	printf("\n季度电费统计柱状图为:\n\n");
	printf("          时间^\n");
	printf("              |\n");
	for(i=3;i>=0;i--)
	{
		printf("2017年第%d季度 |",i+1);
		for(j=0;j<((int)a[i]-70000)/300;j++)
			printf("****");
		printf("%.3f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+------------------------------------------------------------->100元\n");
	printf("           700|  703 706 709 712 715 718 721 724 727 730 733 736 739 742 745\n");
	printf("\n\n          时间^\n");
	printf("              |\n");
	for(i=7;i>=4;i--)
	{
		printf("2018年第%d季度 |",i-3);
		for(j=0;j<((int)a[i]-70000)/300;j++)
			printf("****");
		printf("%.3f\n",a[i]);
		printf("              |\n");
	}
	printf("--------------+------------------------------------------------------------->100元\n");
	printf("           700|  703 706 709 712 715 718 721 724 727 730 733 736 739 742 745\n");
}
