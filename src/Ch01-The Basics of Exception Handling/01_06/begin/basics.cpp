#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string readConfigFile(const string &filename)
{
    ifstream file(filename);

    if (!file.good())
    {
        throw runtime_error("file notfound!!");
    }

    string line;
    string text;
    while (getline(file, line))
    {
        text += line;
        text += '\n';
    }

    return text;
}

int main()
{
    cout << "Reading configuration:" << endl;
    try
    {
        string text = readConfigFile("configuration.txt");
        cout << text;
    }
    catch (const std::exception &e)
    {
        cerr << "error " << e.what() << endl;
    }

    return 0;
}
