#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#define LEN sizeof(struct student)
using namespace std;
class students {
	public:
		void creat();//创建
		void print();//输出
		void change(); //修改
		void input();//插入
		void del();//删除
		void find();//搜索
		void tongji();//统计
		void paixu();//排序
		void save(); //保存
		void read();//读取
	private:
		struct student *head;
};
struct student {
	char num[20];
	char name[20];
	char sex[20];
	char pro[20];
	char bor[20];
	char home[50];
	char score[20];
	struct student*next;
};
int n;
int main() {
	struct student *head;
	students stu;
	head=(struct student*)malloc(LEN);
	while(1) {
		cout<<endl;
		cout<<endl;
		system("date/t");
		system("time/t");
		cout<<"                     ##########################################"<<endl;
		cout<<"                     ###########欢迎使用学生信息系统###########"<<endl;
		cout<<"                     **********输入学生信息请按 【1】 *********"<<endl;
		cout<<"                     **********输出学生信息请按 【2】 *********"<<endl;
		cout<<"                     **********修改学生信息请按 【3】 *********"<<endl;
		cout<<"                     **********插入学生信息请按 【4】 *********"<<endl;
		cout<<"                     **********搜索学生信息请按 【5】 *********"<<endl;
		cout<<"                     **********统计学生信息请按 【6】 *********"<<endl;
		cout<<"                     **********删除学生信息请按 【7】 *********"<<endl;
		cout<<"                     **********排序英语成绩请按 【8】 *********"<<endl;
		cout<<"                     **********读取数据文件到链表按【9】*******"<<endl;
		cout<<"                     **********退出学生系统请按 【0】 *********"<<endl;
		cout<<"                     ##########################################"<<endl;
		int m;
		cin>>m;
		system("cls");
		switch(m) {
			case 1:
				stu.creat();
				break;
			case 2:
				stu.print();
				break;
			case 3:
				stu.change();
				break;
			case 4:
				stu.input();
				break;
			case 5:
				stu.find();
				break;
			case 6:
				stu.tongji();
				break;
			case 7:
				stu.del();
				break;
			case 8:
				stu.paixu();
				stu.print();
				break;
			case 9:
				stu.read();
				break;
			case 0:
				exit(1);
				break;
		}
	}
	stu.save();
}
//创建
void students::creat() {
	struct student *p1,*p2;
	p2=new student;
	head=p2;
	cout<<"请输入学生个数"<<endl;
	cin>>n;
	int k=0;
	cout<<"###########################开始输入学生信息#######################"<<endl;
	for(k=0; k<n; k++) {
		p1=(struct student*)malloc(sizeof(struct student));
		p2->next=p1;
		p2=p1;
		cout<<endl;
		cout<<"请输入学号"<<endl;
		cin>>p1->num;
		cout<<"请输入姓名"<<endl;
		cin>>p1->name;
		cout<<"请输入性别"<<endl;
		cin>>p1->sex;
		cout<<"请输入专业"<<endl;
		cin>>p1->pro;
		cout<<"请输入生日"<<endl;
		cin>>p1->bor;
		cout<<"请输入家庭住址"<<endl;
		cin>>p1->home;
		cout<<"请输入英语成绩"<<endl;
		cin>>p1->score;
		cout<<endl;
	}
	p1->next=NULL;
	cout<<"################信息输入完成###############"<<endl;
	system("cls");
	save();
}
//输出
void students::print() {
	struct student *p;
	p=head->next;
	while(p!=NULL) {
		cout<<endl;
		cout<<"学号"<<'\t';
		cout<<p->num<<endl;
		cout<<"姓名"<<'\t';
		cout<<p->name<<endl;
		cout<<"性别"<<'\t';
		cout<<p->sex<<endl;
		cout<<"专业"<<'\t';
		cout<<p->pro<<endl;
		cout<<"生日"<<'\t';
		cout<<p->bor<<endl;
		cout<<"家庭住址"<<'\t';
		cout<<p->home<<endl;
		cout<<"英语成绩"<<'\t';
		cout<<p->score<<endl;
		p=p->next;
	}
	cout<<"任意键加回车退出"<<endl;
	char w[10];
	scanf("%s",w);
	system("cls");
	save();
}
//修改
void students::change() {
	cout<<"######################开始修改函数####################"<<endl;
	char snum[20];
	cout<<"请输入你想修改的学生的学号："<<endl;
	cin>>snum;
	struct student*p;
	p=head->next;
	while(p!=NULL) {
		if(strcmp(p->num,snum)==0) {
			cout<<"修改后的学号是："<<endl;
			cin>>p->num;
			cout<<"修改后的姓名"<<endl;
			cin>>p->name;
			cout<<"修改后的性别"<<endl;
			cin>>p->sex;
			cout<<"修改后的专业"<<endl;
			cin>>p->pro;
			cout<<"修改后的生日"<<endl;
			cin>>p->bor;
			cout<<"修改后的家庭住址"<<endl;
			cin>>p->home;
			cout<<"修改后的英语成绩"<<endl;
			cin>>p->score;
		}
		p=p->next;
	}
	system("cls");
	save();
}
//插入
void students::input() {
	char k[20];
	cout<<"请输入插在那个学生后的学号："<<endl;
	cin>>k;
	struct student*p1;
	p1=(struct student*)malloc(sizeof(struct student));
	cout<<"请输入要插入学生的学号："<<endl;
	cin>>p1->num;
	cout<<"请输入要插入学生的姓名："<<endl;
	cin>>p1->name;
	cout<<"请输入要插入学生的性别："<<endl;
	cin>>p1->sex;
	cout<<"请输入要插入学生的专业："<<endl;
	cin>>p1->pro;
	cout<<"请输入要插入学生的生日："<<endl;
	cin>>p1->bor;
	cout<<"请输入要插入学生的家庭住址："<<endl;
	cin>>p1->home;
	cout<<"请输入要插入学生的英语成绩："<<endl;
	cin>>p1->score;
	struct student*p2,*p3;
	p2=head->next;
	p3=p2->next;
	while(p2!=NULL) {
		if(strcmp(p2->num,k)==0) {
			p2->next=p1;
			p1->next=p3;
			cout<<"################插入学生信息完成##############"<<endl;
			break;
		}
		p2=p3;
		p3=p3->next;
	}
	system("cls");
	save();
}
//排序
void students::paixu() {
	struct student*p,*p1,*p2;
	p=head->next->next;
	head->next->next=NULL;//断开
	while(p!=NULL) {
		p1=p->next;
		p2=head;
		while(p2->next!=NULL&&strcmp(p2->next->score,p->score)>0) { //由大到小排
			p2=p2->next;
		}
		p->next=p2->next;//NULL向后移
		p2->next=p;
		p=p1;
	}
	cout<<"按英语成绩排序"<<endl;
	cout<<"任意键加回车查看从大到小排序结果"<<endl;
	char m[10];
	cin>>m;
	system("cls");
	save();
}
//统计
void students::tongji() {
	cout<<"请输入想统计的性别："<<endl;
	char b[20];
	cin>>b;
	int a=0;
	struct student*p=head;
	while(p!=NULL) {
		if(strcmp(p->sex,b)==0)
			a++;
		p=p->next;
	}
	cout<<"该性别的学生有："<<endl;
	cout<<a<<endl;
	cout<<"任意键加回车退出"<<endl;
	getchar();

	save();
}
//删除
void students::del() {
	cout<<"请输入想删除学生的学号："<<endl;
	char x[20];
	cin>>x;
	struct student*p1,*p2;
	p1=head->next;
	p2=head;
	while(p1!=NULL) {
		if(strcmp(p1->num,x)==0) {
			p2->next=p1->next;
			cout<<"删除已完成"<<endl;
			break;
		}
		p2=p1;
		p1=p1->next;
	}
	system("cls");
	save();
}
//搜索
void students::find() {
	cout<<"请输入想查找的学生名字："<<endl;
	char t[20];
	cin>>t;
	struct student*p1;
	p1=head->next;
	while(p1!=NULL) {
		if(strcmp(p1->name,t)==0) {
			cout<<"这位同学的学号是："<<endl;
			cout<<p1->num<<endl;
			cout<<"这位同学的性别是："<<endl;
			cout<<p1->sex<<endl;
			cout<<"这位同学的专业是："<<endl;
			cout<<p1->pro<<endl;
			cout<<"这位同学的生日是："<<endl;
			cout<<p1->bor<<endl;
			cout<<"这位同学的家庭住址是："<<endl;
			cout<<p1->home<<endl;
			cout<<"这位同学的英语成绩是："<<endl;
			cout<<p1->score<<endl;
			break;
		}
		p1=p1->next;
	}
	cout<<"任意键加回车退出"<<endl;
	char m[10];
	cin>>m;
	system("cls");
	save();
}
//保存
void students::save() {
	FILE *fp=NULL;
	fp=fopen("xueshengxinxiguanli.txt","w");
	struct student *p;
	p=head->next;
	while(p!=NULL) {
		fprintf(fp,p->num);
		fprintf(fp," ");
		fprintf(fp,p->name);
		fprintf(fp," ");
		fprintf(fp,p->sex);
		fprintf(fp," ");
		fprintf(fp,p->pro);
		fprintf(fp," ");
		fprintf(fp,p->bor);
		fprintf(fp," ");
		fprintf(fp,p->home);
		fprintf(fp," ");
		fprintf(fp,p->score);
		fprintf(fp," ");
		p=p->next;
	}
	fclose(fp);
}
void students::print();
void students::read() {
	struct student *p,*tail;
	head->next=NULL;
	tail=head;
	FILE *fp=NULL;
	fp=fopen("xueshengxinxiguanli.txt","r");
	p=(struct student *)malloc(sizeof(struct student));
	while((fscanf(fp,"%ld%s%s%s%d%s%f\n",p->num,p->name,p->sex,p->pro,p->bor,p->home,p->score))!=EOF) {

		printf("%ld %s %s %s %d %s %f\n",p->num,p->name,p->sex,p->pro,p->bor,p->home,p->score);
		cout<<endl;
		tail->next=p;
		tail=p;
		tail->next=NULL;
		p=(struct student *)malloc(sizeof(struct student));
	}
	fclose(fp);
}
