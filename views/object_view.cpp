#include "bitmap.cpp"
class ObjectView {
	private:
		Bitmap img("resources//object.bmp");
		void *buffer;
		ipoint location;
		int r;
	public:
		void draw (ObjectModel *);
		void destroy ();
};

ObjectView::ObjectView () {
	buffer = malloc(img.get_size());
}

ObjectView::~ObjectView () {
	free(buffer);
}

void ObjectView::draw (ObjectModel *data) {
	setviewport(0,0,WIDTH,HEIGHT,CLIP_ON);	
	location.x = int(data->coords.x);
	location.y = int(data->coords.y);
	r = data->r;
	getimage(location.x-r,
					 location.y-r,
					 location.x+r,
					 location.y+r, buffer);
	img.put( location.x-r,
					 location.y-r, 1, 15);
	setcolor(DARKBLUE);
	circle(x, y, r);
}

void destroy () {
	Bitmap destroyed("resources//object_destroyed.bmp");	
	setviewport(0,0,WIDTH,HEIGHT,CLIP_ON);
	putimage( location.x-r,
						location.y-r, buffer, 256 );	
	destroyed.put(current_location.x-r,
								current_location.y-r, 1, 15);
}
