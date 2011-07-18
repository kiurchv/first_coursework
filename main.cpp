//	Models
#include "models\target_model.cpp"
#include "models\object_model.cpp"
//	Views
#include "views\screen_view.cpp"
#include "views\target_view.cpp"
#include "views\object_view.cpp"
// Controllers
#include "controller.cpp"
//Helpers
#include "helpers\helpers.cpp"

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
		target_model.move(controller.listen(), &object_model);
		target_view.draw(&target_model);
	}
	if (probability() < 0.7) {
		target_model.kill();
		target_view.destroy(&target_model);
	} else {
		while (distance(object_model.get_coords, target_model.get_coords) != target_model.get_radius()) {
			target_model.move(controller.listen(), &object_model);
			target_view.draw(&target_model);
		}
	}
	if (probability() < 0.9) {
		object_model.kill();
		object_view.destroy(&object_model);
	}
// writing results
	
		
}
