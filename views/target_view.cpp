#include "bitmap.cpp"
class TargetView {
	private:
		Bitmap img("resources//target.bmp");
		void *buffer;
		ipoint location;
		int r;
	public:
		TargetView ();
		void draw (TargetModel *);
		void destroy (TargetModel *);
};

TargetView::TargetView () {
	buffer = malloc(img.get_size());
}

TargetView::~TargetView () {
	free(buffer);
}

void TargetView::draw (TargetModel *data) {
	setviewport(0,0,WIDTH,HEIGHT,CLIP_ON);	
	if (location) {
		putimage( location.x-r,
							location.y-r, buffer, 256 );	
	}
	location.x = int(data->coords.x);
	location.y = int(data->coords.y);
	r = data->r;
	getimage(location.x-r,
					 location.y-r,
					 location.x+r,
					 location.y+r, buffer);
	img.put(location.x-r,
					location.y-r, 1, 15);
	setcolor(RED);
	circle(location.x, location.y, r);
}

void destroy (TargetModel *data)	{
	Bitmap destroyed("resources//target_destroyed.bmp");	
	setviewport(0,0,WIDTH,HEIGHT,CLIP_ON);
	putimage( location.x-r,
						location.y-r, buffer, 256 );	
	location.x = int(data->coords.x);
	location.y = int(data->coords.y);
	destroyed.put(location.x-r,
								location.y-r, 1, 15);
}
