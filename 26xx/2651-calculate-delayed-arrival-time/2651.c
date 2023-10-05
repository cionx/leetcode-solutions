/* 2651. Calculate Delayed Arrival Time */

/* Complexities.
 * Time: Θ(1)
 * Space: Θ(1) */

int findDelayedArrivalTime(int arrivalTime, int delayedTime){
	return (arrivalTime + delayedTime) % 24;
}
