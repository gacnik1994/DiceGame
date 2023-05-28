#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
        ofstream file;
        file.open("results.txt");
        int number_of_tries = 10;
        int start = 0;
        while(start < number_of_tries){
            srand((unsigned) time(NULL)*(start*time(NULL)));
            int tabela[7][10][2] {0};
            file << " DAY |   A | wpA |   B|  wpB |   C | wpC |   D | wpD |   E | wpE |   F | wpF |   G | TOTAL \n";
            file << "-------------------------------------------------------------------------------------------\n"; 
            for(int i = 0; i<10; ++i){
                if(i == 9){
                    file << "  " << i+1 << " ";
                }else{
                    file << "   " << i+1 << " ";
                }
     
                if(i == 0){
                    int day1 = (rand() % 6) + 1;
                    tabela[0][i][0] = day1;
                    tabela[0][i][1] = day1;
                    for(int k = 1; k<7; ++k){
                        int dice_throw {(rand() % 6) + 1};
                        tabela[k][i][0] = dice_throw;
                        if(dice_throw > tabela[k-1][i][1]){
                            tabela[k][i][1] = tabela[k-1][i][1];     
                            tabela[k-1][i][1] = 0;
                        }else{
                            tabela[k-1][i][1] -= tabela[k][i][0];
                            tabela[k][i][1] = tabela[k][i][0]; 
                        }
                    }
                    for(int k = 0; k<7; ++k){
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
                    for(int k = 0 ; k<7;++k){
                        int die_throw {rand()%6+1};
                        if(k==0){
                            tabela[k][i][0] = die_throw;
                            tabela[k][i][1] = die_throw + tabela[k][i-1][1];
                        }else{
                            tabela[k][i][0] = die_throw;
                            if(die_throw > tabela[k-1][i][1]){
                                tabela[k][i][1] = tabela[k-1][i][1]+tabela[k][i-1][1];     
                                tabela[k-1][i][1] = 0;
                            }else{
                                tabela[k-1][i][1] -= tabela[k][i][0];
                                tabela[k][i][1] = tabela[k][i][0]+tabela[k][i-1][1]; 
                            }
                        }
                    }
                    for(int k = 0; k<7; ++k){
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
            file << "-------------------------------------------------------------------------------------------\n";
            file << "Skupaj je bilo narejenih: " << tabela[6][9][1] << " izdelkov.\n\n";
            start++;
        }
        return 0;
}