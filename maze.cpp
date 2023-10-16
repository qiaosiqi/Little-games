#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;

int x_start=1,y_start=0;/*@�ĳ�ʼλ��*/
int x_end=18,y_end=19;/*@���յ�λ��*/

char mapp[20][20]={ //ԭʼ��ͼ 
	'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	'@',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',
	'#',' ','#',' ','#','#',' ','#','#','#','#','#',' ',' ',' ','#',' ','#',' ','#',
	'#',' ','#',' ','#',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',
	'#',' ',' ',' ','#','#','#','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#',
	'#',' ','#',' ','#',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#','#','#',
	'#',' ','#',' ',' ','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#',
	'#',' ','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#',
	'#',' ','#',' ',' ',' ',' ','#','#','#',' ','#',' ',' ',' ',' ',' ','#','#','#',
	'#',' ','#','#',' ','#',' ',' ',' ','#',' ','#','#',' ','#',' ','#','#',' ','#',
	'#',' ',' ',' ',' ','#',' ','#',' ','#','#','#',' ',' ','#',' ',' ',' ',' ','#',
	'#','#','#','#',' ',' ',' ','#',' ','#',' ',' ',' ','#','#','#',' ','#',' ','#',
	'#',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',
	'#',' ','#','#','#','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#','#','#',
	'#',' ','#',' ','#',' ',' ','#',' ',' ',' ','#',' ',' ','#',' ',' ','#',' ','#',
	'#',' ','#',' ','#',' ','#','#','#','#',' ','#',' ','#','#',' ','#','#',' ','#',
	'#',' ','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ','#',
	'#','#','#',' ','#','#','#',' ','#','#',' ','#','#',' ','#','#','#','#',' ','#',
	'#',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',
	'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'
	};


void putmap() { //���ڴ�ӡ��ͼ 
	for (int i=0;i<20;i++) {
		for (int j=0;j<20;j++) {
			cout<<mapp[i][j];
		}
		cout<<endl;
	}
}

void getmap() {//�����ڿ�����ģʽ��ȡ�µ�ͼ 
	for (int i=0;i<20;i++) {
		for (int j=0;j<20;j++) {
			mapp[i][j]=getch();
		}
	}
}

void checkmap() {//���ڸ��������յ� 
	for (int i=0;i<20;i++) {
		for (int j=0;j<20;j++) {
			if (mapp[i][j]=='*') {
				x_end=i;
				y_end=j;
			} 
			if (mapp[i][j]=='@') {
				x_start=i;
				y_start=j;
			}
		}
	}
}


int total=0;
int dst[4][2]={//�������� 
        -1,0,
        1,0,
        0,-1,
        0,1
	}; 
void DFS(int x,int y) {//�����������Ѱ�ҺϷ��� 
	if(mapp[x][y]=='*') {//�ж��Ƿ��ߵ����յ㣬�ߵ��˾�������ҵ��Ľ�if�����ǶԿ��н��һ���жϱ���ʽ������Ļ���ִ�����ǵõ�һ�����Ҫ���еĲ�����
        putmap();
        total++;
        cout<<endl;
        return ;
    }
	for(int i=0;i<4;i++)//ö��ת��״̬
    {

        int nextx = x+dst[i][0];//����ת��״̬
        int nexty = y+dst[i][1];
        //�����������DFS�ĺ��Ĳ����ˣ��ж�ת���Ƿ�Ϸ����Ϸ��ĵݹ��ȥ�����Ϸ��ģ�������������if��Ҫ����ȫ���ж�����������ȱһ�����������س�����
        if(nextx>=0 && nextx<=19 && nexty>=0 && nexty<=19 && (mapp[nextx][nexty]!='#') && (mapp[nextx][nexty]!='6'))//�ж���һ��Ҫ�ߵĵ��Ƿ�Ϸ������Թ�����Ŀ������Ҫ���ж�ת�Ƶĵ��ܲ����� 
        {
            mapp[x][y] = '6';//���õ�ǰ��Ϊ�߹�   
            DFS(nextx,nexty);//��һ������            
            mapp[x][y] = ' ';//�˳�������Ϊû���߹��������ڻ��ݽ��к�������ʱ������Ӱ���·��������     
        }
    }
	
	
} 

int xx,yy;/*��¼@��ǰ��λ��*/
int step_sum=0; //��¼��ǰ���� 
double score=0;//��¼��ǰ���� 


