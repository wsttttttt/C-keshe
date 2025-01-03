#include "common.h"
#include "page2.h"
#define Key_Up 0x4800
#define Key_Down 0x5000
#define Key_Right 0x4d00
#define Key_Left 0x4b00
//#include "image.h"
void puthz(int x, int y, char *s, int flag, int part, int color);
void jdt2(int x);
void initpeople(int x,int y);
void clearpeople(int x,int y);
int p2(void)
{
	int page = 0;
	int state=0,pre_state=0;
	int hz_x,key;
	int pp_x,pp_y;
	int key1;
	int x=3,y=10;
	char a;
	int map[12][16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					 0,2,2,2,3,3,3,3,4,4,4,4,5,5,5,0,
					 0,2,2,2,3,3,3,3,4,4,4,4,5,5,5,0,
					 0,2,2,2,1,1,1,1,1,1,1,1,1,1,1,0,
					 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
					 0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,
					 0,1,1,1,1,0,0,0,0,1,1,6,6,6,6,0,
					 0,1,1,1,1,0,0,0,0,1,1,6,6,6,6,0,
					 0,1,1,1,1,1,1,1,1,1,1,6,6,6,6,0,
					 0,1,1,1,1,1,1,1,1,1,1,7,7,7,7,0,
					 0,8,8,1,1,1,1,1,1,1,1,7,7,7,7,0,
					 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	//防止鼠标在跳转页面时留痕
	clrmous(MouseX,MouseY);
	cleardevice();
	setfillstyle(1,WHITE);
	bar(0,0,640,480);
	setcolor(BLUE);
	rectangle(140,140,480,250);
	puthz(150,150,"���˻���ӵƹ�������",32,32,BLUE);
	puthz(230,200,"�п��Ҽ�����",32,32,BLUE);
	hz_x=590;
	key=0;
	do
	{
		jdt2(hz_x);
		delay(5);
		hz_x--;
		  if(hz_x==50)
		{
			key=1;
        } 
    } while (key==0);

	

	page2_screen();
	pp_x=x;
	pp_y=y;
	/*循环，不停地监测异动，当异动导致page值改变，跳转页面*/
	while(1)
	{
		initpeople(x,y);
		if(kbhit())
		{
			//getch();
			a=getch();
			if(a=='w')
			{
				pp_y--;
			}
			else if(a=='a')
			{
				pp_x--;
			}
			else if(a=='s')
			{
				pp_y++;
			}
			else if(a=='d')
			{
				pp_x++;
			}
			

			if(map[pp_y][pp_x]==1)
			{
				clearpeople(x,y);
				x=pp_x;
				y=pp_y;
			}
			else if(map[pp_y][pp_x]==2)
			{
				page=16;
				break;
			}
			else if(map[pp_y][pp_x]==3)
			{
				page=3;
				break;
			}
			else if(map[pp_y][pp_x]==4)
			{
				page=12;
				break;
			}
			else if(map[pp_y][pp_x]==5)
			{
				page=15;
				break;
			}
			else if(map[pp_y][pp_x]==6)
			{
				page=13;
				break;
			}
			else if(map[pp_y][pp_x]==7)
			{
				page=14;
				break;
			}
			else if(map[pp_y][pp_x]==8)
			{
				page=0;
				break;
				x=3;
				y=10;
				pp_x=x;
				pp_y=y;
			}
			else
			{
				pp_x=x;
				pp_y=y;
			}
		}






		//获取鼠标的位置和状�?
		mou_pos(&MouseX,&MouseY,&press);
		
		//点击退出EXIT�?
		if(mouse_press(20,400,120,460) == 1)
		{
			page = 0;
			break;
		}
		//ʹ��˵��
	    if(mouse_press(20,20,150,150) == 1)
		{
			page=16;
			break;
		}
		//Formation
		if(mouse_press(150,20,310,120) == 1)
		{
			page=3;
			break;
		}
		//Perform
		if(mouse_press(310,20,470,120) == 1)
		{
			page=12;
			break;
		}
		//imitation
		if(mouse_press(440,240,620,360) == 1)
		{
			page=13;
			break;
		}
		//Avoid
		if(mouse_press(440,360,620,460) == 1)
		{
			page=14;
			break;
		}
		//Draw
		if(mouse_press(480,20,620,120) == 1)
		{
			page=15;
			break;
		}
		
		//处理高亮
		//EXIT�?
		if(mouse_press(20,400,120,460) == 2)//鼠标在登录框中，且未点击
				{
					pre_state=state;
					state=1;
					if(pre_state!=1)//防止重复标亮
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						rectangle(20,400,120,460);
					}
				}
				
		
		//����ָ���?
				else if(mouse_press(20,20,150,150) == 2)//鼠标在返回框中，且未点击
				{
					pre_state=state;
					state=2;
				
					if(pre_state!=2)//防止重复标亮
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						rectangle(20,20,150,150);
					}
				}
			
		//Formation�?
			else if(mouse_press(150,20,310,120) == 2)//鼠标在返回框中，且未点击
				{
					pre_state=state;
					state=3;
				
					if(pre_state!=3)//防止重复标亮
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						rectangle(150,20,310,120);
					}
				}
		//Perform�?	
					else if(mouse_press(310,20,470,120) == 2)//鼠标在返回框中，且未点击
				{
					pre_state=state;
					state=4;
				
					if(pre_state!=4)//防止重复标亮
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						rectangle(310,20,470,120);
					}
				}
		//imitation�?
					else if(mouse_press(440,240,620,360) == 2)//鼠标在返回框中，且未点击
				{
					pre_state=state;
					state=5;
				
					if(pre_state!=5)//防止重复标亮
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						rectangle(440,240,620,360);
					}
				}
		//Avoid�?	
				else if(mouse_press(440,360,620,460) == 2)//鼠标在返回框中，且未点击
				{
					pre_state=state;
					state=6;
				
					if(pre_state!=6)//防止重复标亮
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						rectangle(440,360,620,460);
					}
				}	
		//Draw�?
				else if(mouse_press(480,20,620,120) == 2)//鼠标在返回框中，且未点击
				{
					pre_state=state;
					state=7;
				
					if(pre_state!=7)//防止重复标亮
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,1);
						rectangle(480,20,620,120);
					}
				}	
				
