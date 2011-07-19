typedef struct {
	float x,y;
} point;

typedef struct {
	int x,y;
} ipoint;

float probability () {
	randomize();
	return random(100)/100;
}

float RtD (float x) { return x*180/M_PI; }

float DtR (float x) { return x*M_PI/180; }

//визначення відстані між точками за їх координатами
float distance (point p1, point p2) { return sqrtl(sqr(p2.x-p1.x)+sqr(p2.y-p1.y)); }

/*
//визначнеея напряму руху цілі за її поточними координатами
float direction (point p){
	if ((p.x==0)|(p.y==0)) {
		if (p.x==0) {
			if (p.y>0) return 0; else return 180;
		} else
			if (p.y==0) {
				if (p.x>0) return 90; else return 270;
			}
	} else
	if (p.x>0) {
		if (p.y>0) {
			return 90-RtD(atan(p.y/p.x));
		} else {
			return 90+RtD(atan (-p.y/p.x));
		};
	} else {
		if (p.y>0) {
			return 270 +(RtD(atan(p.y/(-p.x))));
		} else {
			return 180 +(90-RtD(atan (p.y/p.x)));
		}
	}
}
*/

