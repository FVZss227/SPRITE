#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#define LEN sizeof(struct student)
using namespace std;
class students {
	public:
		void creat();//����
		void print();//���
		void change(); //�޸�
		void input();//����
		void del();//ɾ��
		void find();//����
		void tongji();//ͳ��
		void paixu();//����
		void save(); //����
		void read();//��ȡ
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
		cout<<"                     ###########��ӭʹ��ѧ����Ϣϵͳ###########"<<endl;
		cout<<"                     **********����ѧ����Ϣ�밴 ��1�� *********"<<endl;
		cout<<"                     **********���ѧ����Ϣ�밴 ��2�� *********"<<endl;
		cout<<"                     **********�޸�ѧ����Ϣ�밴 ��3�� *********"<<endl;
		cout<<"                     **********����ѧ����Ϣ�밴 ��4�� *********"<<endl;
		cout<<"                     **********����ѧ����Ϣ�밴 ��5�� *********"<<endl;
		cout<<"                     **********ͳ��ѧ����Ϣ�밴 ��6�� *********"<<endl;
		cout<<"                     **********ɾ��ѧ����Ϣ�밴 ��7�� *********"<<endl;
		cout<<"                     **********����Ӣ��ɼ��밴 ��8�� *********"<<endl;
		cout<<"                     **********��ȡ�����ļ���������9��*******"<<endl;
		cout<<"                     **********�˳�ѧ��ϵͳ�밴 ��0�� *********"<<endl;
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
//����
void students::creat() {
	struct student *p1,*p2;
	p2=new student;
	head=p2;
	cout<<"������ѧ������"<<endl;
	cin>>n;
	int k=0;
	cout<<"###########################��ʼ����ѧ����Ϣ#######################"<<endl;
	for(k=0; k<n; k++) {
		p1=(struct student*)malloc(sizeof(struct student));
		p2->next=p1;
		p2=p1;
		cout<<endl;
		cout<<"������ѧ��"<<endl;
		cin>>p1->num;
		cout<<"����������"<<endl;
		cin>>p1->name;
		cout<<"�������Ա�"<<endl;
		cin>>p1->sex;
		cout<<"������רҵ"<<endl;
		cin>>p1->pro;
		cout<<"����������"<<endl;
		cin>>p1->bor;
		cout<<"�������ͥסַ"<<endl;
		cin>>p1->home;
		cout<<"������Ӣ��ɼ�"<<endl;
		cin>>p1->score;
		cout<<endl;
	}
	p1->next=NULL;
	cout<<"################��Ϣ�������###############"<<endl;
	system("cls");
	save();
}
//���
void students::print() {
	struct student *p;
	p=head->next;
	while(p!=NULL) {
		cout<<endl;
		cout<<"ѧ��"<<'\t';
		cout<<p->num<<endl;
		cout<<"����"<<'\t';
		cout<<p->name<<endl;
		cout<<"�Ա�"<<'\t';
		cout<<p->sex<<endl;
		cout<<"רҵ"<<'\t';
		cout<<p->pro<<endl;
		cout<<"����"<<'\t';
		cout<<p->bor<<endl;
		cout<<"��ͥסַ"<<'\t';
		cout<<p->home<<endl;
		cout<<"Ӣ��ɼ�"<<'\t';
		cout<<p->score<<endl;
		p=p->next;
	}
	cout<<"������ӻس��˳�"<<endl;
	char w[10];
	scanf("%s",w);
	system("cls");
	save();
}
//�޸�
void students::change() {
	cout<<"######################��ʼ�޸ĺ���####################"<<endl;
	char snum[20];
	cout<<"�����������޸ĵ�ѧ����ѧ�ţ�"<<endl;
	cin>>snum;
	struct student*p;
	p=head->next;
	while(p!=NULL) {
		if(strcmp(p->num,snum)==0) {
			cout<<"�޸ĺ��ѧ���ǣ�"<<endl;
			cin>>p->num;
			cout<<"�޸ĺ������"<<endl;
			cin>>p->name;
			cout<<"�޸ĺ���Ա�"<<endl;
			cin>>p->sex;
			cout<<"�޸ĺ��רҵ"<<endl;
			cin>>p->pro;
			cout<<"�޸ĺ������"<<endl;
			cin>>p->bor;
			cout<<"�޸ĺ�ļ�ͥסַ"<<endl;
			cin>>p->home;
			cout<<"�޸ĺ��Ӣ��ɼ�"<<endl;
			cin>>p->score;
		}
		p=p->next;
	}
	system("cls");
	save();
}
//����
void students::input() {
	char k[20];
	cout<<"����������Ǹ�ѧ�����ѧ�ţ�"<<endl;
	cin>>k;
	struct student*p1;
	p1=(struct student*)malloc(sizeof(struct student));
	cout<<"������Ҫ����ѧ����ѧ�ţ�"<<endl;
	cin>>p1->num;
	cout<<"������Ҫ����ѧ����������"<<endl;
	cin>>p1->name;
	cout<<"������Ҫ����ѧ�����Ա�"<<endl;
	cin>>p1->sex;
	cout<<"������Ҫ����ѧ����רҵ��"<<endl;
	cin>>p1->pro;
	cout<<"������Ҫ����ѧ�������գ�"<<endl;
	cin>>p1->bor;
	cout<<"������Ҫ����ѧ���ļ�ͥסַ��"<<endl;
	cin>>p1->home;
	cout<<"������Ҫ����ѧ����Ӣ��ɼ���"<<endl;
	cin>>p1->score;
	struct student*p2,*p3;
	p2=head->next;
	p3=p2->next;
	while(p2!=NULL) {
		if(strcmp(p2->num,k)==0) {
			p2->next=p1;
			p1->next=p3;
			cout<<"################����ѧ����Ϣ���##############"<<endl;
			break;
		}
		p2=p3;
		p3=p3->next;
	}
	system("cls");
	save();
}
//����
void students::paixu() {
	struct student*p,*p1,*p2;
	p=head->next->next;
	head->next->next=NULL;//�Ͽ�
	while(p!=NULL) {
		p1=p->next;
		p2=head;
		while(p2->next!=NULL&&strcmp(p2->next->score,p->score)>0) { //�ɴ�С��
			p2=p2->next;
		}
		p->next=p2->next;//NULL�����
		p2->next=p;
		p=p1;
	}
	cout<<"��Ӣ��ɼ�����"<<endl;
	cout<<"������ӻس��鿴�Ӵ�С������"<<endl;
	char m[10];
	cin>>m;
	system("cls");
	save();
}
//ͳ��
void students::tongji() {
	cout<<"��������ͳ�Ƶ��Ա�"<<endl;
	char b[20];
	cin>>b;
	int a=0;
	struct student*p=head;
	while(p!=NULL) {
		if(strcmp(p->sex,b)==0)
			a++;
		p=p->next;
	}
	cout<<"���Ա��ѧ���У�"<<endl;
	cout<<a<<endl;
	cout<<"������ӻس��˳�"<<endl;
	getchar();

	save();
}
//ɾ��
void students::del() {
	cout<<"��������ɾ��ѧ����ѧ�ţ�"<<endl;
	char x[20];
	cin>>x;
	struct student*p1,*p2;
	p1=head->next;
	p2=head;
	while(p1!=NULL) {
		if(strcmp(p1->num,x)==0) {
			p2->next=p1->next;
			cout<<"ɾ�������"<<endl;
			break;
		}
		p2=p1;
		p1=p1->next;
	}
	system("cls");
	save();
}
//����
void students::find() {
	cout<<"����������ҵ�ѧ�����֣�"<<endl;
	char t[20];
	cin>>t;
	struct student*p1;
	p1=head->next;
	while(p1!=NULL) {
		if(strcmp(p1->name,t)==0) {
			cout<<"��λͬѧ��ѧ���ǣ�"<<endl;
			cout<<p1->num<<endl;
			cout<<"��λͬѧ���Ա��ǣ�"<<endl;
			cout<<p1->sex<<endl;
			cout<<"��λͬѧ��רҵ�ǣ�"<<endl;
			cout<<p1->pro<<endl;
			cout<<"��λͬѧ�������ǣ�"<<endl;
			cout<<p1->bor<<endl;
			cout<<"��λͬѧ�ļ�ͥסַ�ǣ�"<<endl;
			cout<<p1->home<<endl;
			cout<<"��λͬѧ��Ӣ��ɼ��ǣ�"<<endl;
			cout<<p1->score<<endl;
			break;
		}
		p1=p1->next;
	}
	cout<<"������ӻس��˳�"<<endl;
	char m[10];
	cin>>m;
	system("cls");
	save();
}
//����
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
