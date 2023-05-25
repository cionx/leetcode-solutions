double average(int *salary, int salarySize)
{
	int max, min, sum;
	max = min = sum = salary[0];

	int number;
	for (number = 1; number < salarySize; ++number) {
		const int s = salary[number];
		if (s > max)
			max = s;
		else if (s < min)
			min = s;
		sum += s; /* We won’t get an overflow. */
	}

	sum -= max + min;
	number -= 2;

	return ((double) sum) / number;
}
