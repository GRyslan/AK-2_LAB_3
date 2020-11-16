#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv) {

    const char *shortOptions = "HVNL:";

    static struct option longOptions[] = {
        {"HELPME",    no_argument,       0, 'H'}, 
        {"VERSIONME", no_argument,       0, 'V'},
        {"LISTME",    required_argument, 0, 'L'},
        {"NAMEME",    no_argument, 0, 'N'},
        {0, 0, 0, 0},
    };

    const char *helpOption = "Program options:\n"
    "-H or --HELPME                          - messages with program options\n"
    "-V or --VERSIONME                       - version\n"
    "-N or --NAMEME                          - file name\n"
    "-L[<val1>,...] or --LISTME=[<num1>,...] - list of arguments\n";
    

    bool H_visited = false;
    bool V_visited = false;
    bool L_visited = false;
    bool N_visited = false; 
    
    int index;
    int code;

    while ((code = getopt_long(argc, argv, shortOptions, longOptions, &index)) != -1) {
        switch (code) {
            case 'H': {
                if (!H_visited) {
                    H_visited = true;
                    printf("%s\n", helpOption);
                }
                break;
            }
            case 'V': {
                if (!V_visited) {
                    V_visited = true;                    
                    printf("Version: 1.1.1\n");
                }
                break;
            }
            case 'N': {
                if (!N_visited) {
                    N_visited = true;
                    printf("main.cpp\n");
                }
                break;
            }
            case 'L': {
                if (!L_visited) {
                    char *args;
                    printf("Arguments list:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL) {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    L_visited = true;
                }
                break;
            }
            default: {
                printf("ARGUMENT,WHERE YOU?(TRY -H)\n");
                return 0;
            }
        }
    }
    return 0;
}
