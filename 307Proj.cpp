/*
 *  tt.cpp
 *  Created by Chelsea Douglas
 */
// g++ -I/Users/yeahbutiwish/Desktop/project/stk/include/ -L/Users/yeahbutiwish/Desktop/project/stk/src/ -D__MACOSX_CORE__ ttttt.cpp -lstk -lpthread -framework CoreAudio -framework CoreMIDI -framework CoreFoundation

/*#include "Bowed.h"
#include "Clarinet.h"
#include "Guitar.h"
#include "Moog.h"
#include "PercFlut.h"
#include "Rhodey.h"
#include "TubeBell.h"
//#include "Sitar.h"*/

#include "Guitar.h"
#include "RtWvOut.h"
#include "Messager.h"
#include "Skini.h"
#include "SKINI.msg"
#include <cstdlib>
#include <iostream>

using namespace stk;

int main()
{
	//global sample rate 
	Stk::setSampleRate( 44100.0 );
	Stk::showWarnings( true );
	Messager messager;
	Skini::Message message;
	//instruments
    Guitar guitar1;
    Guitar guitar2;
    Guitar guitar3;
    Guitar guitar4;
    Guitar guitar5;
    Guitar guitar6;
    Guitar guitar7;
    Guitar guitar8;
	
	bool done = false;
	messager.startStdInput();
	int messageCounter = 0;

    //Sound
	/*RtWvOut *dac = 0;
	
	try {
		// Define/open the default realtime output device
		dac = new RtWvOut( 2 );
	}
	catch ( StkError & ) {
		exit( 1 );
	}*/
	
    //treat this value as a 8thth note
    float frameDur1 = 11025;

    //define pitches
    float c2 = 65.4;
    float d2 = 73.4;
    float e2 = 82.4;
    float g2 = 98.0;
    float a2 = 110.0;
    float b2 = 123.5;
    
	float c3 = c2*2;
    float d3 = d2*2;
    float e3 = e2*2;
    float g3 = g2*2;
    float a3 = a2*2;
    float b3 = b2*2;
    
    float c4 = c3*2;
    float d4 = d3*2;
    float e4 = e3*2;
    float g4 = g3*2;
    float a4 = a3*2;
    float b4 = b3*2;
    
    float c5 = c4*2;
    float d5 = d4*2;
    float e5 = e4*2;
    float g5 = g4*2;
    float a5 = a4*2;
    float b5 = b4*2;
    
    //melodies
	float melody1[] = {g2, g2, g2, g2, a2, a2, e2, b2, b2, b2, d2, d2, e2, e2, e2, e2};
	float melody2[] = {b4, b4, g4, g4, b4, b4, b4, g4, b4, c5, d5, e5, g5, e5, g5, g4};
	float melody3[] = {g4, g4, b4, b4, d5, d5, g5, g5, d5, d5, g4, g4, b4, b4, d5, d5};
	float melody4[] = {d3, d3, b2, g2, a2, b2, d3, d3, d3, d3, d2, d2, d2, d2, d3, d3};
	float melody5[] = {g2, g2, a2, g2, g3, g3, e3, g3, g4, g4, a4, g4, g3, g3, e3, g3};
	float melody6[] = {g3, g3, g4, g4, g3, g3, g4, g3, g4, g4, g3, g3, g4, g3, g4, g4};
	float melody7[] = {d5, d5, g5, g5, g5, e5, d5, c5, a4, b4, d5, g5, d5, e5, g5, g5};
    float melody8[] = {c3, g3, g3, e3, g3, e3, d3, c3, e3, g3, b3, d4, e4, b3, g3, g3, c3};
	
	//amplitude and string
	float amps1[] = {.5, .5, .5, .5, .5, .5, .5, .5, .5, .5, .5, .5, .5, .5, .5, .5};
	float amps2[] = {1.2, 1.3, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.3, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2};
    float amps3[] = {.3, .3, .2, .2, .2, .2, .2, .2, .3, .3, .1, .1, .2, .2, .2, .2};
	float amps4[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	float amps11 = 1.3;
	int stringx[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	
	//loop for eacg guitar
	int loop1 = 0;
	int loop2 = 0;
	int loop3 = 0;
	int loop4 = 0;
	int loop5 = 0;
	int loop6 = 0;
	int loop7 = 0;
	int loop8 = 0;
    
	//Sound
	RtWvOut *dac = 0;
	
	try {
		// Define/open the default realtime output device
		dac = new RtWvOut( 2 );
	}
	catch ( StkError & ) {
		exit( 1 );
	}
	
	//start loops
	while ( !done ) {
		/*if ( messageCounter++ > 1 ) {
			messageCounter = 0;*/
			messager.popMessage( message );
			if ( message.type > 0 ) {
				StkFloat value1 = message.floatValues[0];
				StkFloat value2 = message.floatValues[1];
				switch( message.type ) {
						
					case __SK_Exit_:
						done = true;
						break;
						
					case __SK_ControlChange_:
						if (value1==1.0) {
							if (value2==1.0){
								loop1=1;}
							else{loop1=0;}
						}
						if (value1==2.0) {
							if (value2==1.0){
								loop2=2;}
							else{loop2=0;}
						}
						if (value1==3.0) {
							if (value2==1.0){
							loop3=3;}
							else{loop3=0;}
						}
						if (value1==4.0) {
							if (value2==1.0){
							loop4=4;}
							else{loop4=0;}
						}
						if (value1==5.0) {
							if (value2==1.0){
							loop5=5;}
							else{loop5=0;}
						}
						if (value1==6.0) {
							if (value2==1.0){
							loop6=6;}
							else{loop6=0;}
						}
						if (value1==7.0) {
							if (value2==1.0){
							loop7=7;}
							else{loop7=0;}
						}
						if (value1==8.0) {
							if (value2==1.0){
							loop8=8;}
							else{loop8=0;}
						}
						if (value1==9.0) {
						frameDur1=22050;
						}
						if (value1==10.0) {
						frameDur1=11025;
						}
						if (value1==11.0) {
						frameDur1=5512;
						}
						
						break;
				}
			}
		//}
		
		for (int k=0; k < 16; k++){
			guitar1.setBodyFile();
			guitar2.setBodyFile();
			guitar3.setBodyFile();
			guitar4.setBodyFile();
			guitar5.setBodyFile();
			guitar6.setBodyFile();
			guitar7.setBodyFile();
			guitar8.setBodyFile();
			
			for ( int i=0; i< frameDur1; i++ ){
				if(loop1==1){
                    guitar1.noteOn(melody1[k], amps2[k], stringx[k]);
				}
				else {
					guitar1.noteOn(melody1[k], amps4[k], stringx[k]);
				}
				if(loop2==2){
                    guitar2.noteOn(melody2[k], amps2[k], stringx[k]);
				}
				else {
					guitar2.noteOn(melody2[k], amps4[k], stringx[k]);
				}
				if(loop3==3){
                    guitar3.noteOn(melody3[k], amps2[k], stringx[k]);
				}
				else {
					guitar3.noteOn(melody3[k], amps4[k], stringx[k]);
				}
				if(loop4==4){
                    guitar4.noteOn(melody4[k], amps2[k], stringx[k]);
				}
				else {
					guitar4.noteOn(melody4[k], amps4[k], stringx[k]);
				}
				if(loop5==5){
                    guitar5.noteOn(melody5[k], amps2[k], stringx[k]);
				}
				else {
					guitar5.noteOn(melody5[k], amps4[k], stringx[k]);
				}
				if(loop6==6){
                    guitar6.noteOn(melody6[k], amps2[k], stringx[k]);
				}
				else {
					guitar6.noteOn(melody6[k], amps4[k], stringx[k]);
				}
                if(loop7==7){
                    guitar7.noteOn(melody7[k], amps2[k], stringx[k]);
				}
				else {
					guitar7.noteOn(melody7[k], amps4[k], stringx[k]);
				}
				if(loop8==8){
                    guitar8.noteOn(melody8[k], amps2[k], stringx[k]);
				}
				else {
					guitar8.noteOn(melody8[k], amps4[k], stringx[k]);
				}


				try {
					dac->tick( guitar1.tick()*2 + guitar2.tick()*2 + guitar3.tick()*2 + 
                              guitar4.tick()*2 + guitar5.tick()*2 + guitar6.tick()*2 + 
                              guitar7.tick()*2 + guitar8.tick()*2);
					/*dac->tick( guitar1.tick() + guitar2.tick() + guitar3.tick() + 
                              guitar4.tick() + guitar5.tick() + guitar6.tick() + 
                              guitar7.tick()+ guitar8.tick()); */

				}
				catch ( StkError & ) {
					continue;
					//goto cleanup;
				}
			}
		}
	}

cleanup:
	delete dac;
	
	return 0;
}
