#include <iostream>
#include <string>

void Compress(std::string src_file_address);
void Decompress(std::string src_file_address);

int main(int argc, char* argv[])
{
    if (argc != 3) 
    {
        std::cout << "Invalid command. It should be of the form: {run command} {compress/decompress} {file address}\n"; 
        return 1;
    }
    
    std::string task = argv[1];
    std::string file_address = argv[2];

    if (task == "compress") Compress(file_address);
    else if (task == "decompress") Decompress(file_address);
    else 
    {
        std::cout << "Invalid command. The task should be either \"compress\" or \"decompress\"\n";
        return 1;
    }

    return 0;
}