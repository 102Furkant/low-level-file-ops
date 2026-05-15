#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

void usage(const char *prog_name);
void display_err_msg(const char *msg);

int main(int argc, char *argv[]) {
	if (argc < 3) usage(argv[0]);

	int fd = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1) display_err_msg("in main() while opening the file");
	
	if (write(fd, argv[2], strlen(argv[2])) == -1) display_err_msg("in main() while writing string to the file");

	if (close(fd) == -1) display_err_msg("in main() while closing the file");

	printf("String has been written to %s\n", argv[1]);

	return 0;
}

void usage(const char *prog_name) {
	printf("Usage: %s <filename> \"<string to be written to the file>\"\n", prog_name);
	exit(0);
}

void display_err_msg(const char *msg) {
	char err_msg[256] = "FATAL ERROR!! ";
	strncat(err_msg, msg, 242);
	perror(err_msg);
	exit(-1);
}
