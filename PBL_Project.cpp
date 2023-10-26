#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <string>
#include <Windows.h>
// #include <algorithm>
// #include <cstdlib> // for srand and rand
// #include <ctime>   // for time

using namespace std;

class Question
{
public:
    string text;
    vector<string> options;
    int correctOption;

    Question(string questionText, vector<string> questionOptions, int correct)
        : text(questionText), options(questionOptions), correctOption(correct) {}

    bool isCorrect(int choice)
    {
        return choice - 1 == correctOption; // Corrected index
    }
};

class Domain
{
public:
    vector<Question> questions;
    string name;
    static int num;
    Domain() { num++; }
    Domain(string domainName) : name(domainName) {}

    void addQuestion(Question question)
    {
        questions.push_back(question);
    }

    void conductQuiz()
    {
        int score = 0;
        cout << "Domain: " << name << endl;
        for (int i = 0; i < questions.size(); i++)
        {
            cout << "Question " << (i + 1) << ": " << questions[i].text << endl;
            vector<string> options = questions[i].options;
            int originalCorrectOption = questions[i].correctOption; // Store the original correct option
            random_shuffle(options.begin(), options.end());         // Shuffle options

            for (int j = 0; j < options.size(); j++)
            {
                cout << j + 1 << ". " << options[j] << endl;
            }

            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            if (options[choice - 1] == questions[i].options[originalCorrectOption])
            {
                cout << "Correct!" << endl;
                score++;
            }
            else
            {
                cout << "Incorrect. The correct answer is: " << questions[i].options[originalCorrectOption] << endl;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            cout << "* ";
        }
        cout << endl
             << endl;
        cout << "Quiz completed. Score: " << score << " out of " << questions.size() << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << "* ";
        }
        cout << endl
             << endl;
    }
};

