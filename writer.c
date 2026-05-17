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
	
	ssize_t written_byte = write(fd, argv[2], strlen(argv[2]));
	if (written_byte = -1) display_err_msg("In main() while writing to the file");
	if (written_byte != strlen(argv[2]) {
		perror("FATAL ERROR!! In main() while writing to the file\n");
		printf("Only \%zu of the string could be written to the file\n", (written_byte * 100) / strlen(argv[2]); 
		exit(-1);
	}
	if (close(fd) == -1) display_err_msg("in main() while closing the file");

	printf("String has been written to %s\n", argv[1]);

	return 0;
}

void usage(const char *prog_name) {
	printf("Usage: %s <filename> \"<string to be written to the file>\"\n", prog_name);
	exit(EXIT_SUCCESS);
}

void display_err_msg(const char *msg) {
	char err_msg[256] = "FATAL ERROR!! ";
	strncat(err_msg, msg, 242);
	perror(err_msg);
	exit(EXIT_FAILURE);
}
