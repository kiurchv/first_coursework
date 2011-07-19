class Bitmap {
	private:
		//bmp format structure
		struct bitmap_header {
			char Type[2]; 									//File type. Set to "BM".
			unsigned long size; 						//Size in BYTES of the file.
			unsigned long reserved; 				//Reserved. Set to zero.
			unsigned long offset; 					//Offset to the data.
			unsigned long headsize; 				//Size of rest of header. Set to 40.
			unsigned long width; 						//Width of bitmap in pixels.
			unsigned long height; 					//Height of bitmap in pixels.
			unsigned int  planes; 					//Number of Planes. Set to 1.
			unsigned int  bits_per_pixel; 	//Number of Bits per pixels.
			unsigned long compression; 			//Compression. Usually set to 0.
			unsigned long image_size; 			//Size in bytes of the bitmap.
			unsigned long x_ppm; 						//Horizontal pixels per meter.
			unsigned long y_ppm; 						//Vertical pixels per meter.
			unsigned long colors_used; 			//Number of colors used.
			unsigned long colors_important;	//Number of "important" colors.
		};
		bitmap_header info;
		unsigned char* data;
		int b,a;
		unsigned char color;
		int in;
		FILE * fp;
	public:
		Bitmap (char*);
		~Bitmap ();
		void put (int, int, int, int);
		int get_width ();
		int get_height ();
		int get_size ();
};

Bitmap::Bitmap (char* file_name) {
	//	opening file
	fp = fopen(file_name,"rb");
	//	reading header
	fread(&info, sizeof(bitmap_header), 1, fp);
}

Bitmap::~Bitmap () {
	free (data);
	fclose(fp);
}

void Bitmap::put (int x, int y, int mask, int mask_color) {
	//	reading data
	fseek(fp, info.offset, SEEK_SET);
	data=(unsigned char*) calloc(info.width/2+1, sizeof(unsigned char));
	for(b=info.height; b >= 0; b--) {
		fread(data, sizeof(unsigned char), info.width/2, fp);
		color = 0;
		in = 0;
		if (mask) {
			for(a = 0; a < info.width; a += 2) {
				color = (data[in] | 0x00) >>4;
				if (color != mask_color) {
						putpixel(a+x, b+y, color);
				}
				color = (data[in] | 0xF0) & 0x0F;
				if (color != mask_color) {
						putpixel(a+1+x, b+y, color);
				}
				in++;
			}
		} else {
			for(a = 0; a < info.width; a += 2) {
				color = (data[in] | 0x00) >>4;
				putpixel(a+x, b+y, color);
				color = (data[in] | 0xF0) & 0x0F;
				putpixel(a+1+x, b+y, color);
				in++;
			}
		}
	}
}

int Bitmap::get_width () {
	return info.width;
}

int Bitmap::get_height () {
	return info.height;
}


int Bitmap::get_size () {
	return info.image_size;
}

