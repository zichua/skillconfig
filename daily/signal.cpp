#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

void signalhandler(int signum)
{
    cout << endl << "signal num : " << signum << endl;
    exit(signum);
}

int main()
{
    signal(SIGINT,signalhandler);

    while(1)
    {
        cout << "slepping..." << endl;
        sleep(1);
    }

    return 0;
}