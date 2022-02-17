#define NUM1 5
#define NUM2 8

#define SUM(x, y) x+y

#define ADD

int main(int argc, char *argv[])
{
	int i, k;

	int sum;
	sum = i + k;
	
	i = NUM1;
	k = NUM2;

	sum = SUM(i, k);

#ifdef ADD
	sum = i + k;
#else
	sum = i + k + 10;
#endif

	return 0;
}
