/***************************************************************************
 *   Copyright (C) 2007 by Simon Schulz   *
 *   Simon.Schulz@esa.int   *
 *                                                                         *
 ***************************************************************************/
 ///this file was automatically created by CI on Thu Jan 24 13:58:30 2008

#include "node_atc18_su01d_s.h"

//register to node factory
std::string Node_ATC18_SU01D_S::node_factory_dummy = Node_factory<Node>::register_create_function("ATC18_SU01D_S",Node_ATC18_SU01D_S::create_function);
std::string Node_ATC18_SU01D_S::node_factory_dummy2 = Node_factory<Node>::register_output("ATC18_SU01D","S");

Node_ATC18_SU01D_S::Node_ATC18_SU01D_S(const char *name) : Node(name, 3){
    port_map_vector.push_back("A"); //0
    port_map_vector.push_back("CI"); //1
    port_map_vector.push_back("B"); //2

}

Node_ATC18_SU01D_S::~Node_ATC18_SU01D_S()
{
}

std::string Node_ATC18_SU01D_S::get_input_name(int i)
{
    switch(i){
        case(0): return("A");
        case(1): return("CI");
        case(2): return("B");
        default: return "<?>";
    }

}

int Node_ATC18_SU01D_S::get_value(int run)
{
//define some helpers, makes it easier to write function
    #define A input_nodes[0]->get_value(run)
    #define CI input_nodes[1]->get_value(run)
    #define B input_nodes[2]->get_value(run)
    #define SC 0
    #define SD D
    #define S  value


    if (last_run != run){
        //need to recalc
        last_run_value = ((((A || (!B)) && !(A && (!B))) || CI) && !(((A || (!B)) && !(A && (!B))) && CI));
        last_run = run;
    }
    return last_run_value;
}

std::string Node_ATC18_SU01D_S::get_formula()
{
//define some helpers, makes it easier to write function
    std::string formula_A = input_nodes[0]->get_formula();
    std::string formula_CI = input_nodes[1]->get_formula();
    std::string formula_B = input_nodes[2]->get_formula();
    std::string formula_0 = "FALSE";
    std::string formula_1 = "TRUE";

    if (is_safe){
        return "SAFE";
    }else{
        return std::string("((((" + formula_A + " || (!" + formula_B + ")) && !(" + formula_A + " && (!" + formula_B + "))) || " + formula_CI + ") && !(((" + formula_A + " || (!" + formula_B + ")) && !(" + formula_A + " && (!" + formula_B + "))) && " + formula_CI + "))");
    }
}
