class FileView {
	private:
		FILE *f;
	public:
		FileView ();
		~FileView ();
		write (ObjectModel *, TargetModel *);
};

FileView::FileView () {
	f=fopen("blackbox.log", "w+");
}

FileView::~FileView () {
	fclose(f);
}

FileView::write (ObjectModel *object_data, TargetModel *target_data) {
	int x = int(target_data->coords.x);
	int y = int(target_data->coords.y);
	int q = int(target_data->Q);
	int d = int(distance(object_data->coords, target_data->coords));
	char state[10];
	if (target_data->live) {
		strcpy(state, "LIVE");
	} else {
		strcpy(state, "DESTROY");
	}
	fprintf(f, "X=%d; Y=%d; Q=%d; D=%d; Target state: %s;\n", x, y, q, d, state);
}

