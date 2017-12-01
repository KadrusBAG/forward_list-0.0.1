#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct node{
    int val;
    node * next;
};

void add(node * & head){
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
    int value;
    stream >> value;
    node * time = new node;
    time->val = value;
    time->next = nullptr;
    if(head == NULL){
        head = time;
    }
    else{
        node * last = head;
        while(last->next){
            last = last->next;
        }
        last->next = time;
    }
}

void sub(node * & head){
    node * time = head;
    head = head->next;
    delete time;
}

void reverse(node * & head){
    node * new_head = nullptr;
	for (node * node = head; node; )
	{
		node * node_next = node->next;
		node->next = new_head;
		new_head = node;
		node = node_next;
	}
	head = new_head;
}

void output(node * head){
    node * time;
	time = head;
	while (time != NULL){
		cout << "+---+" << "    ";
		time = time->next;
	}
	time = head;
	cout << endl;
	while (time != NULL){
		cout << "| " << time->val << " |";
		time = time->next;
		if (time != NULL){
			cout << "--->";
		}
	}
	time = head;
	cout << endl;
	while (time != NULL){ 
		cout << "+---+" << "    ";
		time = time->next;
	}
	cout << endl;
}

int main(){
    node * head = new node;
    head = nullptr;
    char op;
    while(cin >> op){
        if(op == '+'){
            add(head);
        }
        if(op == '-'){
            sub(head);
        }
        if(op == '/'){
            reverse(head);
        }
        if(op == '='){
            output(head);
        }
        if(op == 'q'){
            break;
        }
    }
}
