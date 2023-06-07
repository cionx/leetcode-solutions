int minFlips(int a, int b, int c)
{
	int counter;

	for (counter = 0; a != 0 || b != 0 || c != 0; a /= 2, b /= 2, c /= 2) {
		const int bit_a = a % 2;
		const int bit_b = b % 2;
		const int bit_c = c % 2;
		if (bit_c == 0)
			counter += bit_a + bit_b;
		else
			counter += (bit_a == 0 && bit_b == 0);
	}

	return counter;
}
