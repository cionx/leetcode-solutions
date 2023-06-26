/* 372. Super Pow */

/* Complexities.
 * Time: O(d)
 * Space: O(1)
 * where d is the number of digits of the exponent, and if the modulo number is
 * fixed as 1337. */

/* The prime factorization of 1337 is 7 ⋅ 191. By the Chinese remainder theorem,
 * we have therefore ℤ/1337 ≅ ℤ/7 × ℤ/191. The inverse isomorphism is given by
 *   (a, b)  ->  a ⋅ 764 + b ⋅ 574
 * (The numbers 764 and 574 can be computed using Euclids algorithm, but I used
 * WolframAlpha.) We will first compute the asked-for power modulo 7 and modulo
 * 191, and then use the above isomorphism to get the result in ℤ/1337. The
 * rings ℤ/7 and ℤ/191 have the advantage that we cane use Fermat’s little
 * theorem.
 *
 * Fermat’s little theorem allows in ℤ/p the simplification
 *     a^(b + k ⋅ p)
 *   = a^b ⋅ (a^p)^k
 *   ≡ a^b              (*)
 *   = a^k
 *   = a^(b + k).
 * Moreover, if a^b ≡ a^b', then we also have
 *     a^(10 ⋅ b + c)
 *   = (a^b)^10 ⋅ a^c
 *   ≡ (a^b')^10 ⋅ a^c
 *   = a^(10 ⋅ b' + c);
 * We can therefore employ the simplification (*) as we keep adding digits to
 * the exponent.
 */

#define MODULO  1337
#define PRIME1  7
#define FACTOR1 764
#define PRIME2  191
#define FACTOR2 574

int superPow(int a, int *b, int bSize);
int superPowModPrime(int a, int *b, int bSize, int prime);
int powMod(int a, int n, int modulo);

int superPow(int a, int *b, int bSize)
{
	int powModPrime1 = superPowModPrime(a, b, bSize, PRIME1);
	int powModPrime2 = superPowModPrime(a, b, bSize, PRIME2);

	return (FACTOR1 * powModPrime1 + FACTOR2 * powModPrime2) % MODULO;
}

int superPowModPrime(int a, int *b, int bSize, int prime)
{
	int exponent = 0;
	for (int i = 0; i < bSize; ++i) {
		exponent *= 10;
		exponent += b[i];
		while (exponent > prime)
			exponent = (exponent % prime) + (exponent / prime);
	}

	return powMod(a, exponent, prime);
}

/* requires n >= 0 */
int powMod(int base, int n, int modulo)
{
	base %= modulo;
	/* accumulator * base^n is a loop invariant */
	int accumulator = 1;
	while (n > 0) {
		if (n % 2 == 0) {
			base = (base * base) % modulo;
			n /= 2;
		}
		else {
			accumulator = (accumulator * base) % modulo;
			--n;
		}
	}
	return accumulator;
}
