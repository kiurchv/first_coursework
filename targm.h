class TargetModel :public BaseModel {
	public:
		float V;	//speed
		float Mv;	//scale of speed
		float Q;	//direction
		float dT;
		TargetModel();
		float get_speed ();
		void set_speed (float);
		void move(int, ObjectModel *);
};


TargetModel::TargetModel () {
	Mv = 3600;
	dT = 1;
}

float TargetModel::get_speed () {
	return V;
}

void TargetModel::set_speed (float v_in) {
	V = v_in;
}

void TargetModel::move (int direction_change, ObjectModel *object) {
	float q;
	q=(object->coords.x-coords.x)/distance(coords, object->coords);
	Q=asin(q)*180/M_PI;
	switch (direction_change) {
		case 1:	Q-=40;
						break;
		case 2:	Q+=40;
						break;
	}
	if(Q<0) Q+=360;
	coords.x-=V/Mv*dT*cos((90-Q)*M_PI);
	coords.y+=V/Mv*dT*sin((90-Q)*M_PI);
}

