#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<algorithm>


std::vector<int> split_and_intfy(const std::string& input,char delimiter){

  std::vector<int> tokens;
  std::string token;
  std::istringstream tokenStream(input);

  while(std::getline(tokenStream,token,delimiter)){
    
    tokens.push_back(std::stoi(token));
  }

  return tokens;
}


int checksum(const std::vector<std::vector<int>>& spreadsheet){

  auto checksum{0};
  // e = rows
  for (auto &e : spreadsheet){

    // debug
    auto max = std::max_element(std::begin(e),std::end(e));
    auto min = std::min_element(std::begin(e),std::end(e));

    checksum += (*max)-(*min) ;
  }

  return checksum;

}

int evenly_divisible_sum(std::vector<std::vector<int>> spreadsheet){

  auto checksum{0};
  
  // for each row in our spreadshit
  for (const auto& row: spreadsheet){
    
    // fix a first iterator
    for(auto i = 0; i < row.size() ; i++){
      // fix a moving iterator
      for(auto j = 0;j < row.size();j++){
	// if i%j == 0 and they're different
	// print the result for debugging and add their quotient to checksum
	if (row[i] % row[j] == 0 && row[i] != row[j]){
	  //std::cout << "divisible " << row[i] << " - " << row[j] << std::endl;

	  checksum += row[i] / row[j];
	}
      }

    }
    
    
   
    
  }

  
  return  checksum;

}


int main(int argc,char* argv[]){

  // first load file in

  std::ifstream file(argv[1]);

  std::string line;

  std::vector<std::vector<int>> spreadsheet;
    
  while(!std::getline(file,line).eof()){
     spreadsheet.push_back(split_and_intfy(line,' '));
  }

  std::vector<std::vector<int>> test_input{{5,1,9,5},{7,5,3},{2,4,6,8}};
  
  std::cout << checksum(test_input) << std::endl;
  std::cout << checksum(spreadsheet) << std::endl;


  std::vector<std::vector<int>> test_input_2{{5,9,2,8},{9,4,7,3},{3,8,6,5}};
  
  std::cout << evenly_divisible_sum(test_input_2) << std::endl;

  std::cout << evenly_divisible_sum(spreadsheet) << std::endl;

}

      
  
