#include<all.h>
enum statuss
{
	ERROR, INIT, DEC, DOUBLE, DOT, ED, EDD, EXP,  LONG
};
statuss status[LONG+1][256];
inline void init_status()
{
	for(int ss=DEC; ss<=DOUBLE; ++ss)
	{
		status[ss]['e']=ED;
		status[ss]['E']=ED;
	}
	for(char c='0'; c<='9'; ++c)
		status[INIT][c]=DEC; 
	
	for(char c='0'; c<='9'; ++c)
		status[DEC][c]=DEC;

	status[INIT]['.']=DOT;
	status[DEC]['.']=DOUBLE;

	for(char c='0'; c<='9'; ++c)
		status[DOUBLE][c]=DOUBLE;

	for(char c='0'; c<='9'; ++c)
		status[DOT][c]=DOUBLE;

	for(char c='0'; c<='9'; ++c)
		status[ED][c]=EXP;
	status[ED]['+']=EDD;
	status[ED]['-']=EDD;

	for(char c='0'; c<='9'; ++c)
		status[EDD][c]=EXP;

	for(char c='0'; c<='9'; ++c)
		status[EXP][c]=EXP;
	

}
bool isNumber(string s)
{
	init_status();
	int beg = s.find_first_not_of(" ");
	int end = s.find_last_not_of(" ");
	if(beg==string::npos)
		return false;
	if(s[beg]=='-'||s[beg]=='+')
		++beg;
	statuss stat=INIT;
	for(;beg<=end&&stat; ++beg)
	{
		stat = status[stat][s[beg]];
	}
	return stat&&(stat!=DOT)&&(stat!=ED)&&stat!=EDD;
}
int main()
{
	string s;
	while(cin>>s)
		cout<<isNumber(s)<<endl;
}
