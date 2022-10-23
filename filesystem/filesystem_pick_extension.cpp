#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

void pick_extension(std::filesystem::path extension, std::filesystem::path targetpath, std::vector<std::filesystem::path>& ex_vector);

int main()
{
  std::vector<std::filesystem::path> json_list;
  std::filesystem::path target = "../samplefiles";
  pick_extension(".json", target, json_list);

  for (std::filesystem::path p : json_list)
  { 
    std::cout << p << std::endl;
  }
}

/*
 *
 */
void pick_extension(std::filesystem::path extension, std::filesystem::path targetpath, std::vector<std::filesystem::path>& ex_vector)
{
  if(ex_vector.empty() == false)
  {
    std::cerr << "Target vector is not empty. " << std::endl;
    return;
  }

  for (const fs::directory_entry& entry : fs::directory_iterator(targetpath)) 
  {
    if(entry.path().extension().compare(extension) == 0){
      ex_vector.push_back(entry.path());
    }
  }

  return;
}