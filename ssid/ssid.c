/* (C)opyright MMVI Anselm R. Garbe <garbeam at gmail dot com>
 * See LICENSE file for license details.
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char *argv[]) {
	if(argc < 2) {
		fputs("usage: ssid [-v] cmd [arg ...]\n", stderr);
		exit(EXIT_FAILURE);
	}
	else if(!strncmp(argv[1], "-v", 3)) {
		fputs("ssid-"VERSION", (C)opyright MMVI Anselm R. Garbe\n", stdout);
		exit(EXIT_SUCCESS);
	}
	if(getpgrp() == getpid()) {
		switch(fork()){
			case -1:
				perror("ssid: fork");
				exit(1);
			case 0:
				break;
			default:
				exit(0);
		}
	}
	if(setsid() < 0) {
		perror("ssid: setsid");
		exit(1);
	}
	execvp(argv[1], argv + 1);
	perror("ssid: execvp");
	exit(1);
	return 0;
}

