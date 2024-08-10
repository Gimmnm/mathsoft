#include <unistd.h>  

int main()
{
    char *const ps_argv[] =  
        {"ps", "-el", 0};  
    
    char *const ps_envp[] =  
        {"PATH=/bin:/usr/bin", "TERM=console", 0};  

    execve("/bin/ps", ps_argv, ps_envp);  
    return 0;
}
