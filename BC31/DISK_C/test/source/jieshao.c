#include"common.h"

void jieshao()
{
    int chat_page;
    cleardevice();

	setbkcolor(BLACK);	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(0, 0, 640, 480);
    setfillstyle(SOLID_FILL,BLUE);
    bar(40, 250, 600, 380);
    setfillstyle(SOLID_FILL,WHITE);
    bar(50, 260, 590, 370);


    setfillstyle(1,LIGHTGRAY);
	bar(550,400,625,440);//MAIN
    setcolor(BLACK);
	settextstyle(1,0,3);//··
    outtextxy(585,420,"MAIN");

	puthz(400-10, 400-50, "����������⴦���жԻ�",16,16,DARKGRAY);

    while(1)		//��������ж���
	{
		mou_pos(&MouseX,&MouseY,&press);
        if(mouse_press(550,400,625,440)== 1)
        {
            delay(150);
            break;
        }
		else if(mouse_press(50, 320, 590, 430)== 1)
		{
            delay(200);
			setbkcolor(BLACK);	
	        setfillstyle(SOLID_FILL, LIGHTBLUE);
	        bar(0, 0, 640, 480);
	        setfillstyle(SOLID_FILL,BLUE);
            bar(40, 250, 600, 380);
            setfillstyle(SOLID_FILL,WHITE);
            bar(50, 260, 590, 370);
            puthz(400-10, 400-50, "����������⴦���жԻ�",16,16,DARKGRAY);

            
            setfillstyle(1,LIGHTGRAY);
	        bar(550,400,625,440);//MAIN
            setcolor(BLACK);
	        settextstyle(1,0,3);//··
            outtextxy(585,420,"MAIN");
			if(chat_page == 0)
			{
				
				puthz(60, 300 - 8, "��ó��٣����������˻��ƹ����п���", 16, 16, BLACK);
				
			}

			else if(chat_page == 1)									///////////////////////////////////����CFidint�������Ӧ�Ĳ��?ҽ��
			{
				puthz(60, 300 - 8, "�ܸ��������������", 16, 16, BLACK);
				
			}
			else if (chat_page == 2)
			{
				//outtextxy(60, 300-8, "yisheng: womendexitonghaimeijilunidexuehao, qingnigaosuwonidexuehao.");
				puthz(60, 300 - 8, "��������Ϊ�������������", 16, 16, BLACK);	
			}

			else if(chat_page == 3)
			{
				puthz(60, 300 - 8, "�ڡ�����չʾ��������", 16, 16, BLACK);
			}

			else if(chat_page == 4)
			{
				puthz(60, 300 - 8, "��������Ŀǰ�Լ����źõ����˻���ʾ����", 16, 16, BLACK);
			}
            else if(chat_page == 5)
			{
				puthz(60, 300 - 8, "�ڡ��ƹ��㡱������", 16, 16, BLACK);
			}
			else if(chat_page == 6)
			{
				puthz(60, 300 - 8, "����Թ������˻��ƹ����������ʾЧ��", 16, 16, BLACK);
			}
            else if(chat_page == 7)
			{
				puthz(60, 300 - 8, "�ڡ�ʵʱ���ơ�������", 16, 16, BLACK);
			}
            else if(chat_page == 8)
			{
				puthz(60, 300 - 8, "������Լ������Ҫ��ͼ�������˻�С��ӻ�����������ƽ�����ʾ", 16, 16, BLACK);
			}
            else if(chat_page == 9)
			{
				puthz(60, 300 - 8, "�ڡ�·��ģ��ϵͳ��������", 16, 16, BLACK);
			}
            else if(chat_page == 10)
			{
				puthz(60, 300 - 8, "������Ϊ�������˻����˶�����˶�·��", 16, 16, BLACK);
			}
            else if(chat_page == 11)
			{
				puthz(60, 300 - 8, "�ڡ�����ʵ��ϵͳ��������", 16, 16, BLACK);
			}
            else if(chat_page == 12)
			{
				puthz(60, 300 - 8, "���ǽ��õ������˻���ʾ���Ϲ���", 16, 16, BLACK);
			}
            else if(chat_page == 13)
            {
                puthz(60, 300 - 8, "���Ͼ����п��ҵ�ȫ��������", 16, 16, BLACK);
            }
			else if(chat_page == 14)
            {
                puthz(60, 300 - 8, "�������������˻����֮�ðɣ�", 16, 16, BLACK);
            }
			else
			{
				break;
			}
			chat_page++;
		}
}
}