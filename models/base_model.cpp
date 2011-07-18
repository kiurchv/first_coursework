class BaseModel {
	private:
		point coords;		//координати
		int r;	 				//радіус враження
		int live;				//стан
	public:
		BaseModel ();
		float get_coords ();
		void set_coords (point);
		float get_radius ();
		int get_found ();
		void set_found ();
		friend Controller;
		friend ScreenView;
};

BaseModel::BaseModel () {	
	P = 0;
	live = 1;
	found = 0;
}

point BaseModel::get_coords () {
	return coords;
}

void BaseModel::set_coords (point coords_in) {
	coords = coords_in;
}

float BaseModel::get_radius () {
	return R;			
}

void BaseModel::set_found (int found_in = 1) {
	found = found_in;
}

int is_live () {
	return live;
}

void kill () {
	live = 0;
}
