#include <conio.h>
#include <graphics.h>
#include <bits/stdc++.h>
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;
bool isInsideCircle(int mx,int my,int cx,int cy,int r) {
    int dx=mx-cx;
    int dy=my-cy;
    return (dx*dx+dy*dy<=r*r);
}
bool isPointInSquare(int px, int py,std::pair<float,float>& p1,std::pair<float,float>& p2) {
    return((px>=p1.first && px<=p2.first && py<=p1.second && py>=p2.second)||(px<=p1.first && px>=p2.first && py>=p1.second && py<=p2.second ) || (px >= p1.first && px <= p2.first && py >= p1.second && py <= p2.second ) || (px <= p1.first && px >= p2.first && py <= p1.second && py >= p2.second ));
}
bool areCoinsInSameSquare(int cx1,int cy1,int cx2,int cy2,std::vector<std::pair<float,float> >& v) {
    for (int i=0;i<59;i++) {
            if(i==51)
            {
                continue;
            }
            if(i>52)
            {
                i+=1;
            }
        if (isPointInSquare(cx1,cy1,v[i],v[i+1]) && isPointInSquare(cx2,cy2,v[i],v[i+1])) {
            if((cx1>=280 && cy1>=373.3333 && cx1<=320 && cy1<=430) || (cx1>=440 && cy1>=590 && cx1<=496.6667 && cy1<=630) || (cx1>=553.3334 && cy1>=550 && cx1<=610 && cy1<=590) ||
               (cx1>=770 && cy1>=373.3333 && cx1<=810 && cy1<=430) || (cx1>=730 && cy1>=260 && cx1<=770 && cy1<=316.6667) || (cx1>=553.3333 && cy1>=60 && cx1<=610 && cy1<=100) ||
                (cx1>=440 && cy1>= 100&& cx1<=496.6667 && cy1<=140) || (cx1>=240 && cy1>=260 && cx1<=280 && cy1<=316.6667))
            {
                return false;
            }

            return true;
        }
    }
    return false;
}
void layout();
void blue_corner();
void green_corner();
void yellow_corner();
void red_corner();
void home();
void verticallineGreenRed();
void verticallineYellowBlue();
void horizontallineGreenYellow();
void horizontallineRedBlue();
void horizontalGreenRed();
void verticalGreenYellow();
void verticalRedBlue();
void horizontalYellowBlue();
void flood_fill(int x,int y,int newColor,int oldColor)
{
int c;
c=getpixel(x,y);
if(c==oldColor)
{
setcolor(newColor);
putpixel (x,y,newColor);
flood_fill(x+1,y,newColor,oldColor);
flood_fill(x,y+1,newColor,oldColor);
flood_fill(x-1,y,newColor,oldColor);
flood_fill(x,y-1,newColor,oldColor);
}
}
void star(double x, double y) {
    line(x-7,y-7,x,y+10);
    line(x,y+10,x+7,y-7);
    line(x+7,y-7,x-7,y-7);
    line(x-7,y+7,x+7,y+7);
    line(x+7,y+7,x,y-10);
    line(x,y-10,x-7,y+7);
}
bool isInsideRedPath(int x,int y) {
    return (x>=497 && x<=554 && y>=430 && y<=630);
}
bool isInsideBluePath(int cx,int cy) {
    return (cx>=610 && cx<=810 && cy>=317 && cy<=374);
}
bool isInsideGreenPath(int cx,int cy) {
    return (cx>=240 && cx<=440 && cy>=317 && cy<=374);
}
bool isInsideYellowPath(int cx,int cy) {
    return (cx>=497 && cx<=554 && cy>=60 && cy<=260);
}
bool isInsideHome(int x,int y) {
    return ((x>=240 && x<=400 || x>=650 && x<=810 || x>=240 && x<=400 || x>=650 && x<=810) && (y >= 470 && y <= 630 || y>=470 && y<=630 || y>=60 && y<=220 || y>=60 && y<=220));
}
void drawMenu() {
    //initwindow(600,500,"LUDO");
     int gd = DETECT, gm;
     //initgraph(&gd, &gm, "");
     initwindow(600,500);
    setbkcolor(YELLOW);
    cleardevice();
    readimagefile("image2.jpg",0,0,600,500);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setcolor(BLACK);
    outtextxy(235,180,"WELCOME TO LUDO");
    settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
    outtextxy(235,230,"1.Start");
    outtextxy(235,260,"2.Quit");
}
void playerselect()
{
     int gd = DETECT, gm;
     //initgraph(&gd, &gm, "");
     initwindow(600,500);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(5,5,15);
     setbkcolor(GREEN);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    outtextxy(200,180,"Select Number of player");
    int rectX=200,rectWidth=100,rectHeight=40;


    setcolor(WHITE);
    rectangle(rectX,230,rectX+rectWidth,230+rectHeight);
     setfillstyle(SOLID_FILL, RED);
    floodfill(rectX+1,235,WHITE);
    setcolor(WHITE);
    setbkcolor(RED);
    outtextxy(235,240,"1");


    setcolor(WHITE);
    rectangle(rectX,280,rectX+rectWidth,280+rectHeight);
     setfillstyle(SOLID_FILL, BLUE);
     floodfill(rectX+1,290,WHITE);
    setcolor(WHITE);
    setbkcolor(BLUE);
    outtextxy(235, 290, "2");


    setcolor(WHITE);
    rectangle(rectX,330,rectX+rectWidth,330+rectHeight);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(rectX+1,340,WHITE);
    setcolor(WHITE);
    setbkcolor(YELLOW);
    outtextxy(235,340,"3");


    setcolor(WHITE);
    rectangle(rectX,380,rectX+rectWidth,380+rectHeight);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(rectX+1,390,WHITE);
    setcolor(WHITE);
    setbkcolor(GREEN);
    outtextxy(235, 390, "4");
}

