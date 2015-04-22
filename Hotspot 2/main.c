#include<graphics.h>
#include<string.h>

bool status = false ;
bool tiny = true;
int mainWin,winWidth = 400, winHeight = 250;
char data[2][50];


void setup(int type);
void drawhelp();
void switchWin();
void drawmain();
void drawabout();
void drawfullbox(int style,int color,int bWidth,int bStyle,int bWidth);
void drawbox(int x=0,int y=0,int width=100,int height=100,int style=1,int color=2,int bwidth=2,int bstyle=1,int bcolor=1);
void drawcurset();
void done(int type);

int main()
{
    system("cls");
    system("color 2");
    system("MODE CON: cols=16 lines=2");    
    printf("Don't Close Required By Hotspot");
    FILE *fp;
    fp = fopen("hpdata" , "r");
    if(!fp)
    {
           setup(3);
    }
    else
    {
           fscanf(fp,"%s %s",&data[0],&data[1]);
    }
    
    mainWin = initwindow(winWidth,winHeight,"Hotspot By Bhargav K Patel",400,10);
    drawmain();    
    setcolor(YELLOW);
    
    
   
   while (1)
    {
          int x,y;
          
          if(ismouseclick(WM_LBUTTONDOWN))
          {
             getmouseclick(WM_LBUTTONDOWN,x,y);
             
             if( x > 228 && x < 368 && y > 123 && y< 143 )
             {
                 
                 if(status)
                 {
                           done(2);
                 }
                 else
                 {
                           done(1);
                 }
                 
                 status = !status;
                 clearmouseclick(WM_LBUTTONDOWN);
                 cleardevice();
                 drawmain();                 
             }
             else if( x > 363 && x < 384 && y > 15 && y< 34 )
             {
                     done(2);
                     exit(0);
             }
             else if(tiny)
             {
                 if( x > 20 && x < 80 && y > 200 && y< 218 )
                 {
                      done(3);
                 } 
                 else if( x > 159 && x < 220 && y > 200 && y< 218 )
                 {
                    switchWin();
                 } 
                 else if( x > 306 && x < 372 && y > 200 && y< 218 )
                 {
                      drawabout();
                      setcurrentwindow(mainWin);
                 } 
                 
            }   
            else
            {
                if( x > 82 && x < 315 && y > 215 && y< 233 )
                 {
                      setup(1);
                      closegraph(mainWin);
                      main();
                 } 
                 else if( x > 62 && x < 335 && y > 255 && y< 273 )
                 {
                      setup(2);
                      closegraph(mainWin);
                      main();
                 } 
                 else if( x > 114 && x < 282 && y > 295 && y< 313 )
                 {
                      drawcurset();
                 }
                 else if( x > 173 && x < 224 && y > 335 && y< 353 )
                 {
                      drawhelp();
                 }
                 else if( x > 146 && x < 252 && y > 375 && y< 393 )
                 {
                      drawabout();
                      setcurrentwindow(mainWin);
                 }
                 else if( x > 135 && x < 261 && y > 450 && y< 468 )
                 {
                      switchWin();
                 }
            }                               
             
                        
                                                        
          }
          
    }
    
    
    
    
    getch();
    closegraph();return 0;
}

void drawcurset()
{
     int curset = initwindow(300,200,"Current Settings",450,100);
     setcurrentwindow(curset);
      
     drawfullbox(5,9,10,8,1);
     
     setcolor(BLACK);
     setbkcolor(7);
     settextstyle(9 , HORIZ_DIR , 1);
     outtextxy(getmaxx()-98,15,"CLOSE");
     
     drawbox(10,39,getmaxx()-20,10,2,2,0,4,8); 
     setbkcolor(0);  
     setcolor(9);
     outtextxy(70,55,"Current Settings");
     drawbox(10,80,getmaxx()-20,10,2,2,0,4,8);
     
     setcolor(9);
     rectangle(199,15,283,33);
     
     outtextxy(30,115,"Name");
     outtextxy(30,150,"Password");
     
     outtextxy(160,115,data[0]);
     outtextxy(160,150,data[1]);
     
     while (1)
    {
          int x,y;
          
          if(ismouseclick(WM_LBUTTONDOWN))
          {
             getmouseclick(WM_LBUTTONDOWN,x,y);
             
             if( x > 200 && x < 282 && y > 15 && y< 33 )
             {
                 closegraph(curset);
                 setcurrentwindow(mainWin);
                 return;                 
             }
          }
    }   
     
}

