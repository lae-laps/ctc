/* ctc.c */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include </usr/include/python3.10/Python.h>

char *text;

void exec_pycode(code) {
    Py_Initialize();
    PySys_SetPath("pythonmodules/");
    PyObject *pval;
    char *cString = "test";
    pval = PyString_FromString(cString);

}

int main(int argc, char *argv[]) {

    // REFERENCE (reading from stdin in c) : https://stackoverflow.com/questions/16305971/how-to-read-piped-content-in-c
    if (!isatty(fileno(stdin))) { // check if there is stdin
        int i = 0;
        char pipe[65536];
        while(-1 != (pipe[i++] = getchar()));
        pipe[i-2] = '\0'; // delete newline char '\n' from end of captured stdin 
        text = pipe;
    } else { // there is no stdin
        if (argc < 2) { // if no args - exit
            return 0;
        }
        text = argv[1]; // copy args to pipe
    }
    printf("here is your stdin >>%s<<", text);
}

