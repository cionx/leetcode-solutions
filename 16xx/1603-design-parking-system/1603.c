#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int spacesLeft[3];
} ParkingSystem;

ParkingSystem *parkingSystemCreate(int big, int medium, int small);
bool parkingSystemAddCar(ParkingSystem *lot, int carType);
void parkingSystemFree(ParkingSystem *lot);

ParkingSystem *parkingSystemCreate(int big, int medium, int small)
{
	ParkingSystem *lot = malloc(sizeof(ParkingSystem));
	lot->spacesLeft[0] = big;
	lot->spacesLeft[1] = medium;
	lot->spacesLeft[2] = small;
	return lot;
}

bool parkingSystemAddCar(ParkingSystem *lot, int carType)
{
	if (lot->spacesLeft[carType - 1] == 0)
		return false;

	lot->spacesLeft[carType - 1]--;
	return true;
}

void parkingSystemFree(ParkingSystem *lot)
{
	free(lot);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);

 * parkingSystemFree(obj);
*/
