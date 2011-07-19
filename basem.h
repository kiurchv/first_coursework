class BaseModel {
	public:
		point coords;		//координати
		int r;	 				//радіус враження
		int live;				//стан
		//BaseModel ();
		point get_coords ();
		void set_coords (point);
		float get_radius ();
		int is_live ();
		void kill ();
};

/*BaseModel::BaseModel () {
	live = 1;
}*/

point BaseModel::get_coords () {
	return coords;
}

void BaseModel::set_coords (point coords_in) {
	coords = coords_in;
}

float BaseModel::get_radius () {
	return r;
}

int BaseModel::is_live () {
	return live;
}

void BaseModel::kill () {
	live = 0;
}

