typedef struct {
	float x,y;
} point;

float prob () {
	float p;
	p=rand()%100;
	p/=100;
	return p;
}

float rtd (float x) { return x*180/M_PI; }

float dtr (float x) { return x*M_PI/180; }

float distance (point p1, point p2) { return sqrtl(sqr(p2.x-p1.x)+sqr(p2.y-p1.y)); }

/*float direction (point v){
	if ((v.x==0)|(v.y==0)) {
		if (v.x==0) {
			if (v.y>0) return 0; else return 180;
		} else
			if (v.y==0) {
				if (v.x>0) return 90; else return 270;

			};
	} else
	if (v.x>0) {
		if (v.y>0) {
			return 90-rtd(atan(v.y/v.x));
		} else {
			return 90+rtd(atan (-v.y/v.x));
		};
	} else {
		if (v.y>0) {
			return 270 +(rtd(atan(v.y/(-v.x))));
		} else {
			return 180 +(90-rtd(atan (v.y/v.x)));
		}
	}
}
*/

