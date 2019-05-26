//
// Created by Asia on 2019-05-26.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

void fix(std::string path1, std::string path2){

    std::string buf1;
    std::string buf2;
    std::string delimiter = " ";
    std::ifstream file1;
    std::ofstream file2;
    std::vector<std::string> Vertices;
    int k = 0;
    int i = 0;
    bool cont = true;
    //size_t pos = -1;

    file1.open(path1);

    if(file1.is_open()){
        while(getline(file1,buf1)){
            if(buf1[0] == 'f'){
                buf1.erase(0,2);
                i = k ;
                cont = true;
                while(cont){

                    if (buf1.find(delimiter) == std::string::npos) {
                        Vertices.push_back(buf1.substr(0, buf1.size()));
                        //std::cout<<"pierwszy "<<Vertices[k]<<std::endl;
                        buf1.erase(0, buf1.size());
                        cont = false;
                    } else {
                        Vertices.push_back(buf1.substr(0, buf1.find(delimiter)));
                        //std::cout<<"drugi "<<Vertices[k]<<std::endl;
                        buf1.erase(0, buf1.find(delimiter) + 1);
                    }
                    if(buf1.substr(0, buf1.find(delimiter)).empty()){
                        //std::cout<<"pusty:("<<std::endl;
                        //Vertices.erase(Vertices.begin()+k-1);
                        cont = false;
                    }

                    //std::cout<<"hhh "<<Vertices[k]<<" hhh"<<std::endl;
                    k++;
                    //std::cout << k << " " << i << std::endl;
                    //if(buf1.find(delimiter) == std::string::npos && buf1.empty()){
                    //    cont = false;
                    //}
                }

                buf2+="f ";
                buf2+=Vertices[i];
                buf2+=" ";
                buf2+=Vertices[i+1];
                buf2+=" ";
                buf2+=Vertices[i+2];
                buf2+="\n";
                for(int n=i+3; n<k; ++n){
                    buf2+="f ";
                    buf2+=Vertices[n-3];
                    buf2+=" ";
                    buf2+=Vertices[n-1];
                    buf2+=" ";
                    buf2+=Vertices[n];
                    buf2+="\n";
                }

                //for(int i = 0; i<10; i++){
                //    Vertices.push_back(buf1.substr(2, buf1.find(delimiter)));
                //   buf1.erase(2,buf1.find(delimiter)+1);
                //}
            }
        }
        file1.close();
        std::cout<<buf2;
    } else{
        std::cerr<<"Error opening file1"<<std::endl;
    }

}