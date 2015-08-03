#include <stdio.h>

#define VR   0
#define VGR  1
#define RV   2
#define RVG  3
#define RQ   4

typedef struct {
	bool active;
	int age;
	int sigs;
	char description[10];
} state;

state states[5] = {
	{ true, 0, 0, "VR"}, 
	{ false, 0, 0, "VGR"}, 
	{ false, 0, 0, "RV"}, 
	{ false, 0, 0, "RVG"}, 
	{ false, 0, 0, "RQ"}
};
int sigs;

#define isActive(s)           (states[s].active)
#define isAgeGreaterThan(s, t) (states[s].active && (states[s]).age > (t))
#define deActivate(s) states[s].active = false;
#define activate(s) { states[s].active = true; states[s].age = 0; }

void printState(){
	for (int i = 0; i<5; ++i) {
		if(states[i].active) {
			printf("%s \n", states[i].description);
		}
	}
}

void loop() {
	
	for (int i = 0; i<5; ++i) {
		if(states[i].active) {
			sigs = states[i].sigs;
			states[i].age += 1;
		}
	}

	if(isAgeGreaterThan(VR, 100)) {
		deActivate(VR); activate(VGR);
	}

	if(isActive(RQ) && isAgeGreaterThan(VR, 30)) {
		deActivate(RQ); deActivate(VR); activate(VGR);
	}

	if(isAgeGreaterThan(VGR, 20)) {
		deActivate(VGR); activate(RV);
	}

	if(isAgeGreaterThan(RV, 30)) {
		deActivate(RV); activate(RVG);
	}
	
	if(isAgeGreaterThan(RVG, 20)) {
		deActivate(RVG); activate(VR);
		deActivate(RQ);
	}
}

int main(int argc, char *argv[])
{
    for(;;) {
		loop();
		printState();
	}
    return 0;
}