void inpt(char c) { //��ȡ�������ĸ������λ�Ʋ����������ۼӡ���ǽ�ж� 
	bool flag=false;
	if (c=='w' || c=='W') {
		flag=true;
		xx--;
		if (xx<0||mapp[xx][yy]=='#') xx++,flag=false;//�ж�Խ��ͳ�ǽ����ͬ 
	}
	if (c=='a' || c=='A') {
		flag=true;
		yy--;
		if (yy<0||mapp[xx][yy]=='#') yy++,flag=false;
	}
	if (c=='s' || c=='S') {
		flag=true;
		xx++;
		if (xx>19||mapp[xx][yy]=='#') xx--,flag=false;
	}
	if (c=='d' || c=='D') {
		flag=true;
		yy++;
		if (yy>19||mapp[xx][yy]=='#') yy--,flag=false;
	}
	if (flag) step_sum+=1;//�Ʋ� 
	addscore(mapp[xx][yy]);
}
int main() {
	/*DFS(x_start,y_start);
	cout<<endl<<"�ܽⷨ��="<<total;
	system("pause");*/
	/*
	cout<<"��ӭ���� ���ţ�MAZE"<<endl<<"����Ϸ�ɺ��¹�ҵCDO��ơ��������컹����¡�"<<endl;
	Sleep(3000);
	system("pause");
	cout<<"��Ϸ����"<<endl<<"�����ڵ�λ���ɡ�@ ����ʾ"<<endl<<"ͨ�����̼���W,A,S,D������@�����������ҵ��ƶ�"<<endl<<"���յ��* ��λ�þ���ʤ��"<<endl;
	cout<<"���⣬�ߵ������ֵĸ��ӿ��Լӷ֣����շ���=���Ӽӵķ�-���ܲ���*0.4����"<<endl; 
	Sleep(3000);
	system("pause");
	cout<<"�ǲ��Ǻܼ򵥣�"<<endl;
	Sleep(1000);
	cout<<"�Ͽ쿪ʼ,��ȡ���ߵķ����ɣ�"<<endl; 
	system("pause");//��ӭ�׶� 
	*/
	
	
	/*
	system("cls");
	cout<<"��ѡ���Ƿ���뿪����ģʽ��[����1]����; [����2]������"<<endl;
	int to_dev_mode=0;
	cin>>to_dev_mode;
	if (to_dev_mode==1) {
		long long key;
		cout<<"���������룺"<<endl;
		
		bool key_check=false;
		for (int i=0;i<3;i++) {
			cin>>key;
			if (key==9764312850) {
				cout<<"������ȷ"<<endl;
				Sleep(1000);
				system("cls");
				key_check=true;
				break;
			} else {
				cout<<"Error! �������Գ���"<<2-i<<"��"<<endl;
			}
		} 
		if (key_check) {
			cout<<"��ǰΪ������ģʽ�������޸ĵ�ͼ������������ĵ�ͼ��20*20����"<<endl;
			getmap();
			checkmap();
			cout<<"������ɣ��ٴ��޸�������Ӧ�á�����������Ϸ���档"<<endl;
			system("pause");
		} else {
			cout<<"���벻��ȷ��������Ϸģʽ"<<endl;
			Sleep(1500);
		}
		
	} else {
		system("cls");
		cout<<"������dev_mode��3��������"<<endl<<"3";
		Sleep(1000);
		system("cls");
		cout<<"������dev_mode��3��������"<<endl<<"2";
		Sleep(1000);
		system("cls");
		cout<<"������dev_mode��3��������"<<endl<<"1";
		Sleep(1000);
	}//������ģʽ�������޸ĵ�ͼ������Ŀǰֻ���޸�һ�Σ�����û�е�ͼ�����жϡ� 
	*/
	
	xx=x_start;
	yy=y_start;
	system("cls");
	putmap();
	char inpt_c;
	do {
		//cin>>inpt_c;
		inpt_c=getch();//����wasd 
		mapp[xx][yy]=' ';
		inpt(inpt_c);
		system("cls");
		mapp[xx][yy]='@';//�������λ�� 
		putmap(),cout<<endl<<"���Ѿ�����"<<step_sum<<"��"<<endl<<"����ǰ�ķ����� "<<score<<" ��"<<endl;
		if (xx==x_end && yy==y_end) {//������ 
			system("cls");
			putmap();
			cout<<endl;
			cout<<"-----Congratulations!-----"<<endl;
			cout<<"��ֻ����"<<step_sum<<"��������ˣ�"<<endl;
			cout<<"�����յĵ÷���"<<score-0.4*step_sum<<"��"<<endl; 
			system("pause");
			return 0;
		}
	}while (true);
	system("pause");
	
	
	return 0;
}