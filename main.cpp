#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "trie.cpp"

using namespace std;

void printLine()
{
    cout << "\n----------------------------------------\n";
}

void printMenu()
{
    printLine();
    cout << "1. Search for prefix\n";
    cout << "2. Insert new word\n";
    cout << "3. Exit\n";
    printLine();
    cout << "Choose an option (1/2/3): ";
}

int main()
{
    Trie trie;
    ifstream file("words.txt");
    string word;

    if (!file.is_open())
    {
        cout << "Error: Could not open words.txt\n";
        return 1;
    }

    cout << "Loading words from words.txt...\n";
    while (getline(file, word))
    {
        if (!word.empty())
            trie.insert(word);
    }
    file.close();
    cout << "Words loaded successfully!\n";

    while (true)
    {
        printMenu();
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        if (choice == 1)
        {
            string input;
            cout << "Enter prefix: ";
            getline(cin, input);

            vector<string> suggestions = trie.autocomplete(input);
            printLine();
            if (suggestions.empty())
            {
                cout << "No suggestions found for \"" << input << "\".\n";
            }
            else
            {
                cout << "Suggestions for \"" << input << "\":\n\n";
                int count = 1;
                for (const string &s : suggestions)
                {
                    cout << count << ". " << s << '\n';
                    ++count;
                }
            }
        }
        else if (choice == 2)
        {
            cout << "Enter word to insert: ";
            getline(cin, word);

            if (trie.search(word))
            {
                cout << "Word \"" << word << "\" already exists in the dictionary.\n";
            }
            else
            {
                trie.insert(word);

                ofstream outfile("words.txt", ios::app);
                if (outfile.is_open())
                {
                    outfile << word << "\n";
                    outfile.close();
                    cout << "Word \"" << word << "\" inserted successfully.\n";
                }
                else
                {
                    cout << "Error: Could not open words.txt for writing.\n";
                }
            }
        }
        else if (choice == 3)
        {
            printLine();
            cout << "Exiting autocomplete. Goodbye.\n";
            break;
        }
        else
        {
            cout << "Invalid option. Please choose 1, 2, or 3.\n";
        }
    }

    return 0;
}