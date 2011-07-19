//	Standard libraries
#include <alloc.h>
#include <bios.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <iostream.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//	Helpers
#include "const.h"
#include "hlprs.h"
#include "bmp.h"

//	Models
#include "basem.h"
#include "objm.h"
#include "targm.h"

//	Views
#include "scrv.h"
#include "targv.h"
#include "objv.h"

// Controllers
#include "contr.h"

void main () {
//	creating objects
	TargetModel target_model;
	ObjectModel object_model;
	Controller controller;
	ScreenView screen;
	TargetView target_view;
	ObjectView object_view;
//	entering data
	controller.get_data(&object_model, &target_model);
//	rendering screen
	screen.init();
	screen.draw_map();
	screen.draw_grid();
	target_view.draw(&target_model);
	object_view.draw(&object_model);
//	begin modelling
	while (distance(object_model.coords, target_model.coords) != object_model.r) {
		target_model.move(controller.listen(), &object_model);
		target_view.draw(&target_model);
	}
	if (probability() < 0.7) {
		target_model.kill();
		target_view.destroy();
	} else {
		while (distance(object_model.coords, target_model.coords) != target_model.r) {
			target_model.move(controller.listen(), &object_model);
			target_view.draw(&target_model);
		}
	}
	if (probability() < 0.9) {
		object_model.kill();
		object_view.destroy();
	}
// writing results
	getch();
}

