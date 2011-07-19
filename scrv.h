class ScreenView {
	public:
		void init ();
		void draw_map ();
		void draw_grid ();
		void draw_info (ObjectModel *, TargetModel *);
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
	Bitmap map("map.bmp");
	map.put(0, 0, 0, 0);
}

void ScreenView::draw_grid () {
	int step = 50;
	settextstyle(4,0,1);
	char s[10];
	for (int i = 0; i <= WIDTH; i+=step) {
		setcolor(GREEN);
		line (i,0,i,HEIGHT);
		itoa(i, s, 10);
		setcolor(BLACK);
		outtextxy(i,HEIGHT-20,s);
	}
	for (i = HEIGHT; i>0; i-=step){
		setcolor(GREEN);
		line (0,i,WIDTH,i);
		itoa(i, s, 10);
		setcolor(BLACK);
		outtextxy(2,i+2,s);
	}
}

void ScreenView::draw_info (ObjectModel *object, TargetModel *target) {
	char x[6];	itoa(int(target->coords.x), x, 10);
	char y[6];	itoa(int(target->coords.y), y, 10);
	char v[6];	itoa(int(target->V), v, 10);
	char q[6];	itoa(int(target->Q), q, 10);
	char d[6];	itoa(distance(object->coords, target->coords), d, 10);
	/*char h[2];
	char m[2];
	char s[2];*/
	setviewport(480,480,WIDTH,HEIGHT,1);
	setfillstyle(1,BLUE);
	bar(0,0,160,160);
	settextstyle(1,0,1);
  setcolor(WHITE);	outtextxy(15,15,"X:");	setcolor(LIGHTGRAY);	outtextxy(20,15,x);
  setcolor(WHITE);	outtextxy(15,25,"Y:");  setcolor(LIGHTGRAY);	outtextxy(20,25,y);
  setcolor(WHITE);	outtextxy(15,35,"V:");  setcolor(LIGHTGRAY);	outtextxy(20,35,v);
	setcolor(WHITE);	outtextxy(15,45,"Q:");  setcolor(LIGHTGRAY);	outtextxy(20,45,q);
	setcolor(WHITE);	outtextxy(15,45,"D:");  setcolor(LIGHTGRAY);	outtextxy(20,55,d);
}

