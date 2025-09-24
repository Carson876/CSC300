#include "sqll.h"

//======================= STACK ===========================

Stack::Stack()
{
    top = nullptr; 
}

Stack::~Stack() 
{
    while (!isEmpty()) 
    {
        pop();
    }
}

void Stack::push(string& value) 
{
    node* newNode = new node(value);
    newNode->next = top;
    top = newNode;
}
string Stack::pop() 
{
     if (isEmpty())
    {
        throw runtime_error("Stack underflow");
    }
    node* temp = top;
    string out = temp->data;
    top = top->next;
    delete temp;
    return out;
}

string Stack::peek() 
{
    if (isEmpty()) 
    {
        throw runtime_error("Stack is empty");
    }

    return top->data;  
}

bool Stack::isEmpty() 
{
    return top == nullptr;
}

void Stack::display()
{
    node* current = top;
    cout << "Stack: ";
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

//======================= QUEUE ===========================

Queue::Queue()
{
    front = nullptr;
    rear = nullptr; 
}

Queue::~Queue() 
{
    while (!isEmpty()) 
    {
        dequeue();
    }
}

void Queue::enqueue(string& value) 
{
    node* newNode = new node(value);
    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    } 
}

string Queue::dequeue() 
{
     if (isEmpty())
    {
        throw runtime_error("Queue underflow");
    }
    node* temp = front;
    string out = temp->data;
    front = front->next;
    if (front == nullptr) rear = nullptr; // queue became empty
    delete temp;
    return out;
}

bool Queue::isEmpty() 
{
    return front == nullptr;
}

void Queue::display()
{
    node* current = front;
    cout << "Queue: ";
    
    while (current != nullptr) 
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
//======================= DIJKSTRA'S TWO STACK ===========================
double evaluateExpression(string& expr) 
{ 
    Stack ops;   
    Stack vals;  

    auto isOp = [](char c) {
        return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
    };

    auto apply = [&](const string& op, double a, double b) -> double {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") return a / b;
        if (op == "^") return pow(a, b);
        throw runtime_error("Unknown operator: " + op);
    };

    for (size_t i = 0; i < expr.size(); )
    {
        if (isspace(static_cast<unsigned char>(expr[i])))
        {
            ++i;
            continue;
        }

        if (expr[i] == '(')
        {
            ++i;
        }
        else if (isOp(expr[i]))
        {
            string op(1, expr[i]);
            ops.push(op); 
            ++i;
        }
        else if (expr[i] == ')')
        {
            string op = ops.pop();
            double vb = stod(vals.pop());
            double va = stod(vals.pop());
            double vr = apply(op, va, vb);
            string res = to_string(vr);
            vals.push(res);
            ++i;
        }
        else
        {
            size_t j = i;
            bool dotSeen = false;
            if ((expr[j] == '+' || expr[j] == '-') && j+1 < expr.size() && isdigit(static_cast<unsigned char>(expr[j+1])))
                ++j;

            while (j < expr.size() && (isdigit(static_cast<unsigned char>(expr[j])) || expr[j]=='.'))
            {
                if (expr[j]=='.')
                {
                    if (dotSeen) break;
                    dotSeen = true;
                }
                ++j;
            }
            if (j == i) throw runtime_error("Invalid token at position " + to_string(i));
            string num = expr.substr(i, j - i);
            vals.push(num);
            i = j;
        }
    }

    if (!ops.isEmpty())
    {
       
        while (!ops.isEmpty())
        {
            string op = ops.pop();
            double vb = stod(vals.pop());
            double va = stod(vals.pop());
            double vr = (op=="+")?va+vb:(op=="-")?va-vb:(op=="*")?va*vb:(op=="/")?va/vb:pow(va,vb);
            string res = to_string(vr);
            vals.push(res);
        }
    }

    return stod(vals.pop());
}

// ============= JOSEPHUS PROBLEM ===========================
void josephus(int n, int k) 
{
 if (n <= 0 || k <= 0)
        throw runtime_error("n and k must be positive");

    Queue q;
    for (int i = 1; i <= n; ++i)
    {
        string s = to_string(i);
        q.enqueue(s);
    }

    cout << "Elimination order: ";
    int alive = n;

    while (alive > 1)
    {
        // Move k-1 people from front to rear
        for (int r = 1; r < k; ++r)
        {
            string x = q.dequeue();
            q.enqueue(x);
        }

        // Remove the k-th person
        string eliminated = q.dequeue();
        cout << eliminated << (alive > 2 ? " " : "");
        --alive;
    }

    // Last remaining is the survivor
    string survivor = q.dequeue();
    cout << "\nSurvivor: " << survivor << endl;
}