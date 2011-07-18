#include <graphics.h>
#include "base.cpp"
class TargetModel :public BaseModel {
		private:
		float v;
		float q;
	public:
		ObjectModel() :BaseModel();
		point getSpeed ();
		void setSpeed (float);
};

point ObjectModel::getSpeed () {
	return V;
}
