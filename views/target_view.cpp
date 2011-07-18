#include "bitmap.cpp"
class TargetView {
	private:
		void *buffer;
		ipoint current_location;
	public:
		TargetView ();
		void draw (TargetModel *);
		void destroy (TargetModel *);
};

TargetView::TargetView () {
	Bitmap img("resources//target.bmp");
	buffer = malloc(img.get_size());
}

TargetView::~TargetView () {
	free(buffer);
}

void TargetView::draw (TargetModel *data) {
	setviewport(0,0,WIDTH,HEIGHT,CLIP_ON);	
	if (current_location) {
		putimage( current_location.x-data->r,
							current_location.y-data->r, buffer, 256 );	
	}
	current_location.x = int(data->coords.x);
	current_location.y = int(data->coords.y);
	getimage(current_location.x-data->r,
					 current_location.y-data->r,
					 current_location.x+data->r,
					 current_location.y+data->r, buffer);
	img.put( current_location.x-data->r,
									current_location.y-data->r, 1, 15);
	setcolor(RED);
	circle(current_location.x, current_location.y, data->r);
}

void destroy (TargetModel *data)	{

	
}
