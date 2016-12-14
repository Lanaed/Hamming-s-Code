#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
ofstream fout;
ifstream fin;
void binarycodeofmessage(int count, bool flag);
main()
{
setlocale (LC_ALL, "rus");
fout.open("output.txt");
int n=0;
cout<<"Input your message in the file input.txt"<<endl;
fin.open("input.txt");
if (!fin){
    cout<<"Impossible to open the file";
    return 1;
}
fin>>noskipws;
n=0;
while (!fin.eof())
{
char charr;
fin>>charr;
n++;
}
n--;
fin.close();
long long kol;
if (n%2==0) kol=n*22;
else kol=(n-1)*22+13;
string inp;
do{
    cout<<"Enter OK if you have entered the text into the file:";
    cin>>inp;}
while(inp!="OK"&& inp!="ok");
cout<<"The sent message:"<<endl;
bool flazochek=false;
binarycodeofmessage(n, flazochek);
flazochek=true;
fout.close();
fout.open("forcheck.txt");
cout<<endl;
cout<<"Input received message in the file rmessage.txt"<<endl;
do{
    cout<<"Enter OK if you have entered the text into the file:";
    cin>>inp;}
while(inp!="OK"&& inp!="ok");
cout<<"The received message:"<<endl;
binarycodeofmessage(n, flazochek);
fout.close();
ifstream finpr;
fin.open("output.txt");
finpr.open("forcheck.txt");
fout.open("result.txt");
int kpr=1;
string s1="";
string s2="";
char ss;
int itog=0;
int per=0;
bool check=true;
cout<<endl;
while (kol>0)
{
 if (kol>13) {
  s1=""; s2="";
  for (int i=0; i<22; i++){
    fin>>ss; s1=s1+ss; finpr>>ss; s2=s2+ss;
  }
  int nofmis=0;
  int kolofmis=0;
  if (s1[0]!=s2[0]) {nofmis=nofmis+1; kolofmis++;}
  if (s1[1]!=s2[1]) {nofmis=nofmis+2; kolofmis++;}
  if (s1[3]!=s2[3]) {nofmis=nofmis+4; kolofmis++;}
  if (s1[7]!=s2[7]) {nofmis=nofmis+8; kolofmis++;}
  if (s1[15]!=s2[15]) nofmis=nofmis+16;
  int res=0;
  int fladorn=1;
  if (nofmis!=0){
        if (s2[nofmis-1]=='1') s2[nofmis-1]='0';
        else s2[nofmis-1]='1';
  int w=2;
  while (w<=20 && fladorn==1){
    if (w!=3 && w!=7&& w!=15)
        if (s1[w]!=s2[w]) fladorn=0;
    w++;
  }
  if (fladorn==1) res=1; else res=2;}
  if (res==1){
    cout<<"There is a mistake in the pair "<<kpr<<" in the bit #"<<nofmis<<endl; check=false;}
  else if (res==2)
    {
        cout<<"There is a double mistake in the pair "<<kpr<<". Correction is impossible."<<endl;
        if (s2[nofmis-1]=='1') s2[nofmis-1]='0';
        else s2[nofmis-1]='1';
        check=false;
    }
  if (s2[2]=='1') itog=128;
  if (s2[4]=='1') itog=itog+64;
  if (s2[5]=='1') itog=itog+32;
  if (s2[6]=='1') itog=itog+16;
  if (s2[8]=='1') itog=itog+8;
  if (s2[9]=='1') itog=itog+4;
  if (s2[10]=='1') itog=itog+2;
  if (s2[11]=='1') itog=itog+1;
  fout<<char(itog); itog=0;
  if (s2[12]=='1') itog=128;
  if (s2[13]=='1') itog=itog+64;
  if (s2[14]=='1') itog=itog+32;
  if (s2[16]=='1') itog=itog+16;
  if (s2[17]=='1') itog=itog+8;
  if (s2[18]=='1') itog=itog+4;
  if (s2[19]=='1') itog=itog+2;
  if (s2[20]=='1') itog=itog+1;
  fout<<char(itog); itog=0;
  }
  else {
    s1=""; s2="";
    for (int i=0; i<13; i++){
    fin>>ss; s1=s1+ss; finpr>>ss; s2=s2+ss;
  }
  int nofmis=0;
  int kolofmis=0;
  if (s1[0]!=s2[0]) {nofmis=nofmis+1; kolofmis++;}
  if (s1[1]!=s2[1]) {nofmis=nofmis+2; kolofmis++;}
  if (s1[3]!=s2[3]) {nofmis=nofmis+4; kolofmis++;}
  if (s1[7]!=s2[7]) {nofmis=nofmis+8; kolofmis++;}
  if (nofmis!=0 && s1[12]==s2[12] && kolofmis%2==0)
      {cout<<"There is a double mistake in the pair "<<kpr<<".  Correction is impossible."<<endl; check=false;}
  else
    if (nofmis!=0){
        cout<<"There is a mistake in the pair "<<kpr<<" in the bit #"<<nofmis<<endl;
        if (s2[nofmis-1]=='1') s2[nofmis-1]='0';
        else s2[nofmis-1]='1';
        check=false;
    }
  itog=0;
  if (s2[2]=='1') itog=128;
  if (s2[4]=='1') itog=itog+64;
  if (s2[5]=='1') itog=itog+32;
  if (s2[6]=='1') itog=itog+16;
  if (s2[8]=='1') itog=itog+8;
  if (s2[9]=='1') itog=itog+4;
  if (s2[10]=='1') itog=itog+2;
  if (s2[11]=='1') itog=itog+1;
  fout<<char(itog); itog=0;
  }
  kol=kol-44;
  kpr++;
}
if (check) cout<<"In the received message there are no mistakes.";
fin.close(); finpr.close(); fout.close();
cin.get(); cin.get();cin.get();
}

