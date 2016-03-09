// Include the headers relevant to the boost::program_options
// library
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/tokenizer.hpp>
#include <time.h>
#include "cgrasp.h"
#include "gnuplot-iostream.h"
using namespace boost;
using namespace boost::program_options;
#include <utility> 
#include <iostream>
#include <fstream>

// Include std::exception so we can handling any argument errors
// emitted by the command line parser
#include <exception>

using namespace std;

pair<string, string> at_option_parser(string const &s){
    if ('@' == s[0]){
        return std::make_pair(string("response-file"), s.substr(1));
    }else{
        return pair<string, string>();
        }
}

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
        ("lowerbound", value< double >(),"Specifies lower bound limits.")
        ("upperbound", value< double >(),"Specifies upper bound limits.")
        ("startgrid", value< double >(),"Specifies start grid dimension.")
        ("endgrid", value< double >(),"Specifies end grid dimension.")
        ("ro", value< double >(),"Specifies the portion of neighborhood.")
        ("k", value< int >(),"Specifies the number of samples rounds.")
        ("it", value< int >(),"Specifies the number of iterations.")
        ("ep", value< double >(),"Specifies the optimality gap.")
        ("excpt", value< vector<double> >()->multitoken(),"Specifies the exception sets.")
        ("config-file", value<string>(),"can be specified with '@name', too");
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
    if (vm.count("config-file")) {
        // Load the file and tokenize it
         ifstream ifs(vm["config-file"].as<string>().c_str());
         if (!ifs) {
             cout << "Could not open the response file\n";
             return 1;
         }
         // Read the whole file into a string
         stringstream ss;
         ss << ifs.rdbuf();
         // Split the file content
         
         char_separator<char> sep(" \n\r");
         std::string ResponsefileContents( ss.str() );
         tokenizer<char_separator<char> > tok(ResponsefileContents, sep);
         vector<string> args;
         copy(tok.begin(), tok.end(), back_inserter(args));
         // Parse the file and store the options
         store(command_line_parser(args).options(desc).run(), vm);
    }
    if (vm.count("function")){
        functionName = vm["function"].as< string >();
    }

    if (vm.count("dimension")){
        dimension = vm["dimension"].as< int>();
    }

    if (vm.count("lowerbound")){
        double lTemp = vm["lowerbound"].as< double >();
        for(int i=0; i<dimension;i++){
            l.push_back(lTemp);
        }
        
    }

    if (vm.count("upperbound")){
        double uTemp = vm["upperbound"].as< double >();
        for(int i=0; i<dimension;i++){
            u.push_back(uTemp);
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
    
    //vector<int> pts_A;
    //vector<double> pts_B;
    //for(int i=1;i<=500;i++){
    //    pts_A.push_back(i);
    //}
    //int dim;
    //for(int dim=344;dim<=345;dim++){
    //    printf("Dim = %d\n",dim );
    //    vector<double> lL;
    //    vector<double> uL;
    //    for(int i=0; i<dim;i++){
    //        lL.push_back(-10.0);
    //        uL.push_back(10.0);
    //    }

        time_t start,end;
        time (&start);
        cgrasp(f,dimension,hs,he,l,u,ro,k,iterations,ep);
        time (&end);
        double dif = difftime (end,start);
        //pts_B.push_back(dif);
        printf ("Elapsed time is %.2lf seconds.\n", dif );
    //    lL.clear();
    //    uL.clear();
        //dim = 454;
    //}
    delete [] f;
    //ofstream myfilestream ("myfile_python");
    //for(int i=0;i<pts_A.size();i++){
    //    myfilestream << pts_A[i]<< "\t"<< pts_B[i]<<"\n";
    //}

    
    return EXIT_SUCCESS;

}