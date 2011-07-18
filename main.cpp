#include "target_model.cpp"
#include "object_model.cpp"
#include "controller.cpp"
#include "screen_view.cpp"

void main () {
//	creating objects
	ObjectModel object_model;
	TargetModel target_model;
	Controller controller;
	ScreenView screen;
	ObjectView object_view;
	TargetView target_view;
//	entering data
	controller.get_data(&object_model, &target_model);
//	rendering screen
	screen.init();
	screen.draw_map();
	screen.draw_grid();
	target_view.draw(&target_model);
	object_view.draw(&object_model);
	
//	begin modelling
	while (distance(object_model.get_coords, target_model.get_coords) != object_model.get_radius()) {
		target_model.move(controller.listen());
		target_view.draw(&target_model);
	}
	if (probability() < 0.7) {
		target_model.kill();
		target_view.destroy(&target_model);
	} else {
		while (distance(object_model.get_coords, target_model.get_coords) != target_model.get_radius()) {
			target_model.move(controller.listen());
			target_view.draw(&target_model);
		}
	}
	if (probability() < 0.9) {
		object_model.kill();
		object_view.destroy(&object_model);
	}
// writing results
	
		
}
