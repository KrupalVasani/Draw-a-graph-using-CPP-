#include <iostream>
#include <stack>
#include <graphics.h>
#include <cmath>
#include "infix_to_postfix.cpp"
#include "postfix_evaluation.cpp"
#include<map>
#define mag 10
#define scale 5
string change(string,char,string);
using namespace std;


class equation
{

    private:
    string question;
    friend infix_to_postfix();
    public:
    equation()
    {
        cout<<"Enter a equation "<<endl;
        cin>>question;
    }

    string getequation()
    {
        return question;
    }
void draw()
{

    string s1=question;
    string tempo="O";
    outtextxy(402, 402, &tempo[0]); //ugam

  string temp;
    for(int i=1;i<400/(mag*scale);i++)
    {
        temp=to_string(i*scale);
       outtextxy(402+scale*mag*i,400,&temp[0]);
       outtextxy(400,402-scale*mag*i,&temp[0]);
        temp=to_string(-i*scale);
       outtextxy(402-scale*mag*i,400,&temp[0]);

        outtextxy(400,402+scale*mag*i,&temp[0]);

    }



    setcolor(DARKGRAY);
     for(int i=0;i<800;i+=mag*scale)
    {
    line(0,i,800,i);
    line(i,0,i,800);
    }
    setcolor(15);
     line(400, 20, 400, 780);   //y axis
    line(20, 400, 780, 400);   // x axis
    line(20,400,24,397);line(20,400,24,403);    //for arrow on axis
    line(780,400,776,397);line(780,400,776,403);
    line(400,20,396,23);line(400,20,404,23);
    line(400,780,404,777);line(400,780,404,777);



    string s2 = infix_to_postfix(s1);
    float y = 0;
    float a,b;
    for (float i = 0;i<400 ; i += 0.001)
    {
        y = postfix_evaluation(change(s2, 'x', to_string(i)));
        a=400+i*mag;b=400-y*mag;
       putpixel(a,b,2);

      y = postfix_evaluation(change(s2, 'x', to_string(i*-1)));
        a=400+i*(-1)*mag;b=400-y*mag;
         putpixel(a,b,2);


    }

}
};
string change(string s, char old, string new1)
{
    string ans;
    int k = s.length();
    for (int i = 0; i < k; i++)
    {
        if (s[i] == old)
        {
            ans += new1;
        }
        else
        {
            ans += s[i];
        }
    }

    return ans;
}

int main()
{
    equation e1;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    string temp="Graph of   "+e1.getequation()+"                            here,1 block = "+to_string(scale*scale)+"  unit^2";
    initwindow(800, 800,&temp[0]);

    e1.draw();


    getch();
   closegraph();
    return 0;
}
