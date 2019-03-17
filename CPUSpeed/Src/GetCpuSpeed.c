#include <windows.h>
#include <stdio.h>

inline unsigned __int64 GetCycleCount(void) {
	__asm {
		//rdtc is a 64 bit register on all intel processor
		//that counts the number of cycles since reset and places this value in edx:eax
		rdtsc
	}
}

unsigned __int64 GetCPUSpeed(void) {
	unsigned __int64 speed, startcycle, numA, numB;
	startcycle = GetCycleCount();
	Sleep(1000); //sleep for one second to get number of cycles passed within the one second range
	do {
		speed = (GetCycleCount() - startcycle) / 1000000; // divide the difference by 1000000 to get the frequency
	} while (speed > 1000000);
	
	/*
	numA = speed % 100;
	numB = 100;
	if (numA < 80) numB = 75;
	if (numA < 71) numB = 66;
	if (numA < 55) numB = 50;
	if (numA < 38) numB = 33;
	if (numA < 30) numB = 25;
	if (numA < 10) numB = 0;
	speed = (speed - numA) + numB;
	*/

	return (speed);
}

int main(int argc, char* argv[]) {
	printf_s("CPU Speed for this machine -> %ld\n", GetCPUSpeed());
	getchar();
	return 0;
}