void drawhelp()
{
     int help = initwindow(600,350,"Hotspot Help",300,20);
     setcurrentwindow(help);
      
     drawfullbox(5,9,10,8,1);
     
     setcolor(BLACK);
     setbkcolor(7);
     settextstyle(9 , HORIZ_DIR , 1);
     outtextxy(getmaxx()-98,15,"CLOSE");
     
     drawbox(10,39,getmaxx()-20,10,2,2,0,4,8); 
     setbkcolor(0);  
     setcolor(9);
     outtextxy(270,55,"Help");
     drawbox(10,80,getmaxx()-20,10,2,2,0,4,8);
     
     setcolor(9);
     rectangle(499,15,583,33);
     rectangle(428,305,495,324);
     
     outtextxy(30,115,"If you have difficulty in starting hotspot check");
     outtextxy(70,150,"- Run as Administrator");
     outtextxy(70,185,"- Name and Password is set.");
     outtextxy(70,220,"- Password is minimum 8 characters long.");
     
     outtextxy(30,270,"Still Problems ?");
     outtextxy(70,305,"- Suggestins & Report bugs. See ");
     setbkcolor(7);
     setcolor(0);
     outtextxy(430,305,"About");
     
     
     
     
     while (1)
    {
          int x,y;
          
          if(ismouseclick(WM_LBUTTONDOWN))
          {
             getmouseclick(WM_LBUTTONDOWN,x,y);
             
             if( x > 500 && x < 582 && y > 15 && y< 33 )
             {
                 closegraph(help);
                 setcurrentwindow(mainWin);
                 return;                 
             }
             else if( x > 428 && x < 495 && y > 305 && y< 324 )
             {
                 drawabout();
                 setcurrentwindow(help);                
             }
          }
    }   
     
}

void switchWin()
{
      tiny = !tiny;
                     
     if(tiny)
     {
           winHeight = 250;  
     }
     else
     {
           winHeight = 500;
     }
     
     clearmouseclick(WM_LBUTTONDOWN);
     cleardevice();
     closegraph(mainWin);
     main(); 
     
     return;
}

void drawabout()
{
 
     int about = initwindow(600,400,"About Me ",300,50);   
     setcurrentwindow(about); 
     drawfullbox(5,9,10,8,1);
     drawbox(10,39,getmaxx()-20,10,2,2,0,4,8);
     drawbox(10,49,getmaxx()-20,91,2,2,0,8,3);
     drawbox(10,130,getmaxx()-20,10,2,2,0,4,8);
     
     setcolor(BLACK);
     setbkcolor(7);
     settextstyle(9 , HORIZ_DIR , 1);
     outtextxy(getmaxx()-98,15,"CLOSE");
     
     setbkcolor(0);
     setcolor(2);
     settextstyle(9 , HORIZ_DIR , 6);
     outtextxy(90,65,"Bhargav Patel");
     
     drawbox(30,170,getmaxx()-60,50,2,2,0,10,3);
     drawbox(30,240,getmaxx()-60,50,2,2,0,10,3);
     drawbox(30,310,getmaxx()-60,50,2,2,0,10,3);
     
     setcolor(9);
     settextjustify(1,1);
     settextstyle(9 , HORIZ_DIR , 2);
     outtextxy(300,203,"email : bhargav079@gmail.com");
     outtextxy(300,273,"facebook : www.facebook.com/olodoio");
     outtextxy(300,343,"facebook : www.twitter.com/olodoio"); 
     
    rectangle(500,15,582,33);
     
     while (1)
    {
          int x,y;
          
          if(ismouseclick(WM_LBUTTONDOWN))
          {
             getmouseclick(WM_LBUTTONDOWN,x,y);
             
             if( x > 500 && x < 582 && y > 15 && y< 33 )
             {
                 closegraph(about);
                 return;                 
             }
          }
    }   
     
     
     
}

void drawmain()
{
     settextjustify(1,1);
     
     setcolor(BLACK);
     setbkcolor(BLACK);
     drawfullbox(5,9,10,8,1);

    drawbox(10,90,winWidth-20,10,2,2,0,4,8);
    
    setcolor(BLACK);
     setbkcolor(7);
     settextstyle(9 , HORIZ_DIR , 1);
     outtextxy(getmaxx()-25,30,"X");
    
    
    setbkcolor(6);
    setcolor(0);
    settextstyle(8 , HORIZ_DIR , 4);
    outtextxy(winWidth/2,60,"Hotspot");
    
    drawbox(10,170,winWidth-20,10,2,2,0,4,8);
    
    settextstyle(8 , HORIZ_DIR , 2);
    setbkcolor(1);
    outtextxy(60,140,"Status");
    
    settextstyle(9 , HORIZ_DIR , 1);
    if(status)
    {
              setfillstyle(1,2);
              setcolor(2);
              fillellipse(getmaxx()/2 - 36,135,30,20);
              setbkcolor(GREEN);
              setcolor(WHITE);
              outtextxy(getmaxx()/2 - 36,140,"ON");
              settextstyle(1 , HORIZ_DIR , 2);
              setcolor(BLACK);
              setbkcolor(7);
              outtextxy(getmaxx()-100,140,"Turn OFF");
    }
    else
    {
              setfillstyle(1,4);
              setcolor(4);
              fillellipse(getmaxx()/2 - 36,135,30,20);
              setbkcolor(RED);
              setcolor(WHITE);
              outtextxy(getmaxx()/2 - 36,140,"OFF");
              settextstyle(1 , HORIZ_DIR , 2);
              setcolor(BLACK);
              setbkcolor(7);
              outtextxy(getmaxx()-100,140,"Turn ON");
    }
    
    if(tiny)
    {
       settextstyle(9 , HORIZ_DIR , 1);
       outtextxy(50,215,"Reset");
       outtextxy(getmaxx()/2 - (getmaxx()/40),215,"Menu");
       outtextxy(getmaxx()-60,215,"About");
    }
    else
    {
        settextstyle(9 , HORIZ_DIR , 1);
        outtextxy(getmaxx()/2,230,"Change Hotspot Name");
        outtextxy(getmaxx()/2,270,"Change Hotspot Password");
        outtextxy(getmaxx()/2,310,"Current Settings");
        outtextxy(getmaxx()/2,350,"Help");
        outtextxy(getmaxx()/2,390,"About Me");
        drawbox(10,420,winWidth-20,10,2,2,0,4,8);
        outtextxy(getmaxx()/2,465,"Close Menu");
    }
    
    setcolor(9);
    
    if(tiny)
    {
        rectangle(363,15,384,34);
        rectangle(20,200,80,218);
        rectangle(159,200,220,218);
        rectangle(306,200,372,218);
    }
    else
    {
        rectangle(82,215,315,233);
        rectangle(62,255,335,273);
        rectangle(114,295,282,313);
        rectangle(173,335,224,353);
        rectangle(146,375,252,393);
        rectangle(135,450,261,468);
    }
    
    
    
    
}

