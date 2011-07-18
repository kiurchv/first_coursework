#include <graphics.h>
#include "bitmap.cpp"

class ScreenView {
	private:
	public:
		void init ();
		void load_map ();
		void draw_grid (int step, int color);
		void draw_info (TargetModel *);
};

void ScreenView::init () {
	//	request auto detection
  int gdriver = DETECT, gmode, errorcode;
  //	initialize graphics mode
  initgraph(&gdriver, &gmode, "");
  //	read result of initialization
  errorcode = graphresult();
	if (errorcode != grOk)  // an error occurred
	{
  	printf("Graphics error: %s\n", grapherrormsg(errorcode));
  	printf("Press any key to halt:");
  	getch();
  	exit(1);             // return with error code
	}
}

void ScreenView::draw_map () {
	Bitmap map("resources//map.bmp");
	map.put(0, 0, 0, 0);
}

void ScreenView::draw_grid (int step = 50, int color = LIGHTBLUE) {
	setcolor (color);
	settextstyle(4,0,1);
	char s[10];
	for (int i = 0; i <= WIDTH; i+=step) {
		line (i,0,i,HEIGHT);
		sprintf(s, "%d", i);
		outtextxy(i,HEIGHT-20,s);
	}
	for (i = HEIGHT; i>0; i-=step){
		line (0,i,WIDTH,i);
		sprintf(s,"%d", i);
		outtextxy(2,i+2,s);
	}
}


void ScreenView::draw_info (TargetModel *target) {
	char x[6];
	char y[6];
	char v[6];
	char q[6];
	/*char h[2];
	char m[2];
	char s[2];*/
	itoa(int(target->coords.x), x, 10);
	itoa(int(target->coords.y), y, 10);
	itoa(int(target->v), v, 10);
	itoa(int(target->q), q, 10);
	setviwport(WIDTH,HEIGHT,640,480,CLIP_ON);
	setfillstyle(1,BLUE);
	bar(0,0,160,160);
	settextstyle(1,0,1);
  setcolor(15);
  outtextxy(15,15,"X:");
  setcolor(LIGHTGRAY);
	outtextxy(20,15,x);
  setcolor(15);
  outtextxy(15,25,"Y:");
  setcolor(LIGHTGRAY);
	outtextxy(20,25,y);
  setcolor(15);
  outtextxy(15,35,"V:");
  setcolor(LIGHTGRAY);
	outtextxy(20,35,v);
	setcolor(15);
  outtextxy(15,45,"Q:");
  setcolor(LIGHTGRAY);
	outtextxy(20,45,q);
}
