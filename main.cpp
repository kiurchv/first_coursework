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
#include <string.h>

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
#include "filev.h"

// Controllers
#include "contr.h"

void main () {
	//	creating objects
	TargetModel target_model;
	ObjectModel object_model;
	Controller controller;
	ScreenView screen_view;
	TargetView target_view;
	ObjectView object_view;
	FileView file_view;
	//	entering data
	controller.get_data(&object_model, &target_model);
	//	rendering screen, target, object and info
	screen_view.init();
	screen_view.draw_map();
	screen_view.draw_grid();
	target_view.draw(&target_model, object_model.coords);
	object_view.draw(&object_model);
	screen_view.draw_info(&object_model,&target_model);
	//adding data to list
	file_view.write(&object_model,&target_model);
	//	begin modelling
	while (distance(object_model.coords, target_model.coords) > object_model.r) {
		target_model.move(controller.listen(), &object_model);
		target_view.draw(&target_model, object_model.coords);
		screen_view.draw_info(&object_model,&target_model);
		file_view.write(&object_model,&target_model);
	}
	if (prob() < 0.7) {
		target_model.kill();
		target_view.destroy();
		screen_view.draw_info (&object_model,&target_model);
		file_view.write(&object_model,&target_model);
	} else {
		while (distance(object_model.coords, target_model.coords) > target_model.r) {
			target_model.move(controller.listen(), &object_model);
			target_view.draw(&target_model, object_model.coords);
			screen_view.draw_info (&object_model,&target_model);
			file_view.write(&object_model,&target_model);
		}
		if (prob() < 0.5) {
			object_model.kill();
			object_view.destroy();
			screen_view.draw_info (&object_model,&target_model);
			file_view.write(&object_model,&target_model);
		}
	}
	getch();
}

