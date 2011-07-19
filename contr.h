class Controller {
	public:
		void get_data (ObjectModel *, TargetModel *);
		int listen ();
};

void Controller::get_data(ObjectModel *object, TargetModel *target) {
	int r_object, r_target;
	clrscr();
	//cout << "Set the object dislocation:\n\tEnter X:";
		//cin >>
object->coords.x=320;
	//cout << "\n\tEnter Y:";
		//cin >>
object->coords.y=240;
	//cout << "Set the target dislocation:\n\tEnter X:";
		//cin >>
target->coords.x=100;
	//cout << "\n\tEnter Y:";
		//cin >>
target->coords.y=400;
	//cout << "Enter the speed of target:\n\tV=";
		//cin >>
target->V=1000;
	do {
    //cout<<"Enter damage radius of object:\n\tRo=";
			//cin >>
 r_object=50;
    //cout << "Enter damage radius of target:\n\tRt=";
			//cin >>
 r_target=35;
    if ( (r_target < 35) || (r_object < r_target) ) {
			cout << "Minimal Rt is 35. Ro must be bigger than Rt!\n";
		} else {
			target->r = r_target;
			object->r = r_object;
		}
  } while( (r_target < 35) || (r_object < r_target) );
}

int Controller::listen () {
	if (kbhit()) {
		switch (bioskey(0)) {
			case LEFT:	return 1;	break;
			case RIGHT:	return 2;	break;
			default:	return 0;
		}
	} else {
		return 0;
	}
}