void drawDot(int x, int y) {
    setfillstyle(SOLID_FILL,BLACK);
    fillellipse(x, y, 6, 6);
}
void drawDice(int side) {

    int topleftX=860;
    int topleftY=580;
    int bottomrightX=950;
    int bottomrightY=670;
    int width=bottomrightX-topleftX;
    setcolor(WHITE);
    rectangle(topleftX,topleftY,bottomrightX,bottomrightY);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill((topleftX+bottomrightX)/2,(topleftY+bottomrightY)/2,WHITE);
    int cx=(topleftX+bottomrightX)/2;
    int cy=(topleftY+bottomrightY)/2;
    int offset=width/3;// Distance from the center for corner dots

    switch(side){
        case 1:
            drawDot(cx,cy);
            break;
        case 2:
            drawDot(topleftX+offset,topleftY+offset);
            drawDot(bottomrightX-offset,bottomrightY-offset);
            break;
        case 3:
            drawDot(cx,cy);
            drawDot(topleftX+offset,topleftY+offset);
            drawDot(bottomrightX-offset,bottomrightY-offset);
            break;
        case 4:
            drawDot(topleftX+offset,topleftY+offset);
            drawDot(bottomrightX-offset,bottomrightY-offset);
            drawDot(topleftX+offset,bottomrightY-offset);
            drawDot(bottomrightX-offset,topleftY+offset);
            break;
        case 5:
            drawDot(cx,cy);
            drawDot(topleftX+offset,topleftY+offset);
            drawDot(bottomrightX-offset,bottomrightY-offset);
            drawDot(topleftX+offset,bottomrightY-offset);
            drawDot(bottomrightX-offset,topleftY+offset);
            break;
        case 6:
            drawDot(topleftX+offset,topleftY+offset);
            drawDot(bottomrightX-offset,bottomrightY-offset);
            drawDot(topleftX+offset,bottomrightY-offset);
            drawDot(bottomrightX-offset,topleftY+offset);
            drawDot(topleftX+offset,cy);
            drawDot(bottomrightX-offset,cy);
            break;
    }
}
void rollDiceAnimation(int num,int cxx[8],int cyy[8],int player) {
    srand(time(0));
    int finalSide=num;
    for (int i=0;i<15;++i) {
        int side=rand()%6+1;
        drawDice(side);
        delay(5);
    }
    cleardevice();
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(5,5,15);
    layout();
    int radius=7;
    for (int i=0;i<4;i++){
        setcolor(RED);
        setfillstyle(SOLID_FILL,RED);
        circle(cxx[i],cyy[i],radius);
        floodfill(cxx[i],cyy[i],RED);
    }
    for (int i=4;i<8;i++) {
        setcolor(BLUE);
        setfillstyle(SOLID_FILL,BLUE);
        circle(cxx[i],cyy[i],radius);
        floodfill(cxx[i],cyy[i],BLUE);
    }
    for (int i=8;i<12;i++) {
        setcolor(GREEN);
        setfillstyle(SOLID_FILL,GREEN);
        circle(cxx[i],cyy[i],radius);
        floodfill(cxx[i],cyy[i],GREEN);
    }
    for (int i=12;i<16;i++){
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL,YELLOW);
        circle(cxx[i],cyy[i],radius);
        floodfill(cxx[i],cyy[i],YELLOW);
    }
 drawDice(finalSide);
 setbkcolor(DARKGRAY);
 setcolor(WHITE);
 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
