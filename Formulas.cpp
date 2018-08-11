/*
Luis Enrique Bernal Fuentes
Formulas
*/

Pi = 4 * (2/3 * 4/3 * 4/5 * 6/5 * ...) = 3,14159265358979
Pi = 2 * acos (0);

				sqrt (5) + 1
Golden Number = ------------ = 1,61803398874989
					 2

Fibonaci Number
F(n) = ((1 + sqrt (5)) / 2) ^ n - ((1 - sqrt (5)) / 2) ^ n
       ----------------------------------------------------
                            sqrt (5);

Sumatoria De n
	    n * (n + 1)
S(n) =  -----------
		     2

Catalan Numbers
                                     (2n)!
C(n) = C(n, 2n) - C(n - 1, 2n) = -------------
                                 n! * (n + 1)!
Multilication Principles
			   n!
V(n, p) =  ---------
			(n - p)!
V'(n, p) = n^p;

P(n) = n!
			                     n!
P'n (n1, n2, ..., nk) = -----------------------
		                n1! * n2! * ... * n(k)!

Combinations
			                                    n!
C(n, p) = C(n - 1, p - 1) + C (n - 1, p) = -------------
		                                   (n - p)! * p!

			    a * b
MCM(a, b) = ------------
			  MCD (a, b)

Carmichael Numbers  >= 3 Prime Factors
561,1105,1729,2465,2821,6601,8911,10585,15841,29341,41041,46657,52633,62745,63973

Sum of n^2
1^2 + 2^2 + ... + n^2 = n * (n + 1) * (2n + 1) / 6;

Sum of x^n
x^0 + x^1 + ... + x^n = (x^(n + 1) - 1) / (x - 1);

Sum the divisors of a number
N = p1 ^ a1 + p2 ^ a2 + ... + pk ^ ak

sea p1 < p2 < ... < pk prime numbers.

          p1^(a1 + 1) - 1          pk^(ak + 1) - 1
S (N) =  --------------- * ... *  ---------------
               p1 - 1                  pk - 1
