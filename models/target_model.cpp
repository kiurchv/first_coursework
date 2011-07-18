#include <math.h>
#include "helpers\helpers.cpp"
#include "models\base_model.cpp"
#include "models\object_model.cpp"

class TargetModel :public BaseModel {
		private:
		float V;	//speed
		float Mv;	//scale of speed
		float Q;	//direction
	public:
		friend ObjectModel;
		TargetModel() :BaseModel();
		point get_speed ();
		void set_speed (float);
		void move();
};


TargetModel::TargetModel () {
	Mv=3600;
	dT=1;
}

point TargetModel::get_speed () {
	return V;
}

void TargetModel::move (int direction_change, ObjectModel *object) {
	float x0;	x0 = object->coords.x;
	float y0;	y0 = object->coords.y;
	float q;
	q=(x0-coords.x)/distance(coords, object->coords);
	Q=asin(q)*180/M_PI;
	switch (direction_change) {
		case 1:	Q-=10;
						break;	
		case 2:	Q+=10;
						break;
	}
	if(Q<0) Q+=360;
	x=x+V/Mv*dT*cos((90-Q)*M_PI);
	y=y-V/Mv*dT*sin((90-Q)*M_PI);
}
