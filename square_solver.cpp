#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tests.h"
#include "options.h"

int main(int argc, char *argv[]) {
    int opt = 0;

    while ((opt = getopt(argc, argv, "hts")) != -1) {  
        switch (opt){
        case 'h': 
            help_option();
            break;

        case 't':
            all_tests();
            break;

        case 's': 
            solution_option();
            break;

        case '?': 
            printf("> ?\n");
            break;

        default: 
            printf("Critical");
            exit(1);
        }
    }

    return 0;
}