#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	char buffer1[200];
 	char buffer2[200];

	int count;
	int size;


	if (argc==3) {
		
		fp1 = fopen(argv[1], "rb");
		fread(buffer1,4,sizeof(buffer1),fp1);

		uint8_t file1_buffer[] = { buffer1[0], buffer1[1], buffer1[2], buffer1[3] };
		uint32_t* p = reinterpret_cast<uint32_t*>(file1_buffer);
		uint32_t result1 = ntohl(*p);


		fclose(fp1);

                fp2 = fopen(argv[2], "rb");
                fread(buffer2,4,sizeof(buffer2),fp2);

                uint8_t file2_buffer[] = { buffer2[0], buffer2[1], buffer2[2], buffer2[3] };
                uint32_t* q = reinterpret_cast<uint32_t*>(file2_buffer);
                uint32_t result2 = ntohl(*q);

                printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",result1,result1,result2, result2,result1+result2,result1+result2);

                fclose(fp2);
		




		return 0;
	}


}


