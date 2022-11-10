#include "file.h"

#define X 10

int main() {
	#ifdef X
	int x = 10 ;
	#endif
	#undef X
	#ifndef X
	#define X 12
	int y = X ;
	#endif
}

