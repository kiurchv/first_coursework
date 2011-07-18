#include <alloc.h>
#include <graphics.h>
#include "helpers\helpers.cpp"
#include "helpers\bitmap.cpp"
#include "helpers\constants.cpp"
#include "models\target_model.cpp"

class TargetView {
	private:
		void *buffer;
		ipoint location;
		int r;
	public:
		~TargetView ();
		void draw (TargetModel *);
		void destroy (TargetModel *);
};

TargetView::~TargetView () {
	free(buffer);
}

void TargetView::draw (TargetModel *data) {
	Bitmap img("resources//target.bmp");
	setviewport(0,0,WIDTH,HEIGHT,CLIP_ON);		
	if (buffer) {
		putimage( location.x-r,
							location.y-r, buffer, 256 );	
	}	else {
		buffer = malloc(img.get_size());
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
