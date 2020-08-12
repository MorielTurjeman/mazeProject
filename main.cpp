#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
    std::cout << "hello world" << std::endl;

        time_t start_time = time(NULL); 
        std::cout << ctime(&start_time) << std::endl;





        time_t end_time = time(NULL); 
        std::cout << ctime(&end_time) << std::endl;

    return 0;
}