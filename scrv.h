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

void ScreenView::draw_info (ObjectModel *object_data, TargetModel *target_data) {
	int x0 = 450;
	char x[3];	itoa(int(target_data->coords.x), x, 10);
	char y[3];	itoa(int(target_data->coords.y), y, 10);
	char v[4];	itoa(int(target_data->V), v, 10);
	char q[3];	itoa(int(target_data->Q), q, 10);
	char d[3];	itoa(int(distance(object_data->coords, target_data->coords)), d, 10);

	// putting data
	setfillstyle(1,BLUE);
	bar(x0,0,x0+190,100);
	settextstyle(1,0,1);
  setcolor(WHITE);	outtextxy(x0+15,15,"X:");	setcolor(LIGHTGRAY);	outtextxy(x0+30,15,x);
  setcolor(WHITE);	outtextxy(x0+15,25,"Y:"); setcolor(LIGHTGRAY);	outtextxy(x0+30,25,y);
  setcolor(WHITE);	outtextxy(x0+15,35,"V:"); setcolor(LIGHTGRAY);	outtextxy(x0+30,35,v);
	setcolor(WHITE);	outtextxy(x0+15,45,"Q:"); setcolor(LIGHTGRAY);	outtextxy(x0+30,45,q);
	setcolor(WHITE);	outtextxy(x0+15,55,"D:");	setcolor(LIGHTGRAY);	outtextxy(x0+30,55,d);
	setcolor(WHITE);	outtextxy(x0+15,65,"Target state:");

	if (target_data->live) {
		setcolor(GREEN);	outtextxy(x0+130,65,"LIVE");
	} else {
		setcolor(RED);		outtextxy(x0+130,65,"DESTROY");
	}

	setcolor(WHITE);	outtextxy(x0+15,75,"Object state:");
	if (object_data->live) {
		setcolor(GREEN);	outtextxy(x0+130,75,"LIVE");
	} else {
		setcolor(RED);		outtextxy(x0+130,75,"DESTROY");
	}
}

