#ifndef NODE_H
#define NODE_H

#define SUCCESS 1
#define FAIL 0



enum Symbol_attr {code_attr,data_attr,mdefine_attr};

struct node;

struct node{
    char* label;
    enum Symbol_attr attr;
    int val;
    struct node *next;
};

struct node_mcr;

struct node_mcr{
    char *macro_name;
    char *command_mcr;
    struct node_mcr *next;
};

typedef struct node Node;

typedef struct node_mcr Node_mcr;


void add_node(Node* new_node);
int insert_label_to_symbol_table(char *label, int hasDot, int line_number);
int insert_to_table(char *label,int hasDot, int line_number);
int insert_label_to_symbol_table_as_mdefine(char *label, int val);
Node * get_symbol(char * label);
void add_node_table_macro (Node_mcr *new_node);
void insert_macro_to_table (char *macro_name, char *command_mcr);
Node_mcr * get_macro(char *macro_name_cmp);
int similar_label(char * label,int line_number);



#endif
