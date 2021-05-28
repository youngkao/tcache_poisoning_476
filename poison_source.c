#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SZ_BLOCK 200
#define SZ_HEAP  10
#define SZ_FLAG 100

char a[100];
u_int *(buf);

void win(){
	char buf[SZ_FLAG];
	FILE *f = fopen("flag.txt","r");
	if (f == NULL){
		puts("[!] error code 901");
		exit(0);
	}
	fgets(buf,SZ_FLAG,f);
	puts(buf);
}

void menu(){
	puts("| 1. malloc |");
	puts("| 2. free   |");
	puts("| 3. exit   |");
}

void init(){
	setvbuf(stdout, 0 , 2 , 0);
	setvbuf(stdin, 0 , 2 , 0);
}

void create_memory(){
	int size;
	printf("[?] size : ");
	scanf("%d" , &size);
	printf("[?] data : ");
	if (size <= 0x88){
		buf = malloc(size);
		read(0,buf , size);
	}
	puts("[+] memory allocated!");
}

void release_memory(){
	free(buf);
}

void main(){
	init();
	char buf[4];
	printf("Do you like sci-fi references?");
	while(1){
		menu();
		read(0 , buf , sizeof(buf));
		switch(atoi(buf)){
			case 1:
				create_memory();
				break;
			case 2:
				release_memory();
				break;
			case 3:
				puts("[+] exiting...");
				exit(0);
				break;
			default:
				puts("[!] invalid choice error code 1902");
				break;
		}
	}
}