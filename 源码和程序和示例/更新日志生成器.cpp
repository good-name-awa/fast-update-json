#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int main()
{
	cout<<"开始之前请先创建文件（更新日志.txt）于同级目录下"<<endl<<endl;
	cout<<"        请保证您的(更新日志.txt)是以下结构"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"        底部彩色字体内容"<<endl;
	cout<<"        版本数量（要写几个版本的日志就填几个）"<<endl<<endl<<"下面内容有几个版本就填写几次"<<endl<<endl;
	cout<<"        版本号：按照（a b c）来写，代指版本号a.b.c"<<endl;
	cout<<"        更新日期：按照（a b c）来写，代指a年b月c日"<<endl;
	cout<<"        版本标题"<<endl;
	cout<<"        版本日志段落数"<<endl;
	cout<<"            版本有几段下面就写几段，每段一行"<<endl;
	cout<<"        版本tags数"<<endl;
	cout<<"            版本有几个tags下面就写几个，每个一行"<<endl<<endl;
	cout<<"json文件会在同级目录下出现"<<endl<<"请自行寻找"<<endl<<endl;
	cout<<"如果您明白了"<<endl<<"并保证更新日志.txt内按照要求填写"<<endl<<"请按下任意键开始生成";
	getch();//按键确认
	
	freopen("更新日志.txt","r",stdin);
	freopen("更新日志.json","w",stdout);
	
	string under;
	getline(cin,under);//输入彩字
	cout<<"{"<<endl<<"    "<<'"'<<"footer"<<'"'<<": "<<'"'<<under<<'"'<<','<<endl;
	cout<<"    "<<'"'<<"entries"<<'"'<<": ["<<endl<<endl;
	
	int allversionnum;
	cin>>allversionnum;//输入版本数量
	for(int num=1;num<=allversionnum;num++)//各个版本内容输入输出
	{
		int a,b,c;
		
		cin>>a>>b>>c;//版本号
		cout<<"    {"<<endl<<"        "<<'"'<<"version"<<'"'<<": "<<'"'<<a<<'.'<<b<<'.'<<c<<'"'<<','<<endl;
		
		cin>>a>>b>>c;//日期
		cin.ignore();
		cout<<"        "<<'"'<<"date"<<'"'<<": "<<'"'<<a<<'-';
		if(b<10)cout<<'0';
		cout<<b<<'-';
		if(c<10)cout<<'0';
		cout<<c<<'"'<<','<<endl;
		
		string tit;//标题
		getline(cin,tit);
		cout<<"        "<<'"'<<"title"<<'"'<<": "<<'"'<<tit<<'"'<<','<<endl;
		
		int changenum;//更新内容段落
		cin>>changenum;
		cin.ignore();
		string ch;
		cout<<"        "<<'"'<<"changes"<<'"'<<": ["<<endl;
		for(int i=1;i<=changenum;i++)
		{
			getline(cin,ch);
			cout<<"            "<<'"'<<ch<<'"';
			if(i<changenum)
			cout<<',';
			cout<<endl;
		}
		cout<<"        ],"<<endl;
		
		int tagnum;//tags
		cin>>tagnum;
		cin.ignore();
		string tags;
		cout<<"        "<<'"'<<"tags"<<'"'<<": ["<<endl;
		for(int i=1;i<=tagnum;i++)
		{
			getline(cin,tags);
			cout<<"            "<<'"'<<tags<<'"';
			if(i<tagnum)
			cout<<',';
			cout<<endl;
		}
		cout<<"        ]"<<endl<<"    }";
		if(num<allversionnum)
		cout<<',';
		cout<<endl<<endl;
	}
	cout<<"    ]"<<endl<<'}';
}
