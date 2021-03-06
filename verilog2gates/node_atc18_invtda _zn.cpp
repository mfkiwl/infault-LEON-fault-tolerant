/***************************************************************************
 *   Copyright (C) 2007 by Simon Schulz   *
 *   Simon.Schulz@esa.int   *
 *                                                                         *
 ***************************************************************************/
 ///this file was automatically created by 0 on Thu Jan 24 13:58:25 2008

#include "node_atc18_invtda _zn.h"

//register to node factory
std::string Node_ATC18_INVTDA _ZN::node_factory_dummy = Node_factory<Node>::register_create_function("ATC18_INVTDA _ZN",Node_ATC18_INVTDA _ZN::create_function);
std::string Node_ATC18_INVTDA _ZN::node_factory_dummy2 = Node_factory<Node>::register_output("ATC18_INVTDA ","ZN");

Node_ATC18_INVTDA _ZN::Node_ATC18_INVTDA _ZN(const char *name) : Node(name, 2){
    port_map_vector.push_back("I"); //0
    port_map_vector.push_back("EN"); //1

}

Node_ATC18_INVTDA _ZN::~Node_ATC18_INVTDA _ZN()
{
}

std::string Node_ATC18_INVTDA _ZN::get_input_name(int i)
{
    switch(i){
        case(0): return("I");
        case(1): return("EN");
        default: return "<?>";
    }

}

int Node_ATC18_INVTDA _ZN::get_value(int run)
{
//define some helpers, makes it easier to write function
    #define I input_nodes[0]->get_value(run)
    #define EN input_nodes[1]->get_value(run)
    #define SC 0
    #define SD D
    #define ZN  value


    if (last_run != run){
        //need to recalc
        last_run_value = (EN?I:0);
        last_run = run;
    }
    return last_run_value;
}

std::string Node_ATC18_INVTDA _ZN::get_formula()
{
//define some helpers, makes it easier to write function
    std::string formula_I = input_nodes[0]->get_formula();
    std::string formula_EN = input_nodes[1]->get_formula();
    std::string formula_0 = "FALSE";
    std::string formula_1 = "TRUE";

    if (is_safe){
        return "SAFE";
    }else{
        return std::string("(" + formula_EN + "?" + formula_I + ":" + formula_0 + ")");
    }
}
