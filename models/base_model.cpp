#include "helpers\helpers.cpp"
#include "controllers\controller.cpp"
#include "views\screen_view.cpp"

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
	live = 1;
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

int is_live () {
	return live;
}

void kill () {
	live = 0;
}
