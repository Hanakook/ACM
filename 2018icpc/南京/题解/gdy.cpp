#include <bits/stdc++.h>
using namespace std;
struct player{
	int cnt[15];
}ham[1111];
int card[111111];
int T,n,m,tt;
int last_turner,player_now,last_card,winner,top;

void read_in(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&card[i]);
		if(card[i]==1)card[i]=12;
		else if(card[i]==2)card[i]=13;
		else card[i]-=2;
	}
}

void kick_off(){
	top=1;
	last_turner=1;
	last_card=0;
	player_now=0;
	winner=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<15;j++)ham[i].cnt[j]=0;
	}
}

void get_card(int x){
	if(top>m)return;
	int c=card[top++];
	ham[x].cnt[c]++;
}

void begin_get_card(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++)get_card(i);
	}
}

void take_min(int x){
	for(int i=1;i<=13;i++){
		if(ham[x].cnt[i]){
			last_card=i;
			last_turner=x;
			ham[x].cnt[i]--;
			return;
		}
	}
}

void first_deal(int x){
	if(last_card){
		for(int i=1;i<=n;i++){
			int tmp=i+x-1;
			if(tmp>n)tmp-=n;
			get_card(tmp);
		}
	}
	take_min(x);
}

void nt_deal(int x){
	if(last_card==13)return;
	if(ham[x].cnt[last_card+1]){
		last_card=last_card+1;
		last_turner=x;
		ham[x].cnt[last_card]--;
		return;
	}
	else if(ham[x].cnt[13]){
		last_card=13;
		last_turner=x;
		ham[x].cnt[last_card]--;
		return;
	}
}

bool win(int x){
	for(int i=1;i<=13;i++){
		if(ham[x].cnt[i])return false;
	}
	return true;
}

void playing(){
	while(1){
		player_now++;
		if(player_now>n)player_now-=n;
		if(player_now==last_turner)first_deal(player_now);
		else nt_deal(player_now);
		if(win(player_now)){
			winner=player_now;break;
		}
	}
}

void print_result(){
	printf("Case #%d:\n",++tt);
	for(int x=1;x<=n;x++){
		if(x==winner)printf("Winner\n");
		else{
			int sum=0;
			for(int i=1;i<=11;i++)sum+=ham[x].cnt[i]*(i+2);
			sum+=ham[x].cnt[12]+2*ham[x].cnt[13];
			printf("%d\n",sum);
		}
	}
}

int main()
{
	scanf("%d",&T);
	while(T--){
		read_in();
		kick_off();
		begin_get_card();
		playing();
		print_result();		
	}
	return 0;
}
