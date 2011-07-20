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
target->V=2000;
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
	int key;
	int event = 0;
	if (kbhit()) {
		key = bioskey(0);
		switch (key) {
			case LEFT:	event = 1;	break;
			case RIGHT:	event = 2;	break;
			case ESC:		exit(0);
		}
	}
	return event;
}

