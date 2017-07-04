#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <locale>
#include <time.h>
#include <math.h>
#include <sstream>
#include <chrono>

#define HASH_TABLE_SIZE 100003

using namespace std;


class Node {

  private:
    string word;
    Node *next;
  public:
    Node(string w);
    string getWord(void);
    void setWord(string w);
    void setNext(Node *n);
    Node* getNext(void);

};

Node::Node(string w) {
    word = w;
    next = NULL;
}

string Node::getWord(void) {
    return word;
}

void Node::setWord(string w) {
    word = w;
}

void Node::setNext(Node *n) {
    next = n;
}

Node* Node::getNext(void) {
    return next;
}


class List {

  private:
    int size_l;
    Node *head;
    Node *tail;

  public:
    List();
    ~List();
    void append(string word);
    void print(void);
    int getSize();
    Node* getHead();

};

List::List() {
    size_l = 0;
    head = NULL;
    tail = NULL;
}

List::~List() {
    delete [] head;
}

void List::append(string word) {

    Node *aux = new Node(word);
    aux->setNext(NULL);

    if (head == NULL) {
        head = tail = aux;

    }else {
        tail->setNext(aux);
        tail = aux;
    }

    size_l++;
}

void List::print(void) {

    Node *aux = head;

    if (head == NULL) {
        cout<< "EMPTY LIST! " << endl;
    }else
    {
        cout<< "LIST VALUES: " << endl;
        for (unsigned int i = 0; i < size_l; i++)
        {
            cout<< aux->getWord() << endl;
            aux = aux->getNext();
        }
    }

}

Node* List::getHead() {
    return head;
}

int List::getSize() {
    return size_l;
}

class NotFoundNode {

  private:
    string word;
    int column;
    int row;
    NotFoundNode *next;

  public:
    NotFoundNode(string w, int col, int r);
    string getWord(void);
    int getCol(void);
    int getRow(void);
    void setWord(string w);
    void setNext(NotFoundNode *n);
    NotFoundNode* getNext(void);

};

NotFoundNode::NotFoundNode(string w, int col, int r) {

    word = w;
    column = col;
    row = r;
    next = NULL;
}

string NotFoundNode::getWord(void) {
    return word;
}

int NotFoundNode::getCol(void) {
    return column;
}

int NotFoundNode::getRow(void) {
    return row;
}

void NotFoundNode::setWord(string w) {
    word = w;
}

void NotFoundNode::setNext(NotFoundNode *n) {
    next = n;
}

NotFoundNode* NotFoundNode::getNext(void) {
    return next;
}

class NotFoundList {

  private:
    int size_l;
    NotFoundNode *head;
    NotFoundNode *tail;

  public:
    NotFoundList();
    ~NotFoundList(){}
    void append(string word, int col, int row);
    string print(void);
    int getSize();
    NotFoundNode* getHead();

};

NotFoundList::NotFoundList() {
    size_l = 0;
    head = NULL;
    tail = NULL;
}


void NotFoundList::append(string word, int col, int row) {

    NotFoundNode *aux = new NotFoundNode(word, col, row);

    if (head == NULL) {

        head = tail = aux;
    }else {
        tail->setNext(aux);
        tail = aux;
    }

    size_l++;
}

string NotFoundList::print(void) {

    stringstream ss;
    string s;
    NotFoundNode *aux = head;

    if (head == NULL)
    {
        cout << endl;
        cout << "Todas as palavras estao corretas! " << endl;
        ss << "Todas as palavras estao corretas!";

    }  else {
        cout << endl;
        cout << "Linha - Coluna : Palavra " << endl;
        cout << "-------------------------------------" << endl;
        ss << "Linha - Coluna : Palavra " << endl;
        ss << "-------------------------------------" << endl;

        for (unsigned int i = 0; i < size_l; i++) {

            cout << aux->getRow() << " - " << aux->getCol() << " : " << aux->getWord() << endl;
            ss << aux->getRow(); ss << " - " ; ss << aux->getCol(); ss << " : " ; ss << aux->getWord() << endl;
            aux = aux->getNext();
        }
    }

    s = ss.str();

    return s;
}

NotFoundNode* NotFoundList::getHead() {
    return head;
}

int NotFoundList::getSize() {
    return size_l;
}

class TimeNode {

  private:
    double time;
    TimeNode *next;

  public:
    TimeNode(double t);
    double getTime(void);
    void setTime(double t);
    void setNext(TimeNode *n);
    TimeNode* getNext(void);

};

TimeNode::TimeNode(double t) {
    time = t;
    next = NULL;
}

double TimeNode::getTime(void) {
    return time;
}

