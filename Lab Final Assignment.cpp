#include<iostream>
#include<stack>
#include<string>
using namespace std;

//Linear Search Functions:
int LinearSearch(int a[], int x, int *step);
void Display1Array(int a[], int Asize);

//Binary Search Functions:
int binarysearch(int b[], int s, int e, int item, int *step);
void Display2Array(int b[], int Asize);

//Bubble Sort
void bubblesortA(int a[], int n);
void bubblesortD(int a[], int n);

//Stack
int MyStack[6];
int top = -1;

void push(int n);
void peek();
void pop();
int isFull();
int isEmpty();
void display();

//Queue
int q[5];
int f=0, r=0;

void enQ(int n);
void deQ();
void peekQ();
int isFullQ();
int isEmptyQ();
void displayQ();

//Expression Functions
int postfixEvaluation(string expr);
bool isOperator(char c);
int precedence(char c);
string InfixToPostfix(stack<char> s, string infix);

//Binary Search Tree function
int tree[100], maxIndex = 0;

void add(int n);
void BST(int item);
void displayT();

int main()
{
    int sw, ch, ex, Asize, res, step;
    cout << "= = = = = = = = = = = = = = = = = = =\n";
    cout << "=  1. Linear Search.                =\n";
    cout << "=  2. Binary Search.                =\n";
    cout << "=  3. Bubble Sort.                  =\n";
    cout << "=  4. Stack.                        =\n";
    cout << "=  5. Queue.                        =\n";
    cout << "=  6. Expression Programs.          =\n";
    cout << "=  7. Binary Search Tree.           =\n";
    cout << "=  0. Exit the program.             =\n";
    cout << "= = = = = = = = = = = = = = = = = = =\n";

    while(1)
    {
        cout << "Enter your choice: ";
        cin >> sw;
        switch(sw)
        {
        case 1:
        {
            int a[] = {2, 9, 3, 1, 6, 10, 15};
            Asize = sizeof(a)/sizeof(a[0]);

            Display1Array(a, Asize);

            int x;
            cout << "\nEnter an element which you want to search: ";
            cin >> x;

            step = 0;
            res = LinearSearch(a, x, &step);
            if (res == -1)
                cout << x << " is not found in the given array.\n";
            else
                cout << x << " is found at index " << res << " with " << step << " iterations." << endl;
            cout <<"\n";
            break;
        }

        case 2:
        {
            int b[] = {1, 2, 3, 6, 9, 10, 15};
            Asize = sizeof(b)/sizeof(b[0]);

            Display2Array(b, Asize);

            int item;
            cout << "\nEnter an element you would like to search: ";
            cin >> item;

            step = 0;
            res = binarysearch(b, 0, Asize-1, item, &step);
            if(res == -1)
                cout << item << " is not found in the given array.\n";
            else
                cout << item << " is found at index " << res << " with " << step << " iteration(s)." << endl;
            cout << "\n";
            break;
        }
        case 3:
        {
            cout << "=====================================\n";
            cout << "1. Ascending Order.\n";
            cout << "2. Descending Order.\n";
            cout << "0. Exit the Program.\n";
            cout << "=====================================\n";

            while(1)
            {
                cout << "\nEnter your choice: ";
                cin >> ch;
                switch(ch)
                {
                case 1:
                {
                    int n;
                    cout << "Enter array size: ";
                    cin >> n;
                    int a[n];

                    int i;
                    cout << "Enter " << n << " array elements:\n";
                    for(i = 0; i < n; i++)
                    {
                        cin >> a[i];
                    }

                    bubblesortA(a,n);

                    cout <<"Array elements after sorting:\n";
                    for(i = 0; i < n; i++)
                    {
                        cout << a[i] << "\t";
                    }
                    break;
                }
                case 2:
                {
                    int n;
                    cout << "Enter array size: ";
                    cin >> n;
                    int a[n];

                    int i;
                    cout << "Enter " << n << " array elements:\n";
                    for(i = 0; i < n; i++)
                    {
                        cin >> a[i];
                    }

                    bubblesortD(a,n);

                    cout <<"Array elements after sorting:\n";
                    for(i = 0; i < n; i++)
                    {
                        cout << a[i] << "\t";
                    }
                    break;
                }
                case 0:
                    exit(0);
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        }
        case 4:
        {
            push(10);
            push(20);
            push(30);
            push(40);
            push(50);
            push(60);
            push(70);
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            pop();
            peek();
            display();
            break;
        }
        case 5:
        {
            enQ(10);
            enQ(20);
            enQ(30);
            enQ(40);
            enQ(50);
            displayQ();
            enQ(60);
            enQ(70);
            deQ();
            displayQ();
            peekQ();
            deQ();
            displayQ();
            peekQ();
            deQ();
            displayQ();
            peekQ();
            deQ();
            displayQ();
            peekQ();
            deQ();
            displayQ();
            deQ();
            peekQ();
            break;
        }
        case 6:
        {
            cout << "=====================================\n";
            cout << "1. Infix to Postfix Conversion.\n";
            cout << "2. Postfix Expression Evaluation.\n";
            cout << "0. Exit the Program.\n";
            cout << "=====================================\n";

            while(1)
            {
                cout << "\nEnter your choice: ";
                cin >> ex;
                switch(ex)
                {
                case 1:
                {
                    string infix_exp, postfix_exp;
                    cout <<"Enter a Infix Expression : ";
                    cin >> infix_exp;
                    stack <char> stack;
                    cout << "INFIX EXPRESSION: " << infix_exp << endl;
                    postfix_exp = InfixToPostfix(stack, infix_exp);
                    cout << endl << "POSTFIX EXPRESSION: " << postfix_exp << endl;
                    break;
                }
                case 2:
                {
                    string expr;
                    cout << "Enter a postfix expression: ";
                    cin >> expr;

                    cout << "Given postfix expression: " << expr << endl;
                    cout << "Value after evaluation: " << postfixEvaluation(expr) << endl;
                    break;
                }
                case 0:
                    exit(0);
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        }
        case 7:
        {
            int c,n,item;
            cout << "=====================================\n";
            cout << " 1. Insert a tree element.\n";
            cout << " 2. Enter an element to be searched.\n";
            cout << " 3. Display all tree elements.\n";
            cout << " 0. Exit the program.\n";
            cout << "=====================================\n";

            while(1)
            {
                cout << "Enter your choice: ";
                cin >> c;
                switch(c)
                {
                case 1:
                    cout << "Enter an element which you want to insert into the tree: ";
                    cin >> n;
                    add(n);
                    break;
                case 2:
                    cout << "Item to be searched: ";
                    cin >> item;
                    BST(item);
                    break;
                case 3:
                    displayT();
                    break;
                case 0:
                    exit(0);
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            }
        }
        case 0:
            exit(0);
        default:
            cout << "Invalid choice. Please try again.\n";

        }
    }
}


//Linear Search Function Definitions:
int LinearSearch(int a[], int x, int *step)
{
    int i;
    for(i = 0; i < 7; i++)
    {
        *step = *step+1;
        if(a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void Display1Array(int a[], int Asize)
{
    int i;
    cout << "\nGiven Array Elements:\n";
    for(i = 0; i < Asize; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
}


//Binary Search Function Definitions:
int binarysearch(int b[], int s, int e, int item, int *step)
{
    while(s <= e)
    {
        *step = *step+1;
        int m = (s+e)/2;
        if(b[m] == item)
            return m;
        if(b[m] < item)
            s = m + 1;
        else
            e = m - 1;
    }
    return -1;
}

void Display2Array(int b[], int Asize)
{
    int i;
    cout << "\nDisplaying Array elements:\n";
    for(i = 0; i < Asize; i++)
    {
        cout << b[i] << "\t";
    }
    cout << endl;
}


//Bubble Sort Function Definitions:
void bubblesortA(int a[], int n)
{
    int i, j, pass = 0;
    for(i = 0; i < n-1; i++)
    {
        int flag = 0;
        for(j = 0; j < n-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        pass++;
        if(flag == 0)
        {
            break;
        }
    }
    cout << "Total pass: " << pass << endl;
}

void bubblesortD(int a[], int n)
{
    int i, j, pass = 0;
    for(i = 0; i < n-1; i++)
    {
        int flag = 0;
        for(j = 0; j < n-1-i; j++)
        {
            if(a[j] < a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        pass++;
        if(flag == 0)
        {
            break;
        }
    }
    cout << "Total pass: " << pass << endl;
}


//Stack Function Definitions:
void push(int n)
{
    if(isFull())
    {
        cout << "\nStack is full.\n";
    }
    else
    {
        cout << n << " Pushed into the stack.\n";
        MyStack[top+1] = n;
        top++;
    }
}

void pop()
{
    if(isEmpty())
    {
        cout << "\nStack is Empty.\n";
    }
    else
    {
        cout << "Popped Element: " << MyStack[top] << endl;
        top--;
    }
}

void peek()
{
    cout << "\nTopmost Element: ";
    cout << MyStack[top] << endl;
}

int isFull()
{
    if(top == 4)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void display()
{
    int i;
    cout << "\nStacked Elements are:\n";
    for(i = top; i >=0; i--)
    {
        cout << MyStack[i] << endl;
    }
}


//Queue Functions Definitions:
void enQ(int n)
{
    if(isFullQ())
        cout << "Queue is full!\n";
    else
    {
        q[r] = n;
        cout << "Insert " << n << " at rear " << r << endl;
        r++;
    }
}

int isFullQ()
{
    if(r == 5)
        return 1;
    else
        return 0;
}

void deQ()
{
    if(isEmptyQ())
        cout << "Queue is empty!\n";
    else
    {
        cout << "Delete " << q[f] << " from front " << f << endl;
        f++;
    }
}

int isEmptyQ()
{
    if(f == r)
        return 1;
    else
        return 0;
}

void peekQ()
{
    if(f == r)
        cout << "Queue is empty!\n";
    else
    {
        cout << "Front value " << q[f] << endl;
    }
}

void displayQ()
{
    if(f == r)
        cout << "Queue is empty!\n";
    else
    {
        cout << "Current elements of queue:\n";
        for(int i = r - 1; i >= f; i--)
        {
            cout << q[i] <<"\t";
        }
        cout << endl;
    }
}


//Expression Functions Definitions:
int postfixEvaluation(string expr)
{
    stack <int> s;
    int len = expr.length();

    for(int i; i < len; i++)
    {
        if(expr[i] >= '0' && expr[i] <= '9')
        {
            s.push(expr[i] - '0');
        }
        else
        {
            int v1 = s.top();
            s.pop();
            int v2 = s.top();
            s.pop();

            if(expr[i] == '+')
            {
                s.push(v2 + v1);
            }
            else if(expr[i] == '-')
            {
                s.push(v2 - v1);
            }
            else if(expr[i] == '*')
            {
                s.push(v2 * v1);
            }
            else if(expr[i] == '/')
            {
                s.push(v2 / v1);
            }
        }

    }
    return s.top();
}

bool isOperator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return true;
    else
        return false;
}

int precedence(char c)
{
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string InfixToPostfix(stack<char> s, string infix)
{
    string postfix;
    for(int i=0; i<infix.length(); i++)
    {
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix+=infix[i];
        }
        else if(infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while((s.top()!='(') && (!s.empty()))
            {
                char temp=s.top();
                postfix+=temp;
                s.pop();
            }
            if(s.top()=='(')
            {
                s.pop();
            }
        }
        else if(isOperator(infix[i]))
        {
            if(s.empty())
            {
                s.push(infix[i]);
            }
            else
            {
                if(precedence(infix[i])>precedence(s.top()))
                {
                    s.push(infix[i]);
                }
                else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^'))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while((!s.empty())&&( precedence(infix[i])<=precedence(s.top())))
                    {
                        postfix+=s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    while(!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }

    return postfix;
}


//Binary Search Tree function definitions:
void add(int n)
{
    int index = 0;
    while(1)
    {
        if(tree[index] == 0)
        {
            tree[index] = n;
            break;
        }
        else if(tree[index] < n)
        {
            index = (index + 1) * 2;
        }
        else
        {
            index = (index + 1) * 2 - 1;
        }
    }
    if(maxIndex < index)
        maxIndex = index;
}
void BST(int item)
{
    int index = 0, isFound = 0;
    while(index <= maxIndex)
    {
        //root node
        if(tree[index] == item)
        {
            isFound = 1;
            break;
        }
        //if searching item is greater than root, go right
        else if(tree[index] < item)
        {
            index = (index + 1)* 2;
        }
        //if searching item is less than root, go left
        else
        {
            index = (index + 1)*2 - 1;
        }
    }

    if(isFound == 0)
        cout << item << " is not found in the given tree.\n";
    else
        cout << item << " is found at index " << index << endl;

}

void displayT()
{
    for(int i = 0; i <= maxIndex; i++)
        cout << tree[i] << "\t";
    cout << endl;
}

