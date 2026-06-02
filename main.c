#include <stdio.h>
#include <getopt.h>

int main(int argc, char** argv) {

	if (argc == 1) {
		printf("Hello, World!\n");
		return 0;
	}

	// Basic variables
	int opt;
	int opt_index = 0;

	// Version Digits
	const int ver_firstdig = 1;
	const int ver_seconddig = 0;
	const int ver_thirddig = 0;

	// For the `getopt_long` Function
	static struct option lngopt[] = {
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
				printf("Hello Version %d.%d.%d; All wrongs reserved.\n", ver_firstdig, ver_seconddig, ver_thirddig);
				break;
			case 'g':
				printf("%s\n", optarg);
				break;
			case '?':
				printf("Invalid option. Enter `./hello -h` for more information\n");
				return 1;
		}
	}
	return 0;
}