if(player==1)outtextxy(860,560,"Player 1");
else if(player==2)outtextxy(860,550,"Player 2");
else if(player==3)outtextxy(860,550,"Player 3");
else if(player==4)outtextxy(860,550,"Player 4");

}
int main() {
    int aaa,bb,p;
    drawMenu();
    while (true) {
    if (ismouseclick(WM_LBUTTONDOWN)) {
        aaa = mousex();
        bb = mousey();
        clearmouseclick(WM_LBUTTONDOWN);
        if (aaa>=235 && aaa<=335 && bb>=230 && bb<=250) {
                playerselect();
                while(true){
    if (ismouseclick(WM_LBUTTONDOWN)) {
        aaa=mousex();
        bb=mousey();
        clearmouseclick(WM_LBUTTONDOWN);

        if(aaa>=200 && aaa<=300 && bb>=230 && bb<=270){
            p=1;
        }
        else if(aaa>=200 && aaa<=300 && bb>=280 && bb<=320){
            p=2;
        }
        else if (aaa>=200 && aaa<=300 && bb>=330 && bb<=370){
            p=3;
        }
        else if(aaa>=200 && aaa<=300 && bb>=380 && bb<=420) {
            p=4;
        }
        break;
    }
    delay(10);
}

            int gd = DETECT, gm;
           // initgraph(&gd, &gm,"");
            initwindow(1000, 800);
            setfillstyle(SOLID_FILL, DARKGRAY);
            floodfill(5,5,15);
            layout();
            break;
        }
         if (aaa>=235 && aaa<=335 && bb>=260 && bb<=280){
           // closegraph();
            exit(0);
        }
    }
    delay(10);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    std::vector<std::pair<float,float> >v;
    v.push_back(std::make_pair(200, 430));
    v.push_back(std::make_pair(240, 373.3333));
    v.push_back(std::make_pair(280, 430));
    v.push_back(std::make_pair(320, 373.3333));
    v.push_back(std::make_pair(360, 430));
    v.push_back(std::make_pair(400, 373.3333));
    v.push_back(std::make_pair(440, 430));
    v.push_back(std::make_pair(496.6667, 470));
    v.push_back(std::make_pair(440, 510));
    v.push_back(std::make_pair(496.6667, 550));
    v.push_back(std::make_pair(440, 590));
    v.push_back(std::make_pair(496.6667, 630));
    v.push_back(std::make_pair(440, 670));
    v.push_back(std::make_pair(610,670));
    v.push_back(std::make_pair(553.3334,630));
    v.push_back(std::make_pair(610,590));
    v.push_back(std::make_pair(553.3334,550));
    v.push_back(std::make_pair(610,510));
    v.push_back(std::make_pair(553.3334,470));
    v.push_back(std::make_pair(610,430));
    v.push_back(std::make_pair(650,373.3333));
    v.push_back(std::make_pair(690,430));
    v.push_back(std::make_pair(730,373.3333));
    v.push_back(std::make_pair(770,430));
    v.push_back(std::make_pair(810,373.3333));
    v.push_back(std::make_pair(850,430));
    v.push_back(std::make_pair(850,260));
    v.push_back(std::make_pair(810,316.6667));
    v.push_back(std::make_pair(770,260));
    v.push_back(std::make_pair(730,316.6667));
    v.push_back(std::make_pair(690,260));
    v.push_back(std::make_pair(650,316.6667));
    v.push_back(std::make_pair(610,260));
    v.push_back(std::make_pair(553.3333,220));
    v.push_back(std::make_pair(610,180));
    v.push_back(std::make_pair(553.3333,140));
    v.push_back(std::make_pair(610,100));
    v.push_back(std::make_pair(553.3333,60));
    v.push_back(std::make_pair(610,20));
    v.push_back(std::make_pair(440,20));
    v.push_back(std::make_pair(496.6667,60));
    v.push_back(std::make_pair(440,100));
    v.push_back(std::make_pair(496.6667,140));
    v.push_back(std::make_pair(440,180));
    v.push_back(std::make_pair(496.6667,220));
    v.push_back(std::make_pair(440,260));
    v.push_back(std::make_pair(400,316.6667));
    v.push_back(std::make_pair(360,260));
    v.push_back(std::make_pair(320,316.6667));
    v.push_back(std::make_pair(280,260));
    v.push_back(std::make_pair(240,316.6667));
    v.push_back(std::make_pair(200,260));//51

    v.push_back(std::make_pair(200,316.6667));
    v.push_back(std::make_pair(240,373.3333));
    v.push_back(std::make_pair(496.6667,670));
    v.push_back(std::make_pair(553.3334,630));
    v.push_back(std::make_pair(850,373.3333));
    v.push_back(std::make_pair(810,316.6667));
    v.push_back(std::make_pair(553.3333,20));
    v.push_back(std::make_pair(496.6667,60));
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     int initialX[]={285,365,285,365,695,775,695,775,285,365,285,365,695,775,695,775};
    int initialY[]={505,505,605,605,505,505,605,605,95,95,195,195,95,95,195, 195};
    int cx[]={285,365,285,365,695,775,695,775,285,365,285,365,695,775,695,775};
    int cy[]={505,505,605,605,505,505,605,605,95,95,195,195,95,95,195,195};
    bool r=0,b=0,y=0,g=0;
    int radius=7;
    bool isDragging[16]={false};  //tracks weather the coins are dragged or not
    int selectedCoin=-1;
    int moveRemaining=0;
    for (int i=0;i<4;i++){
        setcolor(RED);
        setfillstyle(SOLID_FILL,RED);
        circle(cx[i],cy[i],radius);
        flood_fill(cx[i],cy[i],RED,WHITE);
    }
    for (int i=4;i<8;i++) {
        setcolor(BLUE);
        setfillstyle(SOLID_FILL,BLUE);
        circle(cx[i],cy[i],radius);
        flood_fill(cx[i],cy[i],BLUE ,WHITE);
    }
    for (int i=8;i<12;i++) {
        setcolor(GREEN);
        setfillstyle(SOLID_FILL,GREEN);
        circle(cx[i],cy[i],radius);
        flood_fill(cx[i],cy[i],GREEN,WHITE);
    }
    for (int i=12;i<16;i++){
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL,YELLOW);
        circle(cx[i],cy[i],radius);
        flood_fill(cx[i],cy[i],YELLOW,WHITE);
    }
    int player=1,num;
    //int p;
    //cout<<"How many player: ";
    //cin>>p;
    int aa;
    if(p==1)aa=4;
    else if(p==2)aa=8;
    else if(p==3)aa=12;
    else if(p==4)aa=16;
   while (true) {
              if (moveRemaining==0) {
             num=(rand()%6)+1;
             rollDiceAnimation(num,cx,cy,player);
             /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
             ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            // cout<<"Player "<< player<<"'s turn."<<'\n';
             //cout<<"Dice Roll: "<<num<<'\n';
            moveRemaining=num;
        }
        if((num!=6 && selectedCoin<4 && r==0) || (num!=6 && selectedCoin>=4 && selectedCoin<8 && b==0) || (num!=6 && selectedCoin>=8 && selectedCoin<12 && y==0) || (num!=6 && selectedCoin>=12 && selectedCoin<16 && g==0))
        {
            moveRemaining=0;
            player++;
            if (player>p){
                player=1;
            }
            continue;
        }
        if(ismouseclick(WM_RBUTTONDOWN)) {
            int mx,my;
            getmouseclick(WM_RBUTTONDOWN, mx, my);
            // Check which circle is clicked for all coins
            for (int i=0;i<aa;i++){
                if (isInsideCircle(mx,my,cx[i],cy[i],radius)) {
                    isDragging[i] = true;
                    selectedCoin = i;
                    if(i<4)r=1;
                    else if(i>=4 && i<8)b=1;
                    else if(i>=8 && i<12)y=1;
                    else g=1;
                    break;
                }
            }
            clearmouseclick(WM_RBUTTONDOWN);
        }
          if(ismouseclick(WM_LBUTTONDOWN)){
            int mx,my;
            getmouseclick(WM_LBUTTONDOWN,mx,my);
            if (selectedCoin!=-1 && isDragging[selectedCoin]) {
                // Checkig if the square is occupied by a different-colored coin
                for (int i=0;i<16;i++) {
                     if((selectedCoin<4 && i>=4) || ((selectedCoin>=4 && selectedCoin<8) && (i<4 || i>=8)) || ((selectedCoin>=8 && selectedCoin<12)&& (i<8 || i>=12)) || ((selectedCoin>=12 && selectedCoin<16) && i<=11)){
                    if (i!=selectedCoin && areCoinsInSameSquare(mx,my,cx[i],cy[i],v) ) {
                        // Move the existing coin back to its initial position
                       if(num!=6) player--;
                        setcolor(DARKGRAY);
                        setfillstyle(SOLID_FILL, DARKGRAY);
                        circle(cx[i],cy[i],radius); // drawing a darkgrey circle since background is darkgrey
                        floodfill(cx[i], cy[i],DARKGRAY);
                        cx[i]=initialX[i];
                        cy[i]=initialY[i];
                        // Redraw the existing coin at its initial position
                        if(i<4) {
                            setcolor(RED);
                            setfillstyle(SOLID_FILL,RED);

                        } else if(i<8) {
                            setcolor(BLUE);
                            setfillstyle(SOLID_FILL,BLUE);
                        } else if(i<12) {
                            setcolor(GREEN);
                            setfillstyle(SOLID_FILL, GREEN);
                        } else {
                            setcolor(YELLOW);
                            setfillstyle(SOLID_FILL,YELLOW);
                        }
                        circle(cx[i],cy[i],radius);
                        flood_fill(cx[i],cy[i],getcolor(),DARKGRAY);
                    }
                }
            }
                //moving the selected coin to the new position
               if(isInsideRedPath(cx[selectedCoin],cy[selectedCoin])) //maintaining the color of the path to home
                {
                setcolor(RED);
                setfillstyle(SOLID_FILL, RED);
                circle(cx[selectedCoin],cy[selectedCoin],radius); // Erase old position
                floodfill(cx[selectedCoin], cy[selectedCoin],RED);
                }
                else if(isInsideBluePath(cx[selectedCoin],cy[selectedCoin]))
                {
                setcolor(BLUE);
                setfillstyle(SOLID_FILL,BLUE);
                circle(cx[selectedCoin],cy[selectedCoin],radius);
                floodfill(cx[selectedCoin],cy[selectedCoin],BLUE);
                }
            else if(isInsideYellowPath(cx[selectedCoin],cy[selectedCoin]))
                {
                setcolor(YELLOW);
                setfillstyle(SOLID_FILL,YELLOW);
                circle(cx[selectedCoin],cy[selectedCoin],radius);
                floodfill(cx[selectedCoin],cy[selectedCoin],YELLOW);
                }
            else if(isInsideGreenPath(cx[selectedCoin],cy[selectedCoin]))
                {
                setcolor(GREEN);
                setfillstyle(SOLID_FILL,GREEN);
                circle(cx[selectedCoin],cy[selectedCoin],radius);
                floodfill(cx[selectedCoin],cy[selectedCoin],GREEN);
                }
               else{
                setcolor(DARKGRAY);
                setfillstyle(SOLID_FILL,DARKGRAY);
                circle(cx[selectedCoin],cy[selectedCoin],radius); // Erase old position
                floodfill(cx[selectedCoin], cy[selectedCoin], DARKGRAY);
               }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                cx[selectedCoin]=mx;
                cy[selectedCoin]=my;
                if (selectedCoin<4) {
                    if (isInsideRedPath(cx[selectedCoin],cy[selectedCoin])) {
                            setcolor(WHITE);
                            setfillstyle(SOLID_FILL, WHITE);
                        } else{
                            setcolor(RED);
                            setfillstyle(SOLID_FILL,RED);
                        }
                } else if(selectedCoin<8) {
                    if (isInsideBluePath(cx[selectedCoin],cy[selectedCoin])) {
                            setcolor(WHITE);
                            setfillstyle(SOLID_FILL,WHITE);
                        } else{
                            setcolor(BLUE);
                            setfillstyle(SOLID_FILL,BLUE);
                        }
                } else if(selectedCoin<12) {
                   if (isInsideGreenPath(cx[selectedCoin],cy[selectedCoin])) {
                            setcolor(WHITE);
                            setfillstyle(SOLID_FILL,WHITE);
                        } else{
                            setcolor(GREEN);
                            setfillstyle(SOLID_FILL,GREEN);
                        }
                } else {
                     if (isInsideYellowPath(cx[selectedCoin],cy[selectedCoin])) {
                            setcolor(WHITE);
                            setfillstyle(SOLID_FILL,WHITE);
                        } else{
                            setcolor(YELLOW);
                            setfillstyle(SOLID_FILL,YELLOW);
                        }
                }
                circle(cx[selectedCoin],cy[selectedCoin],radius);
                flood_fill(cx[selectedCoin],cy[selectedCoin],getcolor(),DARKGRAY);
                isDragging[selectedCoin]=false;
                selectedCoin=-1;
            }
            moveRemaining=0;
            clearmouseclick(WM_LBUTTONDOWN);
            if (num!=6){
            player++;
            if (player>p){
                player=1;
            }
        }
        }



setcolor(RED);
setfillstyle(SOLID_FILL,RED);
flood_fill(205, 435,RED,DARKGRAY);
setcolor(WHITE);
verticallineGreenRed();
verticallineYellowBlue();
horizontallineGreenYellow();
horizontallineRedBlue();
horizontalGreenRed();
verticalGreenYellow();
verticalRedBlue();
horizontalYellowBlue();
red_corner();
blue_corner();
green_corner();
yellow_corner();
delay(50);
if (kbhit()) {
    char c=getch();
    if (c=='q') break;
    }
    }
}



