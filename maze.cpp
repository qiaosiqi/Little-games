#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;

int x_start=1,y_start=0;/*@的初始位置*/
int x_end=18,y_end=19;/*@的终点位置*/

char mapp[20][20]={ //原始地图 
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


void putmap() { //用于打印地图 
	for (int i=0;i<20;i++) {
		for (int j=0;j<20;j++) {
			cout<<mapp[i][j];
		}
		cout<<endl;
	}
}

void getmap() {//用于在开发者模式读取新地图 
	for (int i=0;i<20;i++) {
		for (int j=0;j<20;j++) {
			mapp[i][j]=getch();
		}
	}
}

void checkmap() {//用于更新起点和终点 
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
int dst[4][2]={//上下左右 
        -1,0,
        1,0,
        0,-1,
        0,1
	}; 
void DFS(int x,int y) {//深度优先搜索寻找合法解 
	if(mapp[x][y]=='*') {//判断是否走到了终点，走到了就是输出找到的解if里面是对可行解的一个判断表达式，里面的话就执行我们得到一个解后要进行的操作。
        putmap();
        total++;
        cout<<endl;
        return ;
    }
	for(int i=0;i<4;i++)//枚举转移状态
    {

        int nextx = x+dst[i][0];//计算转移状态
        int nexty = y+dst[i][1];
        //下面这里就是DFS的核心部分了，判断转移是否合法，合法的递归进去，不合法的，不进行搜索，if需要包含全部判断条件，不可缺一，否则搜索回出问题
        if(nextx>=0 && nextx<=19 && nexty>=0 && nexty<=19 && (mapp[nextx][nexty]!='#') && (mapp[nextx][nexty]!='6'))//判断下一个要走的点是否合法，在迷宫的题目里面主要是判断转移的点能不能走 
        {
            mapp[x][y] = '6';//设置当前点为走过   
            DFS(nextx,nexty);//进一步搜索            
            mapp[x][y] = ' ';//退出来设置为没有走过，这样在回溯进行后续搜索时，不会影响对路径的搜索     
        }
    }
	
	
} 

int xx,yy;/*记录@当前的位置*/
int step_sum=0; //记录当前步数 
double score=0;//记录当前分数 


void inpt(char c) { //读取键入的字母，进行位移操作、步数累加、吃墙判断 
	bool flag=false;
	if (c=='w' || c=='W') {
		flag=true;
		xx--;
		if (xx<0||mapp[xx][yy]=='#') xx++,flag=false;//判断越界和吃墙。下同 
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
	if (flag) step_sum+=1;//计步 
	addscore(mapp[xx][yy]);
}
int main() {
	/*DFS(x_start,y_start);
	cout<<endl<<"总解法数="<<total;
	system("pause");*/
	/*
	cout<<"欢迎游玩 代号：MAZE"<<endl<<"本游戏由海德工业CDO设计【粗制滥造还请见谅】"<<endl;
	Sleep(3000);
	system("pause");
	cout<<"游戏规则："<<endl<<"你所在的位置由“@ ”表示"<<endl<<"通过键盘键入W,A,S,D来控制@进行上下左右的移动"<<endl<<"最终到达“* ”位置就算胜利"<<endl;
	cout<<"此外，走到有数字的格子可以加分；最终分数=格子加的分-（总步数*0.4）。"<<endl; 
	Sleep(3000);
	system("pause");
	cout<<"是不是很简单！"<<endl;
	Sleep(1000);
	cout<<"赶快开始,争取更高的分数吧！"<<endl; 
	system("pause");//欢迎阶段 
	*/
	
	
	/*
	system("cls");
	cout<<"请选择是否进入开发者模式：[键入1]进入; [键入2]不进入"<<endl;
	int to_dev_mode=0;
	cin>>to_dev_mode;
	if (to_dev_mode==1) {
		long long key;
		cout<<"请输入密码："<<endl;
		
		bool key_check=false;
		for (int i=0;i<3;i++) {
			cin>>key;
			if (key==9764312850) {
				cout<<"密码正确"<<endl;
				Sleep(1000);
				system("cls");
				key_check=true;
				break;
			} else {
				cout<<"Error! 您还可以尝试"<<2-i<<"次"<<endl;
			}
		} 
		if (key_check) {
			cout<<"当前为开发者模式，可以修改地图。请键入完整的地图（20*20）。"<<endl;
			getmap();
			checkmap();
			cout<<"输入完成，再次修改请重启应用。即将进入游戏界面。"<<endl;
			system("pause");
		} else {
			cout<<"密码不正确，返回游戏模式"<<endl;
			Sleep(1500);
		}
		
	} else {
		system("cls");
		cout<<"不进入dev_mode。3秒后继续。"<<endl<<"3";
		Sleep(1000);
		system("cls");
		cout<<"不进入dev_mode。3秒后继续。"<<endl<<"2";
		Sleep(1000);
		system("cls");
		cout<<"不进入dev_mode。3秒后继续。"<<endl<<"1";
		Sleep(1000);
	}//开发者模式。用于修改地图。但是目前只能修改一次，并且没有地图错误判断。 
	*/
	
	xx=x_start;
	yy=y_start;
	system("cls");
	putmap();
	char inpt_c;
	do {
		//cin>>inpt_c;
		inpt_c=getch();//读入wasd 
		mapp[xx][yy]=' ';
		inpt(inpt_c);
		system("cls");
		mapp[xx][yy]='@';//更新玩家位置 
		putmap(),cout<<endl<<"您已经走了"<<step_sum<<"步"<<endl<<"您当前的分数是 "<<score<<" 分"<<endl;
		if (xx==x_end && yy==y_end) {//结束语 
			system("cls");
			putmap();
			cout<<endl;
			cout<<"-----Congratulations!-----"<<endl;
			cout<<"您只用了"<<step_sum<<"步就完成了！"<<endl;
			cout<<"您最终的得分是"<<score-0.4*step_sum<<"分"<<endl; 
			system("pause");
			return 0;
		}
	}while (true);
	system("pause");
	
	
	return 0;
}
