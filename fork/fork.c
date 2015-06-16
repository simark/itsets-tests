#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    long levels;
    int i;

    if (argc != 2) {
        fprintf (stderr, "Usage: fork [levels]\n");
        return 1;
    }
    
    levels = atoi (argv[1]);
    
    /* Don't crash the computer. */
    if (levels > 5)
        levels = 5;
    
    while (levels > 0) {
        pid_t pid;
        
        pid = fork ();
        
        if (pid > 0) {
            /* Parent */
            break;
        } else {
            /* Child */
            levels--;
        }
    }
    
    printf ("Hello, I am process %d\n", getpid());
    
    for (i = 0; i < 600; i++) {
        sleep (1);
    }
    
    return 0;
}
