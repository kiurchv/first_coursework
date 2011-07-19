class ObjectView {
	private:
		int x;
		int y;
		int r;
		void *buffer;
	public:
		ObjectView ();
		~ObjectView ();
		void draw (ObjectModel *);
		void destroy ();
};

ObjectView::ObjectView () {
	r = 0;
	x = 0;
	y = 0;
}

ObjectView::~ObjectView () {
	free(buffer);
}

void ObjectView::draw (ObjectModel *data) {
	x = int(data->coords.x);
	y = int(data->coords.y);
	r = data->r;
	Bitmap img("obj.bmp");
	buffer = malloc(imagesize(x-r,y-r,x+r ,y+r));
	getimage(x-r,y-r,x+r ,y+r, buffer);
	img.put(x-img.get_width()/2, y-img.get_height()/2, 1, 15);
	setcolor(BLUE);
	circle(x,y,r);
}

void ObjectView::destroy () {
	putimage(x-r,y-r,buffer,COPY_PUT);
	Bitmap destroyed("objd.bmp");
	destroyed.put(x-r, y-r, 1, 15);
}

