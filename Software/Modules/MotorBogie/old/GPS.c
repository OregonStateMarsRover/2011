#include "GPS.h"

void GPSinput(char c){
	static char str[70];
	static char *data[20]; //array of pointers to beginning of strings - parsed data
	static int t = 0;//position in data
	static int j = 0;//position in str
	
	//setting pointer to first string
	static int first = 1;
	if(first == 1){
		data[t++] = &str[0];
		first = 0;
	}
	if(c==','||c=='.'||c=='*'){ // if comma make it the end of string
		str[j] = '\0';
		data[t++] = &str[++j]; // set pointer to the next char
	}else if(c!='\n'){ // skip periods to make all numbers integers
		str[j++] = c;
	}
	if(c=='\n'){ // loops to the end of stream
		str[j] = '\0';
		t = 1;
		j = 0;
		GPSparser(data);
	}
}

void GPSparser(char *data[20]){
	if(strcmp(data[0],"$GPRMC")==0){
		rmc_string g = {
			data[2][0],
			atoi(data[3]),
			atoi(data[4]),
			atoi(data[6]),
			atoi(data[7]),
			atoi(data[9])*10+atoi(data[10])
		};
		rmc = g;
		
		
		nmea.status = g.status;
		nmea.lat_degrees = g.lat_degrees;
		nmea.lat_mins =g.lat_mins;
		nmea.long_degrees = g.long_degrees;
		nmea.long_mins = g.long_mins ;
		
	}else if(strcmp(data[0],"$GPVTG")==0){
		vtg_string g = {
			atoi(data[1])*10+atoi(data[2]),
			atoi(data[4])*10+atoi(data[5]),
			atoi(data[7])*10+atoi(data[8]),
			atoi(data[10])*10+atoi(data[11])
		};
		vtg = g;
		
		nmea.speed_kmph = g.speed_kmph;
		nmea.true_track = g.true_track;
		
	}else if(strcmp(data[0],"$GPGSV")==0){
		gsv_string g;
		g.sat_view = atoi(data[3]);
		short n = 0;
		if(atoi(data[2]) == 1){
			if(atoi(data[3]) >= 4){
				n = 4;
			}else{
				n = atoi(data[3]);
			}
		}else{
			n = atoi(data[3])-4;
		}
		short i;
		for(i=0;i<n;i++){
			short sat_num = 4*(atoi(data[2]))+i-3;
			/*if (sat_num>7)
				sat_num=7;*/
			short j = (i+1)*4;
			g.satellites[sat_num].prn = atoi(data[j+0]);
			g.satellites[sat_num].elev = atoi(data[j+1]);
			g.satellites[sat_num].azi = atoi(data[j+2]);
			g.satellites[sat_num].snr = atoi(data[j+3]);
		}
		gsv = g;
		
		nmea.sat_view = g.sat_view;
		
	}
}
rmc_string returnRmc(){
	return rmc;
}

vtg_string returnVtg(){
	return vtg;
}

gsv_string returnGsv(){
	return gsv;
}

nmea_string returnNmea(){
	return nmea;
}
