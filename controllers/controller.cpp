class Controller {
	public:
		Controller();
		void get_data (ObjectModel *, TargetModel *);
		int listen ();

};

Controller::get_data(ObjectModel *object, TargetModel *target) {
	float r_object, r_target;

	cout << "Set the object dislocation:\n\tEnter X:";
		cin >> object->x;
	cout << "\n\tEnter Y:";
		cin >> object->y;
	cout << "Set the target dislocation:\n\tEnter X:";
		cin >> target->x;
	cout << "\n\tEnter Y:";
		cin >> target->y;
	cout << "Enter the speed of target:\n\tV="; 
		cin >> target->v;
	do {
    cout<<"Enter damage radius of object:\nRo=";
			cin >> r_object;
    cout << "Enter damage radius of target:\nRt=";
			cin >> r_target;
    if (35 =< r_object && r_object < r_target) {
			cout << "Minimal Rt is 35.Rt must be bigger than Ro!\n";
		} else {
			target->r = r_target;
			object->r = r_object;
		}
  } while(r_object < r_target);
}

int listen () {
	if (kbhit()) {
		int key=bioskey(0);
		switch (key) {	
			case LEFT:	return 1;
									break;							
			case RIGHT: return 2;
									break;
			default:		return 0;
									break;
	} else {
		return 0;
	}
}