void red_corner(){
    setcolor(WHITE);
    rectangle(200,430,440,670);// Outer Line
    rectangle(240,470,400,630);// Inner Line
    rectangle(440,590,497,630);// Starting point
    rectangle(497,430,554,630);// Way to destination
    setfillstyle(SOLID_FILL, RED);
    floodfill(550,434,WHITE);
    // Bottom-left and top-right corners of the square */
    double x1=280, y1=430,x2=320,y2=373,x3=440,y3=590,x4=496.6667,y4=630;
    double centerX=(x1+x2)/2;
    double centerY=(y1+y2)/2;
    setcolor(RED);
    star(centerX, centerY);
    centerX=(x3+x4)/2;
    centerY=(y3+y4)/2;
    star(centerX,centerY);
    floodfill(206,434,WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(245,475,WHITE);
}
void blue_corner(){
    setcolor(WHITE);
    rectangle(610,430,850,670);
    rectangle(650,470,810,630);
    rectangle(770,374,810,430);
    rectangle(610,317,810,374);
    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(615,322,WHITE);
    double x1=610, y1=590,x2=553.3334,y2=550;
    double centerX=(x1+x2)/2;
    double centerY=(y1+y2)/2;
    setcolor(BLUE);
    star(790,400);
    star(centerX,centerY);
    floodfill(615,435,WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(660,480,WHITE);
}

void green_corner()
{
    setcolor(WHITE);
    rectangle(200,20,440,260);
    rectangle(240,60,400,220);
    rectangle(240,260,280,317);
    rectangle(240,317,440,374);
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(245,322,WHITE);
     double x1=440,y1=100,x2=496.6667,y2=140;
    double centerX=(x1+x2)/2;
    double centerY=(y1+y2)/2;
    setcolor(GREEN);
    star(260,290);
    star(centerX,centerY);
    floodfill(205,25,WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(245,65,WHITE);
}
void yellow_corner()
{
    setcolor(WHITE);
    rectangle(610,20,850,260);
    rectangle(650,60,810,220);
    rectangle(554,60,610,100);
    rectangle(497,60,554,260);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(550,65,WHITE);
    double x1=730,y1=260,x2=770,y2=316.6667;
    double centerX=(x1+x2)/2;
    double centerY =(y1+y2)/2;
    setcolor(YELLOW);
    star(584,80);
    star(centerX,centerY);
    floodfill(615,25,WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(655,65,WHITE);
}
void verticallineGreenRed()
{
    setcolor(WHITE);
    for(int i=200;i<440;i+=40)
    {
            line(i,260,i,430);
    }

}
void verticallineYellowBlue()
{
    setcolor(WHITE);
    for(int i=610;i<890;i+=40) // 850
    {
            line(i,260,i,430);
    }
}
void horizontallineGreenYellow()
{
    setcolor(WHITE);
    for(int i=20;i<260;i+=40)
    {
        line(440,i,610,i);
    }
}
void horizontallineRedBlue()
{
    setcolor(WHITE);
    for(int i=470;i<710;i+=40)
    {
        line(440,i,610,i);
    }
}

void horizontalGreenRed(){
    setcolor(WHITE);
    line(200,317,440,317);
    line(200,374,440,374);
}
void verticalGreenYellow()
{
    setcolor(WHITE);
    line(497,20,497,260);
    line(554,20,554,260);
}
void verticalRedBlue()
{
    setcolor(WHITE);
    line(497,430,497,670);
    line(554,430,554,670);
}
void horizontalYellowBlue()
{
    setcolor(WHITE);
    line(610,317,850,317);
    line(610,374,850,374);
}
void home() {
    setcolor(WHITE);
    rectangle(440,260,610,430);
    line(440,260,610,430); // Diagonal from top-left to bottom-right
    line(610,260,440,430); // Diagonal from top-right to bottom-left
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(525,270,WHITE);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(450,330,WHITE);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(600,330,WHITE);
    setfillstyle(SOLID_FILL,RED);
    floodfill(525,410,WHITE);
}
void layout()
{
    red_corner();
    blue_corner();
    green_corner();
    yellow_corner();
    verticallineGreenRed();
    verticallineYellowBlue();
    horizontallineGreenYellow();
    horizontallineRedBlue();
    horizontalGreenRed();
    verticalGreenYellow();
    verticalRedBlue();
    horizontalYellowBlue();
    home();
}





