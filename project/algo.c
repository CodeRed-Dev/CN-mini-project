#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int choice=0;
	while(choice!=-1){
		printf("Enter the choice \n");
		printf("1.SSL versions supported by Linux\n");
		printf("2.Verify SSL & TLS version support\n");
		printf("3.Certificate Generation\n");
		printf("4.Key log store\n");
		printf("-1.For exit\n");
		scanf("%d",&choice);
		char website[100];
		switch(choice){
			case 1: system("openssl ciphers -v | awk '{print $2}' | sort | uniq");
					break;
			case 2: printf("Enter the website\n");
					scanf("%s",website);
					char scr[100] = "nmap --script +ssl-enum-ciphers -p 443 ";
					strcat(scr,website);
					system(scr);
					break;
			case 3: system("openssl req -x509 -nodes -days 365 -newkey rsa:1024 -keyout mycert.pem -out mycert.pem");
					break;
			case 4: printf("Enter the location\n");
					char loc[100];
					scanf("%s",loc);
					char exp ="export SSLKEYLOGFILE=\"";
					strcat(exp,loc);
					char c="\"";
					strcat(exp,c);
					system(exp);
					break;
			case -1: printf("Ending the program \n");
					 exit(0);
		}
	}
	return 0;
}
