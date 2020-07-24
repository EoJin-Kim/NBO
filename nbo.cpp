#include <stdio.h>
#include <netinet/in.h>


uint32_t file_hex(char* file_name)
{
    FILE *fp;
    char buffer1[200];
 	//char buffer2[200];
    fp = fopen(file_name, "rb");
    fread(buffer1,4,sizeof(buffer1),fp);

    uint8_t file1_buffer[] = { buffer1[0], buffer1[1], buffer1[2], buffer1[3] };
    uint32_t* p = reinterpret_cast<uint32_t*>(file1_buffer);
    uint32_t result1 = ntohl(*p);
    fclose(fp);
    return result1;
}

void nbo(char* file_name1, char* file_name2)
{
    FILE *fp2;
	char buffer1[200];
 	char buffer2[200];

	int count;
	int size;

    uint32_t result1 = file_hex(file_name1);
    uint32_t result2 = file_hex(file_name2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",result1,result1,result2, result2,result1+result2,result1+result2);

    return;
}

