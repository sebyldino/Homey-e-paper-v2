const uint32_t openEnvelope80_width = 80;
const uint32_t openEnvelope80_height = 80;
const uint8_t openEnvelope80_data[(80*80)/2] = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAE, 0xFA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0x01, 0x10, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x08, 0x00, 0x00, 0x90, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x5F, 0x00, 0x00, 0x00, 0x00, 0xF5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x04, 0x00, 0x00, 0x00, 0x00, 0x30, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1B, 0x00, 0x00, 0xD2, 0x1C, 0x00, 0x00, 0xA1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x00, 0x00, 0x50, 0xFF, 0xEF, 0x03, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x03, 0x00, 0x00, 0x40, 0x45, 0x54, 0x03, 0x00, 0x00, 0x30, 0x44, 0x44, 0x44, 0x44, 0x44, 0x74, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x00, 0x20, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x01, 0x00, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x02, 0x20, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x6F, 0x00, 0xB0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x50, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0x00, 0xA0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x00, 0xA0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xBA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x00, 0xA0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFA, 0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x00, 0xA0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x43, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x54, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x00, 0xA0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x00, 0xA0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x02, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x00, 0xB0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x02, 0x40, 0xFF, 0xFF, 0xFF, 0x9E, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xFB, 0xFF, 0xFF, 0xAF, 0x00, 0x40, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x00, 0x40, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF1, 0xFF, 0xFF, 0xAF, 0x00, 0x00, 0xB1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x00, 0x40, 0xFF, 0xFF, 0xFF, 0x9D, 0x98, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x89, 0xFB, 0xFF, 0xFF, 0xAF, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3D, 0x00, 0x00, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x00, 0x00, 0x00, 0x50, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x01, 0x00, 0x00, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x00, 0x00, 0x00, 0x00, 0xB2, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x01, 0x40, 0xFF, 0xFF, 0xFF, 0x4A, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0xF6, 0xFF, 0xFF, 0xAF, 0x00, 0x40, 0x00, 0x00, 0x00, 0xFB, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0x5F, 0x00, 0x00, 0xC4, 0x03, 0x40, 0xFF, 0xFF, 0xFF, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xAF, 0x00, 0xC0, 0x2C, 0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0x08, 0x00, 0x00, 0xFE, 0x01, 0x40, 0xFF, 0xFF, 0xFF, 0xBE, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xAB, 0xFD, 0xFF, 0xFF, 0xAF, 0x00, 0xA0, 0xBF, 0x00, 0x00, 0x70, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xEF, 0x00, 0x00, 0x00, 0xB3, 0x03, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xAF, 0x00, 0xC0, 0x2C, 0x00, 0x00, 0x30, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x9F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xAF, 0x00, 0x40, 0x00, 0x00, 0x00, 0x10, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x6F, 0x00, 0x20, 0x00, 0x00, 0x00, 0x40, 0xFF, 0xFF, 0xFF, 0x18, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 0xE3, 0xFF, 0xFF, 0xAF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0x0A, 0x00, 0x00, 0x50, 0xFF, 0xFF, 0xFF, 0x07, 0x11, 0x11, 0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x01, 0x11, 0x11, 0x01, 0xE2, 0xFF, 0xFF, 0xBF, 0x00, 0x00, 0x00, 0xA0, 0x06, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xCF, 0x01, 0x00, 0x00, 0xFA, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xFF, 0xFF, 0xFF, 0x8F, 0x00, 0x00, 0x10, 0xFA, 0x08, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0x3D, 0x00, 0x00, 0x70, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x00, 0x00, 0xE5, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0xE5, 0xFF, 0xFF, 0xFF, 0xFF, 0xDC, 0xCC, 0xDD, 0xDD, 0xED, 0xEE, 0xCD, 0xDD, 0xCC, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0x4E, 0x00, 0x00, 0x70, 0xFF, 0xFF, 0x06, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xC0, 0xFF, 0xFF, 0x9F, 0x00, 0x00, 0x20, 0xFC, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xFE, 0xFF, 0xFF, 0xDF, 0x02, 0x00, 0x00, 0xF9, 0xFF, 0xFF, 0x05, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0x2C, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0x7F, 0x21, 0x33, 0x22, 0x33, 0x22, 0x23, 0x33, 0x22, 0x33, 0x43, 0xFE, 0xFF, 0xFF, 0x0A, 0x00, 0x00, 0xD3, 0xFF, 0xFF, 0xFF, 0x04, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0xEF, 0x05, 0x00, 0x00, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x50, 0xFE, 0xFF, 0xFF, 0xFF, 0x04, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x50, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0x03, 0x00, 0x00, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x2C, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1B, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x05, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x03, 0x00, 0x00, 0xF7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x00, 0x00, 0x40, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x60, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x05, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1A, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x2B, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDF, 0x03, 0x00, 0x10, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x00, 0x00, 0x40, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x6F, 0x00, 0x00, 0x70, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x06, 0x00, 0x00, 0xF7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x09, 0x00, 0x00, 0xE4, 0xFF, 0xFF, 0xFF, 0xFF, 0x3D, 0x00, 0x00, 0xB1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x02, 0x00, 0x20, 0xFC, 0xFF, 0xFF, 0xBF, 0x01, 0x00, 0x30, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x5F, 0x00, 0x00, 0x90, 0xFF, 0xFF, 0x08, 0x00, 0x00, 0xF6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x05, 0x00, 0x00, 0xF6, 0x4F, 0x00, 0x00, 0x90, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x9F, 0x01, 0x00, 0x00, 0x40, 0x03, 0x00, 0x00, 0x40, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x05, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x2B, 0x00, 0x00, 0xFA, 0x07, 0x00, 0x00, 0x90, 0x4D, 0x00, 0x00, 0xE5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x00, 0x00, 0xC2, 0xFF, 0xAF, 0x00, 0x20, 0xFB, 0xFF, 0x07, 0x00, 0x20, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x05, 0x00, 0x60, 0xFF, 0xFF, 0xFF, 0x1D, 0xF3, 0xFF, 0xFF, 0xBF, 0x01, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x2B, 0x00, 0x00, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4E, 0x00, 0x00, 0xE5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x8F, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x08, 0x00, 0x20, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0x04, 0x00, 0x60, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0x01, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1B, 0x00, 0x00, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4E, 0x00, 0x00, 0xF5, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x08, 0x00, 0x20, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0xEF, 0x04, 0x00, 0x60, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0x01, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0xFF, 0x1A, 0x00, 0x00, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4E, 0x00, 0x00, 0xE5, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x20, 0xFC, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0xEF, 0x03, 0x00, 0x60, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0x01, 0x00, 0x80, 0xFF, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xD0, 0xFF, 0x1A, 0x00, 0x00, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4E, 0x00, 0x00, 0xE5, 0xFF, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0xE0, 0x6F, 0x00, 0x00, 0xC2, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x08, 0x00, 0x20, 0xFC, 0x07, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x5F, 0x00, 0x90, 0x05, 0x00, 0x60, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xBF, 0x01, 0x00, 0x90, 0x04, 0x00, 0xFE, 0xFF, 0xFF, 
	0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x4E, 0x00, 0x00, 0x00, 0x10, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xBF, 0x00, 0x00, 0x00, 0xE4, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x19, 0x00, 0x00, 0x40, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0x02, 0x00, 0x00, 0xA7, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x98, 0x3A, 0x00, 0x00, 0xB0, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF5, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xAF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0x5D, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xCE, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xBB, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
	};
