#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
void Welcome();
class Student {
private:
	char name[10];
	int num;
	int banji;
	char major[10];
	char course1[10];
	char course2[10];
	int coursenum1;
	int coursenum2;
	int score1;
	int score2;
	
public:
	void Students(const char w_name[], int w_num, int w_banji, const char w_major[], const char w_course1[], const char w_course2[], int w_coursenum1, int w_coursenum2, int w_score1, int w_score2)
	{
		strcpy(name, w_name);
		num = w_num;
		banji = w_banji;
		strcpy(major,w_major);
		strcpy(course1,w_course1);
		strcpy(course2, w_course2);
		coursenum1 = w_coursenum1;
		coursenum2 = w_coursenum2;
		score1 = w_score1;
		score2 = w_score2;
		
	}
	Student(){}
	void showstudent()
	{
		printf("����:%sѧ��:%d�༶:%dרҵ:%s %d%s:%d %d%s:%d\n", name, num, banji, major, coursenum1, course1, score1, coursenum2, course2, score2);
	}
	char* getname()
	{
		return name;
	}
	int getscore1()
	{
		return score1;
	}
	int getscore2()
	{
		return score2;
	}
};
int main()
{
	char w_name[10], addname[10], deletname[10], cname[10], rename[10];
	int w_num, renum;
	int w_banji;
	char w_major[10];
	char w_course1[10], ccourse[10];
	char w_course2[10];
	int w_coursenum1;
	int w_coursenum2;
	int w_score1, addscore1, addscore2, rescore1, rescore2;
	int w_score2;
	int sum1 = 0, sum2 = 0, are1 = 0, are2 = 0;
		
		int z = 1;
	static int w_m = 3;
	Student S[10];
	S[0].Students("liming", 1, 10, "ruanjian", "math", "engliah", 1, 2, 90, 85);
	S[1].Students("qinqin", 2, 10, "ruanjian", "math", "english", 1, 2, 88, 90);
	S[2].Students("xiaoli", 3, 10, "ruanjian", "math", "engliah", 1, 2, 79, 95);
	Welcome();
	while (1)
	{
		char ch=getch();
		switch (ch)
		{
		case'1':
			for (int k = 0; k <w_m; k++)
			{
					S[k].showstudent();
			}
			break;
		case'2':
			printf("���������ѧ����Ϣ:"); scanf("%s%d%d", addname,&addscore1,&addscore2);
			S[w_m].Students(addname, w_m + 1, 10, "ruanjian", "math", "engliah", 1, 2, addscore1, addscore2);
			w_m++;
			for (int i = 0; i < w_m; i++)
			{
				S[i].showstudent();
			}
			break;
		case'3':printf("�����뱻ɾ��ѧ��������:"); scanf("%s", deletname);
			for(int i=0;i<w_m;i++)
			{
			    if (strcmp(S[i].getname(), deletname) == 0)
				{
					z = i;
					break;
				}
			}
			if (z != -1)
			{
				for (int i = z; i < w_m; i++)
				{
					S[i] = S[i + 1];
				}
				w_m--;
			}
			for (int i = 0; i < w_m; i++)
			{
				S[i].showstudent();
			}
			break;
		case'4':printf("�����뱻��ѯѧ������:"); scanf("%s", cname);
			for (int i = 0; i < w_m; i++)
			{
				if (strcmp(S[i].getname(), cname) == 0)
				{
					S[i].showstudent();
				}
			}
			break;
		case'5':printf("�����뱻�޸�ѧ������:"); scanf("%s", rename); printf("ѧ��:"); scanf("%d", &renum);
			printf("��ѧ�ɼ�:"); scanf("%d", &rescore1); printf("Ӣ��ɼ�:"); scanf("%d", &rescore2);
			for (int i = 0; i < w_m; i++)
			{
				if (strcmp(S[i].getname(), rename) != 0)
				{
					S[i].showstudent();
				}
				if (strcmp(S[i].getname(), rename) == 0)
				{
					S[i].Students(rename,renum,10,"ruanjian","math","engliah",1,2,rescore1,rescore2);
					S[i].showstudent();
				}
			}
			break;
		case'6':printf("������鿴ƽ���ɼ��Ŀ�Ŀ:"); scanf("%s", ccourse);
			for (int i = 0; i < w_m; i++)
			{
				sum1 = sum1 + S[i].getscore1();
				sum2 = sum2 + S[i].getscore2();
			}
			are1 = sum1 / w_m;
			are2 + sum2 / w_m;
			if (strcmp(ccourse,"math") == 0)
			{
				printf("%d", are1);
			}
			if (strcmp(ccourse, "english") == 0)
			{
				printf("%d", are2);
			}
			break;
		
		}
	}
	return 0;
}
void Welcome()
{
	printf("*****************************************\n");
	printf("*\t��ӭʹ��С��ѧ���ɼ�����ϵͳ\t*\n");
	printf("*****************************************\n");
	printf("*\t\t��ѡ�����б�\t\t*\n");
	printf("*****************************************\n");
	printf("*\t\t1.��ʾѧ����Ϣ\t\t*\n");
	printf("*\t\t2.���ѧ����Ϣ\t\t*\n");
	printf("*\t\t3.ɾ��ѧ����Ϣ\t\t*\n");
	printf("*\t\t4.��ѯѧ����Ϣ\t\t*\n");
	printf("*\t\t5.�޸�ѧ����Ϣ\t\t*\n");
	printf("*\t\t6.�鿴ƽ���ɼ�\t\t*\n");
	printf("**************************************f***\n");
}
