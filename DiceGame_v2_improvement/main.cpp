#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
        ofstream file;  //create variable for saving file
        file.open("results_improvement.txt");   //decalre file name for saving
        int number_of_tries = 10;   
        int start = 0;  
        while(start < number_of_tries){
            srand((unsigned) time(NULL)*(start*time(NULL))); //random number genartor seed value
            int work_done[6] {0}; //array for storing work done from workers
            int tabela[6][10][2] {0}; //array for storing work proces
            file << "Attempt " << start+1 << "\n\n";
            file << " DAY |   A | wpA |   B|  wpB |   C | wpC |   D | wpD |   E | wpE |   F | TOTAL \n";
            file << "-------------------------------------------------------------------------------------\n"; 
            for(int i = 0; i<10; ++i){ //10 day work proces loop
                if(i == 9){
                    file << "  " << i+1 << " ";
                }else{
                    file << "   " << i+1 << " ";
                }
     
                if(i == 0){ //first day values generator
                    int day1 = (rand() % 20) + 1; //random number generator
                    work_done[0] = day1;
                    tabela[0][i][0] = day1; //random generate number from 1-6 for the first worker
                    tabela[0][i][1] = day1; //work progres left by the first worker
                    for(int k = 1; k<6; ++k){ //loop for generatin number and work progres for other workers
                        int dice_throw;
                        if(k == 1 || k == 5){
                            dice_throw = (rand() % 20) + 1; //random number generator
                        }else if(k == 2 || k == 4){
                            dice_throw = (rand() % 10) + 1; //random number generator
                        }else{
                            dice_throw = (rand() % 6) + 1; //random number generator
                        }
                        
                        tabela[k][i][0] = dice_throw; //storing random number to worker
                        if(dice_throw > tabela[k-1][i][1]){ //saving if work progres from prevoius is less than generated number
                            tabela[k][i][1] = tabela[k-1][i][1]; 
                            work_done[k] = tabela[k-1][i][1]; //saving work done by worker
                            tabela[k-1][i][1] = 0;
                        }else{                              // saving if work progres from previous is more than generated number
                            work_done[k] = dice_throw;        //saving work done by worker
                            tabela[k-1][i][1] -= tabela[k][i][0];
                            tabela[k][i][1] = tabela[k][i][0]; 
                        }
                    }
                    for(int k = 0; k<6; ++k){   //file output loop
                        if(tabela[k][i][0] > 9){
                            file << "|  " << tabela[k][i][0] << " |";
                        }else{
                            file << "|   " << tabela[k][i][0] << " |";
                        }
                        if(tabela[k][i][1] > 9){
                            file << "  " << tabela[k][i][1] << " ";
                        }else{
                            file << "   " << tabela[k][i][1] << " ";
                        }
                    }
                    file << "\n";
                }else{
                    for(int k = 0 ; k<6;++k){ //value generator for the next 9 days (2-10)
                        int die_throw;
                        if(k == 0  || k==5){
                            die_throw = (rand() % 20) + 1; //random number generator
                        }else if(k == 1 || k == 4){
                            die_throw = (rand() % 10) + 1; //random number generator
                        }else{
                            die_throw = (rand() % 6) + 1; //random number generator
                        }
                        if(k==0){   //work done by first worker (A)
                            work_done[0] += die_throw; //saving work done by worker
                            tabela[k][i][0] = die_throw; //storing random number to worker
                            tabela[k][i][1] = die_throw + tabela[k][i-1][1];
                        }else{      // work done for the rest of the workers
                            tabela[k][i][0] = die_throw; //storing random number to worker
                            if(die_throw > tabela[k-1][i][1]){ //saving if work progres from prevoius is less than generated number
                                work_done[k] += tabela[k-1][i][1]; //saving work done by worker
                                tabela[k][i][1] = tabela[k-1][i][1]+tabela[k][i-1][1];     
                                tabela[k-1][i][1] = 0;
                            }else{                              // saving if work progres from previous is more than generated number
                                work_done[k] += die_throw; //saving work done by worker
                                tabela[k-1][i][1] -= tabela[k][i][0]; 
                                tabela[k][i][1] = tabela[k][i][0]+tabela[k][i-1][1]; 
                            }
                        }
                    }
                    for(int k = 0; k<6; ++k){   //print to file loop
                        if(tabela[k][i][0] > 9){
                            file << "|  " << tabela[k][i][0] << " |";
                        }else{
                            file << "|   " << tabela[k][i][0] << " |";
                        }
                        if(tabela[k][i][1] > 9){
                            file << "  " << tabela[k][i][1] << " ";
                        }else{
                            file << "   " << tabela[k][i][1] << " ";
                        }
                    }
                    file << "\n";
                }
            }
            file << "-------------------------------------------------------------------------------------\n"; 
            file << "Skupaj je bilo narejenih: " << tabela[5][9][1] << " izdelkov.\n\n"; 
            file << " Worker    |   A |   B |   C |   D |   E |   F \n";
            file << "-----------------------------------------------\n";
            file << " Work Done ";
            for(int j = 0 ; j < 6 ; ++j){ //print to file for work done by workers
                if(work_done[j] > 9){
                    file << "|  " << work_done[j] << " ";
                }else{
                    file << "|   " << work_done[j] << " ";
                }
            }
            file <<"\n\n";
            file << "**************************************************************************************\n";
            file <<"\n\n";
            start++;
        }
        return 0;
}