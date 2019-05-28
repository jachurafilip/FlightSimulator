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
                        buf1.erase(0, buf1.size());
                        cont = false;
                    } else {
                        Vertices.push_back(buf1.substr(0, buf1.find(delimiter)));
                        buf1.erase(0, buf1.find(delimiter) + 1);
                    }
                    if(buf1.substr(0, buf1.find(delimiter)).empty()){
                        cont = false;
                    }
                    k++;
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

            }
        }
        file1.close();
        file2.open(path2);
        file2 << buf2;
        file2.close();
        //std::cout<<buf2;
    } else{
        std::cerr<<"Error opening file1"<<std::endl;
    }

}