int Domain ::num = 0;
void loading()
{

    system("COLOR Oc");
    system("cls");
    printf("\e[?25l");

    int bar1 = 177, bar2 = 219;
    cout << "\n\t\t\t\t\tLoading...";
    cout << "\n\n\t\t\t\t";

    for (int i = 0; i < 25; i++)
    {
        cout << (char)bar1;
    }

    cout << "\r";
    cout << "\t\t\t\t";
    for (int i = 0; i < 25; i++)
    {
        cout << (char)bar2;
        Sleep(100);
    }
}
int main()
{
    system("Color E4");

    loading();
    // Initialize random seed for shuffling options
    srand(static_cast<unsigned>(time(0)));

    // Create separate Domain objects for each domain
    Domain historyDomain("History");
    Domain scienceDomain("Science");
    Domain sportsDomain("Sports");
    Domain geographyDomain("Geography");
    Domain literatureDomain("Literature");
    Domain moviesDomain("Movies and Cinema");
    Domain musicDomain("Music");
    Domain artDomain("Art and Artists");
    Domain technologyDomain("Technology");
    Domain currentAffairsDomain("Current and World Affairs");

    // Add questions to each domain
    // HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    // SetConsoleTextAttribute(h,3);
    historyDomain.addQuestion(Question("What year did World War II end?", {"1945", "1939", "1950"}, 0));
    historyDomain.addQuestion(Question("Who was the first President of the United States?", {"George Washington", "Thomas Jefferson", "John Adams"}, 0));
    historyDomain.addQuestion(Question("What is the largest planet in the solar system?", {"Jupiter", "Mars", "Earth"}, 0));
    historyDomain.addQuestion(Question("In which year did Christopher Columbus discover America?", {"1492", "1500", "1607"}, 0));
    historyDomain.addQuestion(Question("Who wrote the play 'Romeo and Juliet'?", {"William Shakespeare", "Charles Dickens", "Jane Austen"}, 0));

    // system("Color 0A");
    system("Color B5");

    scienceDomain.addQuestion(Question("What is the chemical symbol for water?", {"H2O", "CO2", "O2"}, 0));
    scienceDomain.addQuestion(Question("What is the process of plants making their own food using sunlight?", {"Photosynthesis", "Respiration", "Transpiration"}, 0));
    scienceDomain.addQuestion(Question("Which gas is most abundant in the Earth's atmosphere?", {"Nitrogen", "Oxygen", "Carbon Dioxide"}, 0));
    scienceDomain.addQuestion(Question("What is the chemical symbol for gold?", {"Au", "Ag", "Fe"}, 0));
    scienceDomain.addQuestion(Question("What is the smallest planet in our solar system?", {"Mercury", "Venus", "Mars"}, 0));

    sportsDomain.addQuestion(Question("Which country won the FIFA World Cup in 2018?", {"France", "Croatia", "Belgium"}, 0));
    sportsDomain.addQuestion(Question("In which sport can you score a 'hat-trick'?", {"Cricket", "Tennis", "Basketball"}, 0));
    sportsDomain.addQuestion(Question("Who holds the record for the most Olympic gold medals in history?", {"Michael Phelps", "Usain Bolt", "Jesse Owens"}, 0));
    sportsDomain.addQuestion(Question("Which country is known as the 'Land of the Rising Sun'?", {"Japan", "China", "South Korea"}, 0));
    sportsDomain.addQuestion(Question("Which sport is associated with Wimbledon?", {"Tennis", "Golf", "Soccer"}, 0));

    geographyDomain.addQuestion(Question("What is the capital of India?", {"New Delhi", "Mumbai", "Bangalore"}, 0));
    geographyDomain.addQuestion(Question("Which river is often referred to as the 'Ganga' in India?", {"Ganges", "Yamuna", "Brahmaputra"}, 0));
    geographyDomain.addQuestion(Question("Which desert is located in the northwest part of India?", {"Thar Desert", "Sahara Desert", "Kalahari Desert"}, 0));
    geographyDomain.addQuestion(Question("What is the southernmost point of India called?", {"Kanyakumari", "Cape Comorin", "Cape Rama"}, 0));
    geographyDomain.addQuestion(Question("Which mountain range is in the northern part of India?", {"Himalayas", "Andes", "Rocky Mountains"}, 0));

    literatureDomain.addQuestion(Question("Who is the author of the epic 'Ramayana'?", {"Valmiki", "Vyasa", "Kalidasa"}, 0));
    literatureDomain.addQuestion(Question("Which prince is the central character of the 'Ramayana'?", {"Rama", "Krishna", "Arjuna"}, 0));
    literatureDomain.addQuestion(Question("In the 'Mahabharata', who was the eldest of the Pandavas?", {"Yudhishthira", "Arjuna", "Bhima"}, 0));
    literatureDomain.addQuestion(Question("Who served as the charioteer of Arjuna in the 'Mahabharata'?", {"Krishna", "Bhishma", "Dronacharya"}, 0));
    literatureDomain.addQuestion(Question("In the 'Ramayana', what is the name of Rama's loyal brother?", {"Lakshmana", "Hanuman", "Bharata"}, 0));

    moviesDomain.addQuestion(Question("Who directed the 1975 Bollywood classic 'Sholay'?", {"Ramesh Sippy", "Rajkumar Hirani", "Karan Johar"}, 0));
    moviesDomain.addQuestion(Question("Which Bollywood actor is often referred to as the 'King of Bollywood'?", {"Shah Rukh Khan", "Amitabh Bachchan", "Salman Khan"}, 0));
    moviesDomain.addQuestion(Question("Who won the Academy Award for Best Director for the movie 'The Revenant'?", {"Alejandro G. Iñárritu", "Martin Scorsese", "Quentin Tarantino"}, 0));
    moviesDomain.addQuestion(Question("In which movie did Heath Ledger famously play the Joker?", {"The Dark Knight", "Inception", "Interstellar"}, 0));
    moviesDomain.addQuestion(Question("Who directed the epic film 'Avatar'?", {"James Cameron", "Steven Spielberg", "Peter Jackson"}, 0));

    musicDomain.addQuestion(Question("Who is known as the 'King of Playback Singing' in the Indian music industry?", {"Kishore Kumar", "Lata Mangeshkar", "Asha Bhosle"}, 0));
    musicDomain.addQuestion(Question("Which music director duo composed the famous song 'Yeh Mera Dil' from the movie 'Don'?", {"R.D. Burman and Anand Bakshi", "Shankar-Ehsaan-Loy", "Vishal-Shekhar"}, 0));
    musicDomain.addQuestion(Question("Which legendary singer is known for his qawwali performances and is often referred to as the 'Shahenshah of Qawwali'?", {"Nusrat Fateh Ali Khan", "Mohammed Rafi", "Kishore Kumar"}, 0));
    musicDomain.addQuestion(Question("Which classical music legend played a pivotal role in the film 'Anand' by composing the song 'Zindagi Kaisi Hai Paheli'?", {"Manna Dey", "Lata Mangeshkar", "Ravi Shankar"}, 0));
    musicDomain.addQuestion(Question("In which Bollywood film did the song 'Chaiyya Chaiyya' feature, which was famously shot on a moving train?", {"Dil Se", "Dilwale Dulhania Le Jayenge", "Kabhi Khushi Kabhie Gham"}, 0));

    artDomain.addQuestion(Question("Who is known for painting the 'Mona Lisa'?", {"Leonardo da Vinci", "Vincent van Gogh", "Pablo Picasso"}, 0));
    artDomain.addQuestion(Question("Which famous artist is known for his surreal and abstract paintings, including 'The Persistence of Memory'?", {"Salvador Dalí", "Jackson Pollock", "Andy Warhol"}, 0));
    artDomain.addQuestion(Question("Who is the sculptor of the famous statue 'David'?", {"Michelangelo", "Auguste Rodin", "Piet Mondrian"}, 0));
    artDomain.addQuestion(Question("Which art movement is known for its use of geometric shapes and primary colors, as seen in works like 'Composition with Red, Blue, and Yellow'?", {"De Stijl", "Cubism", "Surrealism"}, 0));
    artDomain.addQuestion(Question("Who is the artist behind the 'Starry Night' painting?", {"Vincent van Gogh", "Pablo Picasso", "Claude Monet"}, 0));

    technologyDomain.addQuestion(Question("Who is the co-founder of Microsoft Corporation?", {"Bill Gates", "Steve Jobs", "Mark Zuckerberg"}, 0));
    technologyDomain.addQuestion(Question("What does CPU stand for in the context of computers?", {"Central Processing Unit", "Computer Personal Unit", "Central Process Unit"}, 0));
    technologyDomain.addQuestion(Question("Which company developed the first commercially available microprocessor, the 4004?", {"Intel", "AMD", "Apple"}, 0));
    technologyDomain.addQuestion(Question("What is the term for a network of interlinked computers that share information and resources?", {"Internet", "Intranet", "Extranet"}, 0));
    technologyDomain.addQuestion(Question("Which technology company is known for its search engine and operates under the parent company Alphabet Inc.?", {"Google", "Microsoft", "Amazon"}, 0));

    currentAffairsDomain.addQuestion(Question("Who is the current Secretary-General of the United Nations?", {"António Guterres", "Ban Ki-moon", "Kofi Annan"}, 0));
    currentAffairsDomain.addQuestion(Question("Which country is the world's largest producer of oil?", {"United States", "Saudi Arabia", "Russia"}, 0));
    currentAffairsDomain.addQuestion(Question("In which year did the United Kingdom officially leave the European Union (Brexit)?", {"2020", "2018", "2016"}, 0));
    currentAffairsDomain.addQuestion(Question("What is the capital of Australia?", {"Canberra", "Sydney", "Melbourne"}, 0));
    currentAffairsDomain.addQuestion(Question("Which country is hosting the 2022 FIFA World Cup?", {"Qatar", "Russia", "Brazil"}, 0));
    // ... (your question-adding code remains the same)

    cout << "\n\t\t\tWelcome to the General Knowledge Quiz!" << endl;

    int domainChoice;
    while (true)
    {
        cout << "Choose a domain for the quiz:" << endl;
        cout << "1. History" << endl;
        cout << "2. Science" << endl;
        cout << "3. Sports" << endl;
        cout << "4. Geography" << endl;
        cout << "5. Literature" << endl;
        cout << "6. Movies and Cinema" << endl;
        cout << "7. Music" << endl;
        cout << "8. Art and Artists" << endl;
        cout << "9. Technology" << endl;
        cout << "10. Current and World Affairs" << endl;
        cout << "Choose a domain for the quiz (1-10) or enter 0 to exit: ";
        cin >> domainChoice;

        if (domainChoice == 0)
        {
            cout << "Exiting the quiz. Goodbye!" << endl;
            break;
        }

        switch (domainChoice)
        {
        case 1:
            Domain ::num++;
            historyDomain.conductQuiz();
            break;
        case 2:
            Domain ::num++;
            scienceDomain.conductQuiz();
            break;
        case 3:
            Domain ::num++;
            sportsDomain.conductQuiz();
            break;
        case 4:
            Domain ::num++;
            geographyDomain.conductQuiz();
            break;
        case 5:
            Domain ::num++;
            literatureDomain.conductQuiz();
            break;
        case 6:
            Domain ::num++;
            moviesDomain.conductQuiz();
            break;
        case 7:
            Domain ::num++;
            musicDomain.conductQuiz();
            break;
        case 8:
            Domain ::num++;
            artDomain.conductQuiz();
            break;
        case 9:
            Domain ::num++;
            technologyDomain.conductQuiz();
            break;
        case 10:
            Domain ::num++;
            currentAffairsDomain.conductQuiz();
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;

            cout << "No. of Domains covered till now are " << Domain::num << endl;
            for (int i = 0; i < 10; i++)
            {
                cout << "* ";
            }
            cout << endl
                 << endl;
        }
    }

    return 0;
}