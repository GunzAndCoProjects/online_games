#include <cstdlib>
#include "Application.h"

using namespace std;
//yes, this is the only one using namespace std

int main(int argc, char** argv) 
{
    Application* Application = Application::CreateInstance();
    Application->Start();
    return 0;
}

