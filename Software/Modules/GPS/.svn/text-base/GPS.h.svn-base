#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
   char status __attribute__((__packed__));
   unsigned short  lat_degrees __attribute__((__packed__));
   unsigned short  lat_mins __attribute__((__packed__));
   unsigned short  long_degrees __attribute__((__packed__));
   unsigned short  long_mins __attribute__((__packed__));
   unsigned short  speed_knots __attribute__((__packed__));
}rmc_string;

typedef struct {
	unsigned short true_track __attribute__((__packed__));
	unsigned short magnetic_track __attribute__((__packed__));
	unsigned short speed_knots __attribute__((__packed__));
	unsigned short speed_kmph __attribute__((__packed__));
}vtg_string;

typedef struct {
	unsigned short  prn __attribute__((__packed__));
   unsigned short  elev __attribute__((__packed__));
   unsigned short  azi __attribute__((__packed__));
	unsigned short  snr __attribute__((__packed__));
}sat;

typedef struct {
	unsigned short  sat_view __attribute__((__packed__));
	sat satellites[19] __attribute__((__packed__));
}gsv_string;

typedef struct {
   char status __attribute__((__packed__));
	unsigned short  lat_degrees __attribute__((__packed__));
   unsigned short  lat_mins __attribute__((__packed__));
   unsigned short  long_degrees __attribute__((__packed__));
   unsigned short  long_mins __attribute__((__packed__));
	unsigned short  speed_kmph __attribute__((__packed__));
	unsigned short  true_track __attribute__((__packed__));
	unsigned short  sat_view __attribute__((__packed__));
}nmea_string;

rmc_string rmc;

vtg_string vtg;

gsv_string gsv;

nmea_string nmea;

void parser(char *data[15]);
void GPSinput(char c);
rmc_string returnRmc();
vtg_string returnVtg();
gsv_string returnGsv();
nmea_string returnNmea();