void TimeNode::setTime(double t) {
    time = t;
}

void TimeNode::setNext(TimeNode *n) {
    next = n;
}

TimeNode* TimeNode::getNext(void) {
    return next;
}


class TimeList {

  private:
    int size_l;
    TimeNode *head;
    TimeNode *tail;

  public:
    TimeList();
    ~TimeList();
    void append(double time);
    void print(void);
    double totalTime(void);
    int getSize();
    TimeNode* getHead();

};

TimeList::TimeList() {
    size_l = 0;
    head = NULL;
    tail = NULL;
}

TimeList::~TimeList() {
    delete [] head;
}

void TimeList::append(double time)
{
    TimeNode *aux = new TimeNode(time);
    aux->setNext(NULL);

    if (head == NULL)
    {
        head = tail = aux;
    }else
    {
        tail->setNext(aux);
        tail = aux;
    }

    size_l++;
}

void TimeList::print(void) {
    TimeNode *aux = head;

    if (head == NULL) {
        cout<< "EMPTY LIST! " << endl;

    }else {
        cout<< "LIST VALUES: " << endl;

        for (unsigned int i = 0; i < size_l; i++) {

            cout << aux->getTime() << endl;
            aux = aux->getNext();
            cout << "LIST SIZE: " << size_l << endl;
        }
    }
}

double TimeList::totalTime(void) {

    TimeNode *aux = head;
    double time = 0;

    if (head) {

        for (unsigned int i = 0; i < size_l; i++) {

            time += aux->getTime();
            aux = aux->getNext();
        }
    }

    return time;
}

TimeNode* TimeList::getHead() {
    return head;
}

int TimeList::getSize() {
    return size_l;
}

class HashTable {

  private:
    List* hash_array[HASH_TABLE_SIZE];
    int computeHash (string word);
    int collisions_number[HASH_TABLE_SIZE];

  public:
    HashTable();
    void insertPlate (string word);
    bool consulting (string name);
    void printHashArray ();
    void collisionsMedia();

};

HashTable::HashTable() {

    for (unsigned int x = 0; x < HASH_TABLE_SIZE; x++) {this->hash_array[x] = NULL;}
}

/* FUNÇÃO DE HASH 1 */
 /*int HashTable::computeHash(string word) {

    unsigned long k = 0;

    unsigned int b = 378551;
    unsigned int a = 63689;

    for (unsigned int x = 0; x < word.size(); x++) {
            k = (k * a) + word[x];
            a = a * b;
    }

    return k & 0x7FFFFFFF;
}*/

 /*FUNÇÃO DE HASH 2 */
/*int HashTable::computeHash(string word) {

    unsigned long k = 0;

    for (unsigned int x = 0; x < word.size(); x++) {
           k = ((word[x]*33+x+k*31)/23);
    }

    return k;
}*/

/* FUNÇÃO DE HASH 3 */
int HashTable::computeHash(string word) {  // Computa o hash.

    unsigned long k = 0;

    for(unsigned int i = 0; i < word.size();  i++)
     k = (37*k+word[i])*7/33+k;

    return k;
}

void HashTable::insertPlate(string word) {

    int hash_value;
    int compressed_hash_value;

    hash_value = this->computeHash(word);
    compressed_hash_value = hash_value % HASH_TABLE_SIZE;

    if (this->hash_array[compressed_hash_value] == NULL) {

        this->hash_array[compressed_hash_value] = new List;
        this->hash_array[compressed_hash_value]->append(word);

    } else {

        List* l = this->hash_array[compressed_hash_value];
        l->append(word);
    }
}

void HashTable::collisionsMedia() {

    double aux = 0, j = 0;
    int biggest = 0;

    for (unsigned int x = 0; x < HASH_TABLE_SIZE; x++) {collisions_number[x] = 0;}

    for(unsigned int x = 0; x < HASH_TABLE_SIZE; x++) {

        if (hash_array[x] != NULL && (hash_array[x]->getSize() > 1)) {
           collisions_number[x] = hash_array[x]->getSize() - 1;
        }
    }

    for (unsigned int x = 0; x < HASH_TABLE_SIZE; x++) {

            if (collisions_number[x]!=0) {
                aux += collisions_number[x];
                j++;
            }
    }

    for (unsigned int x = 0; x < HASH_TABLE_SIZE; x++) {

        if (biggest < collisions_number[x]) {
            biggest = collisions_number[x];
        }
    }
    cout << endl;
    cout << "Maior numero de colisoes em um unico bucket: " << biggest << endl;
    cout << "Total de buckets que possuem colisoes: " << (int)j << endl;
    cout << "Total de colisoes: " << (int)aux << endl;
    double media = aux / j;
    cout << "Media de colisoes por bucket: " << media << endl;

}

