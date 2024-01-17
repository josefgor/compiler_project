#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"
#include "errorr.h"

/*need to define a global variables(not here.)*/
Node* symbols_table = NULL;
Node_mcr* table_mcr = NULL;
int dc;
int ic;

/*The function adds a node and checks if there is a node already
defined in the list and if so the last node in the list will point
to the node that I receive as a parameter, if not then the node that
I received as a parameter will be the first node in the list*/
void add_node(Node* new_node)
{
    Node* temp_node = NULL;
    if(symbols_table == NULL) {
        symbols_table = new_node;
    }

    temp_node = symbols_table;
    while (symbols_table->next != NULL) {
        temp_node = temp_node->next;
    }
    temp_node->next = new_node;
}

/*The function updates the symbol values according to the symbol attributes in this case its data*/
int insert_label_to_symbol_table(char *label, int hasDot, int line_number)
{
    if(similar_label(label,line_number));
    Node *new_node = (Node*) malloc(sizeof(Node));/*free the malloc*/
    if (!new_node)
    {
        return FAIL;
    }
    new_node->label = label;
    new_node->attr =  hasDot ? data_attr : code_attr;
    new_node->val = dc;
    add_node(new_node);
    return SUCCESS;
}

int insert_to_table(char *label,int hasDot, int line_number)
{
    return insert_label_to_symbol_table(label, hasDot, line_number);
    // return insert_label_to_symbol_table_as_code(label);
}


int insert_label_to_symbol_table_as_mdefine(char *label, int val)
{
    Node *new_node = (Node*) malloc(sizeof(Node));/*free the malloc*/
    if (!new_node)
    {
        return FAIL;
    }
    new_node->label = label;
    new_node->attr = mdefine_attr;
    new_node->val = val;
    add_node(new_node);
    return SUCCESS;
}

/*The function brings me a node according to the label name*/
Node * get_symbol(char * label)
{
    if(symbols_table == NULL) {
        return NULL;
    }
    Node *temp = symbols_table;
    while (temp->label != label) {
        if(temp->next == NULL) {
            return NULL;
        }
        temp = temp->next;
    }
    return temp;
}

void add_node_table_macro (Node_mcr *new_node)
{
    Node_mcr* temp_node = NULL;
    if(table_mcr == NULL) {/*when the list empty its true*/
        table_mcr = new_node;
    }
    else {
        temp_node = table_mcr;
        while (symbols_table->next != NULL) {
            temp_node = temp_node->next;
        }
        temp_node->next = new_node;
    }
}

void insert_macro_to_table (char *macro_name, char *command_mcr)
{
    Node_mcr * new_node = (Node_mcr *)malloc(sizeof(Node_mcr));
    if(!new_node) {
        // error unable to allocate memory(802)
    }
    new_node->macro_name = macro_name;
    new_node->command_mcr = command_mcr;
    add_node_table_macro(new_node);
}

// int macro_in_table(char *macro_name_cmp)
// {
//     if(get_macro != NULL){
//         return 0;
//     }
//     return 1;
// }

Node_mcr * get_macro(char *macro_name_cmp)
{
    if(table_mcr == NULL){
        return NULL;
    }
    Node_mcr *temp_mcr = table_mcr;
    while(temp_mcr->macro_name != macro_name_cmp) {
        if(temp_mcr->next == NULL) {
            return NULL;
        }
        temp_mcr = temp_mcr->next;
    }
    return temp_mcr;
}

int similar_label(char * label,int line_number)
{
    if(get_symbol(label) != NULL){
        /*error symbol allready exist*/
        return 1;
    }
    return 0;
}