void drawfullbox(int style,int color,int bWidth,int bStyle,int bColor)
{    
     int col = getcolor();
     setcolor(BLACK);
     
     setfillstyle(style,color);
     int pointsout[10] = {0,0,getmaxx(),0,getmaxx(),getmaxy(),0,getmaxy(),0,0};
     fillpoly(4,pointsout);
     
     setfillstyle(bStyle,bColor);
     int pointsin[10] = {bWidth,bWidth,getmaxx()-bWidth,bWidth,getmaxx()-bWidth,getmaxy()-bWidth,bWidth,getmaxy()-bWidth,bWidth,bWidth};
     fillpoly(4,pointsin);
     
     setcolor(col);
}

void drawbox(int x,int y,int width,int height,int style,int color,int bwidth,int bstyle,int bcolor)
{    
     int col = getcolor() , bk = getbkcolor();
     setcolor(BLACK);
     setbkcolor(BLACK);
     
     setfillstyle(style,color);
     int pointsout[10] = {x,y,x+width,y,x+width,y+height,x,y+height,x,y};
     fillpoly(4,pointsout);
     
     setfillstyle(bstyle,bcolor);
     int pointsin[10] = {x+bwidth,y+bwidth,x+width-bwidth,y+bwidth,x+width-bwidth,y+height-bwidth,x+bwidth,y+height-bwidth,x+bwidth,y+bwidth};
     fillpoly(4,pointsin);
     
     setbkcolor(bk);
     setcolor(col);
}

void done(int type)
{    
      char* str = "netsh wlan set hostednetwork mode=allow ssid=Hotspot key=vgecvgec keyusage=persistentsssssssssss";
      char stra[50] = "netsh wlan set hostednetwork mode=allow ssid=";
      char* strb = data[0];
      char strc[10] = " key=";
      char* strd = data[1];
      
      str = strcat(stra,strb);
      str = strcat(str,strc);
      str = strcat(str,strd);
      
      
     
     switch(type)
     {
                 case 1:
                      system("netsh wlan start hostednetwork");
                      break;
                 case 2:
                     system("netsh wlan stop hostednetwork"); 
                     break;
                 case 3:
                      system(str);
     }          
     
    system("cls");
    system("color 2");
    system("MODE CON: cols=16 lines=2");    
    printf("Don't Close Required By Hotspot");     
}


void setup(int type)
{
     system("cls");
     switch(type)
     {
                 case 1:
                        system("MODE CON: cols=30 lines=5");
                        printf("\tChange Hotspot Name\n\t===================\n\n");
                        printf("Name \t :\t");
                        scanf("%s",&data[0]);
                        break;
                 case 2:
                        system("MODE CON: cols=40 lines=7");
                        printf("\tChange Hotspot Password\n\t=======================\n\n");
                        printf("Password should be minimum 8 characters.\n");
                        printf("Password :\t");
                        scanf("%s",&data[1]);
                        break;
                 case 3:
                        system("MODE CON: cols=40 lines=9");
                        printf("\tSet Up Hotspot\n\t==============\n\n");
                        printf("Name \t :\t");
                        scanf("%s",&data[0]);
                        printf("\nPassword should be minimum 8 characters.\n");
                        printf("Password :\t");
                        scanf("%s",&data[1]);

     }
     
     if(strlen(data[1])<8)
     {
           setup(type);         
     }
     
      FILE *fp;
      fp = fopen("hpdata","w");
      fprintf(fp,"%s %s",data[0],data[1]);
      
      system("MODE CON: cols=10 lines=1");
      
      done(3);
      
      if(status)
      {
                done(1);
      }
      
    
}
