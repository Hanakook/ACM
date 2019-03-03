#include<set>
#include<map>
#include<list>
#include<deque>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<stdlib.h>
#include<string.h>
//#include<ext/rope>
#include<iostream>
#include<algorithm>
#define pi acos(-1.0)
#define INF 0x3f3f3f3f
#define per(i,a,b) for(int i=a;i<=b;++i)
#define LL long long 
#define swap(a,b) {int t=a;a=b;b=t} 
using namespace std;
//using namespace __gnu_cxx;
int main()
{
	int n,m,k,x;
	string s,s1,s2,s3,s4;
	map<char,string>p1;//字符串转换
	p1['0']="0000";//这样转换成2进制感觉方便
	p1['1']="0001";
	p1['2']="0010";
	p1['3']="0011";
	p1['4']="0100";
	p1['5']="0101";
	p1['6']="0110";
	p1['7']="0111";
	p1['8']="1000";
	p1['9']="1001";
	p1['A']="1010";
	p1['B']="1011";
	p1['C']="1100";
	p1['D']="1101";
	p1['E']="1110";
	p1['F']="1111";
	scanf("%d",&n);
	while(n--)
	{
		s.clear();
		s1.clear();s2.clear();
		s3.clear();s4.clear();
		scanf("%d%d",&m,&k);
		map<string,int>p;//ascll码值对应的关系
		per(i,1,k)
		{
			cin>>x>>s;
			p[s]=x;
		}
		cin>>s1;	
		per(i,0,s1.size()-1)
		{
			if(s1[i]>='a'&&s1[i]<='f') s1[i]=s1[i]-'a'+'A';//注意！转换大小写
			s2+=p1[s1[i]];
		}
		for(int i=0;i<s2.size();i+=9)
		{
			if(i+9>s2.size()) break;//注意！最后一段若长度不够9是要舍弃的
			int fag=0,k=0;
			if(s2[i+8]=='1') fag=1;
			per(j,i,i+7)
			{
				s4+=s2[j];
				if(s2[j]=='1') k++;
			}
                        //cout<<s4<<"?"<<endl;
			if(k%2==0&&k!=1&&fag==1) s3+=s4;//注意k==1的情况
			if(k%2!=0&&fag==0) s3+=s4;
			s4.clear();//注意清空
		}
                //cout<<s3<<"&"<<endl; 
		for(int i=0,j=0;i<s3.size()&&j<m;i++)//注意满足题意中的输出m个字符，长了需要掐掉
		{
			s4+=s3[i];
			if(p[s4])
			{
				printf("%c",p[s4]);j++;
				s4.clear();
			}
		}
		cout<<endl;
	}
	return 0;
}
