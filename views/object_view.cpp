#include "bitmap.cpp"
class ObjectView {
	public:
		void draw (ObjectModel *);
		void destroy (ObjectModel *);
};

void ObjectView::draw (ObjectModel *data) {
	setviewport(0,0,WIDTH,HEIGHT,CLIP_ON);	
	int x = int(data->coords.x);
	int y = int(data->coords.y);
	Bitmap img("resources//object.bmp");
	img.put(x-data->r,
					y-data->r, 1, 15);
	setcolor(DARKBLUE);
	circle(x, y, data->r);
}