//无操作状�?
		else
		{
			pre_state=state;
			state=0;
		}	
		

		//如果状态发生改变，且之前不是无操作状态，则可能需清除标亮
		if(pre_state!=state && pre_state!=0)
		{
			clrmous(MouseX,MouseY);
			delay(5);
			
				switch(pre_state)
				{
					case 1:
						setcolor(BLUE);//原来边框的颜�?
						setlinestyle(0,0,1);
						rectangle(20,400,120,460);	
						break;
					case 2:
						setcolor(BLUE);
						setlinestyle(0,0,1);
						rectangle(20,20,150,150);
						break;	
					case 3:
						setcolor(BLUE);
						setlinestyle(0,0,1);
						rectangle(150,20,310,120);
						break;	
					case 4:
						setcolor(BLUE);
						setlinestyle(0,0,1);
						rectangle(310,20,470,120);
						break;	
					case 5://imitation�?
						setcolor(BLUE);
						setlinestyle(0,0,1);
						rectangle(440,240,620,360);
						break;
					case 6://Avoid�?
						setcolor(BLUE);
						setlinestyle(0,0,1);
						rectangle(440,360,620,460);
						break;
					case 7://Draw�?
						setcolor(BLUE);
						setlinestyle(0,0,1);
						rectangle(480,20,620,120);
						break;
				
				}
		}
		
    }
	return page;
}

void page2_screen(void)
{
	cleardevice();//把以前的页面清屏
	
	setbkcolor(BLUE);//背景色设�?
	setfillstyle(1,GREEN);
	bar(20,20,620,460);
	setfillstyle(1,LIGHTBLUE);
	bar(40,40,600,440);
	
   setcolor(BLUE);
   setfillstyle(1,LIGHTGRAY);
  bar(150,20,310,120);//Formation方框
  rectangle(150,20,310,120);

   setfillstyle(1,LIGHTGRAY);
  bar(310,20,470,120);//Perform方框
  rectangle(310,20,470,120);
  
   setfillstyle(1,LIGHTGRAY);  
  bar(440,240,620,360);//imitation方框
  rectangle(440,240,620,360);
  
   setfillstyle(1,LIGHTGRAY);  
  bar(440,360,620,460);//Avoid方框
  rectangle(440,360,620,460);
  
	setfillstyle(1,LIGHTGRAY);  
  bar(480,20,620,120);//Draw方框
  rectangle(480,20,620,120);
  
  
    setfillstyle(1,LIGHTGRAY);
  bar(20,400,120,460);//EXIT方框
  rectangle(20,400,120,460);
  
    setfillstyle(1,LIGHTGRAY);
  bar(20,20,150,150);//����ָ��
  rectangle(20,20,150,150);

  setfillstyle(1,DARKGRAY);
  bar(200,200,350,320);
  //�п���

  
  
   setcolor(BLACK);
   settextstyle(3,0,3);
   outtextxy(60,420,"EXIT");
   
   setcolor(BLACK);
   settextstyle(3,0,3);
  
  //����
	 puthz(30, 45, "�п���", 32, 32, RED);
	 puthz(22, 80, "����ָ��", 32, 32, RED);
	puthz(170, 50, "����չʾ", 32, 32, RED);
	puthz(340, 50, "�ƹ���", 32, 32, RED);
	puthz(500, 30, "ʵʱ����", 32, 32, RED);
	puthz(460, 260, "·��ģ��ϵͳ", 32, 32, RED);
	puthz(460, 370, "��������ϵͳ", 32, 32, RED);
   puthz(220, 250, "�п���", 32, 32, BLUE);
   //outtextxy(420,340,"Creation");//创意
}

void jdt2(int x)//������������
{
    int y;
    y=300;
    putpixel(x,y,BLUE);
    putpixel(x,y+1,BLUE);
    putpixel(x,y+2,BLUE);
    putpixel(x,y+3,BLUE);
    putpixel(x,y+4,BLUE);
    putpixel(x,y+5,BLUE);
    putpixel(x,y+6,BLUE);
    putpixel(x,y+7,BLUE);
    putpixel(x,y+8,BLUE);
	putpixel(x,y+9,BLUE);
    putpixel(x,y+10,BLUE);
	putpixel(x,y+11,BLUE);
	putpixel(x,y+12,BLUE);
	putpixel(x,y+13,BLUE);
	putpixel(x,y+14,BLUE);
	putpixel(x,y+15,BLUE);
	putpixel(x,y+16,BLUE);
	putpixel(x,y+17,BLUE);
	putpixel(x,y+18,BLUE);
	putpixel(x,y+19,BLUE);
	putpixel(x,y+20,BLUE);
	putpixel(x,y+21,BLUE);
	putpixel(x,y+22,BLUE);
	putpixel(x,y+23,BLUE);
}

void initpeople(int x,int y)
{
	 int unit = 40;
	setfillstyle(SOLID_FILL, LIGHTRED);
    bar(x * unit + 5, y * unit + 5, (x + 1) * unit - 5, (y + 1) * unit - 5); //��ɫ����
}

void clearpeople(int x,int y)
{
	int unit=40;
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	 bar(x * unit + 5, y * unit + 5, (x + 1) * unit - 5, (y + 1) * unit - 5);
}