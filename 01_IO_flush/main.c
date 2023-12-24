#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  bool newLine;
  bool flush;
  bool fileRedirect;
} params_t;

params_t getParams(int argc, char *argv[]) {
    params_t newParams = {'0', '0', '0'};
   
    for (int i = 1; i <= 3 && i < argc; ++i) {
    switch (i) {
        case 1:
            newParams.newLine = (argv[i][0] == '1');
            break;
        case 2:
            newParams.flush = (argv[i][0] == '1');
            break;
        case 3:
            newParams.fileRedirect = (argv[i][0] == '1');
            break;
        }
    }

    return newParams; 
}

int main(int argc, char* argv[]) {
    params_t params = getParams(argc, argv);

    char* outMessage = params.newLine ? "stdout\n" : "stdout";
    char* errMessage = params.newLine ? "stderr\n" : "stderr";

    if (params.fileRedirect) {
        freopen("output.txt", "a", stdout);
        freopen("output.txt", "a", stderr);

    }

    fputs(outMessage, stdout);
    params.flush && fflush(stdout);

    fputs(errMessage, stderr);
    params.flush && fflush(stderr);

    
    if (params.fileRedirect) {
        fclose(stdout);
        fclose(stderr);
    }

    return 0;
}