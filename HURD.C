#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
void person(int j,int a)
{
setcolor(GREEN);
line(0,460,640,460);
setcolor(a);
line(135,j-100,135,j-50);
circle(135,j-120,20);
line(100,j,135,j-50);
line(135,j-50,170,j);
setfillstyle(SOLID_FILL,a);
pieslice(135,j-120,45,270,20);
setcolor(a);
 line(135,j-100,100,j-75);
 line(100,j-75,130,j-50);
 line(135,j-50,170,j-75);
}
int main()
{
	char c1;
 int gd=DETECT,gm,c=0,d=0;
 int  i=620,j=920,k,l=3,s=0;
 char s1[10],sc[10],li[10];
 int a;
char ch,pname[100];
 initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
 settextstyle(1,0,1);
 setcolor(MAGENTA);
 outtextxy(200,100,"HURDLES");
 delay(1000);
 outtextxy(50,175,"INSTRUCTIONS :-");
 settextstyle(1,0,2);
 setcolor(CYAN);
 outtextxy(100,220,"ONLY USE UP ARROW TO JUMP ");
 delay(1000);
 outtextxy(100,350,"Press any key to continue");
 getch();
 cleardevice();
 closegraph();
 printf("Enter player name ");
 scanf("%[^\n]s",&pname);
 initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
 person(460,10);
 settextstyle(1,0,1);
 outtextxy(50,50,"lives : ");
 sprintf(li,"%d",l);
 outtextxy(120,50,li);
 outtextxy(450,50,"Score : ");
 sprintf(sc,"%d",s);
 outtextxy(520,50,sc);
 a=50;
 q:i=620,j=920;
 while(1)
 {

  setcolor(9);
   line(i,375,i,459);
   line(j,375,j,459);
   delay(a);
   setcolor(0);
   line(i,375,i,459);
   line(j,375,j,459);
   if(kbhit())
   {
    ch=getch();
    if(ch==0)
	ch=getch();
    switch(ch)
    {
	case 72:
	       person(460,0);
	       person(320,6);
	       k=320;
	       c=1;
	       break;
	case 27:
		getch();
		cleardevice();
		closegraph();
		return 0;
    }
   }
   if(c==1)
   {
    d=i;
   }
   i=i-10;
   j=j-10;
   if(i==0)
	i=640;
   if(j==0)
	j=640;
   if((i>=100&&i<=170)||(j<=170&&j>=100))
	{
	if(k!=320&&l==0)
	{
	 cleardevice();
	 setcolor(15);
	 settextstyle(1,0,1);
	 setcolor(CYAN);
	 outtextxy(200,100,"GAME OVER");
	 setcolor(14);
	 outtextxy(100,200,"Player Name : ");
	 outtextxy(270,200,pname);
	 outtextxy(100,300,"Score : ");
	 sprintf(s1,"%d",s);
	 outtextxy(200,300,s1);
	 outtextxy(100,350,"Do u want to play again press 'y' or 'Y' ");
	 outtextxy(100,400,"Else press any key..");
	 c1=getch();
	 if(c1=='y'||c1=='Y')
	 {
		cleardevice();
		closegraph();
		main();
	 }
	 closegraph();
	 return 0;
	}
	if(k!=320)
	{
	setcolor(0);
	sprintf(li,"%d",l);
 outtextxy(120,50,li);
 l--;
 setcolor(15);
 sprintf(li,"%d",l);
 outtextxy(120,50,li);
	goto q;
	}
	}
	if(i==d-120||i==80||j==80)
	{
	  person(320,0);
	  person(460,6);
	  k=460;
	  if(i+20==100||j+20==100){
	  setcolor(0);
	  sprintf(sc,"%d",s);
	outtextxy(520,50,sc);
	setcolor(15);
	s++;
	 sprintf(sc,"%d",s);
	 outtextxy(520,50,sc);
	 }
	}
	if(s==20)
	a=40;
	if(s==40)
	a=33;
	if(a==60)
	a=27;
	if(a==80)
	a=23;
	if(a==100)
	a=19;
	c=0;
  }
 return 0;
}