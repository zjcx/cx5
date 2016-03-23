#include <iostream>

#include <vector>

#include <algorithm> 
#include <string>
#include <fstream>

using namespace std;struct WORD

{
string word;
int num;
};

vector<WORD> a; 

int&value(const string&s)
{
for(int i=0;i<a.size();i++)
if(s==a[i].word)
return a[i].num;
WORD p;
p.word=s;
p.num=0;
a.push_back(p); 
return a[a.size()-1].num;
}

int main()
{
string str;
cout << "ÊäÈë×Ö·û´®£º\n";
char c;
while(c=cin.get())
{
if((c>='a' && c<='z') || (c>='A' && c<='Z') || c==' ' || c=='\n') 
str+=c;

if(c=='\n')
break;
}

for(int j=0;str[j]!='\0';j++)
{
if(str[j]>='A'&&str[j]<='Z')
{
str[j]+= 32; 
}
}


string buf;
ofstream fout("D:\\123.txt"); 
fout<<str;
fout.close ();
ifstream fin("D:\\123.txt"); 
while(fin>>buf){
value(buf)++;
}
vector<WORD>::const_iterator p; 
ofstream output("D:\\Result1.txt"); 
for(p=a.begin();p!=a.end();++p)
output<<p->word<<":"<<p->num<<'\n'; 
return 0;

}