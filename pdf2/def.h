#ifdef PDF_H
#else
#define PDF_H
struct pdf
	{
		char name[100];
		int pageall,read;
		char line[100][100];
		int lin;
	};
#endif

