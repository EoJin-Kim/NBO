#include <stdio.h>
#include <netinet/in.h>
#include "nbo.h"
int main(int argc, char *argv[])
{


	if (argc==3){
		nbo(argv[1],argv[2]);
    }
    else
    {
        printf("false input");
    }
	return 0;
	


}
