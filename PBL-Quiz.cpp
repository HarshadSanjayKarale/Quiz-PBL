#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream> // for file handling

using namespace std;

class Question {
public:
    string text;
    vector<string> options;
    int correctOption;

    Question(string questionText, vector<string> questionOptions, int correct)
        : text(questionText), options(questionOptions), correctOption(correct) {}

    bool isCorrect(int choice) {
        return choice - 1 == correctOption;
    }
};

class Domain {
public:
    vector<Question> questions;
    string name;
    static int num;
    Domain() { num++; }
    Domain(string domainName) : name(domainName) {}

    void addQuestion(Question question) {
        questions.push_back(question);
    }

    void conductQuiz() {
        int score = 0;
        cout << "Domain: " << name << endl;
        for (int i = 0; i < questions.size(); i++) {
            cout << "Question " << (i + 1) << ": " << questions[i].text << endl;
            vector<string> options = questions[i].options;
            int originalCorrectOption = questions[i].correctOption;
            random_shuffle(options.begin(), options.end());

            for (int j = 0; j < options.size(); j++) {
                cout << j + 1 << ". " << options[j] << endl;
            }

            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            if (options[choice - 1] == questions[i].options[originalCorrectOption]) {
                cout << "Correct!" << endl;
                score++;
            } else {
                cout << "Incorrect. The correct answer is: " << questions[i].options[originalCorrectOption] << endl;
            }
        }
        for (int i = 0; i < 10; i++) {
            cout << "* ";
        }
        cout << endl
             << endl;
        cout << "Quiz completed. Score: " << score << " out of " << questions.size() << endl;
        for (int i = 0; i < 10; i++) {
            cout << "* ";
        }
        cout << endl
             << endl;
    }
};

int Domain::num = 0;

int main() {
    srand(static_cast<unsigned>(time(0)));

    ifstream inputFile("questions.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    string line;
    string domainName;
    string questionText;
    vector<string> questionOptions;
    int correctOption;

    Domain historyDomain("History");
    Domain scienceDomain("Science");
    Domain sportsDomain("Sports");
    Domain geographyDomain("Geography");
    Domain literatureDomain("Literature");
    Domain moviesDomain("Movies");
    Domain musicDomain("Music");
    Domain artDomain("Art");
    Domain technologyDomain("Technology");
    Domain currentAffairsDomain("Current Affairs");

    while (getline(inputFile, line)) {
        if (line.find("Domain: ") == 0) {
            domainName = line.substr(8);
        } else {
            questionOptions.clear(); // Clear the options for each new question
            questionText = line;
            for (int i = 0; i < 3; i++) {
                getline(inputFile, line);
                questionOptions.push_back(line);
            }
            getline(inputFile, line);
            correctOption = stoi(line);

            if (domainName == "History") {
                historyDomain.addQuestion(Question(questionText, questionOptions, correctOption - 1));
            } else if (domainName == "Science") {
                scienceDomain.addQuestion(Question(questionText, questionOptions, correctOption - 1));
            } else if (domainName == "Sports") {
                sportsDomain.addQuestion(Question(questionText, questionOptions, correctOption - 1));
            } else if (domainName == "Geography") {
                geographyDomain.addQuestion(Question(questionText, questionOptions, correctOption - 1));
            } else if (domainName == "Literature") {
                literatureDomain.addQuestion(Question(questionText, questionOptions, correctOption - 1));
            } else if (domainName == "Movies") {
                moviesDomain.addQuestion(Question(questionText, questionOptions, correctOption - 1));
            } else if (domainName == "Music") {
                musicDomain.addQuestion(Question(questionText, questionOptions, correctOption - 1));
            } else if (domainName == "Art") {
                artDomain.addQuestion(Question(questionText, questionOptions, correctOption - 1));
            } else if (domainName == "Technology") {
                technologyDomain.addQuestion(Question(questionText, questionOptions, correctOption - 1));
            } else if (domainName == "Current Affairs") {
                currentAffairsDomain.addQuestion(Question(questionText, questionOptions, correctOption - 1));
            }
            // Add more cases for other domains
        }
    }

    inputFile.close();

    cout << "Welcome to the General Knowledge Quiz!" << endl;

    int domainChoice;
    while (true) {
        cout << "Choose a domain for the quiz:" << endl;
        cout << "1. History" << endl;
        cout << "2. Science" << endl;
        cout << "3. Sports" << endl;
        cout << "4. Geography" << endl;
        cout << "5. Literature" << endl;
        cout << "6. Movies" << endl;
        cout << "7. Music" << endl;
        cout << "8. Art" << endl;
        cout << "9. Technology" << endl;
        cout << "10. Current and World Affairs" << endl;
        cout << "Choose a domain for the quiz (1-10) or enter 0 to exit: ";
        cin >> domainChoice;

        if (domainChoice == 0) {
            cout << "Exiting the quiz. Goodbye!" << endl;
            break;
        }

        switch (domainChoice) {
            case 1:
                Domain::num++;
                historyDomain.conductQuiz();
                break;
            case 2:
                Domain::num++;
                scienceDomain.conductQuiz();
                break;
            case 3:
                Domain::num++;
                sportsDomain.conductQuiz();
                break;
            case 4:
                Domain::num++;
                geographyDomain.conductQuiz();
                break;
            case 5:
                Domain::num++;
                literatureDomain.conductQuiz();
                break;
            case 6:
                Domain::num++;
                moviesDomain.conductQuiz();
                break;
            case 7:
                Domain::num++;
                musicDomain.conductQuiz();
                break;
            case 8:
                Domain::num++;
                artDomain.conductQuiz();
                break;
            case 9:
                Domain::num++;
                technologyDomain.conductQuiz();
                break;
            case 10:
                Domain::num++;
                currentAffairsDomain.conductQuiz();
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
        cout << "No. of Domains covered till now are " << Domain::num << endl;
        for (int i = 0; i < 10; i++) {
            cout << "* ";
        }
        cout << endl << endl;
    }

    return 0;
}

