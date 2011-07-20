class TargetView {
	private:
		int x;
		int y;
		int r;
		void *buffer;
	public:
		TargetView ();
		~TargetView ();
		void draw (TargetModel *);
		void destroy ();
};

TargetView::TargetView () {
	r = 0;
	x = 0;
	y = 0;
}

TargetView::~TargetView () {
	free(buffer);
}

void TargetView::draw (TargetModel *data) {
	Bitmap image("targ.bmp");
	if (!buffer)	{
		buffer = malloc(imagesize(x-r,y-r,x+r,y+r));
	} else {
		putimage(x-r,y-r,buffer,COPY_PUT);
	}
	x = int(data->coords.x);
	y = int(data->coords.y);
	r = data->r;
	getimage(x-r,y-r,x+r,y+r, buffer);
	image.put(x-image.get_width()/2, y-image.get_height()/2, 1, 15);
	setcolor(RED);
	circle(x,y,r);
	delay(100);
}

void TargetView::destroy ()	{
	putimage(x-r,y-r,buffer,COPY_PUT);
	Bitmap destroyed("targd.bmp");
	destroyed.put(x-destroyed.get_width()/2, y-destroyed.get_height()/2, 1, 15);
}

