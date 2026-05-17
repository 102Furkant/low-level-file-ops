#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 256

void usage(const char *prog_name);
void display_err_msg(const char *msg);

int main(int argc, char *argv[]) {

	if (argc < 2) usage(argv[0]);

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1) display_err_msg("In main() while openning the file");

	char buff[CHUNK_SIZE] = {};

	ssize_t read_byte = 0;

	while ((read_byte = read(fd, buff, sizeof(buff))) > 0) {
		ssize_t to_write_byte = read_byte;
		char *location_at_buff = buff;

		while (to_write_byte > 0) {
			ssize_t written_byte = write(1, location_at_buff, to_write_byte);
			if (written_byte == -1) display_err_msg("In main() while writing to the terminal");
			to_write_byte -= written_byte;
			location_at_buff += written_byte;
		}
	
	}

	if (read_byte == -1) display_err_msg("In main() while reading the file");

	if (close(fd) == -1) display_err_msg("In main() while closing the file");

	printf("\n");

	return 0;
}


void usage(const char *prog_name) {
	printf("Usage: %s <file name>\n", prog_name);
	exit(EXIT_SUCCESS);
}

void display_err_msg(const char *msg) {
	char err_msg[256] = "FATAL ERROR !!";
	strncat(err_msg, msg, 242);
	perror(err_msg);
	exit(EXIT_FAILURE);
}

