/***************************************************************************
 *   Copyright (C) 2007 by Simon Schulz   *
 *   Simon.Schulz@esa.int   *
 *                                                                         *
 ***************************************************************************/
 ///this file was automatically created by B2 on Thu Jan 24 13:58:30 2008

#include "node_atc18_ora21d_z.h"

//register to node factory
std::string Node_ATC18_ORA21D_Z::node_factory_dummy = Node_factory<Node>::register_create_function("ATC18_ORA21D_Z",Node_ATC18_ORA21D_Z::create_function);
std::string Node_ATC18_ORA21D_Z::node_factory_dummy2 = Node_factory<Node>::register_output("ATC18_ORA21D","Z");

Node_ATC18_ORA21D_Z::Node_ATC18_ORA21D_Z(const char *name) : Node(name, 3){
    port_map_vector.push_back("A"); //0
    port_map_vector.push_back("B1"); //1
    port_map_vector.push_back("B2"); //2

}

Node_ATC18_ORA21D_Z::~Node_ATC18_ORA21D_Z()
{
}

std::string Node_ATC18_ORA21D_Z::get_input_name(int i)
{
    switch(i){
        case(0): return("A");
        case(1): return("B1");
        case(2): return("B2");
        default: return "<?>";
    }

}

int Node_ATC18_ORA21D_Z::get_value(int run)
{
//define some helpers, makes it easier to write function
    #define A input_nodes[0]->get_value(run)
    #define B1 input_nodes[1]->get_value(run)
    #define B2 input_nodes[2]->get_value(run)
    #define SC 0
    #define SD D
    #define Z  value


    if (last_run != run){
        //need to recalc
        last_run_value = (A && (B1 || B2));
        last_run = run;
    }
    return last_run_value;
}

std::string Node_ATC18_ORA21D_Z::get_formula()
{
//define some helpers, makes it easier to write function
    std::string formula_A = input_nodes[0]->get_formula();
    std::string formula_B1 = input_nodes[1]->get_formula();
    std::string formula_B2 = input_nodes[2]->get_formula();
    std::string formula_0 = "FALSE";
    std::string formula_1 = "TRUE";

    if (is_safe){
        return "SAFE";
    }else{
        return std::string("(" + formula_A + " && (" + formula_B1 + " || " + formula_B2 + "))");
    }
}
