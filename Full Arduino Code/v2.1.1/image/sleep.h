const uint32_t sleep_width = 25;
const uint32_t sleep_height = 25;
const uint8_t sleep_data[(26*25)/2] = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x85, 0xFD, 0xFF, 0xFF, 0x0F, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0E, 0x00, 0x10, 0x63, 0xC9, 0x0F, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0x47, 0x02, 0x00, 0x00, 0x04, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0x06, 0x00, 0x03, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x82, 0x0F, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x05, 0x60, 0xFF, 0x0F, 
	0xFF, 0xFF, 0xEF, 0x68, 0x45, 0x23, 0xE2, 0xFF, 0x4F, 0x00, 0xF9, 0xFF, 0x0F, 
	0xFF, 0xFF, 0x9F, 0x00, 0x20, 0x00, 0xF2, 0xFF, 0x04, 0xA0, 0xFF, 0xFF, 0x0F, 
	0xFF, 0xFF, 0xFF, 0xDC, 0xAF, 0x40, 0xFE, 0x4E, 0x00, 0xFA, 0xFF, 0xFF, 0x0F, 
	0xFF, 0xFF, 0xFF, 0xFF, 0x1E, 0xF2, 0xEF, 0x03, 0xB1, 0xFF, 0xFF, 0xFF, 0x0F, 
	0xFF, 0xFF, 0xFF, 0xFF, 0x05, 0xFC, 0x5F, 0x00, 0xE8, 0xFF, 0xFF, 0xFF, 0x0F, 
	0xFF, 0xFF, 0xFF, 0xCF, 0x50, 0xFF, 0x3F, 0x00, 0x00, 0x31, 0x96, 0xFD, 0x0F, 
	0xFF, 0xBF, 0xF7, 0x3F, 0xE0, 0xFF, 0xDF, 0x8A, 0x24, 0x00, 0x00, 0xB0, 0x0F, 
	0xAF, 0x04, 0xF2, 0x09, 0xD7, 0x9B, 0xA7, 0xFF, 0xFF, 0xBD, 0x69, 0xD5, 0x0F, 
	0x25, 0x29, 0xF9, 0x02, 0x00, 0x00, 0x50, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 
	0xFD, 0x2E, 0xFE, 0x8A, 0xA9, 0xDB, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 
	0xFF, 0x29, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 
	0xFF, 0x66, 0x7E, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 
	0xFF, 0x24, 0x52, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 
	0xFF, 0x55, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 
	};