void binarycodeofmessage(int count, bool flag)
{
   if (!flag) fin.open("input.txt");
   else fin.open("rmessage.txt");
   int a[22];
   char nom1, nom2;
   while (count>0)
    {
    if (count!=1){
    fin>>nom1;
    fin>>nom2;
    int i;
    for(i=128;i>0;i=i/2)
        if((int)(nom1)&i)
        switch (i)
            {
            case(128):a[2]=1;  break;
            case(64): a[4]=1;  break;
            case(32): a[5]=1;  break;
            case(16): a[6]=1;  break;
            case(8):  a[8]=1;  break;
            case(4):  a[9]=1;  break;
            case(2):  a[10]=1; break;
            case(1):  a[11]=1; break;
            }
          else
            switch (i)
            {
            case(128):a[2]=0;  break;
            case(64): a[4]=0;  break;
            case(32): a[5]=0;  break;
            case(16): a[6]=0;  break;
            case(8):  a[8]=0;  break;
            case(4):  a[9]=0;  break;
            case(2):  a[10]=0; break;
            case(1):  a[11]=0; break;
            }
    for(i=128;i>0;i=i/2)
        if((int)(nom2)&i)
        switch (i)
            {
            case(128):a[12]=1; break;
            case(64): a[13]=1; break;
            case(32): a[14]=1; break;
            case(16): a[16]=1; break;
            case(8):  a[17]=1; break;
            case(4):  a[18]=1; break;
            case(2):  a[19]=1; break;
            case(1):  a[20]=1; break;
            }
        else
            switch (i)
            {
            case(128):a[12]=0; break;
            case(64): a[13]=0; break;
            case(32): a[14]=0; break;
            case(16): a[16]=0; break;
            case(8):  a[17]=0; break;
            case(4):  a[18]=0; break;
            case(2):  a[19]=0; break;
            case(1):  a[20]=0; break;
            }
    int j,s=0;
    for (j=2; j<=20; j=j+2) s+=a[j];
    if (s%2==0) a[0]=0; else a[0]=1;s=0;
    s=a[2]+a[5]+a[6]+a[9]+a[10]+a[13]+a[14]+a[17]+a[18];
    if (s%2==0) a[1]=0; else a[1]=1;s=0;
    s=a[4]+a[5]+a[6]+a[11]+a[12]+a[13]+a[14]+a[19]+a[20];
    if (s%2==0) a[3]=0; else a[3]=1;s=0;
    s=a[8]+a[9]+a[10]+a[11]+a[12]+a[13]+a[14];
    if (s%2==0) a[7]=0; else a[7]=1;s=0;
    s=a[16]+a[17]+a[18]+a[19]+a[20];
    if (s%2==0) a[15]=0; else a[15]=1;s=0;
    for (j=0; j<22; j++) s+=a[j];
    if (s%2==0) a[21]=0; else a[21]=1;
    for (j=0; j<=21; j++) {fout<<a[j]; cout<<a[j];}
    count--; count--;
    }
   else
   {
   count--;
   fin>>nom1;
   int j,s=0;
   int b[13];
   int i;
   for(i=128;i>0;i=i/2)
        if((int)(nom1)&i)
        switch (i)
            {
            case(128):b[2]=1;  break;
            case(64): b[4]=1;  break;
            case(32): b[5]=1;  break;
            case(16): b[6]=1;  break;
            case(8):  b[8]=1;  break;
            case(4):  b[9]=1;  break;
            case(2):  b[10]=1; break;
            case(1):  b[11]=1; break;
            }
          else
            switch (i)
            {
            case(128):b[2]=0;  break;
            case(64): b[4]=0;  break;
            case(32): b[5]=0;  break;
            case(16): b[6]=0;  break;
            case(8):  b[8]=0;  break;
            case(4):  b[9]=0;  break;
            case(2):  b[10]=0; break;
            case(1):  b[11]=0; break;
            }
   for (j=2; j<=10; j=j+2) s+=b[j];
   if (s%2==0) b[0]=0; else b[0]=1;s=0;
   s=b[2]+b[5]+b[6]+b[9]+b[10];
   if (s%2==0) b[1]=0; else b[1]=1;s=0;
   s=b[4]+b[5]+b[6]+b[11];
   if (s%2==0) b[3]=0; else b[3]=1;s=0;
   s=b[8]+b[9]+b[10]+b[11];
   if (s%2==0) b[7]=0; else b[7]=1;s=0;
   for (j=0; j<12; j++) s+=b[j];
   if (s%2==0) b[12]=0; else b[12]=1;
   for (j=0; j<=12; j++) {fout<<b[j];cout<<b[j];}
   }
   }
   fin.close();
}
