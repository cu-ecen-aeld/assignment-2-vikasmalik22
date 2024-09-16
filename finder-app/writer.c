#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Open a connection to syslog with LOG_USER facility
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    // Check if the correct number of arguments are passed
    if (argc != 3) {
        syslog(LOG_ERR, "Error: Incorrect number of arguments");
        printf("Usage: %s <file_path> <string_to_write>\n", argv[0]);
        exit(1);
    }

    char *writefile = argv[1];  // File path
    char *writestr = argv[2];   // String to write

    // Open file for writing, create if it doesn't exist, truncate if it does
    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error: Could not open file %s: %s", writefile, strerror(errno));
        perror("Error");
        exit(1);
    }

    // Log the debug message indicating writing to file
    syslog(LOG_DEBUG, "Writing \"%s\" to %s", writestr, writefile);

    // Write the string to the file
    if (fputs(writestr, file) == EOF) {
        syslog(LOG_ERR, "Error: Could not write to file %s: %s", writefile, strerror(errno));
        perror("Error");
        fclose(file);
        exit(1);
    }

    // Close the file after writing
    if (fclose(file) == EOF) {
        syslog(LOG_ERR, "Error: Could not close file %s: %s", writefile, strerror(errno));
        perror("Error");
        exit(1);
    }

    // Close the syslog connection
    closelog();

    return 0;
}
