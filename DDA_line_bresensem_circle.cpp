#include<graphics.h>
void drawline (int x1, int y1, int x2, int y2)
{
    int dx,dy,m,s;
    float xi,yi,x,y;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
        s=abs(dx);
    else
        s=abs(dy);
    xi=dx/(float)s;
    yi=dy/(float)s;
    x=x1;
    y=y1;
    putpixel(x1,y1,WHITE);
    for(m=0;m<s;m++)
    {
        x+=xi;
        y+=yi;
        putpixel(x,y,WHITE);
    }
}
int main(){
    int gd = DETECT, gm, x1,y1,x2,y2;
    initgraph(&gd, &gm, NULL);
    drawline(80,80,400,80);
    drawline(400,80,400,400);
    drawline(400,400,80,400);
    drawline(80,400,80,80);
    drawline(80,240,240,80);
    drawline(240,80,400,240);
    drawline(400,240,240,400);
    drawline(80,240,240,400);
    circle(240,240,113);
    delay(3000);
    
    closegraph();
    return 0;
}