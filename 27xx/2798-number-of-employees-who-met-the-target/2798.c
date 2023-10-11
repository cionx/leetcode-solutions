/* 2798. Number of Employees Who Met the Target */

/* Complexities.
 * Time: Θ(n)
 * Space: Θ(1)
 * where n is the length of the input array. */

int numberOfEmployeesWhoMetTarget(int *hours, int hoursSize, int target)
{
	int counter = 0;
	for (int i = 0; i < hoursSize; ++i)
		if (hours[i] >= target)
			++counter;
	return counter;
}
