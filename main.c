#ifndef _WIN32
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <getopt.h>
#define VERSION "1.1.0"

int main(int argc, char** argv) {

	opterr = 0;
	
	if (argc == 1) {
		printf("Hello, World!\n");
		return 0;
	}

	// Basic variables
	int opt;
	int opt_index = 0;

	// For the `getopt_long` Function
	static const struct option lngopt[] = {
		{"help", no_argument, 0, 'h'},
		{"version", no_argument, 0, 'v'},
		{"greeting", required_argument, 0, 'g'},
		{0, 0, 0, 0}
	};

	while ((opt = getopt_long(argc, argv, "hvg:", lngopt, &opt_index)) != -1) {
		switch (opt) {
			case 'h':
				printf("\
Basic usage:\n\n\
-h, --help: Show this message.\n\
-v, --version: Show the informations about this version.\n\
-g message, --greeting=message: Shows up \"message\" instead of the defaults.\n\n\
Good Luck!\n\n"
						);
				break;
			case 'v':
				printf("Hello Version %s. All wrongs reserved.\n", VERSION);
				break;
			case 'g':
				printf("%s\n", optarg);
				break;
			case '?':
				fprintf(stderr, "Invalid option. Enter `./hello -h` for more information\n");
				return 1;
		}
	}

	if (optind < argc) {
		fprintf(stderr, "Remaining arguments: %s\n", argv[optind]);
	}
	
	return 0;
}
