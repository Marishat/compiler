#include <iostream>
#include <string.h>
using namespace std; 

int children_counter[50];

int main() {
    int syntax_tree_root, start_variable, top_rule, left_variable;
    int input_token_index, statement_index;
    string input_token;
    char statement[7];

    char grammar_rules[6][11] = {"A->BCDEDF.", "B->i.", "C->=.", "D->i.", "E->+.", "F->i."};

    char variable_replacer[50];
    char syntax_tree[50];

    int var_replacer_looper;
    for (var_replacer_looper = 0; var_replacer_looper < 50; var_replacer_looper++) {
        syntax_tree[var_replacer_looper] = '.';
        variable_replacer[var_replacer_looper] = '.';
    }

    cout << "Enter the input token:";
    cin >> input_token;
    
    cout << "Tokens:\n";
    for (int i = 0; i < input_token.length(); i++) {
    cout << input_token[i] << "\n";
    }


    statement_index = 0;
    for (input_token_index = 0; input_token_index < input_token.length(); input_token_index++) {
        if (input_token[input_token_index] == '<') {
            statement[statement_index] = input_token[input_token_index + 1];
            cout << statement[statement_index] << "\n";
            statement_index++;
        }
    }

    syntax_tree_root = 0;
    start_variable = 0;
    top_rule = 0;
    left_variable = 0;

    syntax_tree[syntax_tree_root] = grammar_rules[top_rule][left_variable];
    cout << syntax_tree[syntax_tree_root] << "\n";

    variable_replacer[start_variable] = grammar_rules[top_rule][left_variable];
    cout << variable_replacer[start_variable] << "\n";

    int variable_replacer_current_index = 0;
    int syntax_tree_current_index = 1;
    int statement_matcher_index = 0;
    int current_parent = 0;
    int last_index = 0;
    int syntax_error_break = 0;

    int iteration = 1;

    while (true) {
        cout << "\nIteration: " << iteration;
        cout << "\n****\n";
        cout << "Variable Replacer Current Index: " << variable_replacer_current_index;
        cout << "\nCurrent Parent: " << current_parent;
        cout << "\nSyntax Tree Current Index: " << syntax_tree_current_index << "\n";

        int grammar_rule_number, rule_right_side_copier_index, copy_flag;
        for (grammar_rule_number = 0; grammar_rule_number < 6; grammar_rule_number++) {
            if (grammar_rules[grammar_rule_number][left_variable] == variable_replacer[variable_replacer_current_index]) {
                copy_flag = 0;
                for (rule_right_side_copier_index = 0; grammar_rules[grammar_rule_number][rule_right_side_copier_index] != '.'; rule_right_side_copier_index++) {
                    if (grammar_rules[grammar_rule_number][rule_right_side_copier_index] == '>') {
                        copy_flag = 1;
                        continue;
                    }
                    if (copy_flag == 1) {
                        children_counter[current_parent]++;
                        syntax_tree[syntax_tree_current_index++] = grammar_rules[grammar_rule_number][rule_right_side_copier_index];
                        variable_replacer[variable_replacer_current_index] = grammar_rules[grammar_rule_number][rule_right_side_copier_index];
                        if (variable_replacer[variable_replacer_current_index] == 'i' || variable_replacer[variable_replacer_current_index] == '=' || variable_replacer[variable_replacer_current_index] == '+' || variable_replacer[variable_replacer_current_index] == ';') {
                            if (variable_replacer[variable_replacer_current_index] == statement[statement_matcher_index]) {
                                cout << "No Syntax Error So Far\n";
                                statement_matcher_index++;
                            } else {
                                cout << "Syntax Error in " << statement[statement_matcher_index] << "\n";
                                syntax_error_break = 1;
                                break;
                            }
                        }
                        variable_replacer_current_index++;
                    }
                }
                if (copy_flag == 1 || syntax_error_break == 1) break;
            }
        }

        if (syntax_error_break == 1) break;

        variable_replacer_current_index = last_index;
        for (int variable_replacer_traverser = last_index; variable_replacer_traverser < 50; variable_replacer_traverser++) {
            if (variable_replacer[variable_replacer_traverser] == 'i' || variable_replacer[variable_replacer_traverser] == '=' || variable_replacer[variable_replacer_traverser] == '+' || variable_replacer[variable_replacer_traverser] == ';') {
                last_index++;
                variable_replacer_current_index = last_index;
            }
            if (variable_replacer[variable_replacer_traverser] != 'i' && variable_replacer[variable_replacer_traverser] != '=' && variable_replacer[variable_replacer_traverser] != '+' && variable_replacer[variable_replacer_traverser] != ';') break;
        }

        current_parent++;

        int m, break_flag = 1;
        for (m = 0; variable_replacer[m] != '.'; m++) {
            if (variable_replacer[m] != 'i' && variable_replacer[m] != '=' && variable_replacer[m] != '+' && variable_replacer[m] != ';') break_flag = 0;
        }

        if (break_flag == 1) break;
        iteration++;
    }

    cout << "\nSyntax Tree:\n";
    for (int loop_counter = 0; loop_counter < 50; loop_counter++) {
        cout << syntax_tree[loop_counter] << "\n";
    }

    cout << "Variable Replacer:\n";
    for (int loop_counter = 0; loop_counter < 50; loop_counter++) {
        cout << variable_replacer[loop_counter] << "\n";
    }

    cout << "Children Counter:\n";
    for (int loop_counter = 0; loop_counter < 50; loop_counter++) {
        cout << children_counter[loop_counter] << "\n";
    }

    return 0;
}