bool HashTable::consulting(string name) {

    int hash_value;
    int compressed_hash_consulting_value;
    bool word_found = false;
    stringstream a;

    hash_value = this->computeHash(name);
    compressed_hash_consulting_value = hash_value % HASH_TABLE_SIZE;

        if (hash_array[compressed_hash_consulting_value]) {

            Node* aux = this->hash_array[compressed_hash_consulting_value]->getHead();

            for (unsigned int i = 0; i < hash_array[compressed_hash_consulting_value]->getSize(); i++) {

                if (aux->getWord() == name) {
                    word_found = true;
                    i = hash_array[compressed_hash_consulting_value]->getSize();

                } else {
                    aux = aux->getNext();
                }
            }

        }
    return word_found;
}
string toLower(string word) {

  locale loc;
  string lower_string;

  for (string::size_type i = 0; i < word.length(); i++)
    lower_string += tolower(word[i],loc);

  return lower_string;
}

void inputDic(HashTable* h) {

    ifstream fdictionary;
    char dictionary[100];

    cout << "------------ S P E L L  C H E C K E R ------------" << endl;
    cout << endl;
    cout << "Digite o nome do dicionario : ";
    gets(dictionary);

	fdictionary.open(dictionary);

	string word;
	int counting = 0;

	while(!fdictionary.eof()) {

		fdictionary >> word;
		word = toLower(word);
		h->insertPlate(word);
		counting++;
	}
    cout << endl;
	cout << counting << " palavras processadas!" << endl;
    cout << endl;

	fdictionary.close();
}

void outputFile(string s, string s1){

    ofstream outFile ("spellCheckerResultado.txt");
    outFile << s1 << endl;
    outFile << s << endl;

    outFile.close();
}
void process(HashTable h) {

    stringstream ss;
    string s,s1;

    FILE* inFile;
    char input[100];

    cout << "Digite o nome do arquivo de input/texto: ";
    gets(input);


	inFile = fopen (input, "r");

	char c;
	char word[100];
	string name;
	int counter = 0;
	char last_character;

	int column = 1;
	int row = 1;

	double partial_process_time = 0;
	TimeList time;
	double total;

	NotFoundList notfound_l;

	while ((c = fgetc(inFile)) != EOF) {


        if(((int)c>=58 && (int)c<=64)||((int)c>=32 && (int)c<=38)||     // : ; < = > ? @    ||   espcaço ! "  # $  % &
            ((int)c>=40 && (int)c<=44)||((int)c>=46 && int(c<=47) || c=='\n')){    // ( ) * + ,    ||     . /

            if(((int)last_character>=65 && (int)last_character<=90)||((int)last_character>=97 && (int)last_character<=122)){    // Todas as letras, maiúsculas ou minúsculas

                for (unsigned int x = 0; x < counter; x++) {

                    name += word[x];
                }

                name = toLower(name);


                auto t1 = chrono::high_resolution_clock::now();
                bool response = h.consulting(name);
                auto t2 = chrono::high_resolution_clock::now();
                partial_process_time = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();

                time.append(partial_process_time);


                if (!response) {notfound_l.append(name, column, row);}

                counter = 0;
                last_character = c;
                name.clear();

                if (c == '\n') {
                    column = 1; row++;
                }  else {
                    column++;
                }

           }  else {

                last_character = c;
                if (c == '\n') {
                    column = 1; row++;
                }
                continue;
              }


        } else {

            word[counter] = c;
            last_character = c;
            counter++;

        }

    }

    total = time.totalTime();
    cout << endl;
    cout << "Numero total de palavras do texto: " << time.getSize() << endl;
    cout.precision(3);
    cout << "Tempo de verificacao: " << fixed << total << " microssegundos" << endl;
    cout << "Numero de palavras que falharam no spell check: " << notfound_l.getSize() << endl;
    cout << "Lista de palavras que falharam no spell check: " << endl;

    ss << "Numero total de palavras do texto: " << time.getSize() << endl;
    ss << "Tempo de verificacao: " << fixed << total << " microssegundos" << endl;
    ss << "Numero de palavras que falharam no spell check: " << notfound_l.getSize() << endl;
    ss << "Lista de palavras que falharam no spell check: " << endl;
    s = notfound_l.print();

    s1 = ss.str();
    outputFile(s,s1);

    h.collisionsMedia();
}


int main () {

    HashTable h;
    inputDic(&h);
    process(h);

 return 0;
}
