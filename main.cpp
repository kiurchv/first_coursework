#include "target_model.cpp"
#include "object_model.cpp"
#include "controller.cpp"
#include "screen_view.cpp"

void main () {
//	creating objects
	ObjectModel object;
	TargetModel target;
	Controller controller;
	ScreenView screen;
	FileView file;
//	entering data
	controller.get_data(&object, &target);
//	rendering screen
	screen.init();
	//screen.load_map();
	screen.draw_grid();
	screen.draw_target(&target);
	screen.draw_object(&object);
	
//	begin modelling
	while (distance(object.get_coords, target.get_coords) != object.get_radius()) {
		target.move(controller.listen());
		screen.draw_target(&target);
	}
	if (probability() < 0.7) {
		target.kill();
		screen.destroy_target(&target);
	} else {
		while (distance(object.get_coords, target.get_coords) != target.get_radius()) {
			target.move(controller.listen());
			screen.draw_target(&target);
		}
	}
	if (probability() < 0.9) {
		object.kill();
		screen.destroy_object(&object);
	}
// writing results
	file.write_results(&target);
}
