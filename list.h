
typedef struct Element{
  char letter;
  int occurence;
  struct Element* next;
}Element;

Element* createElement(char letter);
void addElement(Element** list, Element* element);
void displayList(Element* list);
