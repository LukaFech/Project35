#include <iostream>
#include <cstring>

using namespace std;

void sortNames(char** names, int count)
{
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = 0; j < count - i - 1; ++j)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                char* temp = names[j];
                names[j] = names[j + 1];
                names[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int count = 5;
    char** names = new char* [count];
    char buffer[100];

    cout << "Enter 5 student last names:\n";
    for (int i = 0; i < count; ++i)
    {
        cout << "Student " << (i + 1) << ": ";
        cin >> buffer;

        names[i] = new char[strlen(buffer) + 1];
        strcpy(names[i], buffer);
    }

    sortNames(names, count);

    cout << "\nSorted last names (ascending):\n";
    for (int i = 0; i < count; ++i)
    {
        cout << (i + 1) << ". " << names[i] << "\n";
    }

    for (int i = 0; i < count; ++i)
    {
        delete[] names[i];
    }
    delete[] names;
}