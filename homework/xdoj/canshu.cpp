#include<stdio.h>
int main(int argc, char *argv[]){
	char *s1,*s2;
	if(argc!=3){
		printf("need two string.\n");
		return 1;
	}

	s1=argv[1];
	s2=argv[2];
	while(*s1==*s2&&*s1&&*s2){
		s1++;s2++;
	}

	*s1=0;
	if(s1-argv[1]){
		printf("prefix is : %s\n",argv[1]);
	}
	else
		printf("no same prefix.\n");
	return 0;
}
