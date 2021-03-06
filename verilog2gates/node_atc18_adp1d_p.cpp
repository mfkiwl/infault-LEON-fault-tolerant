/***************************************************************************
 *   Copyright (C) 2007 by Simon Schulz   *
 *   Simon.Schulz@esa.int   *
 *                                                                         *
 ***************************************************************************/
 ///this file was automatically created by B on Thu Jan 24 13:58:23 2008

#include "node_atc18_adp1d_p.h"

//register to node factory
std::string Node_ATC18_ADP1D_P::node_factory_dummy = Node_factory<Node>::register_create_function("ATC18_ADP1D_P",Node_ATC18_ADP1D_P::create_function);
std::string Node_ATC18_ADP1D_P::node_factory_dummy2 = Node_factory<Node>::register_output("ATC18_ADP1D","P");

Node_ATC18_ADP1D_P::Node_ATC18_ADP1D_P(const char *name) : Node(name, 3){
    port_map_vector.push_back("A"); //0
    port_map_vector.push_back("CI"); //1
    port_map_vector.push_back("B"); //2

}

Node_ATC18_ADP1D_P::~Node_ATC18_ADP1D_P()
{
}

std::string Node_ATC18_ADP1D_P::get_input_name(int i)
{
    switch(i){
        case(0): return("A");
        case(1): return("CI");
        case(2): return("B");
        default: return "<?>";
    }

}

int Node_ATC18_ADP1D_P::get_value(int run)
{
//define some helpers, makes it easier to write function
    #define A input_nodes[0]->get_value(run)
    #define CI input_nodes[1]->get_value(run)
    #define B input_nodes[2]->get_value(run)
    #define SC 0
    #define SD D
    #define P  value


    if (last_run != run){
        //need to recalc
        last_run_value = ((A && (!B)) || ((!A) && B));
        last_run = run;
    }
    return last_run_value;
}

std::string Node_ATC18_ADP1D_P::get_formula()
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
        return std::string("((" + formula_A + " && (!" + formula_B + ")) || ((!" + formula_A + ") && " + formula_B + "))");
    }
}
