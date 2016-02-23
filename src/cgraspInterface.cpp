// Include the headers relevant to the boost::program_options
// library
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_functions.hpp>
#include <time.h>
#include "cgrasp.h"
using namespace boost;
using namespace boost::program_options;

#include <iostream>
#include <fstream>

// Include std::exception so we can handling any argument errors
// emitted by the command line parser
#include <exception>

using namespace std;

int main(int argc , char **argv){

    // Add descriptive text for display when help argument is
    // supplied
    options_description desc("\nAn example command using Boost command line arguments.\n\nAllowed arguments");

    // Define command line arguments using either formats:
    //
    //     ("long-name,short-name", "Description of argument")
    //     for flag values or
    //
    //     ("long-name,short-name", <data-type>, 
    //     "Description of argument") arguments with values
    //
    // Remember that arguments with values may be multi-values
    // and must be vectors
    desc.add_options()
        ("function", value< string >(),"Specifies function name.")
        ("dimension", value< int >(),"Specifies dimension.")
        ("lowerbound", value< vector<double> >()->multitoken(),"Specifies lower bound limits.")
        ("upperbound", value< vector<double> >()->multitoken(),"Specifies upper bound limits.")
        ("startgrid", value< double >(),"Specifies start grid dimension.")
        ("endgrid", value< double >(),"Specifies end grid dimension.")
        ("ro", value< double >(),"Specifies the portion of neighborhood.")
        ("k", value< int >(),"Specifies the number of samples rounds.")
        ("it", value< int >(),"Specifies the number of iterations.")
        ("ep", value< double >(),"Specifies the optimality gap.")
        ("excpt", value< vector<double> >()->multitoken(),"Specifies the exception sets.");
    string functionName;
    int dimension;
    vector<double> l;
    vector<double> u;
    double hs;
    double he;
    double ro;
    int k;
    int iterations;
    double ep;
    // Parse the command line catching and displaying any 
    // parser errors
    variables_map vm;

    try{
        //store(command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
        store(command_line_parser(argc, argv).options(desc).style(
        command_line_style::unix_style ^ command_line_style::allow_short
        ).run(), vm);
        notify(vm);
    } catch (std::exception &e){
        cout << endl << e.what() << endl;
        cout << desc << endl;
    }

    // Display help text when requested
    if (vm.count("help")){
        cout << "[--function <function name> ] [--dimension <dimension value>]" 
        <<"[--lowerbound <lower bound limits>] [--upperbound <upper bound limits>]"
        <<"[--startgrid <start grid dimension>] [--endgrid <end grid dimension>]"
        <<"[--ro <neighborhood portion>] [--k <samples rounds>] [--excpt <exception sets>]" << endl;
        cout << desc << endl;
    }

    if (vm.count("function")){
        functionName = vm["function"].as< string >();
    }

    if (vm.count("dimension")){
        dimension = vm["dimension"].as< int>();
    }

    if (vm.count("lowerbound")){
        vector<double> lTemp = vm["lowerbound"].as< vector<double> >();
        if(lTemp.size()==1){
            for(int i=0; i<dimension;i++){
                l.push_back(lTemp[0]);

            }
        }else{
            for(int i=0;i<lTemp.size();i++){
                l.push_back(lTemp[i]);
            }
        }
    }

    if (vm.count("upperbound")){
        vector<double> uTemp = vm["upperbound"].as< vector<double> >();
        if(uTemp.size()==1){
            for(int i=0; i<dimension;i++){
                u.push_back(uTemp[0]);
            }
        }else{
            for(int i=0;i<uTemp.size();i++){
                u.push_back(uTemp[i]);
            }
        }
    }

    if (vm.count("startgrid")){
        hs = vm["startgrid"].as< double>();
    }
    if (vm.count("endgrid")){
        he = vm["endgrid"].as< double>();
    }
    if (vm.count("ro")){
        ro = vm["ro"].as< double>();
    }
    if (vm.count("k")){
        k = vm["k"].as< int>();
    }
    if (vm.count("it")){
        iterations = vm["it"].as< int>();
    }
    if (vm.count("ep")){
        ep = vm["ep"].as< double>();
    }
    if (vm.count("ep")){
        vector<double> excptTemp = vm["excpt"].as< vector<double> >();
        if(excptTemp.size()%3==0){
            for(int i=0;i<excptTemp.size();i=i+3){
                l[excptTemp[i]] = excptTemp[i+1];
                u[excptTemp[i]] = excptTemp[i+2];
            }
        }
    }
    
    char *f = new char[functionName.length() + 1];
    strcpy(f, functionName.c_str());
    time_t start,end;
    time (&start);
    cgrasp(f,dimension,hs,he,l,u,ro,k,iterations,ep);
    time (&end);
    double dif = difftime (end,start);
    printf ("Elapsed time is %.2lf seconds.\n", dif );
    return EXIT_SUCCESS;

}