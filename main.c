// Mumen Anbar
// 1212297
// S3

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct snode* Stack;
typedef struct node* List;

struct node{    // the struct of each node of the numbers
    // data members
    char Data;
    struct node *Next;  // pointer points to the next node if exists
    struct node *Pre;   // pointer points to the previous node if exists
};

struct snode{    // the struct of each node of the numbers
    // data members
    char c;
    int num;
    Stack Next;  // pointer points to the next node if exists
};

typedef struct MainNode{    // the struct of each node of the Main Linked List
    // Data Members
    int ID;
    struct node *ptrNum;    // pointer to point to node of type List
    struct MainNode *Next; // pointer to next node
    struct MainNode *Pre;   // pointer to next node
}MainNode;

void InsertToMain(struct MainNode* Head, struct node* CurNum, int id){ // insert to the main list(2d list)
    struct MainNode* temp = (struct MainNode*)malloc(sizeof(struct MainNode));
    temp->Next = Head->Next; // connect the new one with second node after head
    temp->ID = id;
    temp->ptrNum = CurNum;   //  connect the big list to the small one(2d)
    temp->Next = NULL;  // ensure to have last element points to null
    while(Head->Next != NULL) Head = Head->Next; // iterate over the big list to get last node
    temp->Pre = Head;   // point the prev of new one to the head
    Head->Next = temp;  // connect head to new one by next ptr
}

void insert(char x, List Head){ // function to insert a node to the front of the list
    List temp = (struct node*)malloc(sizeof(struct node)); // allocating a space for the new node
    temp->Next = Head->Next;  // connect the new node to the next node of the head
    Head->Next = temp;  // connect the head to the new node
    temp->Pre = Head;   // connect the new node to the head by previous pointer
    temp->Data = x;     // give the node a value
    if(temp->Next != NULL) temp->Next->Pre = temp;  // connect the next node of the head as the previous of it is the new one
}

struct node* SetList(){ // reinitialize the list
    List L = (struct node*)malloc(sizeof(struct node)); // creating a list
    if(L == NULL) printf("Out of memory!\n"); // if there is no space in memory
    L->Next = NULL; // initialize
    L->Pre = NULL;  // initialize
    return L;   // return the new list
}

bool IsEmpty(Stack s){ // check if the stack is empty or not
    return (s->Next == NULL); // if it points to null then it's empty
}
int GetSize(struct node* cur){ // get the length of the number
    int cnt = 0;
    while(cur->Next != NULL) { // iterate over the list to get length
        cnt++;
        cur = cur->Next; // (increment)
    }
    return cnt;
}
void Delete(struct node* s){ // delete a list
    MakeEmpty(s);
    free(s);    // remove it from the memory
}
bool IsOpening(char c){ // check if the char is closing char(reversed)
    return (c == ')' || c == ']' || c == '}');
}

bool IsClosing(char c){ // check if the char is opening char(reversed)
    return (c == '(' || c == '[' || c == '{');
}

