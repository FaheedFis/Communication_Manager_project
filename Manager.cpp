/*****************************************************************************
 ** File: Manager.h
 ** Project: CMSC 202 Project 5, Fall 2023
 ** Author:  Faheed Sadique
 ** Date:    11/11/2023
 **
 Description: Header file for Manager class.
*****************************************************************************/

#include "Lqueue.cpp"
#include "Communicator.h"
#include "Message.h"

using namespace std;

//Overloaded Constructor
Manager::Manager(string filename) : m_filename(filename) {
  m_fileName = filename;
}

//Destructor
Manager::~Manager(){
  for (size_t i = 0; i < m_communicators.size(); ++i) {
    delete m_communicators[i];
  }
}


// Searches all communicators in m_communicators for passed number

int FindCommunicator(long int){
  for (size_t i = 0; i < m_communicators.size(); ++i) {
    if (communicator[i].GetNumber() == m_number){
      return static_cast<int>(i);
    }
}
  return -1; // Communicator not found
}

// Postcondition: Returns true if file was loaded, else false.
bool Manager::LoadMessages(){
  ifstream inputFile(m_fileName);

  if (!inputFile.is_open()) {
    
    return false; 
  }

  long int time, to, from;
  string message;

  while (inputFile >> time >> to >> from >> ws, getline(inputFile, message)) {
    int toIndex = FindCommunicator(to);
    int fromIndex = FindCommunicator(from);

    Message toMessage(time, to, from, message);
    Message fromMessage(time, from, to, message);

    if (toIndex == -1) {
      m_communicators.push_back(Communicator(to));
      toIndex = m_communicators.size() - 1;
    }

    if (fromIndex == -1) {
      m_communicators.push_back(Communicator(from));
      fromIndex = m_communicators.size() - 1;
    }

    m_communicators[toIndex].InsertMessage(toMessage);
    m_communicators[fromIndex].InsertMessage(fromMessage);
  }

  inputFile.close();
  return true;
}


// Presents user with menu options.
void MainMenu(){
  int choice;
  cout << "Please enter a valid option." << endl;
  do {
    cout << "Choose an option" << endl;
    cout << "1. Display Messages" << endl;
    cout << "2. Choose a Number" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
    case 1:
      DisplayMessages();
      break;
    case 2:
      ChooseNumber();
      break;
    case 3:
      cout << "Thank you!" << endl;
      break;
    default:
      
    }
  } while (choice != 3);
}

// Displays all messages loaded
void DisplayMessages(){
  for (const auto& communicator : m_communicators) {
    communicator.DisplayAllMessages();
  }
}
  
// Displays the title then if the file is successfully loaded,

void InitializeManager(){
  cout << "Welcome to UMBC Communication Manager!" << endl;

  if (LoadMessages()) {
    MainMenu();
    cout << "Thank you for using Communication Manager. " << endl;
  } else {
    cout << "Closing the program." << endl;
  }
}


//Numbered list of all unique numbers in m_communicators

void ListNumbers(){
  cout << "What number's log you like to view?" << endl;

  for (size_t i = 0; i < m_communicators.size(); ++i) {
    cout << i + 1 << ". " << m_communicators[i].GetNumber() << endl;
  }
}

//Calls ListNumbers and the user chooses one number.
long int ChooseNumber(){

  ListNumbers();

  int choice;
  cin >> choice;

  if (choice >= 1 && static_cast<size_t>(choice) <= m_communicators.size()) {
   
    return m_communicators[choice - 1].GetNumber();
  } else {
    cout << "Invalid choice. Please enter a valid index." << endl;

    return -1;
  }
}

// Displays all "to" and "from" from a specific number
void DisplayNumber(long int){
  int index = FindCommunicator(number);

  if (index != -1) {
    m_communicators[index].DisplayAllMessages();
  } else {
  }
}
