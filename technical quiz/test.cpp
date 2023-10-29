#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <exception>

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

class BonusQuestion {
public:
    string text;
    vector<string> options;
    int correctOption;

    BonusQuestion(string questionText, vector<string> questionOptions, int correct)
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
    int bonusPoints;

    Domain() : bonusPoints(0) { num++; }
    Domain(string domainName) : name(domainName), bonusPoints(0) {}

    void addQuestion(Question question) {
        questions.push_back(question);
    }

    string categorizeUser(int score) {
        if (score >= 8) {
            return "ACE";
        } else if (score >= 6) {
            return "Expert";
        } else if (score >= 4) {
            return "Intermediate";
        } else {
            return "Beginner";
        }
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
        cout << endl << endl;
        cout << "Quiz completed. Score: " << score << " out of " << questions.size() << endl;
        for (int i = 0; i < 10; i++) {
            cout << "* ";
        }
        cout << endl << endl;

        if (score >= 4) {
            bonusPoints = score;
            cout << "Congratulations! You have earned " << bonusPoints << " bonus point(s)." << endl;
        }

        // Print the grand total points and the number of domains covered
        cout << "Grand Total Points: " << bonusPoints << endl;
        string userCategory = categorizeUser(bonusPoints);
        cout << "You earned a Badge : " << userCategory <<endl; 
        cout << "Number of Domains Covered: " << num << endl;
    }

    void askBonusQuestion(vector<BonusQuestion> &bonusQuestions) {
        if (bonusPoints >= 4 && !bonusQuestions.empty()) {
            cout << "Bonus Question for " << name << " Domain:" << endl;
            BonusQuestion bonusQuestion = bonusQuestions.back();
            bonusQuestions.pop_back();

            cout << bonusQuestion.text << endl;
            vector<string> options = bonusQuestion.options;
            random_shuffle(options.begin(), options.end());

            for (int i = 0; i < options.size(); i++) {
                cout << i + 1 << ". " << options[i] << endl;
            }

            int choice;
            cout << "Enter your choice for the bonus question: ";
            cin >> choice;

            // Adjust the choice based on shuffled options
            int adjustedChoice = -1;
            for (int i = 0; i < options.size(); i++) {
                if (bonusQuestion.isCorrect(i)) {
                    adjustedChoice = i + 1;
                    break;
                }
            }

            if (adjustedChoice == choice) {
                cout << "Correct! You earned the bonus point." << endl;
                bonusPoints++;
            } else {
                cout << "Incorrect. The correct answer is: " << adjustedChoice << ". " << bonusQuestion.options[bonusQuestion.correctOption] << endl;
            }

            // Print the grand total points and the number of domains covered
            cout << "Grand Total Points: " << bonusPoints << endl;
            cout << "Number of Domains Covered: " << num << endl;
        }
    }
};

int Domain::num = 0;

int main() {
    srand(static_cast<unsigned>(time(0)));

    ifstream inputFile("questions.txt");
    ifstream bonusFile("bonus.txt");
    if (!inputFile.is_open() || !bonusFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    string line;
    string domainName;
    string questionText;
    vector<string> questionOptions;
    int correctOption;

    vector<Domain> domains;
    vector<BonusQuestion> bonusQuestions;

    while (getline(bonusFile, line)) {
        vector<string> bonusQuestionOptions;
        questionText = line;
        for (int i = 0; i < 4; i++) {
            getline(bonusFile, line);
            bonusQuestionOptions.push_back(line);
        }
        getline(bonusFile, line);
        try {
            correctOption = stoi(line);
        } catch (const exception& e) {
            cerr << "Error converting to integer: " << e.what() << endl;
        }

        bonusQuestions.push_back(BonusQuestion(questionText, bonusQuestionOptions, correctOption - 1));
    }

    while (getline(inputFile, line)) {
        if (line.find("Domain: ") == 0) {
            domainName = line.substr(8);
            domains.push_back(Domain(domainName));
        } else {
            questionOptions.clear();
            questionText = line;
            for (int i = 0; i < 4; i++) {
                getline(inputFile, line);
                questionOptions.push_back(line);
            }
            getline(inputFile, line);
            correctOption = stoi(line);

            if (!domains.empty()) {
                domains.back().addQuestion(Question(questionText, questionOptions, correctOption - 1));
            }
        }
    }

    inputFile.close();
    bonusFile.close();

    cout << "Welcome to the Technical Knowledge Quiz!" << endl;

    int domainChoice;
    while (true) {
        cout << "Choose a domain for the quiz:" << endl;
        for (int i = 0; i < domains.size(); i++) {
            cout << i + 1 << ". " << domains[i].name << endl;
        }
        cout << "Enter the number of the domain (1-" << domains.size() << ") or enter 0 to exit: ";
        cin >> domainChoice;

        if (domainChoice == 0) {
            cout << "Exiting the quiz. Goodbye!" << endl;
            break;
        }

        if (domainChoice >= 1 && domainChoice <= domains.size()) {
            Domain::num++;
            Domain& selectedDomain = domains[domainChoice - 1];
            selectedDomain.conductQuiz();
            selectedDomain.askBonusQuestion(bonusQuestions);
        } else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}