bool IsOperator(char c){ // check if the char is operator char
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool IsSign(char c){    // check if the char is sign char + or -
    return (c == '+' || c == '-');
}

bool IsDigit(char c){ // check if the char is digit char
    for(char x = '0';x <= '9'; x++){
        if(x == c) return 1;
    }
    return 0;
}

void Pop(Stack s){ // delete last element of the stack
    Stack tmp;
    if(s->Next == NULL) printf("Out of Memorey!");
    else{
        tmp = s->Next; // target to delete
        s->Next = s->Next->Next;    // skip the target
        free(tmp);// delete it from memory
    }
}
char Top(Stack s){  // get last element in stack
    if(!IsEmpty(s)) return s->Next->c; // return last one (char)
    return 0;
}

int TopInt(Stack s){ // same as before but for integers
    if(!IsEmpty(s)) return s->Next->num;
    printf("\nEmpty!!!\n");
    return 0;
}
void MakeEmpty(Stack s){ // empty an stack
    if(s == NULL) printf("Out of Memorey!");
    else{
        while(!IsEmpty(s)) Pop(s); // delete all elements in the stack
    }
}
Stack CreateStack(){ // create and initialize the stack
    Stack s = (Stack)malloc(sizeof(struct snode));  // have a space in memory
    if(s == NULL) printf("Out of Memorey!"); // if memo is full
    s->Next = NULL; // the new head of stack
    MakeEmpty(s);   // clear it if it has data in the stack
    return s; // return the pointer of the stack
}
void Push(Stack s, int x, char sym){ // add element to top of the stack
    // it is the same as inserting in the listttt
    Stack temp = (struct snode*)malloc(sizeof(struct snode));
    if(temp == NULL) printf("Out of space!");
    else{
        temp->num = x;
        temp->c = sym;
        temp->Next = s->Next;
        s->Next = temp;
    }
}

bool IsValidNoPrint(List L){ // method to find if the exp is valid or not
    Stack test = CreateStack(); // creating a stack
    while(L->Next != NULL) {
        L = L->Next;
        char a = L->Data; // current char
        if(IsOperator(a)){ // if a is operator
            if(L->Pre->Pre == NULL && !IsSign(a)){ // if it has no later digits and it's not a sign ex: -5, +5
                return 0;
            }
            if(IsClosing(L->Next->Data)) { // if it's next opening bracket (5 + _)
                return 0;
            }
            if(IsOpening(L->Pre->Data)) { // if it's pre opening bracket (5 + _)
                return 0;
            }
        }
        else if(IsDigit(a)){ // if it's a digit
            if(L->Next != NULL && IsOpening(L->Next->Data)){ //  (1 + 2)_3 no operant between ) and 3
                return 0;
            }
            if(L->Pre->Pre != NULL && IsClosing(L->Pre->Data)) { // same as above but 1_(2 + 3)
                return 0;
            }
        }
        if(IsOpening(a)) Push(test, 0, a); // if it's opening [({ reversed push to the stack
        else if(IsClosing(a)){ // it it's closing )}] reversed
            if(test->Next == NULL) return 0; // if it has no closing (opening reversed) in the stack
            if(a == '('){  // the opening is (
                if(test->Next->c != ')'){ // must the closing be ) in the top of stack
                    return 0;
                }
            }
            else if(a == '{'){  // the opening is {
                if(test->Next->c != '}'){ // must the closing be ) in the top of stack
                    return 0;
                }
            }
            else{   // the opening is [
                if(test->Next->c != ']') { // must the closing be ) in the top of stack
                    return 0;
                }
            }
            Pop(test); // pop the top (opening)
        }
    }
    return (test->Next == NULL); // return false if it has more brackets not closed
}
 // this function is the same as prev but with printing on screen
bool IsValid(List L, int cnt, char X){
    Stack test = CreateStack();
    while(L->Next != NULL) {
        L = L->Next;
        char a = L->Data;
        if(L->Next == NULL && IsSign(a)) continue;
        if(IsOperator(a)){
            if(L->Pre->Pre == NULL && !IsSign(a)){
                printf("%c. ", X);
                printf("Equation No. %d -> Invalid: There Is No Digit After %c.\n", cnt, a);
                return 0;
            }
            if(IsClosing(L->Next->Data)) {
                printf("%c. ", X);
                printf("Equation No. %d -> Invalid: There Is No Digit between %c And %c.\n", cnt, a, L->Next->Data);
                return 0;
            }
            if(IsOpening(L->Pre->Data)) {
                printf("%c. ", X);
                printf("Equation No. %d -> Invalid: There Is No Digit between %c And %c.\n", cnt, a, L->Pre->Data);
                return 0;
            }
        }
        else if(IsDigit(a)){
            if(L->Next != NULL && IsOpening(L->Next->Data)){
                printf("%c. ", X);
                printf("Equation No. %d -> Invalid: There Is No Operator between %c And %c.\n", cnt, a, L->Next->Data);
                return 0;
            }
            if(L->Pre->Pre != NULL && IsClosing(L->Pre->Data)) {
                printf("%c. ", X);
                printf("Equation No. %d -> Invalid: There Is No Operator between %c And %c.\n", cnt, a, L->Pre->Data);
                return 0;
            }
        }
        if(IsOpening(a)) Push(test, 0, a);
        else if(IsClosing(a)){
            if(test->Next == NULL) return 0;
            if(a == '('){
                if(test->Next->c != ')'){
                    printf("%c. ", X);
                    printf("Equation No. %d -> Invalid: ( is not closed.\n", cnt);
                    return 0;
                }
            }
            else if(a == '{'){
                if(test->Next->c != '}'){
                    printf("%c. ", X);
                    printf("Equation No. %d -> Invalid: { is not closed.\n", cnt);
                    return 0;
                }
            }
            else{
                if(test->Next->c != ']') {
                    printf("%c. ", X);
                    printf("Equation No. %d -> Invalid: [ is not closed.\n", cnt);
                    return 0;
                }
            }
            Pop(test);
        }
    }
    if(test->Next != NULL){
        printf("%c. ", X);
        printf("Equation No. %d -> Invalid: Extra Operator In The End.\n", cnt);
        return 0;
    }
    return (test->Next == NULL);
}

int getValue(char c){ // assign value for each operant for precedence
    if(c == '-' || c == '+') return 0;
    if(c == '*' || c == '/') return 1;
    if(c == '^') return 2;
    if(IsOpening(c)) return 3;
}

List FindPrefix(List L){ // find prefix of a list
    List ans = SetList(); // answer(prefix)

    Stack s = CreateStack();
    while(L->Next != NULL){
        L = L->Next;
        char x = L->Data; // cur char
        if(IsOpening(x)){ // if it's }])
            insert(' ', ans); // insert space
            Push(s, 0, x);  // push the bracket to the list
        }

        else if(IsOperator(x)){ // if it's +-*/
            if(IsEmpty(s)){ // if it's first operator
                insert(' ', ans);
                Push(s, 0, x); // insert it to the top of the stack
            }
            else{
                int v1 = getValue(x), v2 = getValue(Top(s)); // the value of each operant
                if(v1 >= v2 || getValue(Top(s)) == 3) { // if the new one has larger priority or it's a bracket
                    insert(' ', ans);
                    Push(s, 0, x); // insert it to the stack
                }
                else{
                    while(getValue(x) < getValue(Top(s)) && !IsEmpty(s)){ // if new one has lower priority keep deleting from it
                        insert(' ', ans);
                        insert(Top(s), ans); // insert the operant to the list
                        Pop(s); // delete from stack
                    }
                    Push(s, 0, x); // push the new operant to the stack
                }
            }
        }
        else if(IsClosing(x)){ // if  x = ({[
            while(!IsOpening(Top(s))){ // search for the nearest closing one since it's valid
                insert(' ', ans);
                insert(Top(s), ans); // insert the operant between them
                Pop(s); // delete current top
            }
            Pop(s); // delete the opening bracket
        }
        else if(IsDigit(x)) insert(x, ans); // if x is digit just insert it
    }
    while(!IsEmpty(s)){ // while the stack has more elements add them to the list and delete it
        insert(' ', ans);
        insert(Top(s), ans);
        Pop(s);
    }
    free(s);
    return ans;
}

int CalcOperation(int x1, int x2, char x){ // calculate operations of two numbers
    if(x == '+') return x1 + x2;
    if(x == '-') return x1 - x2;
    if(x == '*') return x1 * x2;
    if(x == '/') return x1 / x2;
}

int CalcEvaluation(List L){ // calc the value of the valid exp
    Stack s = CreateStack();
    while(L->Next != NULL) L = L->Next; // get last node to move reversevly
    while(L->Pre != NULL){
        if(L->Data == ' '){ // if char is space skip
            L = L->Pre;
            continue;
        }
        char x = L->Data;
        if(IsOperator(x)){
            int x1 = TopInt(s);  // get first element from stack
            Pop(s); // delete it from stack
            int x2 = TopInt(s);    // get second element from stack
            Pop(s); // delete from stack
            Push(s, CalcOperation(x1, x2, x), NULL); // push the answer of the current operation again to the stack
        }
        if(IsDigit(x)){ // if it's a digit
            Stack cur = CreateStack();
            Push(cur, (x - '0'), ' '); // convert it to int then push it to the stack
            while(IsDigit(L->Pre->Data)){ // add all the consecutive digits together as one int
                Push(cur, (L->Pre->Data - '0'), ' ');   // add to the stack
                L = L->Pre;
            }
            // next code to gather seprated chars to one int
            int N = 0;
            while(!IsEmpty(cur)){
                N *= 10; // have new digit
                N += (TopInt(cur)); // add the current char
                Pop(cur); // delete the current char
            }
            Delete(cur);
            Push(s, N, ' '); // push the last answer as integer to the main stack
        }
        L = L->Pre; // (counter)
    }
    return TopInt(s); // return the top of the stack after operations done(since it must be valid so this will always be optimal as last element)
}

void PrintListToScreen(List L, char X){ // print list to screen
    printf("%c. ", X); // printing the chars a. b. c. (I DON'T KNOW WHY WE HAVE TO DO THISSSSSSSS)
    while(L->Next != NULL){
        L = L->Next;
        printf("%c", L->Data);
    }
    printf("\n");
}

void PrintListToScreenReverse(List L, char X){ // same as prev one but in reverse mode to get the original expression
    while(L->Next != NULL) L = L->Next; // get last node
    printf("%c. ", X);
    while(L->Pre != NULL){
        printf("%c", L->Data);
        L = L->Pre;
    }
    printf("\n");
}

void PrintToFile(struct MainNode* Main, FILE* FileOut){ // print to the file
    char X = 'a';
    int cnt = 0;
    while(Main->Next != NULL){
        Main = Main->Next; // main list that has all exp
        List L = Main->ptrNum; // current exp
        fprintf(FileOut, "%c. Eq No. %d -> ", X++, ++cnt);
        while(L->Next != NULL) L = L->Next;
        // printing the details of the exp:
        printf("%c. ", X);
        while(L->Pre != NULL){
            printf("%c", L->Data);
            L = L->Pre;
        }
        if(IsValidNoPrint(Main->ptrNum)) fprintf(FileOut, " | The Equation is Valid. ");
        else fprintf(FileOut, " | The Equation is InValid. ");
        fprintf(FileOut, "The Answer Of The Eq. = %d \n\n", CalcEvaluation(Main->ptrNum));
    }
}

int main()
{   // creating a big list to have the expressions
    struct MainNode* Main = (struct MainNode*)malloc(sizeof(struct MainNode));
    Main->Next = NULL;
    Main->Pre = NULL;

    FILE* FileIn; // input file
    FILE* FileOut; // output file
    char c;
    int cnt = 0;
    int V = 0;

    while(true){ // repeat until get choice = 7;
        // showing the menu
        printf("Please Choose One Of The Following:\n");
        printf("1- Read The Input From The File.\n2- Check The Validity Of Equations.\n");
        printf("3- Convert Valid Equations From Infix To Prefix And Print The Prefix Expressions.\n");
        printf("4- Evaluate The Prefix Expressions And Print The Results Of Each Equation.\n5- Print Invalid Equations.\n");
        printf("6- Print All Equations To A File (output.txt).\n7- Exit.\n\n");
        int Choice;
        scanf("%d", &Choice); // the choice of the user
        if(Choice == 1){
            FileIn = fopen("input.txt", "r"); // inisialize the input file
            if(FileIn){
                struct node* L = SetList(L); // list contains the expression
                while (true){ // while unfinishing
                    c = getc(FileIn); // get char from the file
                    if(c != '\n' && c != EOF) insert(c, L); // if it's not new line or end of file then insert it to the list
                    else{
                        InsertToMain(Main, L, ++cnt);   // insert the current list to the main one
                        L = SetList(L); // reinisialize the list
                    }
                    if(c == EOF) break; // break if we reached the end of file
                }
            }
            printf("DONE!\n\n");
        }else if(Choice == 2){ // print the valid and invalid exp
            struct MainNode* cur = Main;
            char X = 'a'; // for printing
            while(cur->Next != NULL){
                cur = cur->Next;
                if(IsValid(cur->ptrNum, cnt + 1 - cur->ID, X)){ // check if the current list is valid or not
                    printf("%c. Equation No. %d -> Valid\n", X, cnt + 1 - cur->ID); // print details about valid exp
                }
            }
        }else if(Choice == 3){ // find prefix exp of the current
            struct MainNode* cur = Main;
            char X = 'a';
            while(cur->Next != NULL){
                cur = cur->Next;
                if(IsValidNoPrint(cur->ptrNum)){ // check if it's valid first before getting prefix
                    PrintListToScreen(FindPrefix(cur->ptrNum), X); // print to the list
                }
                X++; // the id of each
            }
        }else if(Choice == 4){ // print the answer of the valid exp
            struct MainNode* cur = Main;
            char X = 'a';
            while(cur->Next != NULL){
                cur = cur->Next;
                // if it's valid then print the value of the exp using prefix exp
                if(IsValidNoPrint(cur->ptrNum))printf("%c. Equation No. %d -> %d\n", X, cnt - cur->ID + 1 , CalcEvaluation(FindPrefix(cur->ptrNum)));
                X++;
            }
        }else if(Choice == 5){ // print the invalid eq to the screen
            struct MainNode* cur = Main;
            char X = 'a';
            while(cur->Next != NULL){
                cur = cur->Next;
                if(!IsValidNoPrint(cur->ptrNum)){ // check if it's valid or not
                    PrintListToScreenReverse(cur->ptrNum, X); // print it if it's invalid
                }
                X++;
            }
        }else if(Choice == 6){ // print the details to the output file
            FileOut = fopen("output.txt", "w"); // inisialize the output fileeee
            PrintToFile(Main, FileOut);
        }
        else break;
    }
    fclose(FileIn); // close input file
    fclose(FileOut); // close output file
    return 0; // BEST RETURN 0 IN THE WORLDDDDDDDD
}
