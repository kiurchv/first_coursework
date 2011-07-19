class TargetView {
	private:
		int x;
		int y;
		int r;
	public:
		TargetView ();
		void draw (TargetModel *);
		void destroy ();
};

TargetView::TargetView () {
	r = 0;
	x = 0;
	y = 0;
}

void TargetView::draw (TargetModel *data) {
	x = int(data->coords.x);
	y = int(data->coords.y);
	r = data->r;
	void *buffer;
	Bitmap img("targ.bmp");
	buffer = malloc(imagesize(x-r,y-r,x+r,y+r));
	getimage(x-r,y-r,x+r,y+r, buffer);
	img.put(x-img.get_width()/2, y-img.get_height()/2, 1, 15);
	setcolor(RED);
	circle(x,y,r);
	//delay(10);
	putimage(x-r,y-r,buffer,COPY_PUT);
	free(buffer);
}

void TargetView::destroy ()	{
	Bitmap destroyed("targd.bmp");
	destroyed.put(x-r,	y-r, 1, 15);
}

